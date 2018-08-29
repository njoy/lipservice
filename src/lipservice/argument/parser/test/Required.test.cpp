#include "catch.hpp"
#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice::argument::parser;

template< typename Char >
using iRecordStream = njoy::njoy21::lipservice::iRecordStream<Char>;

SCENARIO( "Required" ){
  SECTION( "Argument is present" ){
    int sink = 0;
    iRecordStream<char> iss( std::istringstream("   101") );
    REQUIRE( Required< Base<int> >::read( iss, sink ) );
    REQUIRE( sink == 101 );
  }

  SECTION( "Argument is not present" ){
    int sink = 0;
    iRecordStream<char> iss( std::istringstream("") );
    REQUIRE_THROWS( Required< Base<int> >::read( iss, sink ) );
  }

  SECTION( "Argument is wrong type" ){
    int sink = 0;
    iRecordStream<char> iss( std::istringstream(" alphabet ") );
    REQUIRE_THROWS( Required< Base<int> >::read( iss, sink ) );
  }
}
