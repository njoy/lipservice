#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "Eb output values", "[GROUPR],[Card8c], [Eb]"){

  GIVEN( "valid Eb parameters" ){

    THEN( "the returned class has the correct value" ){
      for( auto eb : { 1.0, 1E-3, 10.0} ){
        iRecordStream<char> issEb( 
            std::istringstream( std::to_string( eb ) ) );

        REQUIRE( eb == 
                argument::extract< GROUPR::Card8c::Eb >( issEb ).value );
      }
    }
  } // GIVEN
  GIVEN( "invalid Eb parameters" ){

    THEN( "the returned class has the correct value" ){
      for( auto eb : {-1.0, 0.0}){
        njoy::Log::debug("eb: {}", eb);
        iRecordStream<char> issEb( 
            std::istringstream( std::to_string( eb ) ) );

        REQUIRE_THROWS( argument::extract< GROUPR::Card8c::Eb >( issEb ) );
      }
    }
  } // GIVEN
} // SCENARIO
