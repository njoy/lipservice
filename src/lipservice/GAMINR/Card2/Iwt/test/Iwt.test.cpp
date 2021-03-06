#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "expected successes" ){
  for( auto iwt : {1, 2, 3} ){
    {
      iRecordStream<char> iss( std::istringstream( std::to_string(iwt) ) );
      REQUIRE( argument::extract
                    < GAMINR::Card2::Iwt >( iss ).value  == iwt );
    }
  }
}

SCENARIO( "expected failures" ){
  for( auto iwt : {-1, 0, 4} ){
    iRecordStream<char> iss( std::istringstream( std::to_string(iwt) ) );
    REQUIRE_THROWS( argument::extract
                         <GAMINR::Card2::Iwt >( iss ) );
  }
  {
    iRecordStream<char> iss( std::istringstream(" cat") );
    REQUIRE_THROWS( argument::extract
                         <GAMINR::Card2::Iwt >( iss ) );
  }{
    iRecordStream<char> iss( std::istringstream("    ") );
    REQUIRE_THROWS( argument::extract
                         <GAMINR::Card2::Iwt >( iss ) );
  }
}
