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
  if (card6.controlTuple){
    JSON = { 
      { "nss", card6.nss.value  },
      //{ "b7" , card6.b7.value   },
      //{ "aws", card6.aws.value  },
      //{ "sps", card6.sps.value  }, 
      //{ "mss", card6.mss.value  }
    };

    auto controlTuple = card6.controlTuple;
    //auto ctrl = *controlTuple;
    //JSON["b7"] = ctrl.b7;
    //JSON = {{"b7", ctrl.b7}};
    //JSON["aws"] = std::get<1>(card6.controlTuple);
    //JSON["sps"] = std::get<2>(card6.controlTuple);
    //JSON["mss"] = std::get<3>(card6.controlTuple);
  }
  else {
    JSON = { 
      { "nss", card6.nss.value  }
    };
  }
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

inline void to_json( nlohmann::json& JSON, const LEAPR::Card10& card10 ){
  JSON = { 
    { "temperature", card10.temp.value }
  };
}
/*

inline void to_json( nlohmann::json& JSON, const LEAPR::Card11& card11 ){
  JSON = { 
    { "delta", card11.delta.value },
    { "ni",    card11.ni.value }
  };
}

inline void to_json( nlohmann::json& JSON, const LEAPR::Card12& card12 ){
  JSON = { 
    { "rho", card12.rho.value }
  };
}

inline void to_json( nlohmann::json& JSON, const LEAPR::Card13& card13 ){
  JSON = { 
    { "rho",   card13.twt.value },
    { "c",     card13.c.value },
    { "tbeta", card13.tbeta.value }
  };
}

inline void to_json( nlohmann::json& JSON, const LEAPR::OscillatorTuple& oscillatorTuple ){
  if (oscillatorTuple){
    JSON = {
      { "oscillatorEnergies", std::get<0>(oscillatorTuple) },
      { "oscillatorWeights" , std::get<1>(oscillatorTuple) }
    }
  }
  else {
    JSON = {
      { "oscillatorEnergies", nlohmann::json::array() },
      { "oscillatorWeights" , nlohmann::json::array() }
    }
  } 
}

inline void to_json( nlohmann::json& JSON, const LEAPR::PairCorrelTuple& pairCorrelationTuple ){
  if (pairCorrelationTuple){
    JSON = {
      { "nka",    std::get<0>(pairCorrelationTuple).nka.value },
      { "dka",    std::get<0>(pairCorrelationTuple).dka.value },
      { "skappa", std::get<1>(pairCorrelationTuple).skappa.value },
    }
  }
  else {
    JSON = {
    }
  } 
}

*/



inline void to_json( nlohmann::json& JSON, const LEAPR::TempLoop& tempLoop){
  std::vector<double> temperatures;
  std::vector<std::tuple<
  for (auto& tempLoop_iter : tempLoop){
      auto thisTemp = std::get<0>(tempLoop_iter).temp.value;
      if (thisTemp > 0){
        //nlohmann::json JSON_this_temp = std::get<0>(tempLoop_iter);//.Card10;
        temperatures.push_back(std::get<0>(tempLoop_iter).temp.value);//.Card10
        //JSON_this_temp.update(tempLoop_iter.Card11);
        //JSON_this_temp.update(tempLoop_iter.Card12);
        //JSON_this_temp.update(tempLoop_iter.Card13);
        //JSON_this_temp["nd"] = thisLoop_iter.Card14.nd.value();
        //JSON_this_temp.update(thisLoop_iter.OscillatorTuple); //Cards 15 & 16
        //JSON_this_temp.update(thisLoop_iter.PairCorrelTuple); //Cards 17 & 18
        //JSON["temperatures"].append(JSON_this_temp);
      }
      else {
        //nlohmann::json JSON_this_temp = JSON["temperatures"].back();
        //JSON_this_temp["temperature"] = std::abs(thisTemp);
        //JSON["temperatures"].append(JSON_this_temp);
      }
  }
  JSON = { "temperatures", temperatures };
}




/*
inline void to_json( nlohmann::json& JSON, const LEAPR::TempLoop& tempLoop){
  JSON = { "temperatures", {} };
  for (auto& tempLoop_iter : tempLoop){
      auto thisTemp = std::get<0>(tempLoop_iter).temp.value;
      if (thisTemp > 0){
        //nlohmann::json JSON_this_temp = std::get<0>(tempLoop_iter);//.Card10;
        nlohmann::json JSON_this_temp = std::get<0>(tempLoop_iter);//.Card10;
        //JSON_this_temp.update(tempLoop_iter.Card11);
        //JSON_this_temp.update(tempLoop_iter.Card12);
        //JSON_this_temp.update(tempLoop_iter.Card13);
        //JSON_this_temp["nd"] = thisLoop_iter.Card14.nd.value();
        //JSON_this_temp.update(thisLoop_iter.OscillatorTuple); //Cards 15 & 16
        //JSON_this_temp.update(thisLoop_iter.PairCorrelTuple); //Cards 17 & 18
        //JSON["temperatures"].append(JSON_this_temp);
      }
      else {
        //nlohmann::json JSON_this_temp = JSON["temperatures"].back();
        //JSON_this_temp["temperature"] = std::abs(thisTemp);
        //JSON["temperatures"].append(JSON_this_temp);
      }
  }
}
*/



/*

inline void to_json( nlohmann::json& JSON, const std::optional<LEAPR::Card19>& card19 ){
  if ( card19 ){
    JSON = {
      { "cfrac" , card19->cfrac.value }
    };
  }
  else {
    JSON = {
      { nlohmann::json::array() }
    };
}
*/


inline void to_json( nlohmann::json& JSON, const LEAPR& leapr ){
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
  //JSON.update( leapr.card19 );
  //JSON["comments"] = leapr.card20List;
}









