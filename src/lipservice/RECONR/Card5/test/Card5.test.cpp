#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "bugless" ){
  std::string value("123456789 123456789 123456789 123456789 123456789 123456789 123456");
  iRecordStream<char> iss( std::istringstream( "'" + value + "'" ) );
  RECONR::Card5 card5( iss );
  CHECK( value == card5.cards.value );

  THEN( "Card5 can be turned to JSON" ){
    nlohmann::json refJSON = value;
    nlohmann::json JSON = card5;
    CHECK( refJSON == card5 );
  } // THEN
}

SCENARIO( "bugged" ){
  std::string value("'123456789 123456789 123456789 123456789 123456789 123456789 1234567'");
  iRecordStream<char> iss( (std::istringstream(value)) );
  CHECK_THROWS( RECONR::Card5( iss ) );
}

