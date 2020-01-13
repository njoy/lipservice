inline void to_json( nlohmann::json& JSON, const THERMR::Card1& card1 ) {
  JSON = { 
    { "nendf", card1.nendf.value },
    { "nin",   card1.nin.value },
    { "nout",  card1.nout.value }
  };
}

inline void to_json( nlohmann::json& JSON, const THERMR::Card2& card2 ) {
  JSON = { 
    { "matde",  card2.matde.value },
    { "matdp",  card2.matdp.value },
    { "nbin",   card2.nbin.value },
    { "ntemp",  card2.ntemp.value },
    { "iin",    card2.iin.value },
    { "icoh",   card2.icoh.value },
    { "iform",  card2.iform.value },
    { "natom",  card2.natom.value },
    { "mtref",  card2.mtref.value },
    { "iprint", card2.iprint.value }
  };
}

inline void to_json( nlohmann::json& JSON, const THERMR::Card3& card3 ) {
  JSON = { { "tempr", card3.tempr.value } };
}

inline void to_json( nlohmann::json& JSON, const THERMR::Card4& card4 ) {
  JSON = {
    { "tol", card4.tol.value },
    { "emax", card4.emax.value }
  };
}

inline void to_json( nlohmann::json& JSON, const THERMR& thermr ) {
  JSON = thermr.card1;
  JSON.update( thermr.card2 );
  JSON.update( thermr.card3 );
  JSON.update( thermr.card4 );
}
