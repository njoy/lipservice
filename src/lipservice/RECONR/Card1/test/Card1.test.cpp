#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "RECONR Card1 input" ){
  GIVEN( "valid Card1 inputs" ){
    std::vector<std::pair<int, int>> validCard1Pairs{ {20, 21},
                                                      {21, 22},
                                                      {41, 42} };
    for( auto& card1Pair : validCard1Pairs ){
      THEN( "Card1's can be created with pair: " +
            "(" + std::to_string( card1Pair.first ) + 
            ", " + std::to_string( card1Pair.second ) + ")" ){

        iRecordStream<char> iss ( std::istringstream( 
            std::to_string(card1Pair.first) + " " +
            std::to_string(card1Pair.second) ) );

        RECONR::Card1 card1 (iss );
        AND_THEN( "the members can be tested" ){
          CHECK( card1Pair.first == card1.nendf.value );
          CHECK( card1Pair.second == card1.npend.value );
        }

        AND_THEN( "Card1 can be turned to JSON " ){
          nlohmann::json refJSON = { card1Pair.first, card1Pair.second };
          CHECK( refJSON == nlohmann::json( card1 ) );
          
        } // AND_THEN
      }
    }
  }

  GIVEN( "invalid Card1 inputs" ){
    // Note we don't have to test for all possible invalid Nendf and Npend
    // as those are tested in their respective classes/tests.
      iRecordStream<char> stream1( std::istringstream("   -20 21") );
      CHECK_THROWS( RECONR::Card1( stream1 ) );
      iRecordStream<char> stream2( std::istringstream("   -20 -20") );
      CHECK_THROWS( RECONR::Card1( stream2 ) );
  }
} // SCENARIO
