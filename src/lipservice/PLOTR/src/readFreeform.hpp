template< typename Istream >
static std::optional< Freeform > readFreeform( Istream& is, const int iverf )
{

  if( iverf != 0 ) return std::nullopt;

  return Freeform( is );
}
