template< typename Istream, typename Nextra >
auto readCard4( Istream& is, const Nextra& nxtra ){
  return nxtra.value ?
    std::optional< Card4 >{ std::in_place, is, nxtra } :
    std::nullopt;
}
