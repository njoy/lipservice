class Card3 {
public:
  #include "lipservice/LEAPR/Card3/Ntempr.hpp"
  #include "lipservice/LEAPR/Card3/Iprint.hpp"
  #include "lipservice/LEAPR/Card3/Nphon.hpp"

  Argument < Ntempr > ntempr;
  Argument < Iprint > iprint;
  Argument < Nphon  > nphon;

  template< typename Char> 
  Card3( iRecordStream < Char >& iss )
    try:
      ntempr( argument::extract < Ntempr > ( iss ) ),
      iprint( argument::extract < Iprint > ( iss ) ),
      nphon(  argument::extract < Nphon  > ( iss ) ){
        Card::clear( iss );
      }
    catch( std::exception& e) {
      Log::info( "Trouble while validating Card3" );
      throw e;
    }
};
