#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "ERRORR, Normal, Card10, Mat1",
          "[ERRORR] [Normal] [Card10] [Mat1]" ){
  GIVEN( "valid inputs" ){
    for( auto i : {0, 1, 10, 100, 1000, 9999} ){
      std::string situ( "valid input " + std::to_string(i) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< ERRORR::Normal::Card10::Mat1 >(
                                                                  iss ).value );
        }
      } // WHEN
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< ERRORR::Normal::Card10::Mat1 >(
                                                                        iss ) );
      }
    } // WHEN

    for( auto i : {-1, 10000} ){
      std::string situ( "invalid input " + std::to_string(i) + " is provided.");
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< ERRORR::Normal::Card10::Mat1 >(
                                                                        iss ) );
        }
      } // WHEN
    }
  } // GIVEN
} // SCENARIO
