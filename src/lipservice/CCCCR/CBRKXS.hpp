class CBRKXS {
public:

#include "lipservice/CCCCR/CBRKXS/Card1.hpp"
#include "lipservice/CCCCR/CBRKXS/Card2.hpp"
#include "lipservice/CCCCR/CBRKXS/Card3.hpp"

#include "lipservice/CCCCR/CBRKXS/src/readCard2.hpp"
#include "lipservice/CCCCR/CBRKXS/src/readCard3.hpp"

Card1 card1;
std::optional< Card2 > card2;
std::optional< Card3 > card3;

template< typename Istream >
CBRKXS( Istream& is )
try:
  card1( is ),
  card2( readCard2( is, this->card1.nti.value ) ),
  card3( readCard3( is, this->card1.nzi.value ) )
{
}
catch( std::exception& e ){
  Log::info( "Trouble reading CBRKXS." );
  throw e;
}
};
