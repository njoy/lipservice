#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

SCENARIO( "THERMR input", 
  "[THERMR]" ){
  GIVEN( "valid THERMR cards" ){
    WHEN( "all entries are provided" ){
      iRecordStream<char> iss( std::istringstream( 
        "0 -22 -24\n"
        "0 1306 8 2 1 0 0 1 221 2\n"
        "350.0 450.0\n"
        "0.05 1.2/\n"
        ) );
      THERMR thermr( iss );
      THEN( "all cards should have the correct values" ){
        CHECK( thermr.card1.nendf.value == 0 );
        CHECK( thermr.card1.nin.value   == -22 );
        CHECK( thermr.card1.nout.value  == -24 );

        CHECK( thermr.card2.matde.value  == 0 );
        CHECK( thermr.card2.matdp.value  == 1306 );
        CHECK( thermr.card2.nbin.value   == 8 );
        CHECK( thermr.card2.ntemp.value  == 2 );
        CHECK( thermr.card2.iin.value    == 1 );
        CHECK( thermr.card2.icoh.value   == 0 );
        CHECK( thermr.card2.iform.value  == 0 );
        CHECK( thermr.card2.natom.value  == 1 );
        CHECK( thermr.card2.mtref.value  == 221 );
        CHECK( thermr.card2.iprint.value == 2 );
	
        CHECK( thermr.card3.tempr.value[0] == 350.0 );
        CHECK( thermr.card3.tempr.value[1] == 450.0 );

        CHECK( thermr.card4.tol.value  == 0.05 );
        CHECK( thermr.card4.emax.value == 1.2 );

        AND_THEN( "RECONR can be turned to JSON" ){
          nlohmann::json refJSON = R"(
          {
            "nendf": 0,
            "nin":   -22,
            "nout":   -24,
            "matde":  0,
            "matdp":  1306,
            "nbin":   8,
            "ntemp":  2,
            "iin":    1,
            "icoh":   0,
            "iform":  0,
            "natom":  1,
            "mtref":  221,
            "iprint": 2,
            "tempr": [ 350.0, 450.0 ],
            "tol":  0.05,
            "emax": 1.2
          }
          )"_json;

          CHECK( refJSON == nlohmann::json( thermr ) );

        } // AND_THEN
      } // THEN
    } // WHEN
    WHEN( "optional parameter not provided" ){
      iRecordStream<char> iss( std::istringstream( 
        "0 -22 -24\n"
        "0 1306 8 2 1 0 0 1 221 /\n"
        "350.0 450.0\n"
        "0.05 1.2/\n"
        ) );
      THERMR thermr( iss );
      THEN( "optional parameter should have the correct value" ){
        CHECK( thermr.card1.nendf.value == 0 );
        CHECK( thermr.card1.nin.value   == -22 );
        CHECK( thermr.card1.nout.value  == -24 );

        CHECK( thermr.card2.matde.value  == 0 );
        CHECK( thermr.card2.matdp.value  == 1306 );
        CHECK( thermr.card2.nbin.value   == 8 );
        CHECK( thermr.card2.ntemp.value  == 2 );
        CHECK( thermr.card2.iin.value    == 1 );
        CHECK( thermr.card2.icoh.value   == 0 );
        CHECK( thermr.card2.iform.value  == 0 );
        CHECK( thermr.card2.natom.value  == 1 );
        CHECK( thermr.card2.mtref.value  == 221 );
        CHECK( thermr.card2.iprint.value == 0 );
	
        CHECK( thermr.card3.tempr.value[0] == 350.0 );
        CHECK( thermr.card3.tempr.value[1] == 450.0 );

        CHECK( thermr.card4.tol.value  == 0.05 );
        CHECK( thermr.card4.emax.value == 1.2 );

        AND_THEN( "RECONR can be turned to JSON" ){
          nlohmann::json refJSON = R"(
          {
            "nendf": 0,
            "nin":   -22,
            "nout":   -24,
            "matde":  0,
            "matdp":  1306,
            "nbin":   8,
            "ntemp":  2,
            "iin":    1,
            "icoh":   0,
            "iform":  0,
            "natom":  1,
            "mtref":  221,
            "iprint": 0,
            "tempr": [ 350.0, 450.0 ],
            "tol":  0.05,
            "emax": 1.2
          }
          )"_json;

          CHECK( refJSON == nlohmann::json( thermr ) );

        } // AND_THEN
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "invalid THERMR input" ){
    WHEN( "inconsistency between ntemp and tempr" ){
      iRecordStream<char> iss( std::istringstream( 
        "0 -22 -24\n"
        "0 1306 8 2 1 0 0 1 221 2\n"
        "350.0\n"
        "0.05 1.2/\n"
        ) );
      THEN( "an exception is thrown" ){
        CHECK_THROWS( THERMR( iss ) );
      } // THEN
    } // WHEN
    WHEN( "inconsistency between nendf and matde" ){
      iRecordStream<char> iss1( std::istringstream( 
        "0 -22 -24\n"
        "1 1306 8 1 1 0 0 1 221 2\n"
        "350.0\n"
        "0.05 1.2/\n"
        ) );
      iRecordStream<char> iss2( std::istringstream( 
        "0 -22 -24\n"
        "1 1306 8 1 1 0 0 1 221 2\n"
        "350.0\n"
        "0.05 1.2/\n"
        ) );

      THEN( "an exception is thrown" ){
        CHECK_THROWS( THERMR( iss1) );
        CHECK_THROWS( THERMR( iss2 ) );
      } // THEN
    } // WHEN
    WHEN( "inconsistency between nendf and iin" ){
      iRecordStream<char> iss( std::istringstream(
        "0 -22 -24\n"
	"0 1306 8 1 2 0 0 1 221 2\n"
	"350.0\n"
	"0.05 1.2/\n"
      ) );
      THEN( "an exception is thrown" ){
        CHECK_THROWS( THERMR( iss ) );
      } // THEN
    } // WHEN
    WHEN( "card1 input files repeated" ){
      iRecordStream<char> iss( std::istringstream( 
        "20 20 21\n"
        "0 1306 8 1 1 0 0 1 221 2\n"
        "350.0\n"
        "0.05 1.2/\n"
        ) );
      THEN( "an exception is thrown" ){
        CHECK_THROWS( THERMR( iss ) );
      } // THEN
    } // WHEN 
    WHEN( "invalid (out of range) card4 entry" ){
      iRecordStream<char> iss( std::istringstream( 
        "20 20 21\n"
        "0 1306 8 1 1 0 0 1 221 2\n"
        "350.0\n"
        "1.e-6 1.2/\n"
        ) );
      THEN( "an exception is thrown" ){
        CHECK_THROWS( THERMR( iss ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
