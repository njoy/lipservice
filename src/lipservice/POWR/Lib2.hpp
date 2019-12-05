class Lib2 {
public:

#include "lipservice/POWR/Lib2/Card3.hpp"
#include "lipservice/POWR/Lib2/Card4.hpp"
#include "lipservice/POWR/Lib2/Card5.hpp"

#include "lipservice/POWR/Lib2/src/readCard45.hpp"

Card3 card3;
std::optional< std::pair< Card4, Card5 > > card45;

template< typename Istream >
Lib2( Istream& is )
try:
  card3( is ),
  card45( readCard45( is, this->card3.matd.value ) )
{
}
catch( std::exception& e ){
  Log::info( "Trouble reading cards for lib=2." );
  throw e;
}
};
