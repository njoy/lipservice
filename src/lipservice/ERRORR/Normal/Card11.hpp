class Card11 {
public:

#include "lipservice/ERRORR/Normal/Card11/Matb.hpp"
#include "lipservice/ERRORR/Normal/Card11/Mtb.hpp"
#include "lipservice/ERRORR/Normal/Card11/Matc.hpp"
#include "lipservice/ERRORR/Normal/Card11/Mtc.hpp"

#include "lipservice/ERRORR/Normal/Card11/src/readRest.hpp"

Argument< Matb > matb;
optional< std::tuple< Argument< Mtb >, Argument< Matc >, Argument< Mtc > > >
                                                                           rest;
Card11( Card11& ) = default;
Card11( const Card11& ) = default;
Card11( Card11&& ) = default;

template< typename Istream >
Card11( Istream& is )
try:
  matb( argument::extract< ERRORR::Normal::Card11::Matb >( is ) ),
  rest( readRest( is, this->matb.value ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card11." );
  throw e;
}
};
