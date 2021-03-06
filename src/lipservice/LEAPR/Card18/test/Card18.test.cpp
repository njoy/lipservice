#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;
SCENARIO( "LEAPR Card18 input values",
  "[LEAPR], [Card18]" ){
  GIVEN( "a value for nka" ){
    Argument< LEAPR::Card17::Nka > nka;
    nka.value = 3;

    WHEN( "there are the correct number of card18 inputs and they are valid" ){
      iRecordStream< char> iss( std::istringstream(" 1.0 2.0 3.0") );

      THEN( "the skappa values can be extracted correctly" ){
        std::vector< double > refSkappas{ 1.0, 2.0, 3.0 };
        LEAPR::Card18 card18( iss, nka );
        REQUIRE( refSkappas == card18.skappa.value );
      } // THEN
    } // WHEN
    WHEN( "a card18 input value is out of range" ){
      iRecordStream< char> iss( std::istringstream("0.0 2.0 3.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR::Card18( iss, nka ) );
      } // THEN
    } // WHEN
//    WHEN( "the card18 input values are not in increasing order" ){
//      iRecordStream< char> iss( std::istringstream("1.0 3.0 2.0") );
//      THEN( "an exception is thrown" ){
//        REQUIRE_THROWS( LEAPR::Card18( iss, nka ) );
//      } // THEN
//    } // WHEN
    WHEN( "too few card18 input values are provided" ){
      iRecordStream< char> iss( std::istringstream("1.0 2.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR::Card18( iss, nka ) );
      } // THEN
    } // WHEN
    WHEN( "too many card18 input values are provided" ){
      iRecordStream< char> iss( std::istringstream("1.0 2.0 3.0 4.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR::Card18( iss, nka ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
