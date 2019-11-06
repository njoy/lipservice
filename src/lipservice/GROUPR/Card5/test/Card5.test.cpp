#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "Verifying GROUPR Card5 input", "[GROUPR], [Card5]" ){

  Argument< GROUPR::Card2::Nsigz > nsigz;
  nsigz.value = 3;

  GIVEN( "valid sigzs" ){
    iRecordStream< char> issSigzs( std::istringstream( " 1 2 3" ) );
    long ln(0);

    THEN( "the sigma zero cross section values can be extracted and verified" ){
      std::vector< double > refSigzs{
        std::numeric_limits<double>::infinity() 
        2
        3

      GROUPR::Card5 card5( issSigzs, nsigz );
      REQUIRE( refSigzs == card5.sigz.value );
    }
  }
  GIVEN( "invalid sigz---not enough sigma zero values" ){
    iRecordStream< char> issTemps( std::istringstream( " 1 2 " ) );
    long ln(0);

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( GROUPR::Card5( issTemps, nsigz ) );
    }
  }
  GIVEN( "invalid sigz---too many sigma zero values" ){
    iRecordStream< char> issTemps( std::istringstream( " 1 2 3 4 " ) );
    long ln(0);

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( GROUPR::Card5( issTemps, nsigz ) );
    }
  }
} // SCENARIO

