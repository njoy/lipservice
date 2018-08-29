class Card5a {
public:
  #include "lipservice/PLOTR/Card5a/Xlabl.hpp"

  Argument< Xlabl > xlabl;

  template< typename Char >
  Card5a( iRecordStream< Char >& is )
    try:
      xlabl( argument::extract< Xlabl >( is ) )
    {
      Card::clear( is );
    }
    catch( std::exception& e ){
      Log::info("Trouble while validating Card 5a - Label for the x-axis");
      throw e;
    }
};
