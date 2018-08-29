class Card2 {
public:

#include "legacyInputVerification/CCCCR/CBRKXS/Card2/Atem.hpp"

Argument< Atem > atem;

template< typename Istream >
Card2( Istream& is, const int nti )
try:
  atem( argument::extract< CCCCR::CBRKXS::Card2::Atem >( is, nti ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card2." );
  throw e;
}
};
