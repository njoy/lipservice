#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "ACER Card8a Nza", "[Card8], [Nza]" ){
  GIVEN( "valid nza values" ){
    std::array< int, 16 > validNZAs;
    std::iota( validNZAs.begin(), validNZAs.end(), 1 );
    for( const auto& NZA : validNZAs ){
      THEN( "the nza " + std::to_string( NZA ) + 
            "value is correctly read and returned" ){
        iRecordStream<char> iss( std::istringstream( std::to_string( NZA ) ) );

        CHECK( NZA == argument::extract< ACER::Card8::Nza >( iss ).value );
      } // THEN
    }
  } // GIVEN
  GIVEN( "no nza value" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss( std::istringstream( "/") );
      REQUIRE( 3 == argument::extract< ACER::Card8::Nza >( iss ).value );
    } // THEN
  } // GIVEN
  GIVEN( "invalid nza values" ){
    std::vector< int > invalidNZAs{ -1, 0, 17, 18 };
    for( const auto& NZA : invalidNZAs ){
      THEN( "an exception is thrown when NZA=" + std::to_string( NZA ) ){
        iRecordStream<char> iss( std::istringstream( std::to_string( NZA ) ) );
        CHECK_THROWS( argument::extract< ACER::Card8::Nza >( iss ) );
        
      } // THEN
    }
  } // GIVEN
  
} // SCENARIO
