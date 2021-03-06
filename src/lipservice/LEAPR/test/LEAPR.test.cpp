#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "lipservice.hpp"
#include "tsl-SiO2-alpha.h"

using namespace njoy::njoy21::lipservice;

SCENARIO( "LEAPR input",
  "[LEAPR]" ){
  std::string card1         = "20/\n";
  std::string card2         = "'graphite, endf model'/\n";
  std::string card3_1_temp  = "1 0 101/\n";
  std::string card3_2_temps = "2 0 101/\n";
  std::string card4         = "31 6012 1 1/\n";
  std::string card5_vineyard = "11.898 4.7392 1 1 1 1/\n";
  std::string card5_skold    = "11.898 4.7392 1 1 1 2/\n";
  std::string card5_plain    = "11.898 4.7392 1 1 0 0/\n";
  std::string card6_no_secondary_scatter = "0/\n";
  std::string card7         = "3 5 1/\n";
  std::string card8         = "2.5e-1 7.5e-1 1.0/\n"; 
  std::string card9         = "0.0 0.2 0.4 0.6 0.8/\n";
  std::string card20        = "'test run for njoy leapr'\n"
                              "' where this fun comment spans'\n" 
                              "' multiple lines.'/\n";       
	  
  GIVEN( "valid LEAPR input" ){
    WHEN( "b7 = 0 [sct treatment for secondary scatterer]" ){
      AND_WHEN( "temperature loop specifications are identical" ){
        iRecordStream<char> iss( (std::istringstream(tslSiO2)) );
        LEAPR leapr( iss );
        REQUIRE( leapr.card1.nout.value == 24 );
        REQUIRE( leapr.card2.title.value == "Si_qtz, ENDF MODEL (EXTENDED)" );
        REQUIRE( leapr.card3.ntempr.value == 5 );

        REQUIRE( leapr.card6.controlTuple );
        auto ct = *( leapr.card6.controlTuple );
        REQUIRE( ct.b7.value  == 0      );
        REQUIRE( ct.aws.value == 15.862 );
        REQUIRE( ct.sps.value == 7.4975 );
        REQUIRE( ct.mss.value == 1      );

        THEN( "temperature loop is repeated identically" ){
          REQUIRE( leapr.tempLoop.size() == 2*leapr.card3.ntempr.value );
          std::vector<double> temps {293.6, -350.0, -400.0, -500.0, -800.0, 
                                     293.6, -350.0, -400.0, -500.0, -800.0 },
                             deltas {8.27e-4, 0, 0, 0, 0, 8.27e-4, 0, 0, 0, 0};
          std::vector<int> ni { 185, 0, 0, 0, 0, 185, 0, 0, 0, 0 };

          for (size_t i = 0; i < temps.size(); ++i){
            const auto& loop = leapr.tempLoop[i];
            const auto& card10    = std::get<0>( loop );
            REQUIRE( card10.temp.value  == temps[i] );

            const auto& tempTuple = std::get<1>( loop );
            const auto& card11    = std::get<0>( *tempTuple );

            REQUIRE( card11.delta.value  == deltas[i] );
            REQUIRE( card11.ni.value     == ni[i] );

          }

          THEN( "json can be correctly constructed" ){
            nlohmann::json json( leapr );
            int ntempr = json["ntempr"];
            REQUIRE( json["temperatures"].size() == 2*ntempr );
  
          } // THEN
        } // THEN
      } // AND WHEN
    } // WHEN

    WHEN( "single temp loop, no secondary scatterer (card6 nss = 0)" ){
      iRecordStream<char> iss( std::istringstream(
        card1 +                                 // Card1
        card2 +                                 // Card2
        card3_1_temp +                          // Card3
        card4 +                                 // Card4
        card5_skold +                           // Card5
        card6_no_secondary_scatter +            // Card6
        card7 +                                 // Card7
        card8 +                                 // Card8
        card9 +                                 // Card9
        "293/\n"                                // Card10 --
        ".03 4/\n"                              // Card11  |
        "1.0 2.0 3.0 4.0/\n"                    // Card12  |
        "0.0192 0.0 0.4904/\n"                  // Card13  |
        "2/\n"                                  // Card14  |- Temp Loop 1
        "0.205 0.436/\n"                        // Card15  |
        "0.163467 0.326933/\n"                  // Card16  |
        "2 0.001/\n"                            // Card17  |
        "1.5 2.0/\n"                            // Card18 -- 
        "0.1/\n" +                              // Card19 
        card20 +
        "/ "
      ) );

      THEN( "all cards have the correct values" ){
        LEAPR leapr( iss );
        REQUIRE( leapr.card1.nout.value == 20 );

        REQUIRE( leapr.card2.title.value == "graphite, endf model" );

        REQUIRE( leapr.card3.ntempr.value == 1   );
        REQUIRE( leapr.card3.iprint.value == 0   );
        REQUIRE( leapr.card3.nphon.value  == 101 );

        REQUIRE( leapr.card4.mat.value   == 31     );
        REQUIRE( leapr.card4.za.value    == 6012.0 );
        REQUIRE( leapr.card4.isabt.value == 1      );
        REQUIRE( leapr.card4.ilog.value  == 1      );
        REQUIRE( leapr.card4.smin.value  == 1e-75  );
      
        REQUIRE( leapr.card5.awr.value   == 11.898 );
        REQUIRE( leapr.card5.spr.value   == 4.7392 );
        REQUIRE( leapr.card5.npr.value   == 1 );
        REQUIRE( leapr.card5.iel.value   == 1 );
        REQUIRE( leapr.card5.ncold.value == 1 );
        REQUIRE( leapr.card5.nsk.value   == 2 );
      
        REQUIRE( leapr.card6.nss.value == 0   );
        REQUIRE( not leapr.card6.controlTuple );

        REQUIRE( leapr.card7.nalpha.value == 3 );
        REQUIRE( leapr.card7.nbeta.value  == 5 );
        REQUIRE( leapr.card7.lat.value    == 1 );

        std::vector<double> refAlphas = { 0.25, 0.75, 1.0 };
        std::vector<double> refBetas  = { 0.0, 0.2, 0.4, 0.6, 0.8 };

        REQUIRE( leapr.card8.alpha.value.size() == 3 );
        REQUIRE( leapr.card9.beta.value.size()  == 5 );
        
        REQUIRE( leapr.card8.alpha.value == refAlphas );
        REQUIRE( leapr.card9.beta.value  == refBetas  );

        // ENTERING TEMP LOOP 1
        REQUIRE( leapr.tempLoop.size() == 1 );

        const auto& loop1 = leapr.tempLoop[0];

        const auto& card10 = std::get<0>( loop1 );
        const auto& tempTuple = std::get<1>( loop1 );
        const auto& card11 = std::get<0>( *tempTuple );
        const auto& card12 = std::get<1>( *tempTuple );
        const auto& card13 = std::get<2>( *tempTuple );
        const auto& card14 = std::get<3>( *tempTuple );
        const auto& oscillatorTuple = std::get<4>( *tempTuple   );
        const auto& card15 = std::get<0>( *oscillatorTuple );
        const auto& card16 = std::get<1>( *oscillatorTuple );
        const auto& pairCorrelTuple = std::get<5>( *tempTuple   );
        const auto& card17 = std::get<0>( *pairCorrelTuple );
        const auto& card18 = std::get<1>( *pairCorrelTuple );
        const auto& card19 = std::get<2>( *pairCorrelTuple );

        REQUIRE( card10.temp.value  == 293.0 );
        REQUIRE( card11.delta.value == 0.03 );
        REQUIRE( card11.ni.value    == 4 );
        std::vector<double> refRho = { 1.0, 2.0, 3.0, 4.0 };
        REQUIRE( card12.rho.value   == refRho ); 
        REQUIRE( card13.twt.value   == 0.0192 );
        REQUIRE( card13.c.value     == 0.0    );
        REQUIRE( card13.tbeta.value == 0.4904 );
        REQUIRE( card14.nd.value    == 2      );
        std::vector< double > 
          refOes = { 0.205, 0.436 };
        REQUIRE( card15.oe.value    == refOes        );
        std::vector< double > refOws = { 0.163467, 0.326933 };
        REQUIRE( card16.ow.value    == refOws );
        REQUIRE( card17.nka.value   == 2      );
        REQUIRE( card17.dka.value   == 0.001 );
        std::vector< double > refSkappas{ 1.5, 2.0 };
        REQUIRE( card18.skappa.value == refSkappas );
        REQUIRE( card19->cfrac.value == 0.1 );
        // FINISHED TEMP LOOP 1

        std::string refCard20_0 = "test run for njoy leapr";
        std::string refCard20_1 = " where this fun comment spans";
        std::string refCard20_2 = " multiple lines.";
        const auto& card20_0 = leapr.card20List[0];
        const auto& card20_1 = leapr.card20List[1];
        const auto& card20_2 = leapr.card20List[2];
        REQUIRE( *(card20_0.comment.value) == refCard20_0 );
        REQUIRE( *(card20_1.comment.value) == refCard20_1 );
        REQUIRE( *(card20_2.comment.value) == refCard20_2 );

        AND_THEN( "LEAPR can be turned into JSON" ){
          nlohmann::json refJSON = R"({
            "nout"  :  20,
            "title" : "graphite, endf model",
            "ntempr":  1,
            "iprint":  0,
            "nphon" :  101,
            "mat"   :  31,
            "za"    :  6012,
            "isabt" :  1,
            "ilog"  :  1,
            "smin"  :  1e-75,
            "awr"   :  11.898,
            "spr"   :  4.7392,
            "npr"   :  1,
            "iel"   :  1,
            "ncold" :  1,
            "nsk"   :  2,
            "nss"   :  0,
            "lat"   :  1,
            "alpha" :  [2.5e-1, 7.5e-1, 1.0],
            "beta"  :  [0.0, 0.2, 0.4, 0.6, 0.8],
            "temperatures" : [
              {
                "temperature"     :  293,
                "delta"           :  0.03,
                "rho"             :  [ 1.0, 2.0, 3.0, 4.0  ],
                "twt"             :  0.0192,
                "c"               :  0.0,
                "tbeta"           :  0.4904,
                "oscillators"     :  { "energies" : [0.205   , 0.436   ],
                                       "weights"  : [0.163467, 0.326933]  },
                "pairCorrelation" : { "dka"    : 0.001,
                                      "skappa" : [1.5, 2.0],
                                      "cfrac"  : 0.1 }
              }
            ],
            "comments" :  [ "test run for njoy leapr",
                            " where this fun comment spans",
                            " multiple lines." ]
          })"_json;
          CHECK( refJSON == nlohmann::json( leapr ) );
        } // AND THEN
      } // THEN
    } // WHEN

    WHEN( "single temp loop, no secondary scatterer & no kappas & no comments" ){
      iRecordStream<char> iss( std::istringstream(
        card1 +                                 // Card1
        card2 +                                 // Card2
        card3_1_temp +                          // Card3
        card4 +                                 // Card4
        card5_plain +                           // Card5
        card6_no_secondary_scatter +            // Card6
        card7 +                                 // Card7
        card8 +                                 // Card8
        card9 +                                 // Card9
        "293/\n"                                // Card10 --
        ".03 4/\n"                              // Card11  |
        "1.0 2.0 3.0 4.0/\n"                    // Card12  |
        "0.0192 0.0 0.4904/\n"                  // Card13  |
        "2/\n"                                  // Card14  |- Temp Loop 1
        "0.205 0.436/\n"                        // Card15  |
        "0.163467 0.326933/\n"                  // Card16 -|
        "/ "
      ) );

      THEN( "all cards have the correct values" ){
        LEAPR leapr( iss );
        REQUIRE( leapr.card1.nout.value == 20 );

        REQUIRE( leapr.card2.title.value == "graphite, endf model" );

        REQUIRE( leapr.card3.ntempr.value == 1   );
        REQUIRE( leapr.card3.iprint.value == 0   );
        REQUIRE( leapr.card3.nphon.value  == 101 );

        REQUIRE( leapr.card4.mat.value   == 31     );
        REQUIRE( leapr.card4.za.value    == 6012.0 );
        REQUIRE( leapr.card4.isabt.value == 1      );
        REQUIRE( leapr.card4.ilog.value  == 1      );
        REQUIRE( leapr.card4.smin.value  == 1e-75  );
      
        REQUIRE( leapr.card5.awr.value   == 11.898 );
        REQUIRE( leapr.card5.spr.value   == 4.7392 );
        REQUIRE( leapr.card5.npr.value   == 1 );
        REQUIRE( leapr.card5.iel.value   == 1 );
        REQUIRE( leapr.card5.ncold.value == 0 );
        REQUIRE( leapr.card5.nsk.value   == 0 );
      
        REQUIRE( leapr.card6.nss.value == 0   );
        REQUIRE( not leapr.card6.controlTuple );

        REQUIRE( leapr.card7.nalpha.value == 3 );
        REQUIRE( leapr.card7.nbeta.value  == 5 );
        REQUIRE( leapr.card7.lat.value    == 1 );

        std::vector<double> refAlphas = { 0.25, 0.75, 1.0 };
        std::vector<double> refBetas  = { 0.0, 0.2, 0.4, 0.6, 0.8 };

        REQUIRE( leapr.card8.alpha.value.size() == 3 );
        REQUIRE( leapr.card9.beta.value.size()  == 5 );
        
        REQUIRE( leapr.card8.alpha.value == refAlphas );
        REQUIRE( leapr.card9.beta.value  == refBetas  );

        // ENTERING TEMP LOOP 1
        REQUIRE( leapr.tempLoop.size() == 1 );

        const auto& loop1 = leapr.tempLoop[0];

        const auto& card10    = std::get<0>( loop1 );
        const auto& tempTuple = std::get<1>( loop1 );
        const auto& card11    = std::get<0>( *tempTuple );
        const auto& card12    = std::get<1>( *tempTuple );
        const auto& card13    = std::get<2>( *tempTuple );
        const auto& card14    = std::get<3>( *tempTuple );
        const auto& oscillatorTuple = std::get<4>( *tempTuple );
        const auto& card15    = std::get<0>( *oscillatorTuple );
        const auto& card16    = std::get<1>( *oscillatorTuple );
        const auto& pairCorrelTuple = std::get<5>( *tempTuple );

        REQUIRE( not pairCorrelTuple );

        REQUIRE( card10.temp.value  == 293.0 );
        REQUIRE( card11.delta.value == 0.03 );
        REQUIRE( card11.ni.value    == 4 );
        std::vector<double> refRho = { 1.0, 2.0, 3.0, 4.0 };
        REQUIRE( card12.rho.value   == refRho ); 
        REQUIRE( card13.twt.value   == 0.0192 );
        REQUIRE( card13.c.value     == 0.0    );
        REQUIRE( card13.tbeta.value == 0.4904 );
        REQUIRE( card14.nd.value    == 2      );
        std::vector< double > 
          refOes = { 0.205, 0.436 };
        REQUIRE( card15.oe.value    == refOes        );
        std::vector< double > refOws = { 0.163467, 0.326933 };
        REQUIRE( card16.ow.value    == refOws );

        REQUIRE( leapr.card20List.size() == 0 );

        AND_THEN( "LEAPR can be turned into JSON" ){
          nlohmann::json refJSON = R"({
            "nout"  :  20,
            "title" : "graphite, endf model",
            "ntempr":  1,
            "iprint":  0,
            "nphon" :  101,
            "mat"   :  31,
            "za"    :  6012,
            "isabt" :  1,
            "ilog"  :  1,
            "smin"  :  1e-75,
            "awr"   :  11.898,
            "spr"   :  4.7392,
            "npr"   :  1,
            "iel"   :  1,
            "ncold" :  0,
            "nsk"   :  0,
            "nss"   :  0,
            "lat"   :  1,
            "alpha" :  [2.5e-1, 7.5e-1, 1.0],
            "beta"  :  [0.0, 0.2, 0.4, 0.6, 0.8],
            "temperatures" : [
              {
                "temperature" :  293,
                "delta"       :  0.03,
                "rho"         :  [ 1.0, 2.0, 3.0, 4.0  ],
                "twt"         :  0.0192,
                "c"           :  0.0,
                "tbeta"       :  0.4904,
                "oscillators" :  { "energies" : [0.205   , 0.436   ],
                                   "weights"  : [0.163467, 0.326933]  },
                "pairCorrelation" : null
               }
            ],
            "comments" :  [ ]
          })"_json;
          CHECK( refJSON == nlohmann::json( leapr ) );
        } // AND THEN
      } // THEN
    } // WHEN





    WHEN( "temp specific inputs (Card11-18) provided for two temps" ){
      iRecordStream<char> iss( std::istringstream(
        card1 +                                 // Card1
        card2 +                                 // Card2
        card3_2_temps +                         // Card3
        card4 +                                 // Card4
        card5_vineyard +                        // Card5
        card6_no_secondary_scatter +            // Card6
        card7 +                                 // Card7
        card8 +                                 // Card8
        card9 +                                 // Card9
        "293/\n"                                // Card10 --
        ".03 4\n"                               // Card11  |
        "1.0 2.0 3.0 4.0\n"                     // Card12  |
        "0.0192 0.0 0.4904\n"                   // Card13  |
        "2\n"                                   // Card14  |- Temp Loop 1
        "0.205 0.436\n"                         // Card15  |
        "0.163467 0.326933\n"                   // Card16  |
        "2 0.001\n"                             // Card17  |
        "1.5 2.0\n"                             // Card18 --
        "300/\n"                                // Card10 --
        ".02 3\n"                               // Card11  |
        "2.0 4.0 6.0\n"                         // Card12  |- Temp Loop 2
        "0.2 0.0 0.5\n"                         // Card13  |
        "0\n"                                   // Card14, no Card15 or Card16
        "3 0.002\n"                             // Card17  |
        "2.0 2.5 3.0\n" +                       // Card18 --
        card20 +
        "/ "
      ) );

      THEN( "all cards have the correct values" ){
        LEAPR leapr( iss );

        REQUIRE( leapr.card3.ntempr.value == 2   );

        REQUIRE( leapr.tempLoop.size() == 2 );

        const auto& loop1 = leapr.tempLoop[0];
        {
          const auto& card10 = std::get<0>( loop1 );
          const auto& tempTuple = std::get<1>( loop1 );
          const auto& card11 = std::get<0>( *tempTuple );
          const auto& card12 = std::get<1>( *tempTuple );
          const auto& card13 = std::get<2>( *tempTuple );
          const auto& card14 = std::get<3>( *tempTuple );
          const auto& oscillatorTuple = std::get<4>( *tempTuple );
          const auto& card15 = std::get<0>( *oscillatorTuple );
          const auto& card16 = std::get<1>( *oscillatorTuple );
          const auto& pairCorrelTuple = std::get<5>( *tempTuple  );
          const auto& card17 = std::get<0>( *pairCorrelTuple );
          const auto& card18 = std::get<1>( *pairCorrelTuple );
          const auto& card19 = std::get<2>( *pairCorrelTuple );

          REQUIRE( card10.temp.value  == 293.0 );
          REQUIRE( card11.delta.value == 0.03 );
          REQUIRE( card11.ni.value    == 4 );
          std::vector<double> refRho = { 1.0, 2.0, 3.0, 4.0 };
          REQUIRE( card12.rho.value   == refRho ); 
          REQUIRE( card13.twt.value   == 0.0192 );
          REQUIRE( card13.c.value     == 0.0    );
          REQUIRE( card13.tbeta.value == 0.4904 );
          REQUIRE( card14.nd.value    == 2      );
          std::vector< double > 
            refOes = { 0.205, 0.436 };
          REQUIRE( card15.oe.value    == refOes        );
          std::vector< double > refOws = { 0.163467, 0.326933 };
          REQUIRE( card16.ow.value    == refOws );
          REQUIRE( card17.nka.value   == 2      );
          REQUIRE( card17.dka.value   == 0.001 );
          std::vector< double > refSkappas{ 1.5, 2.0 };
          REQUIRE( card18.skappa.value == refSkappas );
          REQUIRE( not card19 );
       
        }
    
        const auto& loop2 = leapr.tempLoop[1];
        {
          const auto& card10 = std::get<0>( loop2 );
          const auto& tempTuple = std::get<1>( loop2 );
          const auto& card11 = std::get<0>( *tempTuple );
          const auto& card12 = std::get<1>( *tempTuple );
          const auto& card13 = std::get<2>( *tempTuple );
          const auto& card14 = std::get<3>( *tempTuple );
          const auto& oscillatorTuple = std::get<4>( *tempTuple );
          const auto& pairCorrelTuple = std::get<5>( *tempTuple );
          const auto& card17 = std::get<0>( *pairCorrelTuple );
          const auto& card18 = std::get<1>( *pairCorrelTuple );
          const auto& card19 = std::get<2>( *pairCorrelTuple );

          REQUIRE( card10.temp.value  == 300.0 );
          REQUIRE( card11.delta.value == 0.02 );
          REQUIRE( card11.ni.value    == 3   );
          std::vector<double> refRho = { 2.0, 4.0, 6.0 };
          REQUIRE( card12.rho.value   == refRho        ); 
          REQUIRE( card13.twt.value   == 0.2 );
          REQUIRE( card13.c.value     == 0.0 );
          REQUIRE( card13.tbeta.value == 0.5 );
          REQUIRE( card14.nd.value    == 0   );
          REQUIRE( not oscillatorTuple );
          REQUIRE( card17.nka.value  == 3    );
          REQUIRE( card17.dka.value  == 0.002 );
          std::vector< double > refSkappas{ 2.0, 2.5, 3.0 };
          REQUIRE( card18.skappa.value == refSkappas );
          REQUIRE( not card19 );
        }
        AND_THEN( "LEAPR can be turned into JSON" ){
          nlohmann::json refJSON = R"({
            "nout"  : 20,
            "title" : "graphite, endf model",
            "ntempr": 2,
            "iprint": 0,
            "nphon" : 101,
            "mat"   : 31,
            "za"    : 6012,
            "isabt" : 1,
            "ilog"  : 1,
            "smin"  : 1e-75,
            "awr"   : 11.898,
            "spr"   : 4.7392,
            "npr"   : 1,
            "iel"   : 1,
            "ncold" : 1,
            "nsk"   : 1,
            "nss"   : 0,
            "lat"   : 1,
            "alpha" : [2.5e-1, 7.5e-1, 1.0],
            "beta"  : [0.0, 0.2, 0.4, 0.6, 0.8],
            "temperatures" : [
              {
                "temperature" : 293.0,
                "delta"       : 0.03,
                "rho"         : [ 1.0, 2.0, 3.0, 4.0  ],
                "twt"         : 0.0192,
                "c"           : 0.0,
                "tbeta"       : 0.4904,
                "oscillators" : { "energies" : [0.205, 0.436],
                                  "weights"  : [0.163467, 0.326933] },
                "pairCorrelation" : { "dka"    : 0.001,
                                      "skappa" : [1.5, 2.0] }
              },
              {
                "temperature" : 300.0,
                "delta"       : 0.02,
                "rho"         : [ 2.0, 4.0, 6.0 ],
                "twt"         : 0.2,
                "c"           : 0.0,
                "tbeta"       : 0.5,
                "oscillators" : null,
                "pairCorrelation" : { "dka"    : 0.002,
                                      "skappa" : [2.0, 2.5, 3.0] }
              }
            ],
          "comments" : [ "test run for njoy leapr",
                         " where this fun comment spans",
                         " multiple lines." ]
          })"_json;
          CHECK( refJSON == nlohmann::json( leapr ) );
        } // AND THEN

      } // THEN
      WHEN( "two temp loops, with secondary scatterer (card6 nss = 1)" ){
        iRecordStream<char> iss( std::istringstream(
          card1 +                                 // Card1
          card2 +                                 // Card2
          card3_2_temps +                         // Card3
          card4 +                                 // Card4
          card5_vineyard +                        // Card5
          "1 1 15.87 3.84 1/ \n" +                // Card6
          card7 +                                 // Card7
          card8 +                                 // Card8
          card9 +                                 // Card9
          "293/\n"                                // Card10 --
          ".03 4\n"                               // Card11  |
          "1.0 2.0 3.0 4.0\n"                     // Card12  |
          "0.0192 0.0 0.4904\n"                   // Card13  |
          "2\n"                                   // Card14  |- Temp Loop 1
          "0.205 0.436\n"                         // Card15  |
          "0.163467 0.326933\n"                   // Card16  |
          "2 0.001\n"                             // Card17  |
          "1.5 2.0\n"                             // Card18 --
          "300/\n"                                // Card10 --
          ".02 3\n"                               // Card11  |
          "2.0 4.0 6.0\n"                         // Card12  |- Temp Loop 2
          "0.2 0.0 0.5\n"                         // Card13  |
          "0\n"                                   // Card14, no Card15 or Card16
          "3 0.002\n"                             // Card17  |
          "2.0 2.5 3.0\n" +                       // Card18 --
          card20 +
          "/ "
        ) );
        
        THEN( "all cards have the correct values" ){
          LEAPR leapr( iss );
          REQUIRE( leapr.card6.nss.value == 1 );
          REQUIRE( leapr.card6.controlTuple );
          auto ct = *( leapr.card6.controlTuple );
          REQUIRE( ct.b7.value == 1 );
          REQUIRE( ct.aws.value == 15.87 );
          REQUIRE( ct.sps.value == 3.84 );
          REQUIRE( ct.mss.value == 1 );

          AND_THEN( "LEAPR can be turned into JSON" ){
            nlohmann::json refJSON = R"({
              "nout"   : 20,
              "title"  : "graphite, endf model",
              "ntempr" : 2,
              "iprint" : 0,
              "nphon"  : 101,
              "mat"    : 31,
              "za"     : 6012,
              "isabt"  : 1,
              "ilog"   : 1,
              "smin"   : 1e-75,
              "awr"    : 11.898,
              "spr"    : 4.7392,
              "npr"    : 1,
              "iel"    : 1,
              "ncold"  : 1,
              "nsk"    : 1,
              "nss"    : 1,
              "b7"     : 1,
              "aws"    : 15.87,
              "sps"    : 3.84,
              "mss"    : 1,
              "lat"    : 1,
              "alpha"  : [2.5e-1, 7.5e-1, 1.0],
              "beta"   : [0.0, 0.2, 0.4, 0.6, 0.8],
              "temperatures" : [
                {
                  "temperature" : 293.0,
                  "delta"       : 0.03,
                  "rho"         : [ 1.0, 2.0, 3.0, 4.0  ],
                  "twt"         : 0.0192,
                  "c"           : 0.0,
                  "tbeta"       : 0.4904,
                  "oscillators" : { "energies" : [0.205, 0.436],
                                    "weights"  : [0.163467, 0.326933] },
                "pairCorrelation" : { "dka"    : 0.001,
                                      "skappa" : [1.5, 2.0] }
                },
                {
                  "temperature" : 300.0,
                  "delta"       : 0.02,
                  "rho"         : [ 2.0, 4.0, 6.0 ],
                  "twt"         : 0.2,
                  "c"           : 0.0,
                  "tbeta"       : 0.5,
                  "oscillators" : null,
                  "pairCorrelation" : { "dka"    : 0.002,
                                        "skappa" : [2.0, 2.5, 3.0] }
                }
              ],
              "comments" : ["test run for njoy leapr",
                            " where this fun comment spans",
                            " multiple lines."]
              })"_json;
            CHECK( refJSON == nlohmann::json( leapr ) );
          } // AND THEN

        } // THEN

      } // WHEN
    } // WHEN
    WHEN( "two temp loops, first temp is positive second temp negative" ){
      iRecordStream<char> iss( std::istringstream(
        card1 +                                 // Card1
        card2 +                                 // Card2
        card3_2_temps +                         // Card3
        card4 +                                 // Card4
        card5_vineyard +                        // Card5
        card6_no_secondary_scatter +            // Card6
        card7 +                                 // Card7
        card8 +                                 // Card8
        card9 +                                 // Card9
        "293/\n"                                // Card10 --
        ".03 4\n"                               // Card11  |
        "1.0 2.0 3.0 4.0\n"                     // Card12  |
        "0.0192 0.0 0.4904\n"                   // Card13  |
        "2\n"                                   // Card14  |- Temp Loop 1
        "0.205 0.436\n"                         // Card15  |
        "0.163467 0.326933\n"                   // Card16  |
        "2 0.001\n"                             // Card17  |
        "1.5 2.0\n"                             // Card18 --
        "-300/\n" +                             // Card10 -- Temp Loop 2
        card20 +
        "/ "
      ) );
      
      LEAPR leapr( iss );

      THEN( "temp loop one reads in cards 11-18, temp loop 2 does not" ){
        REQUIRE( leapr.tempLoop.size() == 2 );
        {
          const auto& loop1 = leapr.tempLoop[0];
          const auto& card10 = std::get<0>( loop1 );
          const auto& tempTuple = std::get<1>( loop1 );
          const auto& card11 = std::get<0>( *tempTuple );
          const auto& card12 = std::get<1>( *tempTuple );
          const auto& card13 = std::get<2>( *tempTuple );
          const auto& card14 = std::get<3>( *tempTuple );
          const auto& oscillatorTuple = std::get<4>( *tempTuple );
          const auto& card15 = std::get<0>( *oscillatorTuple );
          const auto& card16 = std::get<1>( *oscillatorTuple );
          const auto& pairCorrelTuple = std::get<5>( *tempTuple  );
          const auto& card17 = std::get<0>( *pairCorrelTuple );
          const auto& card18 = std::get<1>( *pairCorrelTuple );

          REQUIRE( card10.temp.value  == 293.0 );
          REQUIRE( card11.delta.value == 0.03 );
          REQUIRE( card11.ni.value    == 4 );
          std::vector<double> refRho = { 1.0, 2.0, 3.0, 4.0 };
          REQUIRE( card12.rho.value   == refRho ); 
          REQUIRE( card13.twt.value   == 0.0192 );
          REQUIRE( card13.c.value     == 0.0    );
          REQUIRE( card13.tbeta.value == 0.4904 );
          REQUIRE( card14.nd.value    == 2      );
          std::vector< double > 
            refOes = { 0.205, 0.436 };
          REQUIRE( card15.oe.value    == refOes        );
          std::vector< double > refOws = { 0.163467, 0.326933 };
          REQUIRE( card16.ow.value    == refOws );
          REQUIRE( card17.nka.value   == 2      );
          REQUIRE( card17.dka.value   == 0.001 );
          std::vector< double > refSkappas{ 1.5, 2.0 };
          REQUIRE( card18.skappa.value == refSkappas );
        }

        {
          const auto& loop2 = leapr.tempLoop[1];
          const auto& card10 = std::get<0>( loop2 );
          const auto& tempTuple = std::get<1>( loop2 );
          REQUIRE( card10.temp.value == -300 );
          REQUIRE( not tempTuple );
        }

          AND_THEN( "LEAPR can be turned into JSON" ){
            nlohmann::json refJSON = R"({
              "nout"   : 20,
              "title"  : "graphite, endf model",
              "ntempr" : 2,
              "iprint" : 0,
              "nphon"  : 101,
              "mat"    :  31,
              "za"     :  6012,
              "isabt"  :  1,
              "ilog"   :  1,
              "smin"   :  1e-75,
              "awr"    :  11.898,
              "spr"    :  4.7392,
              "npr"    :  1,
              "iel"    :  1,
              "ncold"  :  1,
              "nsk"    :  1,
              "nss"    :  0,
              "lat"    :  1,
              "alpha"  : [2.5e-1, 7.5e-1, 1.0],
              "beta"   : [0.0, 0.2, 0.4, 0.6, 0.8],
              "temperatures" : [
                {
                  "temperature" : 293.0,
                  "delta"       : 0.03,
                  "rho"         : [ 1.0, 2.0, 3.0, 4.0  ],
                  "twt"         : 0.0192,
                  "c"           : 0.0,
                  "tbeta"       : 0.4904,
                  "oscillators" : { "energies" : [0.205, 0.436],
                                    "weights"  : [0.163467, 0.326933] },
                  "pairCorrelation" : { "dka"    : 0.001,
                                        "skappa" : [1.5, 2.0] }
                },
                {
                  "temperature" : 300.0,
                  "delta"       : 0.03,
                  "rho"         : [ 1.0, 2.0, 3.0, 4.0  ],
                  "twt"         : 0.0192,
                  "c"           : 0.0,
                  "tbeta"       : 0.4904,
                  "oscillators" : { "energies" : [0.205, 0.436],
                                    "weights"  : [0.163467, 0.326933] },
                  "pairCorrelation" : { "dka"    : 0.001,
                                        "skappa" : [1.5, 2.0] }
                }
              ],
              "comments" : [ "test run for njoy leapr",
                             " where this fun comment spans",
                             " multiple lines."]
              })"_json;
            CHECK( refJSON == nlohmann::json( leapr ) );
          } // AND THEN


      } // THEN

    } // WHEN
  } // GIVEN

  GIVEN( "invalid LEAPR input" ){
    WHEN( "ntempr conflicts with given number of temps" ){
      iRecordStream<char> iss( std::istringstream(
        card1 +                                 // Card1
        card2 +                                 // Card2
        card3_2_temps +                         // Card3
        card4 +                                 // Card4
        card5_vineyard +                        // Card5
        card6_no_secondary_scatter +            // Card6
        card7 +                                 // Card7
        card8 +                                 // Card8
        card9 +                                 // Card9
        "293/\n"                                // Card10 --
        ".03 4\n"                               // Card11  |
        "1.0 2.0 3.0 4.0\n"                     // Card12  |
        "0.0192 0.0 0.4904\n"                   // Card13  |
        "2\n"                                   // Card14  |- Temp Loop 1
        "0.205 0.436\n"                         // Card15  |
        "0.163467 0.326933\n"                   // Card16  |
        "2 0.001\n"                             // Card17  |
        "1.5 2.0\n" +                           // Card18 --
        card20 +
        "/ "
      ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR( iss ) );
      } // THEN
    } // WHEN
    WHEN( "card6 nss conflicts with rest of output" ){
      iRecordStream<char> iss( std::istringstream(
        card1 +                                 // Card1
        card2 +                                 // Card2
        card3_1_temp +                          // Card3
        card4 +                                 // Card4
        card5_vineyard +                        // Card5
        "1/ \n" +                               // Card6
        card7 +                                 // Card7
        card8 +                                 // Card8
        card9 +                                 // Card9
        "293/\n"                                // Card10 --
        ".03 4\n"                               // Card11  |
        "1.0 2.0 3.0 4.0\n"                     // Card12  |
        "0.0192 0.0 0.4904\n"                   // Card13  |
        "2\n"                                   // Card14  |- Temp Loop 1
        "0.205 0.436\n"                         // Card15  |
        "0.163467 0.326933\n"                   // Card16  |
        "2 0.001\n"                             // Card17  |
        "1.5 2.0\n" +                           // Card18 --
        card20 +
        "/ "
      ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR( iss ) );
      } // THEN
    } // WHEN
    WHEN( "first temperature is negative" ){
      iRecordStream<char> iss( std::istringstream(
        card1 +                                 // Card1
        card2 +                                 // Card2
        card3_1_temp +                          // Card3
        card4 +                                 // Card4
        card5_vineyard +                        // Card5
        card6_no_secondary_scatter +            // Card6
        card7 +                                 // Card7
        card8 +                                 // Card8
        card9 +                                 // Card9
        "-293/\n"                               // Card10 --
        ".03 4\n"                               // Card11  |
        "1.0 2.0 3.0 4.0\n"                     // Card12  |
        "0.0192 0.0 0.4904\n"                   // Card13  |
        "2\n"                                   // Card14  |- Temp Loop 1
        "0.205 0.436\n"                         // Card15  |
        "0.163467 0.326933\n"                   // Card16  |
        "2 0.001\n"                             // Card17  |
        "1.5 2.0\n" +                           // Card18 --
        card20 +
        "/ "
      ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( LEAPR( iss ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
