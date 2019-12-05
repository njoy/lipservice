class ERRORR {
public:

#include "lipservice/ERRORR/Card1.hpp"

#include "lipservice/ERRORR/DummyMF33.hpp"
#include "lipservice/ERRORR/Normal.hpp"

#include "lipservice/ERRORR/src/readDummyMF33.hpp"
#include "lipservice/ERRORR/src/readNormal.hpp"

Card1 card1;
std::optional< DummyMF33 > dummyMF33;
std::optional< Normal > normal;

template< typename Istream >
ERRORR( Istream& is )
try:
  card1( is ),
  dummyMF33( readDummyMF33( is, this->card1.nendf.value ) ),
  normal( readNormal( is, this->card1.nendf.value,
                      std::get<1>( *(this->card1.rest) ).value,
                      std::get<4>( *(this->card1.rest) ).value ) )
{
}
catch( std::exception& e ){
  Log::info( "Trouble reading ERRORR." );
  throw e;
}
};
