class Card8a {
public:

#include "lipservice/ERRORR/Normal/Card8a/Mts.hpp"

Argument< Mts > mts;

template< typename Istream >
Card8a( Istream& is, const int nmt )
try:
  mts( argument::extract< ERRORR::Normal::Card8a::Mts >( is, nmt ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card8a." );
  throw e;
}
};
