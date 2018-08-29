class Card1 {
public:
  #include "lipservice/THERMR/Card1/Nendf.hpp"
  #include "lipservice/THERMR/Card1/Nin.hpp"
  #include "lipservice/THERMR/Card1/Nout.hpp"
  
  Argument< Nendf > nendf;
  Argument< Nin > nin;
  Argument< Nout > nout;

  template< typename Char >
  Card1( iRecordStream< Char >& is )
    try:
      nendf ( argument::extract< Nendf >( is ) ),
      nin   ( argument::extract< Nin >  ( is, this->nendf ) ),
      nout  ( argument::extract< Nout > ( is, this->nendf, this->nin ) ){
	Card::clear(is);
    } catch( std::exception& e ){
      Log::info("Trouble while validating THERMR Card 1");
      throw e;
    }
};
