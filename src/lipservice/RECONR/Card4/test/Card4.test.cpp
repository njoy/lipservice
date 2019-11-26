#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "Verifying RECONR Card4 input", "[Card4]"){
  GIVEN( "valid err" ){
    double err(0.01);

    WHEN( "all the optional parameters are given" ){
      iRecordStream<char> iss( std::istringstream( std::to_string(err) 
						   + " 293.6 1.0 2.0") );
      RECONR::Card4 card4(iss );
      CHECK( err == card4.err.value );
      CHECK( 293.6 == Approx(card4.tempr.value) );
      CHECK( 1.0 == card4.errmax.value );
      CHECK( 2.0 == Approx(card4.errint.value) );

      THEN( "Card4 can be turned to JSON" ){
        nlohmann::json refJSON = { 
          { "err", err }, 
          { "tempr", 293.6 },
          { "errmax", 1.0 },
          { "errint", 2.0 }
        };
        CHECK( refJSON == nlohmann::json( card4 ) );
      } // THEN

    }
    WHEN( "none of the optional parameters are given" ){
      iRecordStream<char> iss( std::istringstream( std::to_string(err) + '/') );
      RECONR::Card4 card4(iss);

      CHECK( err == card4.err.value );
      CHECK( 0.0 == Approx(card4.tempr.value) );
      CHECK( err * 10 == card4.errmax.value );
      CHECK( (err / 2E4) == Approx(card4.errint.value) );

      THEN( "Card4 can be turned to JSON" ){
        nlohmann::json refJSON = { 
          { "err", err }, 
          { "tempr", 0.0 },
          { "errmax", err*10 },
          { "errint", err/2E4 }
        };
        CHECK( refJSON == nlohmann::json( card4 ) );
      } // THEN
    }
  }

  GIVEN( "invalid err" ){
    double err(0.0);
    THEN( "an exception is thrown" ){
      iRecordStream<char> iss( std::istringstream( std::to_string(err) + '/') );
      CHECK_THROWS( RECONR::Card4(iss) );
    }
  }
} // SCENARIO

