#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "Verifying ACER Card8a input", "[ACER], [Card8a]" ){
  GIVEN( "valid entries" ){
    // iRecordStream<char> issCard8a( std::istringstream( " 1001 6012 6000 / ) );

    std::vector< int > vIZA{
      1001,    1002,     1003,   2003,  
          8016,    8017,     8018,   2004,  
          40090,   40091,    40092,  40094,  
          100000,  199999,  99254,  99255
    };
    for (int i = 0; i < 16; ++i) {
      std::string sIZA{};
      std::for_each( std::begin( vIZA ), std::end( vIZA ) - i,
          [&]( const auto& iz ){ sIZA += std::to_string( iz ) + " "; } );

      sIZA += " /";

      std::vector< int > refIZA{ std::begin( vIZA ), std::end( vIZA ) - i }; 

      int nza = 16 - i;
      THEN( "the iza values can be extracted and verified with nza = " +
           std::to_string( nza ) ){
        iRecordStream<char> issCard8a{ std::istringstream{ sIZA } };
        ACER::Card8a  card8a( issCard8a, nza );

        CHECK( refIZA == card8a.iza.value );

      } // THEN
    }
  }
  GIVEN( "invalid Card8a input" ){
    WHEN( "invalid IZA numers are given" ){
      iRecordStream<char> issCard8a( std::istringstream( " -1001 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ACER::Card8a( issCard8a, 1 ) );
      }
    } // WHEN
    WHEN( "wrong number of IZA numers are given" ){
      iRecordStream<char> issCard8a( std::istringstream( " 1001 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( ACER::Card8a( issCard8a, 2 ) );
      }
    } // WHEN
  } // GIVEN
}
