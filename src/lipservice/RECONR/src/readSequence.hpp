template< typename Char >
auto readSequence( iRecordStream< Char >& is ){
  std::vector< RECONR_tuple > sequence;
  Card3 card3( is );
  if ( not card3.mat.value ){
    Log::error( "Must have at least one non-zero mat number in RECONR Card3" );
    throw std::exception();
  }

  std::optional< Card4 > card4;
  std::vector< Card5 > card5;
  std::optional< Card6 > card6;

  do{
    try {
      card4 = Card4( is );
    } catch( std::exception& e ){
      Log::info( "Failed to read card 4" );
      throw e;
    }

    try {
      if( card3.ncards.value ){
        card5 = std::vector< Card5 >();
        for( int n=0; n < card3.ncards.value; n++ ){
          card5.emplace_back( is );
        }
      }
    } catch( std::exception& e){
      Log::info("Trouble reading card 5 cards.");
      Log::info( "Expecting {} cards, read {} card(s) instead.",
                  card3.ncards.value, card5.size() );
      throw e;
    }
    if( card3.ngrid.value ){
      try {
        card6 = Card6( is, card3.ngrid );
      } catch( std::exception& e ){
        Log::info( "Failed reading card 6." );
        Log::info( "Expected to read {} grid points on card 6.", 
                    card3.ngrid.value );
        throw e;
      }
    }

    sequence.emplace_back( std::move(card3),
                                std::move(*card4), 
                                std::move(card5), 
                                std::move(card6) );
    card4 = std::nullopt;
    card5.clear();
    card6 = std::nullopt;

    try{
      card3 = Card3( is );
    } catch( std::exception& e ){
      Log::info( "Expected to read a terminating card 3 (mat=0).");
      Log::info( "Read {} card 5 entries, expected {}", 
                ( card5.empty() ? card5.size() : 0 ), card3.ncards.value );
      Log::info( "Read {} grid points from card 6, expected to read {}",
                ( card6 ? card6->enode.value.size() : 0 ), 
                card3.ngrid.value );
      throw e;
    }

    if( card3.mat.value == 0 ){ break; }
    int previousMat = std::get<Card3>(sequence.back()).mat.value;
    if( previousMat > card3.mat.value ){
      Log::error( "MAT values should be provided in increasing order" );
      Log::info( "MAT value {} followed by MAT value {}",
                previousMat, card3.mat.value );
      throw std::exception();
    }

  } while( true );

  auto unsortedStart = std::is_sorted_until( 
      sequence.begin(), sequence.end(), 
      []( RECONR_tuple first, RECONR_tuple second )->bool{
        return std::get<Card3>(first).mat.value < 
                std::get<Card3>(second).mat.value; } );

  if( unsortedStart != sequence.end() ){
    Log::error( "Materials in RECONR::Card3 should be specified in\n"
                "ascending order." );
    Log::info( "Card3 material {} > material {}.",
              std::get<Card3>(unsortedStart[-1]).mat.value,
              std::get<Card3>(*(unsortedStart)).mat.value );
    throw std::exception();
  }

  return sequence;
}
