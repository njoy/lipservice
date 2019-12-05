template< typename Istream >
static std::optional< Card11 >
 readCard11( Istream& is, const int itype )
{

  if( itype < 0 ){
    Card11 card11( is );
    return std::optional< Card11 >( card11 );
  }
  return std::nullopt;
}
