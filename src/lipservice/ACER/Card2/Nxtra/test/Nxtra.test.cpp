#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "Nxtra input values",
          "[Card2], [Nxtra]" ){
  long ln(0);

  GIVEN( "valid nxtra values" ){
    std::vector<int> validValues{0, 1, 10, 16};

    THEN( "the returned class has the correct value" ){
      for( auto& nxtra : validValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(nxtra) ) );

        REQUIRE( 
          nxtra == argument::extract< ACER::Card2::Nxtra >( iss ).value );
      }
    }
  }

  GIVEN( "no nxtra values" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss(
          std::istringstream( " /" ) );
      REQUIRE( 0 == argument::extract< ACER::Card2::Nxtra >( iss ).value );
    }
  }
  
  GIVEN( "invalid nxtra values" ){
    std::vector<int> invalidValues{-1, 17, 20};

    THEN( "an exception is thrown" ){
      for( auto& nxtra : invalidValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(nxtra) ) );

        REQUIRE_THROWS( argument::extract< ACER::Card2::Nxtra >( iss ) );
      }
    }
  }
} // SCENARIO

