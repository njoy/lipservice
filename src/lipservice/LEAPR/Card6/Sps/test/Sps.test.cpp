#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "LEAPR Card6 sps input values", 
  "[LEAPR], [Card6], [Sps]"){
  GIVEN( "valid sps input values" ){
    std::vector<double> validValues{0.001, 23.0};
    THEN( "the returned class has the correct value" ){
      for( auto& sps : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( sps ) ) );
        REQUIRE( sps == argument::extract< 
          LEAPR::Card6::Sps >( iss ).value );
      }
    } // THEN
  } // GIVEN
  GIVEN( "invalid sps values" ){
    std::vector<double> invalidValues{0,-0.001};
    THEN( "an exception is thrown" ){
      for( auto& sps : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( sps ) ) );
        REQUIRE_THROWS( argument::extract< LEAPR::Card6::Sps >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
