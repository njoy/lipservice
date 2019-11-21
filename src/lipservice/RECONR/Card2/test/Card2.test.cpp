#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "bugless" ){
  std::string value( 
      "012345678901234567890123456789012345678901234567890123456789012345" );
  iRecordStream<char> iss{ std::istringstream( "'" + value + "'" ) };
  RECONR::Card2 card2( iss );
  CHECK( card2.tlabel.value == value );

  nlohmann::json refJSON = value;
  CHECK( refJSON == nlohmann::json( card2 ) );
}

SCENARIO( "bugged" ){
  std::string value( 
    "'0123456789012345678901234567890123456789012345678901234567890123456'");
  iRecordStream<char> iss{ std::istringstream( value ) };
  CHECK_THROWS( RECONR::Card2( iss ) );
}
