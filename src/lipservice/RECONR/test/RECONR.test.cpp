#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

std::string card1(" 21 22\n");
std::string card2("'This is a sample Card2'\n");
std::string card3(" 1306 3 0\n");
std::string card4(" 0.005 0 0.1 5e-07\n");
std::string card4a(" 0.067 3 2.1 8e-07\n");
std::string card5( "'This a sample description TEXT Record for Card5'\n" );
auto card5String = std::string( ++(card5.begin()), (card5.end() - 2) ); 
std::string card6(" 1.0 2 3.0\n");

SCENARIO( "Parsing valid RECONR input" ){
  /*
  WHEN( "Cards 3,4,3" ){
    iRecordStream<char> iss
      ( std::istringstream( card1 + card2 + " 1306 0 0\n" + card4 + "0/\n" ) );
  
    RECONR reconr(iss);
    THEN( "The read values can be verified" ){
      CHECK( 21 == reconr.card1.nendf.value );
  
      CHECK( 1 == reconr.cardSequence.size() );
  
      auto& card3 = std::get<0>( reconr.cardSequence.front() );
      CHECK( 1306 == card3.mat.value );
      CHECK( 0 == card3.ncards.value );
      CHECK( 0 == card3.ngrid.value );
  
      auto& card4 = std::get<1>( reconr.cardSequence.front() );
      CHECK( 0.005 == card4.err.value );
      CHECK( 0.0 == card4.tempr.value );
      CHECK( 0.1 == card4.errmax.value );
      CHECK( 5E-7 == card4.errint.value );
  
      auto& card5 = std::get<2>( reconr.cardSequence.front() );
      CHECK( card5.empty() );
  
      auto& card6 = std::get<3>( reconr.cardSequence.front() );
      CHECK( not card6 );
  
      CHECK( 5 == iss.lineNumber );
  
      AND_THEN( "RECONR can be turned to JSON" ){
        nlohmann::json refJSON = {
          { "card1", { 21, 22 } },
          { "card2", "This is a sample Card2" },
          { "sequence", {
              {
                { "card3", { 1306, 0, 0 } },
                { "card4", { 0.005, 0, 0.1, 5E-7 } },
                { "card5", nlohmann::json::array() },
                { "card6", nullptr }
              }
            }
          }
        };
  
        CHECK( refJSON == nlohmann::json( reconr ) );
  
      } // AND_THEN
    }
  
  }
  WHEN( "Cards 3,4,5,3" ){
    iRecordStream<char> iss
      ( std::istringstream( card1 + card2 + " 1306 1 0\n"
  			    + card4 + card5 + "0/\n" ) );
  
    THEN( "The read values can be verified" ){
      RECONR reconr(iss);
  
      auto& card5 = std::get<2>( reconr.cardSequence.front() );
      CHECK( 1 == card5.size() );
      CHECK( card5String == card5.front().cards.value );
  
      auto& card6 = std::get<3>( reconr.cardSequence.front() );
      CHECK( not card6 );
  
      AND_THEN( "RECONR can be turned to JSON" ){
        nlohmann::json refJSON = {
          { "card1", { 21, 22 } },
          { "card2", "This is a sample Card2" },
          { "sequence", {
              {
                { "card3", { 1306, 1, 0 } },
                { "card4", { 0.005, 0, 0.1, 5E-7 } },
                { "card5", card5 },
                { "card6", nullptr }
              }
            }
          }
        };
  
        CHECK( refJSON == nlohmann::json( reconr ) );
  
      } // AND_THEN
    }
  }
  
  WHEN( "Cards 3,4,5,6,3" ){
    iRecordStream<char> iss
      ( std::istringstream( card1 + card2 + " 1306 1 3\n"
  			    + card4 + card5 + card6 + "0/\n" ) );
  
    THEN( "The read values can be verified" ){
      RECONR reconr(iss);
  
      auto& card5 = std::get<2>( reconr.cardSequence.front() );
      CHECK( 1 == card5.size() );
  
      auto& card6 = std::get<3>( reconr.cardSequence.front() );
      CHECK( card6 );
      CHECK( 3 == card6->enode.value.size() );
      CHECK( 1.0 == card6->enode.value[0] );
      CHECK( 2.0 == card6->enode.value[1] );
      CHECK( 3.0 == card6->enode.value[2] );
  
      AND_THEN( "RECONR can be turned to JSON" ){
        nlohmann::json refJSON = {
          { "card1", { 21, 22 } },
          { "card2", "This is a sample Card2" },
          { "sequence", {
              {
                { "card3", { 1306, 1, 3 } },
                { "card4", { 0.005, 0, 0.1, 5E-7 } },
                { "card5", { card5String } },
                { "card6", { 1.0, 2, 3.0 } }
              }
            }
          }
        };
  
        CHECK( refJSON == nlohmann::json( reconr ) );
  
      } // AND_THEN
    }
  }
  WHEN( "Cards 3,4,6,3" ){
    iRecordStream<char> iss
      ( std::istringstream( card1 + card2 + " 1306 0 3\n"
  			    + card4 + card6 + "0/\n" ) );
  
    THEN( "The read values can be verified" ){
      RECONR reconr(iss);
  
      auto& card5 = std::get<2>( reconr.cardSequence.front() );
      CHECK( card5.empty() );
  
      auto& card6 = std::get<3>( reconr.cardSequence.front() );
      CHECK( card6 );
      CHECK( 3 == card6->enode.value.size() );
      CHECK( 1.0 == card6->enode.value[0] );
      CHECK( 2.0 == card6->enode.value[1] );
      CHECK( 3.0 == card6->enode.value[2] );
  
      AND_THEN( "RECONR can be turned to JSON" ){
        nlohmann::json refJSON = {
          { "card1", { 21, 22 } },
          { "card2", "This is a sample Card2" },
          { "sequence", {
              {
                { "card3", { 1306, 0, 3 } },
                { "card4", { 0.005, 0, 0.1, 5E-7 } },
                { "card5", nlohmann::json::array() },
                { "card6", { 1.0, 2, 3.0 } }
              }
            }
          }
        };
  
        CHECK( refJSON == nlohmann::json( reconr ) );
  
      } // AND_THEN
    }
  }
  WHEN( "Cards 3,4,5,5,5,3" ){
    iRecordStream<char> iss
      ( std::istringstream( card1 + card2 + " 1306 3 0\n"
  			    + card4 + card5 + card5 + card5 + "0/\n" ) );
  
    THEN( "The read values can be verified" ){
      RECONR reconr(iss);
  
      auto& card5 = std::get<2>( reconr.cardSequence.front() );
      CHECK( 3 == card5.size() );
      CHECK( card5String == card5[ 0 ].cards.value );
      CHECK( card5String == card5[ 1 ].cards.value );
      CHECK( card5String == card5[ 2 ].cards.value );
  
      auto& card6 = std::get<3>( reconr.cardSequence.front() );
      CHECK( not card6 );
  
      AND_THEN( "RECONR can be turned to JSON" ){
        nlohmann::json refJSON = {
          { "card1", { 21, 22 } },
          { "card2", "This is a sample Card2" },
          { "sequence", {
              {
                { "card3", { 1306, 3, 0 } },
                { "card4", { 0.005, 0, 0.1, 5E-7 } },
                { "card5", { card5String, card5String, card5String } },
                { "card6", nullptr }
              }
            }
          }
        };
  
        CHECK( refJSON == nlohmann::json( reconr ) );
  
      } // AND_THEN
    }
  }
   */
  WHEN( "Cards 3,4,5,6,3,4,3" ){
    std::string input{ card1 + card2 + " 1306 1 3\n" + card4 + card5
  			    + card6 + " 1316 0 0\n" + card4a + "0/\n"};
    njoy::Log::info( "input: {}", input );
    iRecordStream<char> iss{ std::istringstream( input ) };

    THEN( "The read values can be verified" ){
      RECONR reconr(iss);

      CHECK( 2 == reconr.cardSequence.size() );

      auto& card3 = std::get<0>( reconr.cardSequence.front() );
      CHECK( 1306 == card3.mat.value );
      CHECK( 1 == card3.ncards.value );
      CHECK( 3 == card3.ngrid.value );
      card3 = std::get<0>( reconr.cardSequence.back() );
      CHECK( 1316 == card3.mat.value );
      CHECK( 0 == card3.ncards.value );
      CHECK( 0 == card3.ngrid.value );

      auto& card4 = std::get<1>( reconr.cardSequence.front() );
      CHECK( 0.005 == card4.err.value );
      CHECK( 0.0 == card4.tempr.value );
      CHECK( 0.1 == card4.errmax.value );
      CHECK( 5E-7 == card4.errint.value );
      card4 = std::get<1>( reconr.cardSequence.back() );
      CHECK( 0.067 == card4.err.value );
      CHECK( 3.0 == card4.tempr.value );
      CHECK( 2.1 == card4.errmax.value );
      CHECK( 8E-7 == card4.errint.value );

      auto& card5 = std::get<2>( reconr.cardSequence.front() );
      CHECK( card5String == card5.front().cards.value );

      auto& card6 = std::get<3>( reconr.cardSequence.front() );
      CHECK( card6 );
      CHECK( 3 == card6->enode.value.size() );
      CHECK( 1.0 == card6->enode.value[0] );
      CHECK( 2.0 == card6->enode.value[1] );
      CHECK( 3.0 == card6->enode.value[2] );

      njoy::Log::info( "LAST ONE" );
      AND_THEN( "RECONR can be turned to JSON" ){
        nlohmann::json refJSON = {
          { "card1", { 21, 22 } },
          { "card2", "This is a sample Card2" },
          { "sequence", {
              {
                { "card3", { 1306, 1, 3 } },
                { "card4", { 0.005, 0, 0.1, 5E-7 } },
                { "card5", { card5String } },
                { "card6", { 1.0, 2, 3.0 } }
              },
              {
                { "card3", { 1316, 0, 0 } },
                { "card4", { 0.067, 3, 2.1, 8E-7 } },
                { "card5", nlohmann::json::array() },
                { "card6", nullptr }
              }
            }
          }
        };

        CHECK( refJSON == nlohmann::json( reconr ) );
        
      } // AND_THEN
    }
  }
  WHEN( "Cards 3,4,5,6,3,4,3,4,5, 3" ){
    std::string input{ card1 + card2 + 
      " 1306 1 3\n" + card4 + card5 + card6 + 
      " 1316 0 0\n" + card4a + card5 + card5 +
      " 1316 1 0\n" + card4a + "'Another sample for Card5'"
      "0/\n"};
    njoy::Log::info( "input: {}", input );
    iRecordStream<char> iss{ std::istringstream( input ) };

    THEN( "The read values can be verified" ){
      RECONR reconr(iss);

      CHECK( 2 == reconr.cardSequence.size() );

      auto& card3 = std::get<0>( reconr.cardSequence[ 0 ] );
      CHECK( 1306 == card3.mat.value );
      CHECK( 1 == card3.ncards.value );
      CHECK( 3 == card3.ngrid.value );
      card3 = std::get<0>( reconr.cardSequence[ 1 ] );
      CHECK( 1316 == card3.mat.value );
      CHECK( 2 == card3.ncards.value );
      CHECK( 0 == card3.ngrid.value );
      card3 = std::get<0>( reconr.cardSequence[ 2 ] );
      CHECK( 1316 == card3.mat.value );
      CHECK( 0 == card3.ncards.value );
      CHECK( 0 == card3.ngrid.value );

      auto& card4 = std::get<1>( reconr.cardSequence.front() );
      CHECK( 0.005 == card4.err.value );
      CHECK( 0.0 == card4.tempr.value );
      CHECK( 0.1 == card4.errmax.value );
      CHECK( 5E-7 == card4.errint.value );
      card4 = std::get<1>( reconr.cardSequence.back() );
      CHECK( 0.067 == card4.err.value );
      CHECK( 3.0 == card4.tempr.value );
      CHECK( 2.1 == card4.errmax.value );
      CHECK( 8E-7 == card4.errint.value );

      auto& card5 = std::get<2>( reconr.cardSequence.front() );
      CHECK( card5String == card5.front().cards.value );

      auto& card6 = std::get<3>( reconr.cardSequence.front() );
      CHECK( card6 );
      CHECK( 3 == card6->enode.value.size() );
      CHECK( 1.0 == card6->enode.value[0] );
      CHECK( 2.0 == card6->enode.value[1] );
      CHECK( 3.0 == card6->enode.value[2] );

      njoy::Log::info( "LAST ONE" );
      AND_THEN( "RECONR can be turned to JSON" ){
        nlohmann::json refJSON = {
          { "card1", { 21, 22 } },
          { "card2", "This is a sample Card2" },
          { "sequence", {
              {
                { "card3", { 1306, 1, 3 } },
                { "card4", { 0.005, 0, 0.1, 5E-7 } },
                { "card5", { card5String } },
                { "card6", { 1.0, 2, 3.0 } }
              },
              {
                { "card3", { 1306, 2, 0 } },
                { "card4", { 0.005, 0, 0.1, 5E-7 } },
                { "card5", { card5String, card5String, card5String } },
                { "card6", nullptr }
              },
              {
                { "card3", { 1316, 0, 0 } },
                { "card4", { 0.067, 3, 2.1, 8E-7 } },
                { "card5", nlohmann::json::array() },
                { "card6", nullptr }
              }
            }
          }
        };

        CHECK( refJSON == nlohmann::json( reconr ) );
        
      } // AND_THEN
    }
  }
} // SCENARIO

/*
SCENARIO( "Parsing invalid RECONR input" ){
  std::istringstream iss;
  WHEN( "Card 3 mat values not in increasing order" ){
    iRecordStream<char> iss( std::istringstream( 
      card1 + card2 + "1306 1 3\n" + card4 + card5 + card6 + 
      "125 0 0\n" + card4 + "0/\n" ) );
    THEN( "an exception is thrown" ){
      CHECK_THROWS( RECONR(iss) );
    }
  }

  WHEN( "Only terminating Card3" ){
    THEN( "an exception is thrown" ){
      iRecordStream<char> iss
	( std::istringstream( card1 + card2 + "0/\n" ) );

      CHECK_THROWS( RECONR(iss) );
    }
  }
  WHEN( "Cards non-terminating-3" ){
    THEN( "an exception is thrown" ){
      iRecordStream<char> iss
	( std::istringstream( card1 + card2 + card3 ) );
      CHECK_THROWS( RECONR(iss) );
    }
  }
  WHEN( "Cards 3,4" ){
    THEN( "an exception is thrown" ){
      iRecordStream<char> iss
	( std::istringstream( card1 + card2 + " 1234 0 0\n"  + card4 ) );
      CHECK_THROWS( RECONR(iss) );
    }
  }
  WHEN( "Cards 3,4,5,5,5,3 and ncards = 2" ){
    THEN( "an exception is thrown" ){
      iRecordStream<char> iss
	( std::istringstream( card1 + card2 + "1306 2 0\n" + card4 + card5
			      + card5 + card5 + "0/\n" ) );
      CHECK_THROWS( RECONR(iss) );
    }
  }
  WHEN( "Cards 3,4,5,5,5,3 and ncards = 4" ){
    THEN( "an exception is thrown" ){
      iRecordStream<char> iss
	( std::istringstream( card1 + card2 + "1306 4 0\n" + card4
			      + card5 + card5 + card5 + "0/\n" ) );
      CHECK_THROWS( RECONR(iss) );
    }
  }
  WHEN( "Cards 3,4,6,3 and ngrid = 0" ){
    THEN( "an exception is thrown" ){
      iRecordStream<char> iss
	( std::istringstream( card1 + card2 + "1306 0 0\n"
			      + card4 + card6 + "0/\n" ) );
      CHECK_THROWS( RECONR(iss) );
    }
  }
  WHEN( "Cards 3,4,3 and ngrid > 0" ){
    THEN( "an exception is thrown" ){
      iRecordStream<char> iss
	( std::istringstream( card1 + card2 + "1306 0 1000000\n"
			      + card4 + "0/\n" ) );
      CHECK_THROWS( RECONR(iss) );
    }
  }
  WHEN( "Cards 3,4, and faulty 5" ){
    THEN( "an exception is thrown" ){
      iRecordStream<char> iss
	( std::istringstream( card1 + card2 + "1306 1 0\n"
			      + card4 + "'abcd\n" + "0/\n" ) );
      CHECK_THROWS( RECONR(iss) );
    }
  }
  WHEN( "Cards 3,4,5,6,3,4,3 with materials specified in descending order" ){
    iRecordStream<char> iss
      ( std::istringstream( card1 + card2 + " 1306 1 3\n" + card4 + card5
  			    + card6 + " 1305 0 0\n" + card4 + "0/\n" ) );

    THEN( "an exception is thrown" ){
      CHECK_THROWS( RECONR( iss ) );
    }
  }
}
 */
