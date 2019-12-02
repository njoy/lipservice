void to_json( nlohmann::json& JSON, const RECONR::Card1& card1 ) {
  JSON = { { "nendf", card1.nendf.value }, 
           { "npend", card1.npend.value }
  };
}

void to_json( nlohmann::json& JSON, const RECONR::Card2& card2 ) {
  JSON = { { "tlabel", card2.tlabel.value } };
}

void to_json( nlohmann::json& JSON, const RECONR::Card3& card3 ) {
  JSON = { 
    { "mat", card3.mat.value }, 
    { "ncards", card3.ncards.value }, 
    { "ngrid", card3.ngrid.value }
  };
}

void to_json( nlohmann::json& JSON, const RECONR::Card4& card4 ) {
  JSON = { { "err", card4.err.value },
           { "tempr", card4.tempr.value },
           { "errmax", card4.errmax.value },
           { "errint", card4.errint.value }
  };
}

void to_json( nlohmann::json& JSON, const RECONR::Card5& card5 ) {
  JSON = card5.cards.value;
}

void to_json( nlohmann::json& JSON, const RECONR::Card6& card6 ) {
  JSON = { { "enode", card6.enode.value } };
}

void to_json( nlohmann::json& JSON, const RECONR::RECONR_tuple& seq ) {
  Log::info( "to_json RECONR_tuple" );
  JSON = {
    { "card3", std::get< 0 >( seq ) },
    { "card4", std::get< 1 >( seq ) },
    { "card5", std::get< 2 >( seq ) },
    { "card6", std::get< 3 >( seq ) },
  };
}

void to_json( nlohmann::json& JSON, const RECONR& reconr ) {
  Log::info( "to_json RECONR" );
  JSON  = {
    { "card1", reconr.card1 },
    { "card2", reconr.card2 },
    { "sequence", reconr.cardSequence }
  };

}
