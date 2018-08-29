class Card5 {
  public:
  #include "legacyInputVerification/LEAPR/Card5/Awr.hpp"
  #include "legacyInputVerification/LEAPR/Card5/Spr.hpp"
  #include "legacyInputVerification/LEAPR/Card5/Npr.hpp"
  #include "legacyInputVerification/LEAPR/Card5/Iel.hpp"
  #include "legacyInputVerification/LEAPR/Card5/Ncold.hpp"
  #include "legacyInputVerification/LEAPR/Card5/Nsk.hpp"

  Argument< Awr   > awr;
  Argument< Spr   > spr;
  Argument< Npr   > npr;
  Argument< Iel   > iel;
  Argument< Ncold > ncold;
  Argument< Nsk   > nsk;

  template< typename Char >
  Card5( iRecordStream<Char>& is )
  try:
    awr  ( argument::extract< Awr   >( is ) ),
    spr  ( argument::extract< Spr   >( is ) ),
    npr  ( argument::extract< Npr   >( is ) ),
    iel  ( argument::extract< Iel   >( is ) ),
    ncold( argument::extract< Ncold >( is ) ),
    nsk  ( argument::extract< Nsk   >( is ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble while validating LEAPR Card5" );
    throw e;
  }
};
