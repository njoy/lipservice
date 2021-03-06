#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "CCCCR, Card5, Habsid",
          "[CCCCR] [Card5] [Habsid]" ){
  GIVEN( "valid inputs" ){
    WHEN( "a valid input is provided" ){
      iRecordStream<char> iss( std::istringstream( " '123456'/ " ) );

      THEN( "the value can be verified" ){
        REQUIRE( "123456" == argument::extract< CCCCR::Card5::Habsid >(
                                                                  iss ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< CCCCR::Card5::Habsid >( iss ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " '1234567'/ " ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< CCCCR::Card5::Habsid >( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
