#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "efirst values",
          "[RESXSR],[Card2],[Efirst]" ){

  GIVEN( "valid values" ){
    for( auto efirst : { 0.0, 0.1, 2.0, 20.1, 4002.1 } ){
    std::string situ( "valid value " + std::to_string( efirst ) +
                                                              " is provided." );
      THEN( situ.c_str() ){
        iRecordStream<char> issEfirst( std::istringstream(
                            std::to_string( efirst ) ) );
        REQUIRE( efirst ==
                 argument::extract< RESXSR::Card2::Efirst >( issEfirst ).value);
      }
    }
  }

  GIVEN( "invalid values" ){
    for( auto efirst : { -10.0, -2.0 } ){
      std::string situ( "invalid value " + std::to_string( efirst ) +
                                                              " is provided." );
      THEN( situ.c_str() ){
        iRecordStream<char> issEfirst( std::istringstream(
                            std::to_string( efirst ) ) );
        REQUIRE_THROWS( argument::extract< RESXSR::Card2::Efirst >(
                        issEfirst ) );
      }
    }
  }
}
