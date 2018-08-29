#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "nendf input values",
  "[THERMR],[Card1],[Nendf]" ){
  GIVEN( "valid nendf tape values" ){
    std::vector<int> validValues{-20, 20, 0, 42, 99, -99};
    THEN( "the returned class has the correct tape value" ){
      for( auto nendf : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( nendf ) ) );
        REQUIRE(nendf == argument::extract< 
          THERMR::Card1::Nendf >( iss ).value );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid nendf tape values" ){
    std::vector<int> invalidValues{-19, 19, -1, 1, 100, -100};
    THEN( "an exception is thrown" ){
      for( auto nendf : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string(nendf) ) );
        REQUIRE_THROWS( argument::extract<
          THERMR::Card1::Nendf>( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO

