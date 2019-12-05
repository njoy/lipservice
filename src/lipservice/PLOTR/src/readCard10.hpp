template< typename Istream >
static std::optional< Card10 >
 readCard10( Istream& is, const int ileg )
{
  if( ileg != 0 ){
    return Card10( is );
  }
  return std::nullopt;
}
