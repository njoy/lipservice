class LEAPR {
public:
#include "legacyInputVerification/LEAPR/Card1.hpp"
#include "legacyInputVerification/LEAPR/Card2.hpp"
#include "legacyInputVerification/LEAPR/Card3.hpp"
#include "legacyInputVerification/LEAPR/Card4.hpp"
#include "legacyInputVerification/LEAPR/Card5.hpp"
#include "legacyInputVerification/LEAPR/Card6.hpp"
#include "legacyInputVerification/LEAPR/Card7.hpp"
#include "legacyInputVerification/LEAPR/Card8.hpp"
#include "legacyInputVerification/LEAPR/Card9.hpp"
#include "legacyInputVerification/LEAPR/Card10.hpp"
#include "legacyInputVerification/LEAPR/Card11.hpp"
#include "legacyInputVerification/LEAPR/Card12.hpp"
#include "legacyInputVerification/LEAPR/Card13.hpp"
#include "legacyInputVerification/LEAPR/Card14.hpp"
#include "legacyInputVerification/LEAPR/Card15.hpp"
#include "legacyInputVerification/LEAPR/Card16.hpp"
#include "legacyInputVerification/LEAPR/Card17.hpp"
#include "legacyInputVerification/LEAPR/Card18.hpp"
#include "legacyInputVerification/LEAPR/Card19.hpp"
#include "legacyInputVerification/LEAPR/Card20.hpp"
using OscillatorTuple = std::tuple< Card15, Card16 >;

using PairCorrelTuple = std::tuple< Card17, Card18 >;

using TempSpecificTuple = std::tuple< Card11, Card12, Card13, Card14,
                                 optional<OscillatorTuple>,
                                 optional<PairCorrelTuple> >;

using TempLoopIter = std::tuple< Card10, optional< TempSpecificTuple > >;

using TempLoop = std::vector<TempLoopIter>;

using Card20List = std::vector<Card20>;

#include "legacyInputVerification/LEAPR/src/buildOscillatorTuple.hpp"
#include "legacyInputVerification/LEAPR/src/buildPairCorrelTuple.hpp"
#include "legacyInputVerification/LEAPR/src/buildTempSpecificTuple.hpp"
#include "legacyInputVerification/LEAPR/src/tempLoopIter.hpp"
#include "legacyInputVerification/LEAPR/src/tempLoop.hpp"
#include "legacyInputVerification/LEAPR/src/buildCard20List.hpp"


Card1 card1;
Card2 card2;
Card3 card3;
Card4 card4;
Card5 card5;
Card6 card6;
Card7 card7;
Card8 card8;
Card9 card9;
TempLoop tempLoop;
optional< Card19 > card19;
Card20List card20List;
 

template <typename Char> 
  LEAPR( iRecordStream<Char>& iss )
  try:
    card1( iss ),
    card2( iss ),
    card3( iss ),
    card4( iss ),
    card5( iss ),
    card6( iss ),
    card7( iss ),
    card8( iss, this->card7.nalpha ),
    card9( iss, this->card7.nbeta  ),
    tempLoop( buildTempLoop( iss, this->card3, this->card5, this->card6 ) )
    {
      if( this->card5.nsk.value == 2 ){ this->card19 = Card19( iss ); }
      card20List = buildCard20List( iss );
    }

  catch( std::exception &e ){
    Log::info( "Trouble with validating LEAPR input" );
    throw e;
  }
};
