class Card10 {
public:

#include "lipservice/ERRORR/Normal/Card10/Mat1.hpp"
#include "lipservice/ERRORR/Normal/Card10/Mt1.hpp"

#include "lipservice/ERRORR/Normal/Card10/src/readMt1.hpp"

Argument< Mat1 > mat1;
optional< Argument< Mt1 > > mt1;

template< typename Char >
Card10( iRecordStream< Char >& is )
try:
  mat1( argument::extract< Mat1 >( is ) ),
  mt1( readMt1( is, this->mat1.value ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card10." );
  throw e;
}
};
