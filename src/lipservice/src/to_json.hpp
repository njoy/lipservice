void to_json( nlohmann::json& JSON, const RECONR& reconr ) {
  JSON  = {
    { "card1", reconr.card1 },
    { "card2", reconr.card2 }
  };
  nlohmann::json sequence{};

  for(const auto& seq : reconr.cardSequence ){
    nlohmann::json jsonSequence{
      { "card3", std::get< 0 >( seq ) },
      { "card4", std::get< 1 >( seq ) },
      { "card5", std::get< 2 >( seq ) },
      { "card6", std::get< 3 >( seq ) }
    };

    // auto card6 = std::get< 3 >( seq );
    // if( card6 ){
    //   jsonSequence[ "card6" ] = *card6;
    // } else{
    //   jsonSequence[ "card6" ] = nullptr;
    // }
    sequence.push_back( jsonSequence );
  }

  JSON[ "sequence" ] = sequence;
}

void to_json( nlohmann::json& JSON, const RECONR::Card1& card1 ) {
  JSON = { card1.nendf.value, card1.npend.value };
}

void to_json( nlohmann::json& JSON, const RECONR::Card2& card2 ) {
  JSON = card2.tlabel.value;
}

void to_json( nlohmann::json& JSON, const RECONR::Card3& card3 ) {
  JSON = { card3.mat.value, card3.ncards.value, card3.ngrid.value };
}

void to_json( nlohmann::json& JSON, const RECONR::Card4& card4 ) {
  JSON = { card4.err.value, 
           card4.tempr.value, 
           card4.errmax.value, 
           card4.errint.value };
}

void to_json( nlohmann::json& JSON, const RECONR::Card5& card5 ) {
  JSON = card5.cards.value;
}

void to_json( nlohmann::json& JSON, const RECONR::Card6& card6 ) {
  JSON = card6.enode.value;
}
