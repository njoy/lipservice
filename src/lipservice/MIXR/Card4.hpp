class Card4 {
  public:
    #include "lipservice/MIXR/Card4/Temp.hpp"
    Argument< Temp > temp;

    template< typename Char >
    Card4( iRecordStream< Char >& is )
      try:
        temp( argument::extract< Temp > ( is ) )
	{ 
	  Card::clear( is );
        }
      catch( std::exception& e ){
        Log::info( "Trouble validating Card4" );
	throw e;
      }
};  
