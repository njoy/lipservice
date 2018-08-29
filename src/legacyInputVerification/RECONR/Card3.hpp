class Card3 {
public:
   #include "legacyInputVerification/RECONR/Card3/Mat.hpp"
   #include "legacyInputVerification/RECONR/Card3/Ncards.hpp"
   #include "legacyInputVerification/RECONR/Card3/Ngrid.hpp"

  Argument< Mat > mat;
  Argument< Ncards > ncards;
  Argument< Ngrid > ngrid;

  template< typename Char >
  Card3( iRecordStream< Char >& is )
    try:
      mat( argument::extract< Mat >( is ) ),
      ncards( argument::extract< Ncards >( is ) ),
      ngrid( argument::extract< Ngrid >( is ) ){
	Card::clear(is);
      }
  catch( std::exception& e ){
    Log::info( "Trouble validating Card3" );
    throw e;
  }
};
