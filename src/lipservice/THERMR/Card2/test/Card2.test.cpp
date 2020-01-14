#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "THERMR Card2 inputs",
  "[THERMR], [Card2] "){
  GIVEN( "a nonzero Card1 nendf input" ){
    Argument< THERMR::Card1::Nendf > nendf; nendf.value = 20;
    WHEN( "input is valid, all values provided" ){
      iRecordStream<char> is( std::istringstream("1 125 8 2 2 0 0 2 222 1") );
      THEN( "the extracted values are correct" ){
        THERMR::Card2 card2( is, nendf );
        CHECK( card2.matde.value == 1 );
        CHECK( card2.matdp.value == 125 );
        CHECK( card2.nbin.value == 8 );
        CHECK( card2.ntemp.value == 2 );
        CHECK( card2.iin.value == 2 );
        CHECK( card2.icoh.value == 0 );
        CHECK( card2.iform.value == 0 );
        CHECK( card2.natom.value == 2 );
        CHECK( card2.mtref.value == 222 );
        CHECK( card2.iprint.value == 1 );

        AND_THEN( "Card2 can be turned to JSON" ){
          nlohmann::json refJSON = R"(
          {
            "matde":  1,
            "matdp":  125,
            "nbin":   8,
            "ntemp":  2,
            "iin":    2,
            "icoh":   0,
            "iform":  0,
            "natom":  2,
            "mtref":  222,
            "iprint": 1
          }
          )"_json;
          CHECK( refJSON == nlohmann::json( card2 ) );
        } // AND_THEN
      } // THEN 
    } // WHEN

    WHEN( "input is valid, optional inputs not included" ){
      iRecordStream<char> is( std::istringstream("1 125 8 2 2 0 0 2 222 /") );
      THEN( "default values used" ){
        THERMR::Card2 card2( is, nendf );
        CHECK( card2.matde.value == 1 );
        CHECK( card2.matdp.value == 125 );
        CHECK( card2.nbin.value == 8 );
        CHECK( card2.ntemp.value == 2 );
        CHECK( card2.iin.value == 2 );
        CHECK( card2.icoh.value == 0 );
        CHECK( card2.iform.value == 0 );
        CHECK( card2.natom.value == 2 );
        CHECK( card2.mtref.value == 222 );
        CHECK( card2.iprint.value == 0 );

        AND_THEN( "Card2 can be turned to JSON" ){
          nlohmann::json refJSON = R"(
          {
            "matde":  1,
            "matdp":  125,
            "nbin":   8,
            "ntemp":  2,
            "iin":    2,
            "icoh":   0,
            "iform":  0,
            "natom":  2,
            "mtref":  222,
            "iprint": 0
          }
          )"_json;
          CHECK( refJSON == nlohmann::json( card2 ) );
        } // AND_THEN
      } // THEN
    } // WHEN
    
    WHEN( "matde conflicts with card1 nendf value" ){
      iRecordStream<char> is( std::istringstream("0 125 8 2 2 0 0 2 222 1") );
      THEN( "an exception is thrown" ){
        CHECK_THROWS( THERMR::Card2( is, nendf ) );
      } // THEN
    } // WHEN
 
    WHEN( "a card2 input value is out of range" ){
      iRecordStream<char> is1( std::istringstream("-5 125 8 2 2 0 0 2 222 1") );
      iRecordStream<char> is2( std::istringstream(" 1 1e5 8 2 2 0 0 2 222 1") );
      iRecordStream<char> is3( std::istringstream(" 1 125 0 2 2 0 0 2 222 1") );
      iRecordStream<char> is4( std::istringstream(" 1 125 8 0 2 0 0 2 222 1") );
      iRecordStream<char> is5( std::istringstream(" 1 125 8 2 3 0 0 2 222 1") );
      iRecordStream<char> is6( std::istringstream(" 1 125 8 2 2 4 0 2 222 1") );
      iRecordStream<char> is7( std::istringstream(" 1 125 8 2 2 0 3 2 222 1") );
      iRecordStream<char> is8( std::istringstream(" 1 125 8 2 2 0 0 0 222 1") );
      iRecordStream<char> is9( std::istringstream(" 1 125 8 2 2 0 0 2 220 1") );
      iRecordStream<char> is0( std::istringstream(" 1 125 8 2 2 0 0 2 222 3") );
      THEN( "an exception is thrown" ){
        CHECK_THROWS( THERMR::Card2( is1, nendf ) );
        CHECK_THROWS( THERMR::Card2( is2, nendf ) );
        CHECK_THROWS( THERMR::Card2( is3, nendf ) );
        CHECK_THROWS( THERMR::Card2( is4, nendf ) );
        CHECK_THROWS( THERMR::Card2( is5, nendf ) );
        CHECK_THROWS( THERMR::Card2( is6, nendf ) );
        CHECK_THROWS( THERMR::Card2( is7, nendf ) );
        CHECK_THROWS( THERMR::Card2( is8, nendf ) );
        CHECK_THROWS( THERMR::Card2( is9, nendf ) );
        CHECK_THROWS( THERMR::Card2( is0, nendf ) );
      } // THEN
    } // WHEN
  } // GIVEN
  
  GIVEN( "a Card1 nendf input value of zero" ){
    Argument< THERMR::Card1::Nendf > nendf; nendf.value = 0;
    WHEN( "input is valid, all values provided" ){
      iRecordStream<char> is( std::istringstream("0 125 8 2 1 0 0 2 222 1") );
      THEN( "the extracted values are correct" ){
        THERMR::Card2 card2( is, nendf );
        CHECK( card2.matde.value == 0 );
        CHECK( card2.matdp.value == 125 );
        CHECK( card2.nbin.value == 8 );
        CHECK( card2.ntemp.value == 2 );
        CHECK( card2.iin.value == 1 );
        CHECK( card2.icoh.value == 0 );
        CHECK( card2.iform.value == 0 );
        CHECK( card2.natom.value == 2 );
        CHECK( card2.mtref.value == 222 );
        CHECK( card2.iprint.value == 1 );

        AND_THEN( "Card2 can be turned to JSON" ){
          nlohmann::json refJSON = R"(
          {
            "matde":  0,
            "matdp":  125,
            "nbin":   8,
            "ntemp":  2,
            "iin":    1,
            "icoh":   0,
            "iform":  0,
            "natom":  2,
            "mtref":  222,
            "iprint": 1
          }
          )"_json;
          CHECK( refJSON == nlohmann::json( card2 ) );
        } // AND_THEN
      } // THEN 
    } // WHEN
    WHEN( "matde conflicts with card1 nendf value" ){
      iRecordStream<char> is( std::istringstream("1 125 8 2 1 0 0 2 222 1") );
      THEN( "an exception is thrown" ){
        CHECK_THROWS( THERMR::Card2( is, nendf ) );
      } // THEN
    } // WHEN
    WHEN( "iin conflicts with card1 nendf value" ){
      iRecordStream<char> is( std::istringstream("0 125 8 2 2 0 0 2 222 1") );
      THEN( "an exception is thrown" ){
        CHECK_THROWS( THERMR::Card2( is, nendf ) );
      } // THEN
   } // WHEN
  } // GIVEN
} // SCENARIO
