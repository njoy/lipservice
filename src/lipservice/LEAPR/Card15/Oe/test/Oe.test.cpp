#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "LEAPR Card15 oe input values",
  "[LEAPR], [Card15], [Oe]" ){
  GIVEN( "a small value for nd" ){
    Argument< LEAPR::Card14::Nd > nd;
    nd.value = 3;

    WHEN( "there are the correct number of oes and they are valid" ){
      iRecordStream< char> iss( std::istringstream(" 1.0 2.0 3.0") );

      THEN( "the oe values can be extracted correctly" ){
        auto oes = argument::extract< 
          LEAPR::Card15::Oe >(iss, nd);
          std::vector< double > refOes{ 1.0, 2.0, 3.0 };
        REQUIRE( refOes == oes.value );
      } // THEN
    } // WHEN
    WHEN( "the oe values are invalid" ){
      iRecordStream< char> iss( std::istringstream("-1.0 2.0 3.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< 
          LEAPR::Card15::Oe >( iss, nd ) );
      } // THEN
    } // WHEN
    WHEN( "the oe values are not in increasing order" ){
      iRecordStream< char> iss( std::istringstream("1.0 3.0 2.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< 
          LEAPR::Card15::Oe >( iss, nd ) );
      } // THEN
    } // WHEN
    WHEN( "too few oe values are provided" ){
      iRecordStream< char> iss( std::istringstream("1.0 2.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract<
          LEAPR::Card15::Oe >( iss, nd ) );
      } // THEN
    } // WHEN
    WHEN( "too many oe values are provided" ){
      iRecordStream< char> iss( std::istringstream("1.0 2.0 3.0 4.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_NOTHROW( argument::extract<
          LEAPR::Card15::Oe >( iss, nd ) );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "a larger value for nd" ){
    Argument< LEAPR::Card14::Nd > nd;
    nd.value = 7;

    WHEN( "there are the correct number of oes and they are valid" ){
      iRecordStream< char> iss( std::istringstream(
      ".010 .015 .025 .035\n"
      "2.5e-1 3.3e-1  5.04e-1/"
      ) );

      THEN( "the oe values can be extracted correctly" ){
        auto oes = argument::extract< 
          LEAPR::Card15::Oe >(iss, nd);
        std::vector< double > refOes{ .01, .015, .025, .035, .250, .330, .504 };
        REQUIRE( refOes == oes.value );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
