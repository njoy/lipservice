template< typename Istream >
static std::optional< Plot > readPlot( Istream& is, const int iplot )
{
  if( std::abs( iplot ) != 1 ) return std::nullopt;
  return Plot( is );
}
