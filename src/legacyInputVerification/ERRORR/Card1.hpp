class Card1 {
public:

#include "legacyInputVerification/ERRORR/Card1/Nendf.hpp"
#include "legacyInputVerification/ERRORR/Card1/Npend.hpp"
#include "legacyInputVerification/ERRORR/Card1/Ngout.hpp"
#include "legacyInputVerification/ERRORR/Card1/Nout.hpp"
#include "legacyInputVerification/ERRORR/Card1/Nin.hpp"
#include "legacyInputVerification/ERRORR/Card1/Nstan.hpp"

#include "legacyInputVerification/ERRORR/Card1/src/readRest.hpp"

Argument< Nendf > nendf;
optional< std::tuple< Argument< Npend >, Argument< Ngout >, Argument< Nout >,
                      Argument< Nin >, Argument< Nstan > > > rest;

template< typename Istream >
Card1( Istream& is )
try:
  nendf( argument::extract< ERRORR::Card1::Nendf >( is ) ),
  rest( readRest( is, this->nendf.value ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card1." );
  throw e;
}
};
