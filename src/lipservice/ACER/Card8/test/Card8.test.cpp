#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "Verifying ACER Card8 input", "[ACER], [Card8]" ){
  GIVEN( "valid material, temperature, name, and nza" ){
    iRecordStream<char> issCard8( std::istringstream( " 1 293.6 'lwtr' 2" ) );

    THEN( " the material and temperature can be extracted and verified" ){
      ACER::Card8 card8 ( issCard8 );
      CHECK( 1 == card8.matd.value );
      CHECK( 293.6 == card8.tempd.value );
      CHECK( "lwtr" == *card8.tname.value );
      CHECK( 2 == card8.nza.value );
    }
  } // GIVEN
  GIVEN( "only material and temperature" ){
    iRecordStream<char> issCard8( 
        std::istringstream( " 1 293.6  /" ) );

    THEN( " the material and temperature can be extracted and verified" ){
      ACER::Card8 card8 ( issCard8 );
      CHECK( 1 == card8.matd.value );
      CHECK( 293.6 == card8.tempd.value );
      CHECK( std::nullopt == card8.tname.value );
      CHECK( 3 == card8.nza.value );
    }
  } // GIVEN

  GIVEN( "invalid Card8 input" ){
    WHEN( "invalid entries" ){
    iRecordStream<char> issCard8( 
        std::istringstream( " 1 293.6 'abcdefghij' /" ) );
      THEN( "an exception is thrown" ){
        CHECK_THROWS( ACER::Card8( issCard8 ) );
      }

    }
  } // GIVEN
} // SCENARIO
