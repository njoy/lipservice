#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "Ytag output values", "[PLOTR],[Card10a], [Ytag]"){

  GIVEN( "valid Ytag parameters" ){
    std::vector<double> validValues{-2.0,-1.0,0.0,0.1,0.5,0.8,1.0,2.0,80.0};

    THEN( "the returned class has the correct value" ){
      for( auto ytag : validValues ){
        iRecordStream<char> issYtag( 
            std::istringstream( std::to_string( ytag ) ) );

        REQUIRE( ytag == argument::extract< PLOTR::Card10a::Ytag >( 
                          issYtag ).value );
      }
    }
  } // GIVEN

} // SCENARIO
