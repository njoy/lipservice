#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "lipservice.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "WIMSR, Card4, Ires",
          "[WIMSR] [Card4] [Ires]" ){
  GIVEN( "valid inputs" ){
    for( auto i : {0, 1, 10, 100} ){
      std::string situ( "valid input " + std::to_string(i) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< WIMSR::Card4::Ires >( iss ).value );
        }
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< WIMSR::Card4::Ires >( iss ) );
      }
    }

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( "-1" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< WIMSR::Card4::Ires >( iss ) );
      }
    }
  } // GIVEN
} // SCENARIO
