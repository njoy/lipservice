#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "Xstep output values", "[PLOTR],[Card5], [Xstep]"){

  GIVEN( "valid entries" ){
    WHEN( "valid Xstep parameters" ){
      std::vector<double> validValues{0.1,0.5,0.8,1.0,2.0,80.0};
  
      THEN( "the returned class has the correct value" ){
        for( auto xstep : validValues ){
          iRecordStream<char> issXstep( 
              std::istringstream( std::to_string( xstep ) ) );
  
          REQUIRE( xstep == *( argument::extract< PLOTR::Card5::Xstep >( 
                               issXstep ).value ) );
        }
      }
    }
  
    WHEN( "default value" ){
      iRecordStream<char> issXstep( std::istringstream( " /" ) );
  
      THEN( "default value is returned" ){
        REQUIRE( std::nullopt == argument::extract< PLOTR::Card5::Xstep >(
                            issXstep ).value );
      }
    }
  } // GIVEN

  GIVEN( "invalid Xstep parameters" ){

//    WHEN( "xstep uses the default value but el and/or eh don't" ){
//      iRecordStream<char> issXstep( std::istringstream( " / " ) );
//      THEN( "an exception is thrown" ){
//        REQUIRE_THROWS( argument::extract< PLOTR::Card5::Xstep >(
//                                            issXstep, el ) );
//      }
//    }

    std::vector<double> invalidValues{ -2.0, -1.1, 0.0 };

    for( auto xstep : invalidValues ){
      std::string situ( "invalid xstep value " + std::to_string( xstep ) +
                                                              " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> issXstep( 
            std::istringstream( std::to_string( xstep ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< PLOTR::Card5::Xstep >(
                                              issXstep ) );
        }
      }
    }
  } // GIVEN
} // SCENARIO
