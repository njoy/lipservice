#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "Verifying RECONR Card6 input", "[RECONR],[Card6]"){
  Argument< RECONR::Card3::Ngrid > ngrid; ngrid.value = 3;
  
  GIVEN( "valid enode" ){
    iRecordStream<char> iss( std::istringstream(" 1.0 2.0 3.0") );
    THEN( "the energy grid can be extracted" ){
      std::vector< double > refGrid{ 1.0, 2.0, 3.0};
      RECONR::Card6 card6( iss, ngrid );
      CHECK( refGrid == card6.enode.value );

      AND_THEN( "Card6 can be turned to JSON" ){
        nlohmann::json refJSON = { { "enode", { 1.0, 2.0, 3.0 } } };
        CHECK( refJSON == nlohmann::json( card6 ) );
      } // AND_THEN
    }
  }
  GIVEN( "invalid enode" ){
    iRecordStream<char> iss( std::istringstream(" 1.0 2.0 3.0 4.0") );

    THEN( "an exception is thrown" ){
      CHECK_THROWS( RECONR::Card6( iss, ngrid ) );
    }
  }
}

