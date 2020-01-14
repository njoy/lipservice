#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "THERMR Card1 inputs",
  "[THERMR], [Card1] "){
  GIVEN( "valid Card1 inputs" ){
    WHEN( "thermal scattering data provided" ){
      iRecordStream<char> iss( std::istringstream("20 21 22") );
      THEN( "the extracted values are correct" ){
        THERMR::Card1 card1( iss );
        CHECK( card1.nendf.value == 20 );
        CHECK( card1.nin.value == 21 );
        CHECK( card1.nout.value == 22 );

        AND_THEN( "Card1 can be turned to JSON" ){
          nlohmann::json refJSON = R"(
          {
            "nendf": 20,
            "nin": 21,
            "nout": 22
          }
          )"_json;
          CHECK( refJSON == nlohmann::json( card1 ) );
        } // AND_THEN
      } // THEN
    } // WHEN
    WHEN( "thermal scattering data not provided" ){
      iRecordStream<char> iss( std::istringstream("0 21 22") );
      THEN( "the extracted values are correct" ){
        THERMR::Card1 card1( iss );
        CHECK( card1.nendf.value == 0 );
        CHECK( card1.nin.value == 21 );
        CHECK( card1.nout.value == 22 );

        AND_THEN( "Card1 can be turned to JSON" ){
          nlohmann::json refJSON = R"(
          {
            "nendf": 0,
            "nin": 21,
            "nout": 22
          }
          )"_json;
          CHECK( refJSON == nlohmann::json( card1 ) );
          
        } // AND_THEN
      } // THEN
    } // WHEN
  } // GIVEN
  
  GIVEN( "invalid Card1 inputs" ){
    WHEN( "an input tape is reused" ){    
      iRecordStream<char> iss1( std::istringstream("20 20 21\n") );
      iRecordStream<char> iss2( std::istringstream("20 21 20\n") );
      iRecordStream<char> iss3( std::istringstream("20 21 21\n") );
      THEN( "an exception is thrown" ){
        CHECK_THROWS( THERMR::Card1( iss1 ) );
        CHECK_THROWS( THERMR::Card1( iss2 ) );
        CHECK_THROWS( THERMR::Card1( iss3 ) );
      } // THEN
    } // WHEN
    WHEN( "an input tape is out of range" ){
      iRecordStream<char> iss1( std::istringstream("20 21 100\n") );
      iRecordStream<char> iss2( std::istringstream("20 19 20\n") );
      iRecordStream<char> iss3( std::istringstream("19 20 22\n") );
      THEN( "an exception is thrown" ){
        CHECK_THROWS( THERMR::Card1( iss1 ) );
        CHECK_THROWS( THERMR::Card1( iss2 ) );
        CHECK_THROWS( THERMR::Card1( iss3 ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
