#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "Tempd input values", "[ACER], [Card10], [Tempd]" ){
  GIVEN( "valid tempd values" ){
    std::vector<double> validTempd{ 0.0, 293.6 };

    THEN( "the returned class has the correct value" ){
      for( auto tempd : validTempd ){
	iRecordStream<char> issTempd( std::istringstream( std::to_string(tempd) ) );
        auto tempdArg = argument::extract< argument::common::Tempd >(issTempd );
        REQUIRE( tempd == tempdArg.value );
      }
    }
  }
  GIVEN( "no tempd value" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss( std::istringstream( "/") );
      REQUIRE( 300 == 
               argument::extract< argument::common::Tempd >( iss ).value );
    }
  }
  GIVEN( "invalid tempd values" ){
    double tempd(-0.01);
    THEN( "an exception is thrown" ){
      iRecordStream<char> issTempd( std::istringstream( std::to_string(tempd) ) );
      REQUIRE_THROWS( argument::extract< argument::common::Tempd >(issTempd) );
    }
  }
}

