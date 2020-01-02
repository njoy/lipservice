#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "THERMR Card4 inputs",
  "[THERMR], [Card4] "){
  GIVEN( "valid Card4 inputs" ){
    WHEN( "all values provided" ){
      iRecordStream<char> is( std::istringstream(".01 4.6") );
      THEN( "the extracted values are correct" ){
        THERMR::Card4 card4( is );
        CHECK( card4.tol.value == 0.01 );
        CHECK( card4.emax.value == 4.6 );

        AND_THEN( "Card4 can be turned to JSON" ){
          nlohmann::json refJSON = R"(
          {
            "tol":  0.01,
            "emax": 4.6
          }
          )"_json;
          CHECK( refJSON == nlohmann::json( card4 ) );
        } // AND_THEN
      } // THEN 
    } // WHEN
  } // GIVEN
  
  GIVEN( "invalid Card4 inputs" ){
    WHEN( "an card4 input is out of range" ){
      iRecordStream<char> is1( std::istringstream("1e-6 4.5") );
      iRecordStream<char> is2( std::istringstream("0.05 0.0") );
      THEN( "an exception is thrown" ){
        CHECK_THROWS( THERMR::Card4( is1 ) );
        CHECK_THROWS( THERMR::Card4( is2 ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
