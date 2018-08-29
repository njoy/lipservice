class Card9 {
public:
  #include "legacyInputVerification/PLOTR/Card9/Icon.hpp"
  #include "legacyInputVerification/PLOTR/Card9/Isym.hpp"
  #include "legacyInputVerification/PLOTR/Card9/Idash.hpp"
  #include "legacyInputVerification/PLOTR/Card9/Iccol.hpp"
  #include "legacyInputVerification/PLOTR/Card9/Ithick.hpp"
  #include "legacyInputVerification/PLOTR/Card9/Ishade.hpp"

  Argument< Icon > icon;
  Argument< Isym > isym;
  Argument< Idash > idash;
  Argument< Iccol > iccol;
  Argument< Ithick > ithick;
  Argument< Ishade > ishade;

  template< typename Char >
  Card9 ( iRecordStream< Char >& is )
    try:
      icon( argument::extract< Icon >( is ) ),
      isym( argument::extract< Isym >( is ) ),
      idash( argument::extract< Idash >( is ) ),
      iccol( argument::extract< Iccol >( is ) ),
      ithick( argument::extract< Ithick >( is ) ),
      ishade( argument::extract< Ishade >( is ) )
      {
        Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble validating Card9" );
      throw e;
    }
};
