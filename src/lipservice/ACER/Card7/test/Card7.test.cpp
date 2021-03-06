#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "Verifying ACER Card7 input", 
         "[ACER], [Card7]" ){
  GIVEN( "all three entries" ){
    THEN( "the appropriate values are returned" ){
      iRecordStream<char> issCard7( std::istringstream( "2.0 1E3 2/" ) );
      ACER::Card7 card7( issCard7 );

      REQUIRE(2.00 == card7.thin1.value );
      REQUIRE( 1E3 == card7.thin2.value );
      REQUIRE( 2   == card7.thin3.value );
    }
  }
  GIVEN( "only two entries" ){
    THEN( "the appropriate values are returned" ){
      iRecordStream<char> issCard7( std::istringstream( "-2.0 1E3 /" ) );
      ACER::Card7 card7( issCard7 );

      REQUIRE(-2.00 == card7.thin1.value );
      REQUIRE( 1E3 == card7.thin2.value );
      REQUIRE( 0   == card7.thin3.value );
    }
  }
  GIVEN( "only one entry" ){
    THEN( "the appropriate values are returned" ){
      iRecordStream<char> issCard7( std::istringstream( "2.0 /" ) );
      ACER::Card7 card7( issCard7 );

      REQUIRE(2.00 == card7.thin1.value );
      REQUIRE( 0 == card7.thin2.value );
      REQUIRE( 0   == card7.thin3.value );
    }
  }
  GIVEN( "no entries---default" ){
    THEN( "the default values can be returned" ){
      iRecordStream<char> issCard7( std::istringstream( "/" ) );
      ACER::Card7 card7( issCard7 );

      REQUIRE( 0.0 == card7.thin1.value );
      REQUIRE( 0.0 == card7.thin2.value );
      REQUIRE( 0   == card7.thin3.value );
    }
  }
  GIVEN( "invalid entries" ){
    THEN( "an exception is thrown" ){
      iRecordStream<char> issCard7( std::istringstream( " -1 -2 -7 " ) );
      REQUIRE_THROWS( ACER::Card7( issCard7 ) );
    }
  }
}

