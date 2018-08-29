#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "MATXSR Card1 Ngen2 values",
          "[MATXSR],[Card1],[Ngen2]" ){

  const int ngen1 = 24;

  GIVEN( "valid inputs" ){
    for( auto i : {-99,-40,-20,0,20,97,99} ){
      std::string situ( "valid input " + std::to_string(i) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< MATXSR::Card1::Ngen2 >(
                                           iss, ngen1 ).value );
        }
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    for( auto i : {-100,-24,-19,19,24,100} ){
      std::string situ( "invalid input " + std::to_string(i) + " is provided.");
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< MATXSR::Card1::Ngen2 >(
                                             iss, ngen1 ) );
        }
      }
    }

    WHEN( "no input is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      REQUIRE_THROWS( argument::extract< MATXSR::Card1::Ngen2 >(
                                         iss, ngen1 ) );
    }
  } // GIVEN
} // SCENARIO
