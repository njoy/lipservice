class Card8b {
public:

  #include "lipservice/GROUPR/Card8b/Wght.hpp"

  Argument< Wght > wght;

  template< typename Char >
  Card8b( iRecordStream< Char >& is)
    try:
      wght( argument::extract< Wght >( is ) )
    {
        Card::clear( is );
    } catch( std::exception& e ) {
      Log::info( "Trouble while validating card 8b" );
      throw e;
    }
};

