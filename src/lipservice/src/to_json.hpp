void to_json( nlohmann::json& JSON, const RECONR::Card1& card1 ) {
  JSON = { card1.nendf.value, card1.npend.value };
}

void to_json( nlohmann::json& JSON, const RECONR::Card2& card2 ) {
  JSON = card2.tlabel.value;
}

void to_json( nlohmann::json& JSON, const RECONR::Card3& card3 ) {
  JSON = { card3.mat.value, card3.ncards.value, card3.ngrid.value };
  Log::info( "card3: {}", JSON );
}

void to_json( nlohmann::json& JSON, const RECONR::Card4& card4 ) {
  JSON = { card4.err.value, 
           card4.tempr.value, 
           card4.errmax.value, 
           card4.errint.value };
  Log::info( "card4: {}", JSON );
}

void to_json( nlohmann::json& JSON, const RECONR::Card5& card5 ) {
  JSON = card5.cards.value;
}

void to_json( nlohmann::json& JSON, const RECONR::Card6& card6 ) {
  JSON = card6.enode.value;
}

void to_json( nlohmann::json& JSON, const RECONR::RECONR_tuple& seq ) {
  Log::info( "In to_json for RECONR_tuple" );
  JSON = {
    { "card3", std::get< RECONR::Card3 >( seq ) },
    { "card4", std::get< RECONR::Card4 >( seq ) },
    { "card5", std::get< std::vector< RECONR::Card5 > >( seq ) },
    { "card6", std::get< optional< RECONR::Card6 > >( seq ) }
  };
  Log::info( "JSON: {}", JSON.dump(2) );
}

void to_json( nlohmann::json& JSON, const RECONR& reconr ) {
  JSON  = {
    { "card1", reconr.card1 },
    { "card2", reconr.card2 },
    // { "sequence", reconr.cardSequence }
  };

  nlohmann::json sequence = {};
  int i{ 0 };
  Log::info( "sequence size()", ranges::distance( reconr.cardSequence ) );
  for( auto& seq : reconr.cardSequence ){
    Log::info( "" );
    Log::info( "i: {}", i++ );
    Log::info( "MAT: {}", std::get< RECONR::Card3 >( seq ).mat.value );
    auto sequ = seq;
    // sequence.push_back( nlohmann::json( seq ) );
    sequence.push_back( nlohmann::json( sequ ) );
  }

  JSON[ "sequence" ] = sequence;
}
