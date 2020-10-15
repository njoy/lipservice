#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "Iza input values", "[ACER], [Card8a], [Iza]" ){
  std::vector< int > vIZA{
    1001,    1002,     1003,   2003,  
    8016,    8017,     8018,   2004,  
    40090,   40091,    40092,  40094,  
    100000,  199999,  99254,  99255
  };
  std::string sIZA{};
  std::for_each( std::begin( vIZA ), std::end( vIZA ),
    [&]( const auto& iz ){ sIZA += std::to_string( iz ) + " "; } );
  GIVEN( "valid iza values" ){

    THEN( "the returned class has the correct value" ){
      sIZA += " /";
      njoy::Log::info( "sIZA: {}", sIZA );
      iRecordStream< char > issIza{ std::istringstream( sIZA ) };
      auto izaArg = argument::extract< ACER::Card8a::Iza >( issIza, 16 ).value;

      for( size_t i = 0; i < vIZA.size(); i++ ){
        CHECK( vIZA[ i ] == izaArg.at( i ) );
      }

    } // THEN
  } // GIVEN
  GIVEN( "invalid iza values" ){
    WHEN( "values are < 1" ){
      iRecordStream< char > issIza{ std::istringstream( "0" ) };
      THEN( "an exception is thrown" ){
        CHECK_THROWS( argument::extract< ACER::Card8a::Iza >( issIza, 1 ) );
      } // THEN
    } // WHEN

    WHEN( "values are > 199999" ){
      iRecordStream< char > issIza{ std::istringstream( "200000" ) };
      THEN( "an exception is thrown" ){
        CHECK_THROWS( argument::extract< ACER::Card8a::Iza >( issIza, 1 ) );
      } // THEN
    } // WHEN

    WHEN( "no values are given" ){
      iRecordStream< char > issIza{ std::istringstream( "" ) };
      THEN( "an exception is thrown" ){
        CHECK_THROWS( argument::extract< ACER::Card8a::Iza >( issIza, 1 ) );
      } // THEN
    } // WHEN
    
  } // GIVEN
} // SCENARIO
