class Card10a {
public:
  #include "lipservice/PLOTR/Card10a/Xtag.hpp"
  #include "lipservice/PLOTR/Card10a/Ytag.hpp"
  #include "lipservice/PLOTR/Card10a/Xpoint.hpp"

  Argument< Xtag > xtag;
  Argument< Ytag > ytag;
  Argument< Xpoint > xpoint;

  template< typename Char >
  Card10a ( iRecordStream< Char >& is )
    try:
      xtag( argument::extract< Xtag >( is ) ),
      ytag( argument::extract< Ytag >( is ) ),
      xpoint( argument::extract< Xpoint >( is ) )
      {
        Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble validating Card10a" );
      throw e;
    }
};
