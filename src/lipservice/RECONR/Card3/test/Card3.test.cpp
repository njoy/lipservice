#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "Verifying RECONR Card3 input", "[RECONR], [Card3]" ){
  GIVEN( "valid Material" ){
    int material{9228};

    WHEN( "both ncards and ngrid are given" ){
      THEN( "the Card1 values can be tested" ){
        iRecordStream<char> iss( std::istringstream( std::to_string(material) + " 1 2 " ) );
        RECONR::Card3 card3(iss);
        CHECK( 9228 == card3.mat.value );
        CHECK( 1 == card3.ncards.value );
        CHECK( not card3.ncards.defaulted );
        CHECK( 2 == card3.ngrid.value );
        CHECK( not card3.ngrid.defaulted );

        AND_THEN( "Card3 can be turned to JSON" ){
          nlohmann::json refJSON = { 9228, 1, 2 };
          CHECK( refJSON == nlohmann::json( card3 ) );
        } // AND_THEN
      }
      THEN( "an exception is thrown when ncards is invalid" ){
        iRecordStream<char> iss( std::istringstream( std::to_string(material) + " -1 2 " ) );
        CHECK_THROWS( RECONR::Card3(iss) );
      }
      THEN( "an exception is thrown when ngrid is invalid" ){
        iRecordStream<char> iss( std::istringstream( std::to_string(material) + " 1 -2 " ) );
        CHECK_THROWS( RECONR::Card3(iss) );
      }
    } // WHEN

    WHEN( "ncards is given but ngrid is absent"){
      iRecordStream<char> iss( std::istringstream( std::to_string(material) + " 1 /" ) );
      RECONR::Card3 card3(iss);

      CHECK( 9228 == card3.mat.value );
      CHECK( 1 == card3.ncards.value );
      CHECK( not card3.ncards.defaulted );
      CHECK( 0 == card3.ngrid.value );
      CHECK( card3.ngrid.defaulted );

      THEN( "Card3 can be turned to JSON" ){
        nlohmann::json refJSON = { 9228, 1, 0 };
        CHECK( refJSON == nlohmann::json( card3 ) );
      } // THEN
    } // WHEN

    WHEN( "both ncards and grid are absent" ){
      iRecordStream<char> iss( std::istringstream( std::to_string(material) + '/' ) );
      RECONR::Card3 card3(iss);

      CHECK( 9228 == card3.mat.value );
      CHECK( 0 == card3.ncards.value );
      CHECK( card3.ncards.defaulted );
      CHECK( 0 == card3.ngrid.value );
      CHECK( card3.ngrid.defaulted );

      THEN( "Card3 can be turned to JSON" ){
        nlohmann::json refJSON = { 9228, 0, 0 };
        CHECK( refJSON == nlohmann::json( card3 ) );
      } // THEN
    }
  } // GIVEN

  GIVEN( "invalid Material" ){
    int material{-1};
    
    THEN( "an exception is thrown when reading RECONR Card3 input" ){
      iRecordStream<char> iss( std::istringstream( std::to_string(material) ) );
      CHECK_THROWS( RECONR::Card3(iss) );
    }
  } // GIVEN
} // SCENARIO
