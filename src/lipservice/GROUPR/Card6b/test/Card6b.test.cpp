#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "Verifying GROUPR Card6b input", "[GROUPR], [Card6b]" ){

  Argument< GROUPR::Card6a::Ngn > ngn;
  ngn.value = 3;

  GIVEN( "valid energy boundaries" ){
    iRecordStream< char> issEgns( std::istringstream( " 1 2 3 4" ) );

    THEN( "the sigma zero cross section values can be extracted and verified" ){
      std::vector< double > refEgns{
        1,
        2,
        3,
        4};

      GROUPR::Card6b card6b( issEgns, ngn );
      REQUIRE( refEgns == card6b.egn.value );
    }
  }
  GIVEN( "invalid egn---not enough energy boundaries" ){
    iRecordStream< char> issTemps( std::istringstream( " 1 2 3 " ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( GROUPR::Card6b( issTemps, ngn ) );
    }
  }
  GIVEN( "invalid ngn---too many enery boundaries " ){
    iRecordStream< char> issTemps( std::istringstream( " 1 2 3 4 5 " ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( GROUPR::Card6b( issTemps, ngn ) );
    }
  }
} // SCENARIO

