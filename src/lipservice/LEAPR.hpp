class LEAPR {
public:
#include "lipservice/LEAPR/Card1.hpp"
#include "lipservice/LEAPR/Card2.hpp"
#include "lipservice/LEAPR/Card3.hpp"
#include "lipservice/LEAPR/Card4.hpp"
#include "lipservice/LEAPR/Card5.hpp"
#include "lipservice/LEAPR/Card6.hpp"
#include "lipservice/LEAPR/Card7.hpp"
#include "lipservice/LEAPR/Card8.hpp"
#include "lipservice/LEAPR/Card9.hpp"
#include "lipservice/LEAPR/Card10.hpp"
#include "lipservice/LEAPR/Card11.hpp"
#include "lipservice/LEAPR/Card12.hpp"
#include "lipservice/LEAPR/Card13.hpp"
#include "lipservice/LEAPR/Card14.hpp"
#include "lipservice/LEAPR/Card15.hpp"
#include "lipservice/LEAPR/Card16.hpp"
#include "lipservice/LEAPR/Card17.hpp"
#include "lipservice/LEAPR/Card18.hpp"
#include "lipservice/LEAPR/Card19.hpp"
#include "lipservice/LEAPR/Card20.hpp"
using OscillatorTuple = std::tuple< Card15, Card16 >;

using PairCorrelTuple = std::tuple< Card17, Card18, std::optional<Card19> >;

using TempSpecificTuple = std::tuple< Card11, Card12, Card13, Card14,
                                 std::optional<OscillatorTuple>,
                                 std::optional<PairCorrelTuple> >;

using TempLoopIter = std::tuple< Card10, std::optional< TempSpecificTuple > >;

using TempLoop = std::vector<TempLoopIter>;

using Card20List = std::vector<Card20>;

#include "lipservice/LEAPR/src/buildOscillatorTuple.hpp"
#include "lipservice/LEAPR/src/buildPairCorrelTuple.hpp"
#include "lipservice/LEAPR/src/buildTempSpecificTuple.hpp"
#include "lipservice/LEAPR/src/tempLoopIter.hpp"
#include "lipservice/LEAPR/src/tempLoop.hpp"
#include "lipservice/LEAPR/src/buildCard20List.hpp"


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
      card20List = buildCard20List( iss );
    }

  catch( std::exception &e ){
    Log::info( "Trouble with validating LEAPR input" );
    throw e;
  }
};
