#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "lipservice.hpp"

using namespace njoy::njoy21::lipservice;

//  Test matrix:
//  - All default to 1
//
//  - mfd = 3 or 5 and iverf != 1 -> not used
//  - mfd = 4 and iverf != 1 -> not used
//  - mfd = 6 and iverf != 1
//  - mfd = 3 and iverf == 1
//  - mfd = 6 and iverf == 1 -> not used
//  - mfd = 7 and iverf != 1

SCENARIO( "Nkh input values", "[PLOTR], [Card8], [Nkh]" ){
  GIVEN( "valid nkh values" ){
    WHEN( "mfd = 6 and iverf != 1" ){
      std::vector<int> validNkh{ 1, 5, 30 };
      int mfd = 6; int iverf = 3;
      THEN( "the returned value is correct" ){
        for( auto nkh : validNkh ){
          iRecordStream<char> issNkh( std::istringstream(
                               std::to_string(nkh) ) );
          REQUIRE( argument::extract< PLOTR::Card8::Nkh >(
                   issNkh, mfd, iverf ).value == nkh );
        }
      }
      THEN( "the default value is returned" ){
        iRecordStream<char> issNkh( std::istringstream( " /" ) );
        REQUIRE( argument::extract< PLOTR::Card8::Nkh >(
                 issNkh, mfd, iverf ).value == 1 );
      }
    }
    WHEN( "mfd = 3 and iverf == 1" ){
      std::vector<int> validNkh{ 1, 2 };
      int mfd = 3; int iverf = 1;
      THEN( "the returned value is correct" ){
        for( auto nkh : validNkh ){
          iRecordStream<char> issNkh( std::istringstream(
                               std::to_string(nkh) ) );
          REQUIRE( argument::extract< PLOTR::Card8::Nkh >(
                   issNkh, mfd, iverf ).value == nkh );
        }
      }
      THEN( "the default value is returned" ){
        iRecordStream<char> issNkh( std::istringstream( " /" ) );
        REQUIRE( argument::extract< PLOTR::Card8::Nkh >(
                 issNkh, mfd, iverf ).value == 1 );
      }
    }
    WHEN( "mfd = 7 and iverf != 1 and jtype == 0" ){
      std::vector<int> validNkh{ 1, 2, 3 };
      int mfd = 7; int iverf = 3;
      THEN( "the returned value is correct" ){
        for( auto nkh : validNkh ){
          iRecordStream<char> issNkh( std::istringstream(
                               std::to_string(nkh) ) );
          REQUIRE( argument::extract< PLOTR::Card8::Nkh >(
                   issNkh, mfd, iverf ).value == nkh );
        }
      }
      THEN( "the default value is returned" ){
        iRecordStream<char> issNkh( std::istringstream( " /" ) );
        REQUIRE( argument::extract< PLOTR::Card8::Nkh >(
                 issNkh, mfd, iverf ).value == 1 );
      }
    }
  }//GIVEN
  GIVEN( "invalid nkh values" ){
    WHEN( "mfd = 3 and iverf != 1, this value is not used" ){
      std::vector<int> invalidNkh{ -10, -1, 0, 1, 5, 10, 50};
      int mfd = 3; int iverf = 2;
      THEN( "an exception is thrown" ){
        for( auto nkh : invalidNkh ){
          iRecordStream<char> issNkh( std::istringstream(
                               std::to_string(nkh) ) );
          REQUIRE_THROWS( argument::extract< PLOTR::Card8::Nkh >(
                          issNkh, mfd, iverf ) );
        }
      }
    }
    WHEN( "mfd = 5 and iverf != 1, this value is not used" ){
      std::vector<int> invalidNkh{ -10, -1, 0, 1, 5, 10, 50 };
      int mfd = 5; int iverf = 2;
      THEN( "an exception is thrown" ){
        for( auto nkh : invalidNkh ){
          iRecordStream<char> issNkh( std::istringstream(
                               std::to_string(nkh) ) );
          REQUIRE_THROWS( argument::extract< PLOTR::Card8::Nkh >(
                          issNkh, mfd, iverf ) );
        }
      }
    }
    WHEN( "mfd = 4 and iverf != 1, this value is not used" ){
      std::vector<int> invalidNkh{ -10, -2, -1, 0, 1, 5, 30 };
      int mfd = 4; int iverf = 2;
      THEN( "an exception is thrown" ){
        for( auto nkh : invalidNkh ){
          iRecordStream<char> issNkh( std::istringstream(
                               std::to_string(nkh) ) );
          REQUIRE_THROWS( argument::extract< PLOTR::Card8::Nkh >(
                          issNkh, mfd, iverf ) );
        }
      }
    }
    WHEN( "mfd = 6 and iverf != 1" ){
      std::vector<int> invalidNkh{ 0, -10, -2, -1 };
      int mfd = 6; int iverf = 3;
      THEN( "an exception is thrown" ){
        for( auto nkh : invalidNkh ){
          iRecordStream<char> issNkh( std::istringstream(
                               std::to_string(nkh) ) );
          REQUIRE_THROWS( argument::extract< PLOTR::Card8::Nkh >(
                          issNkh, mfd, iverf ) );
        }
      }
    }
    WHEN( "mfd = 3 and iverf == 1" ){
      std::vector<int> invalidNkh{ -2, -1, 0, 3, 5 };
      int mfd = 3; int iverf = 1;
      THEN( "an exception is thrown" ){
        for( auto nkh : invalidNkh ){
          iRecordStream<char> issNkh( std::istringstream(
                               std::to_string(nkh) ) );
          REQUIRE_THROWS( argument::extract< PLOTR::Card8::Nkh >(
                          issNkh, mfd, iverf ) );
        }
      }
    }
    WHEN( "mfd = 6 and iverf == 1, this value isn't used" ){
      std::vector<int> invalidNkh{ -10, -5, -1, 0, 1, 2, 5, 10, 288 };
      int mfd = 6; int iverf = 1;
      THEN( "an exception is thrown" ){
        for( auto nkh : invalidNkh ){
          iRecordStream<char> issNkh( std::istringstream(
                               std::to_string(nkh) ) );
          REQUIRE_THROWS( argument::extract< PLOTR::Card8::Nkh >(
                          issNkh, mfd, iverf ) );
        }
      }
    }
    WHEN( "mfd = 7 and iverf != 1 and jtype == 0" ){
      std::vector<int> invalidNkh{ -10, -2, -1, 0, 4, 5, 10 };
      int mfd = 7; int iverf = 2;
      THEN( "an exception is thrown" ){
        for( auto nkh : invalidNkh ){
          iRecordStream<char> issNkh( std::istringstream(
                               std::to_string(nkh) ) );
          REQUIRE_THROWS( argument::extract< PLOTR::Card8::Nkh >(
                          issNkh, mfd, iverf ) );
        }
      }
    }
  }//GIVEN
  GIVEN( "iverf == 0" ){
    int iverf = 0;
    std::vector<int> mfds{ -10, -5, 0, 1, 5, 10, 20 };
    THEN( "the values don't matter" ){
      for( auto mfd : mfds ){
        for( auto nkh : mfds ){
          iRecordStream<char> issNkh( std::istringstream(
                               std::to_string(nkh) ) );
          REQUIRE_NOTHROW( argument::extract< PLOTR::Card8::Nkh >(
                            issNkh, mfd, iverf ) );
        }
      }
    }
  }//GIVEN
}

