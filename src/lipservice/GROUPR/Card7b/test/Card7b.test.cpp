#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "Verifying GROUPR Card7b input", "[GROUPR], [Card7b]" ){

  Argument< GROUPR::Card7a::Ngg > ngg;
  ngg.value = 3;

  GIVEN( "valid energy boundaries" ){
    iRecordStream< char> issEggs( std::istringstream( " 1 2 3 4" ) );

    THEN( "the sigma zero cross section values can be extracted and verified" ){
      std::vector< double > refEggs{
        1,
        2,
        3,
        4};

      GROUPR::Card7b card7b( issEggs, ngg );
      REQUIRE( refEggs == card7b.egg.value );
    }
  }
  GIVEN( "invalid egg---not enough energy boundaries" ){
    iRecordStream< char> issTemps( std::istringstream( " 1 2 3 " ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( GROUPR::Card7b( issTemps, ngg ) );
    }
  }
  GIVEN( "invalid sigz---too many sigma zero values" ){
    iRecordStream< char> issTemps( std::istringstream( " 1 2 3 4 5 " ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( GROUPR::Card7b( issTemps, ngg ) );
    }
  }
} // SCENARIO

