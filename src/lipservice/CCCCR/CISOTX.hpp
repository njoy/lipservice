class CISOTX {
public:

#include "lipservice/CCCCR/CISOTX/Card1.hpp"
#include "lipservice/CCCCR/CISOTX/Card2.hpp"
#include "lipservice/CCCCR/CISOTX/Card3.hpp"
#include "lipservice/CCCCR/CISOTX/Card4.hpp"

#include "lipservice/CCCCR/CISOTX/src/readCard2.hpp"
#include "lipservice/CCCCR/CISOTX/src/readCard3.hpp"
#include "lipservice/CCCCR/CISOTX/src/readCard4.hpp"

Card1 card1;
std::optional< Card2 > card2;
std::optional< Card3 > card3;
std::vector< Card4 > card4;

template< typename Istream >
CISOTX( Istream& is, const int ngroup, const int niso )
try:
  card1( is, ngroup ),
  card2( readCard2( is, ngroup, this->card1.ichix.value ) ),
  card3( readCard3( is, ngroup, this->card1.ichix.value ) ),
  card4( readCard4( is, niso ) )
{
}
catch( std::exception& e ){
  Log::info( "Trouble reading CISOTX." );
  throw e;
}
};
