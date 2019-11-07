#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "Verifying THERMR Card3 input", "[THERMR], [Card3]" ){

  GIVEN( "a valid value for ntemp" ){
    Argument< THERMR::Card2::Ntemp > ntemp; ntemp.value = 3;
    WHEN( "Card3 input is valid" ){
      iRecordStream< char> iss( std::istringstream( "293.6 600 1200" ) );
      THEN( "the tempreratures can be extracted and verified" ){
        std::vector< double > refTemprs{ 293.6, 600, 1200 };
        THERMR::Card3 card3( iss, ntemp );
        REQUIRE( refTemprs == card3.tempr.value );
      } // THEN
    } // WHEN
    WHEN( "not enough tempreratures provided" ){
      iRecordStream< char> iss( std::istringstream( "293.6 600 " ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( THERMR::Card3( iss, ntemp ) );
      } // THEN
    } // WHEN
    WHEN( "too many tempreratures provided" ){
      iRecordStream< char> iss( std::istringstream( "293.6 600 900 1200" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( THERMR::Card3( iss, ntemp ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
