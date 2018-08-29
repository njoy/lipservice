#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "Verifying ACER Card11 input",
          "[ACER], [Card11]" ){
  GIVEN( "valid material and temperature" ){
    iRecordStream<char> issCard11( std::istringstream( " 9235 " ) );

    THEN( " the material and temperature can be extracted and verified" ){
      ACER::Card11 card11 ( issCard11 );
      REQUIRE( 9235 == card11.matd.value );
    }
  } // GIVEN

  GIVEN( "invalid Card11 input" ){
    iRecordStream<char> issCard11( std::istringstream( " -9235" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ACER::Card11( issCard11 ) );
      }
  } // GIVEN
} // SCENARIO

