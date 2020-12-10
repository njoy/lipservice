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
    auto controlTuple = *(card6.controlTuple);
    JSON = { 
      { "nss" , card6.nss.value          },
      { "b7"  , controlTuple.b7.value    },
      { "aws" , controlTuple.aws.value   },
      { "sps" , controlTuple.sps.value   },
      { "mss" , controlTuple.mss.value   }
    };

  }
  else {
    JSON = { 
      { "nss", card6.nss.value  },
    };
  }
}


inline void to_json( nlohmann::json& JSON, const LEAPR::Card7& card7 ){
  JSON = { 
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

inline void to_json( nlohmann::json& JSON, const LEAPR::Card11& card11 ){
  JSON = { 
    { "delta", card11.delta.value },
  };
}

inline void to_json( nlohmann::json& JSON, const LEAPR::Card12& card12 ){
  JSON = { 
    { "rho", card12.rho.value }
  };
}

inline void to_json( nlohmann::json& JSON, const LEAPR::Card13& card13 ){
  JSON = { 
    { "twt",   card13.twt.value },
    { "c",     card13.c.value },
    { "tbeta", card13.tbeta.value }
  };
}


inline void to_json( nlohmann::json& JSON, 
              const std::optional<LEAPR::OscillatorTuple>& oscillatorTuple ){
  if (oscillatorTuple){
    JSON = { 
      { "energies", std::get<0>(*oscillatorTuple).oe.value },
      { "weights" , std::get<1>(*oscillatorTuple).ow.value }
    };
  }
  else {
    JSON =  nlohmann::json:: array();
  } 
}



inline void to_json( nlohmann::json& JSON, 
          const std::optional<LEAPR::PairCorrelTuple>& pairCorrelationTuple){
  if (pairCorrelationTuple){
    JSON = { 
      { "dka"   , std::get<0>(*pairCorrelationTuple).dka.value },
      { "skappa", std::get<1>(*pairCorrelationTuple).skappa.value }
    };
  }
  else {
    JSON = { nlohmann::json::array() };
  }
}



inline nlohmann::json make_json( const LEAPR::TempLoopIter& temp ){
    nlohmann::json JSON = {
      { "temperature", std::get<0>(temp).temp.value } // Card 10
    };

    auto tempTuple = std::get<1>(temp);
    if (tempTuple){
      JSON.update(std::get<0>(*tempTuple)); //Card 11
      JSON.update(std::get<1>(*tempTuple)); //Card 12
      JSON.update(std::get<2>(*tempTuple)); //Card 13
      auto oscillatorTuple = std::get<4>(*tempTuple); // Cards 14 & 15
      JSON["oscillators"] = oscillatorTuple;
      auto pairCorrelationTuple = std::get<5>( *tempTuple ); // Cards 16 & 17
      JSON["pairCorrelation"] = pairCorrelationTuple;
    }
    return JSON;

}

inline void to_json( nlohmann::json& JSON, const LEAPR::TempLoop& tempLoop){
  auto temperatures = nlohmann::json::array();
  for (auto& tempLoop_iter : tempLoop){
      auto thisTemp = std::get<0>(tempLoop_iter).temp.value;
      if (thisTemp > 0){
        temperatures.push_back(make_json(tempLoop_iter));
      }
      else {
        auto lastTemperatureInfo = temperatures[temperatures.size()-1];
        lastTemperatureInfo["temperature"] = std::abs(thisTemp);
        temperatures.push_back(lastTemperatureInfo);
      }
  }
  JSON = { { "temperatures", temperatures } };
}


inline void to_json( nlohmann::json& JSON, 
                     const std::optional<LEAPR::Card19>& card19 ){
  if ( card19 ){
    JSON = card19->cfrac.value;
  }
  else {
    JSON = nlohmann::json::array();
  }
}

inline void to_json( nlohmann::json& JSON, const std::vector<LEAPR::Card20>& card20List ){
  if ( card20List.size() > 0 ){
    std::vector<std::string> card20Values;
    for (const auto& card : card20List){
      card20Values.push_back( *(card.comment.value) );
    }
    JSON = card20Values;
  }
  else {
    JSON = nlohmann::json::array();
  }
}

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
  JSON.update( leapr.tempLoop );
  JSON["cfrac"] = leapr.card19;
  JSON["comments"] = leapr.card20List;
}
