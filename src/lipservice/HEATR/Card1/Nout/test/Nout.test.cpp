#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "nout output values",
  "[HEATR], [Card1], [Nout]"){
  GIVEN( "a valid nendf tape value" ){
    Argument< HEATR::Card1::Nendf > nendf; nendf.value = 21;
    Argument< HEATR::Card1::Nin   > nin;   nin.value = 22;
    
    WHEN( "nout input is within range and not equal to nendf or nin" ){
      std::vector<int> validValues{-20, 20, 42, 99, -99};
      for( auto nout : validValues ){
        THEN( "the returned class has the correct tape value: " + 
               std::to_string( nout ) ){
            nendf.value = nout/std::abs( nout );
            nin.value = nout/std::abs( nout );
            iRecordStream<char> iss(
              std::istringstream( std::to_string( nout ) ) );
            REQUIRE( nout == argument::extract< 
              HEATR::Card1::Nout >( iss, nendf, nin ).value );
        } // THEN
      } // for
    } // WHEN
    WHEN( "nout input is equal to nendf" ){
      THEN( "an exception is thrown" ){
        iRecordStream<char> iss( std::istringstream( "21" ) );
        REQUIRE_THROWS( argument::extract< 
          HEATR::Card1::Nout >( iss, nendf, nin ) );
      } // THEN
    } // WHEN

    WHEN( "nout input is equal to nin" ){
      THEN( "an exception is thrown" ){
        iRecordStream<char> iss( std::istringstream( "22" ) );
        REQUIRE_THROWS( argument::extract< 
          HEATR::Card1::Nout >( iss, nendf, nin ) );
      } // THEN
    } // WHEN

    WHEN( "nout values are out of range" ){
      std::vector<int> invalidValues{-19, 19, 0, 100, -100};
      THEN( "an exception is thrown" ){
        for( auto nout : invalidValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( nout ) ) );
          REQUIRE_THROWS( argument::extract<
            HEATR::Card1::Nout>( iss, nendf, nin ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

