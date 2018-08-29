class Card12 {
public:
  #include "legacyInputVerification/PLOTR/Card12/Nform.hpp"

  Argument< Nform > nform;

  template< typename Char >
  Card12 ( iRecordStream< Char >& is )
    try:
      nform( argument::extract< Nform >( is ) )
      {
        Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble validating Card12" );
      throw e;
    }
};
