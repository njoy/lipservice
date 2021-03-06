#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "LEAPR Card17 dka input values",
  "[LEAPR], [Card17], [Dka] "){
  GIVEN( "valid dka values" ){
    std::vector<double> validDka{ 0.001, 293.6, 500.0 };
    THEN( "the returned class has the correct value" ){
      for( auto& dka : validDka ){
        iRecordStream<char> iss( std::istringstream( std::to_string(dka) ) );
        REQUIRE( dka == 
                ( argument::extract< LEAPR::Card17::Dka >( iss ) ).value );
      }
    } // THEN
  } // GIVEN
  GIVEN( "invalid dka values" ){
    std::vector<double> invalidDka{ 0.0, -1.0 };
    THEN( "an exception is thrown" ){
      for( auto& dka : invalidDka ){
        iRecordStream<char> iss( std::istringstream( std::to_string(dka) ) );
        REQUIRE_THROWS( argument::extract< LEAPR::Card17::Dka >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
