#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "bugless" ){
  std::string value(
      "123456789 123456789 123456789 123456789 123456789 123456789 123456");
  iRecordStream<char> iss{ std::istringstream( "'" + value + "'" ) };
  GROUPR::Card3 card3( iss );
  REQUIRE( card3.title.value == value );
}

SCENARIO( "bugged" ){
  GIVEN( "a string that's too long" ){
    std::string value(
      "123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789 12");
    iRecordStream<char> iss{ std::istringstream( "'" + value + "'" ) };
    REQUIRE_THROWS( GROUPR::Card3( iss ) );
  }
}
