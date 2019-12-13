template< typename Char >
RECONR( iRecordStream<Char>& is )
try:
  card1( is ),
  card2( is ),
  cardSequence( readSequence( is ) )
{ }
catch( std::exception& e ){
  Log::info( "Trouble validating RECONR input" );
  throw e;
}
