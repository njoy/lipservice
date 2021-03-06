#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "Sigz input values",
         "[Card4], [Sigz]" ){
  GIVEN( "a value for nsigz (number of temperatures)" ){
    Argument< PURR::Card2::Nsigz > nsigz;
    nsigz.value = 3;

    WHEN( "there are the correct number of temperatures and they are valid" ){
      iRecordStream< char> issPoints( std::istringstream(" 1.0 2.0 3.0") );

      THEN( "the grid points can be extracted correctly" ){
        auto sigz = argument::extract< 
                    PURR::Card4::Sigz >(issPoints, nsigz);
        std::vector< double > refSigzs{ 1.0, 2.0, 3.0 };
        REQUIRE( refSigzs == sigz.value );
      }
    }

    WHEN( "the grid points are invalid" ){
      iRecordStream< char> issPoints( std::istringstream(" 1.0 -2.0 3.0") );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS(
            argument::extract< PURR::Card4::Sigz >(issPoints, nsigz) );
      }
    }

    WHEN( "commas are used to separate values" ){
      iRecordStream< char> issPoints( std::istringstream(" 1.0, 2.0, 3.0") );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS(
            argument::extract< PURR::Card4::Sigz >(issPoints, nsigz) );
      }
    }

    WHEN( "there are too many grid points" ){
      iRecordStream< char> issPoints( std::istringstream(" 1.0 2.0 3.0 4.0 /") );

      THEN( "an exception is thrown" ){
        REQUIRE_NOTHROW(
            argument::extract< PURR::Card4::Sigz >(issPoints, nsigz) );
      }
    }

    WHEN( "there are not enough many grid points" ){
      iRecordStream< char> issPoints( std::istringstream(" 1.0 2.0") );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS(
            argument::extract< PURR::Card4::Sigz >(issPoints, nsigz) );
      }
    }
  }
} // SCENARIO

