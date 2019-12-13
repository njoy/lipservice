template< typename Istream >
std::optional< Card13b > readCard13b( Istream& is, const int iwt ){
  if( iwt != 4 ) return std::nullopt;

  return Card13b( is );
}
