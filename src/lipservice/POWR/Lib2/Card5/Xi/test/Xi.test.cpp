#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "POWR, Lib2, Card5, Xi",
          "[POWR] [Lib2] [Card5] [Xi]" ){
  GIVEN( "valid inputs" ){
    for( double d : {0.0, 0.1, 1.0, 10.0, 100.0} ){
      std::string situ( "valid input " + std::to_string(d) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( d ) ) );

        THEN( "the value is verified" ){
          REQUIRE( Approx( d ) == argument::extract< POWR::Lib2::Card5::Xi >(
                                                                  iss ).value );
        }
      }
    } // WHEN

    WHEN( "no input is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value is verified" ){
        REQUIRE( Approx( 0.0 ) == argument::extract< POWR::Lib2::Card5::Xi >(
                                                                  iss ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    for( double d : {-100.0, -10.0, -1.0, -0.1} ){
      std::string situ( "invalid input " + std::to_string(d) + " is provided.");
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( d ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< POWR::Lib2::Card5::Xi >( iss ) );
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
