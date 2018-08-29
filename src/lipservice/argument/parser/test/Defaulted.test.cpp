#include "catch.hpp"
#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice::argument::parser;

struct defaultZero{ static int defaultValue(){ return 0; } };
using Defaultor = Defaulted< Base<int>, defaultZero >;

template< typename Char >
using iRecordStream = njoy::njoy21::lipservice::iRecordStream<Char>;

SCENARIO( "Defaulted" ){
  SECTION( "Argument is present" ){
    int sink = 0;
    iRecordStream<char> iss( std::istringstream("   101") );
    REQUIRE( Defaultor::read( iss, sink ) );
    REQUIRE( sink == 101 );
  }

  SECTION( "Argument is missing" ){
    int sink = 101;
    iRecordStream<char> iss( std::istringstream("   /") );
    REQUIRE( not Defaultor::read( iss, sink ) );
    REQUIRE( sink == 0 );
  }
}
