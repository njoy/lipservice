#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "ERRORR, Normal, Card11, Mtb",
          "[ERRORR] [Normal] [Card11] [Mtb]" ){
  GIVEN( "valid inputs" ){
    for( auto i : {-999, -10, -1, 1, 10, 999} ){
      std::string situ( "valid input " + std::to_string(i) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< ERRORR::Normal::Card11::Mtb >(
                                                                  iss ).value );
        }
      } // WHEN
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< ERRORR::Normal::Card11::Mtb >(
                                                                        iss ) );
      }
    } // WHEN

    for( auto i : {-1000, 0, 1000} ){
      std::string situ( "invalid input " + std::to_string(i) + " is provided.");
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< ERRORR::Normal::Card11::Mtb >(
                                                                        iss ) );
        }
      } // WHEN
    }
  } // GIVEN
} // SCENARIO
