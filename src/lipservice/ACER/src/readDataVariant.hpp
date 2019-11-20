template< typename Istream >
DataVariant readDataVariant( Istream& is, int iopt ){
  assert( (iopt > 0) and (iopt < 6) );
  switch( iopt ){
  case 1: {
    Card5 card5( is );
    Card6 card6( is );
    Card7 card7( is );
    return std::make_tuple< Card5, Card6, Card7 >( std::move( card5 ),
                                                    std::move( card6 ),
                                                    std::move( card7 ) );
  }
  case 2: {
    Card8 card8( is );
    Card8a card8a( is, card8.nza.value );
    Card9 card9( is );
    return std::make_tuple< Card8, Card8a, Card9 >( std::move( card8 ),
                                                    std::move( card8a ),
                                                    std::move( card9 ) );
  }
  case 3: {
    return Card10( is );
  }
  case 4:
  case 5: {
    return Card11( is );
  }
  }
  /* unreachable but necessary to silence compiler warning */
  throw std::exception();
}
