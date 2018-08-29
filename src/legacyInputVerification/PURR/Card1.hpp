class Card1 {
public:
  #include "legacyInputVerification/PURR/Card1/Nendf.hpp"
  #include "legacyInputVerification/BROADR/Card1/Nin.hpp"
  #include "legacyInputVerification/BROADR/Card1/Nout.hpp"
  
  Argument< Nendf > nendf;
  Argument< Nin > nin;
  Argument< Nout > nout;

  template< typename Char >
  Card1( iRecordStream< Char >& is )
    try:
      nendf( argument::extract< Nendf >( is ) ),
      nin( argument::extract< Nin >( is, this->nendf ) ),
      nout( argument::extract< Nout > ( is, this->nendf, this->nin ) ){
        Card::clear(is);
      }
    catch( std::exception& e ){
      Log::info("Trouble while validating Card 1");
      throw e;
    }
};
