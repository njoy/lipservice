class Lib1 {
public:

#include "lipservice/POWR/Lib1/Card3.hpp"
#include "lipservice/POWR/Lib1/Card4.hpp"
#include "lipservice/POWR/Lib1/Card5.hpp"
#include "lipservice/POWR/Lib1/Card6.hpp"

#include "lipservice/POWR/Lib1/src/readCard45.hpp"
#include "lipservice/POWR/Lib1/src/readCard6.hpp"

Card3 card3;
std::optional< std::pair< Card4, Card5 > > card45;
std::optional< Card6 > card6;

template< typename Istream >
Lib1( Istream& is )
try:
  card3( is ),
  card45( readCard45( is, this->card3.matd.value ) ),
  card6( readCard6( is, this->card3.matd.value ) )
{
}
catch( std::exception& e ){
  Log::info( "Trouble reading cards for lib=1." );
  throw e;
}
};
