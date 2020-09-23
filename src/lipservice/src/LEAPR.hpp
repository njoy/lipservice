inline void to_json( nlohmann::json& JSON, const LEAPR::Card1& card1 ){
  JSON = {
    { "nout", card1.nout.value }
  };
}


inline void to_json( nlohmann::json& JSON, const LEAPR::Card2& card2 ){
  JSON = { 
    { "title", card2.title.value } 
  };
}


inline void to_json( nlohmann::json& JSON, const LEAPR::Card3& card3 ){
  JSON = { 
    { "ntempr", card3.ntempr.value },
    { "iprint", card3.iprint.value },
    { "nphon" , card3.nphon.value } 
  };
}


inline void to_json( nlohmann::json& JSON, const LEAPR::Card4& card4 ){
  JSON = { 
    { "mat"  , card4.mat.value   },
    { "za"   , card4.za.value    },
    { "isabt", card4.isabt.value },
    { "ilog" , card4.ilog.value  }, 
    { "smin" , card4.smin.value  } 
  };
}

inline void to_json( nlohmann::json& JSON, const LEAPR::Card5& card5 ){
  JSON = { 
    { "awr"  , card5.awr.value   },
    { "spr"  , card5.spr.value   },
    { "npr"  , card5.npr.value   },
    { "iel"  , card5.iel.value   }, 
    { "ncold", card5.ncold.value },
    { "nsk"  , card5.nsk.value   } 
  };
}

inline void to_json( nlohmann::json& JSON, const LEAPR::Card6& card6 ){
  JSON = { 
    { "nss", card6.nss.value  },
    { "b7" , card6.b7.value   },
    { "aws", card6.aws.value  },
    { "sps", card6.sps.value  }, 
    { "mss", card6.mss.value  }
  };
}


inline void to_json( nlohmann::json& JSON, const LEAPR::Card7& card7 ){
  JSON = { 
    { "nalpha", card7.nalpha.value },
    { "nbeta" , card7.nbeta.value  },
    { "lat"   , card7.lat.value    }
   };
}

inline void to_json( nlohmann::json& JSON, const LEAPR::Card8& card8 ){
  JSON = { 
    { "alpha", card8.alpha.value }
  };
}

inline void to_json( nlohmann::json& JSON, const LEAPR::Card9& card9 ){
  JSON = { 
    { "beta", card9.beta.value }
  };
}



inline void to_json( nlohmannn::json& JSON, const LEAPR::TempLoop& tempLoop){
  JSON = {
    { "tempLoop", tempLoop }
  };
}

inline void to_json( nlohmannn::json& JSON, const std::optional<LEAPR::Card19>& card19 ){
  if ( card19 ){
    JSON = {
      { "cfrac" , card19->cfrac.value }
    };
  }
  else {
    JSON = {
      { nlohmann::json:array() }
    };
}


inline void to_json( nlohmannn::json& JSON, const LEAPR& leapr ){
  JSON = leapr.card1;
  JSON.update( leapr.card2 );
  JSON.update( leapr.card3 );
  JSON.update( leapr.card4 );
  JSON.update( leapr.card5 );
  JSON.update( leapr.card6 );
  JSON.update( leapr.card7 );
  JSON.update( leapr.card8 );
  JSON.update( leapr.card9 );
  JSON["tempLoop"] = leapr.tempLoop;
  JSON.update( leapr.card19 );
  JSON["comments"] = leapr.card20List;
}









