#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "ndir output values",
         "[ACER],[Card2], [Suff]"){

  long ln{0};
  GIVEN( "valid suff values" ){
    std::vector< double > validValues{.01, .80, 0.99, 0.00, -.00, -0.01, -0.99};

    THEN( "the returned class has the correct value" ){
      for( auto& suff : validValues ){
        iRecordStream<char> iss( std::istringstream( std::to_string( suff ) ) );

        njoy::Log::info( "suff: {}", suff );
        CHECK( suff == argument::extract< ACER::Card2::Suff >( iss ).value );
      }
    }
  }
  GIVEN( "no suff values" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );
      CHECK( 0.00 == argument::extract< ACER::Card2::Suff >( iss ).value );
    }
  }
  
  GIVEN( "invalid suff values" ){
    std::vector< double > invalidValues{ 0.009, 1.0 };

    THEN( "an exception is thrown" ){
      for( auto& suff : invalidValues ){
        njoy::Log::info( "suff: {}", suff );
        iRecordStream<char> iss( std::istringstream( std::to_string( suff ) ) );
        CHECK_THROWS( argument::extract< ACER::Card2::Suff >( iss ) );
      }
    }
  }

}

