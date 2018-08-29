class Card13 {
  public:
  #include "lipservice/LEAPR/Card13/Twt.hpp"
  #include "lipservice/LEAPR/Card13/C.hpp"
  #include "lipservice/LEAPR/Card13/Tbeta.hpp"

  Argument< Twt   > twt;
  Argument< C     > c;
  Argument< Tbeta > tbeta;

  template< typename Char >
  Card13( iRecordStream<Char>& is )
  try:
    twt  ( argument::extract< Twt   >( is ) ),
    c    ( argument::extract< C     >( is ) ),
    tbeta( argument::extract< Tbeta >( is ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble while validating LEAPR Card13" );
    throw e;
  }
};
