#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "ACER, Card6, Ismooth",
          "[ACER] [Card6] [Ismooth]" ){
  GIVEN( "valid inputs" ){
    for( auto i : { 0, 1 } ){
      std::string situ( "valid input " + std::to_string(i) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< ACER::Card6::Ismooth >( iss ).value);
        }
      }
    }

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value can be verified" ){
        REQUIRE( 1 == argument::extract< ACER::Card6::Ismooth >( iss ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    for( auto i : { -1, 2 } ){
      std::string situ( "invalid input " + std::to_string(i) + " is provided.");
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string(i) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< ACER::Card6::Ismooth >( iss ) );
        }
      }
    }
  } // GIVEN
} // SCENARIO
