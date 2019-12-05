class Card8a {
public:

  #include "lipservice/ACER/Card8a/Iza.hpp"

  Argument< Iza > iza;

  template< typename Char >
  Card8a( iRecordStream< Char >& is, const int nza )
  try:
    iza( argument::extract< Iza >( is, nza ) )
  {
    Card::clear( is );
  } catch( std::exception& e ){
      Log::info( "Trouble while validating card 8a" );
      throw e;
  }
};
