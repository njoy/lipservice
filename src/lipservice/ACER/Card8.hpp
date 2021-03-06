class Card8 {
public:

  #include "lipservice/ACER/Card8/Tname.hpp"
  #include "lipservice/ACER/Card8/Nza.hpp"

  Argument< argument::common::Matd > matd;
  Argument< argument::common::Tempd > tempd;
  Argument< Tname > tname;
  Argument< Nza > nza;

  template< typename Char >
  Card8( iRecordStream< Char >& is )
  try:
    matd( argument::extract< argument::common::Matd >( is ) ),
    tempd( argument::extract< argument::common::Tempd >( is ) ),
    tname( argument::extract< Tname >( is ) ),
    nza( argument::extract< Nza >( is ) )
  {
    Card::clear( is );
  } catch( std::exception& e ){
      Log::info( "Trouble while validating card 8" );
      throw e;
  }
};
