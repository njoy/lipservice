inline void to_json( nlohmann::json& JSON, const RECONR::Card1& card1 ) {
  JSON = { { "nendf", card1.nendf.value }, 
           { "npend", card1.npend.value }
  };
}

inline void to_json( nlohmann::json& JSON, const RECONR::Card2& card2 ) {
  JSON = { { "tlabel", card2.tlabel.value } };
}

inline void to_json( nlohmann::json& JSON, const RECONR::Card3& card3 ) {
  JSON = { 
    { "mat", card3.mat.value }, 
    { "ncards", card3.ncards.value }, 
    { "ngrid", card3.ngrid.value }
  };
}

inline void to_json( nlohmann::json& JSON, const RECONR::Card4& card4 ) {
  JSON = { { "err", card4.err.value },
           { "tempr", card4.tempr.value },
           { "errmax", card4.errmax.value },
           { "errint", card4.errint.value }
  };
}

inline void to_json( nlohmann::json& JSON, const RECONR::Card5& card5 ) {
  JSON = card5.cards.value;
}

inline void to_json( nlohmann::json& JSON, const RECONR::Card6& card6 ) {
  JSON = { { "enode", card6.enode.value } };
}

inline void to_json( nlohmann::json& JSON, const RECONR::RECONR_tuple& seq ) {
  JSON = {
    { "card3", std::get< 0 >( seq ) },
    { "card4", std::get< 1 >( seq ) },
    { "card5", std::get< 2 >( seq ) },
    { "card6", std::get< 3 >( seq ) },
  };
}

inline void to_json( nlohmann::json& JSON, const RECONR& reconr ) {
  JSON  = { {
    reconr.card1, 
    reconr.card2,
    { "sequence", reconr.cardSequence }
  } };
}
