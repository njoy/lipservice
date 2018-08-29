class POWR {
public:

using Card1 = WIMSR::Card1;
#include "lipservice/POWR/Card2.hpp"

#include "lipservice/POWR/Lib1.hpp"
#include "lipservice/POWR/Lib2.hpp"
#include "lipservice/POWR/Lib3.hpp"

#include "lipservice/POWR/src/readLib1.hpp"
#include "lipservice/POWR/src/readLib2.hpp"

#include "lipservice/POWR/src/readLib.hpp"

Card1 card1;
Card2 card2;
std::variant< std::vector< Lib1 >, std::vector< Lib2 >, Lib3 > lib;

template< typename Istream >
POWR( Istream& is )
try:
  card1( is ),
  card2( is ),
  lib( readLib( is, this->card2.lib.value, this->card2.iclaps.value ) )
{
}
catch( std::exception& e ){
  Log::info( "Trouble reading in POWR module." );
  throw e;
}

};
