class Card3 {
public:
  #include "lipservice/PLOTR/Card3/Title.hpp"

  Argument< Title > t1;

  template< typename Char >
  Card3( iRecordStream< Char >& is )
    try:
      t1( argument::extract< Title >( is ) )
    {
      Card::clear( is );
    }
    catch( std::exception& e ){
      Log::info("Trouble while validating Card 3 - Title line 1");
      throw e;
    }
};
