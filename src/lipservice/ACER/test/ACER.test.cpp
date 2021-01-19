#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "lipservice.hpp"
#include "range/v3/algorithm/equal.hpp"

using namespace njoy::njoy21::lipservice;

std::string sCard1( "20 21 0 30 31 /\n" );
std::string sCard3( "Here is a descriptive character string for Card3.");

SCENARIO( "Parsing valid ACER input" ){
  WHEN( "processing a 'fast' data file, iopt=1" ){

    iRecordStream<char> iss( std::istringstream( 
            sCard1
            + "1 1 1 .80 0 /\n"       // Card2
            + "'" + sCard3 + "'/\n"   // Card3
            + " 1001 293.6 /\n"       // Card5
            + " 0 1 /\n"              // Card6
            + " -1 1E4 5 /\n"         // Card7
            ) );

    THEN( "the input values can be verified" ){
      ACER acer( iss );

      // Card1
      CHECK( 20 == acer.card1.nendf.value );
      CHECK( 21 == acer.card1.npend.value );
      CHECK(  0 == acer.card1.ngend.value );
      CHECK( 30 == acer.card1.nace.value );
      CHECK( 31 == acer.card1.ndir.value );

      // Card2
      CHECK(  1 == acer.card2.iopt.value );
      CHECK(  1 == acer.card2.iprint.value );
      CHECK(  1 == acer.card2.itype.value );
      CHECK( .80 == acer.card2.suff.value );
      CHECK(  0 == acer.card2.nxtra.value );

      // Card3
      CHECK( sCard3 == acer.card3.hk.value );

      const auto& fastCards =
        std::get< ACER::FastCards >( *(acer.dataVariant) );
      
      // Card5
      const auto& card5 = std::get<0>( fastCards );
      CHECK( 1001 == card5.matd.value );
      CHECK( 293.6 == card5.tempd.value );

      // Card6
      const auto& card6 = std::get<1>( fastCards );
      CHECK( 0 == card6.newfor.value );
      CHECK( 1 == card6.iopp.value );
      CHECK( 1 == card6.ismooth.value );

      // Card7
      const auto& card7 = std::get<2>( fastCards );
      CHECK( -1 == card7.thin1.value );
      CHECK( 1E4 == card7.thin2.value );
      CHECK( 5 == card7.thin3.value );

      CHECK( not acer.card4 );
    }
  }
  WHEN( "processing a 'thermal' data file, iopt=2" ){
    GIVEN( "a NZA value" ){
      iRecordStream<char> iss( std::istringstream( 
              sCard1
              + "2 1 1 .80 2 /\n"                   // Card2
              + "'" + sCard3 + "'/\n"               // Card3
              + " 1001 0.99167 92235 233.02479 /\n" // Card4
              + " 1 293.6 'lwtr' 3 /\n"             // Card8
              + " 1001 8016 9235 /\n"               // Card8a
              + " 1 80 231 0 1 10.1 2 /"            // Card9
              ) );
      
      THEN( "the input values can be verified" ){
        ACER acer( iss );
      
        // Card1
        CHECK( 20 == acer.card1.nendf.value );
        CHECK( 21 == acer.card1.npend.value );
        CHECK(  0 == acer.card1.ngend.value );
        CHECK( 30 == acer.card1.nace.value );
        CHECK( 31 == acer.card1.ndir.value );
      
        // Card2
        CHECK(  2 == acer.card2.iopt.value );
        CHECK(  1 == acer.card2.iprint.value );
        CHECK(  1 == acer.card2.itype.value );
        CHECK( .80 == acer.card2.suff.value );
        CHECK(  2 == acer.card2.nxtra.value );
      
        // Card3
        CHECK( sCard3 == acer.card3.hk.value );
      
        // Card4
        const auto& values = acer.card4->izaw.value;
        CHECK( 1001 == values[0].first );
        CHECK( 0.99167 == values[0].second );
        CHECK( 92235 == values[1].first );
        CHECK( 233.02479 == values[1].second );
      
        const auto& thermalCards =
          std::get< ACER::ThermalCards >( *(acer.dataVariant) );
      
        // Card8
        const auto& card8 = std::get<0>( thermalCards );
        CHECK( 1 == card8.matd.value );
        CHECK( 293.6 == card8.tempd.value );
        CHECK( "lwtr" == *card8.tname.value );
        CHECK( 3 == card8.nza.value );
      
        // Card8a
        const auto& card8a = std::get<1>(thermalCards);
        CHECK( ranges::equal( { 1001, 8016, 9235 }, card8a.iza.value ) );
      
        // Card9
        const auto& card9 = std::get<2>(thermalCards);
        CHECK( 1 == card9.mti.value );
        CHECK( 80 == card9.nbint.value );
        CHECK( 231 == card9.mte.value );
        CHECK( 0 == card9.ielas.value );
        CHECK( 1 == card9.nmix.value );
        CHECK( 10.1 == card9.emax.value );
        CHECK( 2 == card9.iwt.value );
      }
    } // GIVEN
    GIVEN( "no NZA value (uses default)" ){
      iRecordStream<char> iss( std::istringstream( 
              sCard1
              + "2 1 1 .80 2 /\n"                   // Card2
              + "'" + sCard3 + "'/\n"               // Card3
              + " 1001 0.99167 92235 233.02479 /\n" // Card4
              + " 1 293.6 'lwtr' /\n"               // Card8
              + " 1001 1002 1003 /\n"               // Card8a
              + " 1 80 231 0 1 10.1 2 /"            // Card9
              ) );
      
      THEN( "the input values can be verified" ){
        ACER acer( iss );
      
        // Card1
        CHECK( 20 == acer.card1.nendf.value );
        CHECK( 21 == acer.card1.npend.value );
        CHECK(  0 == acer.card1.ngend.value );
        CHECK( 30 == acer.card1.nace.value );
        CHECK( 31 == acer.card1.ndir.value );
      
        // Card2
        CHECK(  2 == acer.card2.iopt.value );
        CHECK(  1 == acer.card2.iprint.value );
        CHECK(  1 == acer.card2.itype.value );
        CHECK( .80 == acer.card2.suff.value );
        CHECK(  2 == acer.card2.nxtra.value );
      
        // Card3
        CHECK( sCard3 == acer.card3.hk.value );
      
        // Card4
        const auto& values = acer.card4->izaw.value;
        CHECK( 1001 == values[0].first );
        CHECK( 0.99167 == values[0].second );
        CHECK( 92235 == values[1].first );
        CHECK( 233.02479 == values[1].second );
      
        const auto& thermalCards =
          std::get< ACER::ThermalCards >( *(acer.dataVariant) );
      
        // Card8
        const auto& card8 = std::get<0>( thermalCards );
        CHECK( 1 == card8.matd.value );
        CHECK( 293.6 == card8.tempd.value );
        CHECK( "lwtr" == *card8.tname.value );
        CHECK( 3 == card8.nza.value );
      
        // Card8a
        const auto& card8a = std::get<1>(thermalCards);
        CHECK( ranges::equal( { 1001, 1002, 1003 }, card8a.iza.value ) );
      
        // Card9
        const auto& card9 = std::get<2>(thermalCards);
        CHECK( 1 == card9.mti.value );
        CHECK( 80 == card9.nbint.value );
        CHECK( 231 == card9.mte.value );
        CHECK( 0 == card9.ielas.value );
        CHECK( 1 == card9.nmix.value );
        CHECK( 10.1 == card9.emax.value );
        CHECK( 2 == card9.iwt.value );
      }
    } // GIVEN
  }
  WHEN( "processing a 'dosimetry' data file, iopt=3" ){
    iRecordStream<char> iss( std::istringstream( 
            sCard1
            + "3 1 1 .80 0 /\n"                   // Card2
            + "'" + sCard3 + "'/\n"               // Card3
            + " 9235 600 /\n"                     // Card10
            ) );
    THEN( "the input values can be verified" ){
      ACER acer( iss );

      // Card1
      CHECK( 20 == acer.card1.nendf.value );
      CHECK( 21 == acer.card1.npend.value );
      CHECK(  0 == acer.card1.ngend.value );
      CHECK( 30 == acer.card1.nace.value );
      CHECK( 31 == acer.card1.ndir.value );

      // Card2
      CHECK(  3 == acer.card2.iopt.value );
      CHECK(  1 == acer.card2.iprint.value );
      CHECK(  1 == acer.card2.itype.value );
      CHECK( .80 == acer.card2.suff.value );
      CHECK(  0 == acer.card2.nxtra.value );

      // Card3
      CHECK( sCard3 == acer.card3.hk.value );

      // Card10
      const auto& card10 = std::get< ACER::Card10 >( *(acer.dataVariant) );
      CHECK( 9235 == card10.matd.value );
      CHECK( 600.0 == card10.tempd.value );

      CHECK( not acer.card4 );
    }
  }
  WHEN( "processing a 'photo-atomic' data file, iopt=4" ){
    iRecordStream<char> iss( std::istringstream( 
            sCard1
            + "4 1 1 .80 0 /\n"                   // Card2
            + "'" + sCard3 + "'/\n"               // Card3
            + " 9235 /\n"                         // Card11
            ) );
    THEN( "the input values can be verified" ){
      ACER acer( iss );

      // Card1
      CHECK( 20 == acer.card1.nendf.value );
      CHECK( 21 == acer.card1.npend.value );
      CHECK(  0 == acer.card1.ngend.value );
      CHECK( 30 == acer.card1.nace.value );
      CHECK( 31 == acer.card1.ndir.value );
      
      // Card2
      CHECK(  4 == acer.card2.iopt.value );
      CHECK(  1 == acer.card2.iprint.value );
      CHECK(  1 == acer.card2.itype.value );
      CHECK( .80 == acer.card2.suff.value );
      CHECK(  0 == acer.card2.nxtra.value );
      
      // Card3
      CHECK( sCard3 == acer.card3.hk.value );

      // Card11
      const auto& card11 =
        std::get< ACER::Card11 >( *(acer.dataVariant) );
      
      CHECK( 9235 == card11.matd.value );

      CHECK( not acer.card4 );
    }
  }
  WHEN( "processing a 'photo-nuclear' data file, iopt=5" ){
    iRecordStream<char> iss( std::istringstream( 
            sCard1
            + "5 1 1 .80 0 /\n"                   // Card2
            + "'" + sCard3 + "'/\n"               // Card3
            + " 9235 /\n"                         // Card11
            ) );
    THEN( "the input values can be verified" ){
      ACER acer( iss );

      // Card1
      CHECK( 20 == acer.card1.nendf.value );
      CHECK( 21 == acer.card1.npend.value );
      CHECK(  0 == acer.card1.ngend.value );
      CHECK( 30 == acer.card1.nace.value );
      CHECK( 31 == acer.card1.ndir.value );

      // Card2
      CHECK(  5 == acer.card2.iopt.value );
      CHECK(  1 == acer.card2.iprint.value );
      CHECK(  1 == acer.card2.itype.value );
      CHECK( .80 == acer.card2.suff.value );
      CHECK(  0 == acer.card2.nxtra.value );

      // Card3
      CHECK( sCard3 == acer.card3.hk.value );

      // Card11
      const auto& card11 =
        std::get< ACER::Card11 >( *(acer.dataVariant) );
      
      CHECK( 9235 == card11.matd.value );

      CHECK( not acer.card4 );
    }
  }
  WHEN( "reading/checking type 1 ACE files" ){
    iRecordStream<char> iss( std::istringstream( 
            sCard1
            + "7 1 1 .80 0 /\n"                   // Card2
            + "'" + sCard3 + "'/\n"               // Card3
            ) );
    THEN( "the input values can be verified" ){
      ACER acer( iss );

      // Card1
      CHECK( 20 == acer.card1.nendf.value );
      CHECK( 21 == acer.card1.npend.value );
      CHECK(  0 == acer.card1.ngend.value );
      CHECK( 30 == acer.card1.nace.value );
      CHECK( 31 == acer.card1.ndir.value );
      // Card2
      CHECK(  7 == acer.card2.iopt.value );
      CHECK(  1 == acer.card2.iprint.value );
      CHECK(  1 == acer.card2.itype.value );
      CHECK( .80 == acer.card2.suff.value );
      CHECK(  0 == acer.card2.nxtra.value );
      // Card3
      CHECK( sCard3 == acer.card3.hk.value );

      CHECK( not acer.card4 );
      CHECK( not acer.dataVariant );
    }
  }
  WHEN( "reading/checking type 2 ACE files" ){
    iRecordStream<char> iss( std::istringstream( 
            sCard1
            + "8 1 2 .80 0 /\n"                   // Card2
            + "'" + sCard3 + "'/\n"               // Card3
            ) );
    THEN( "the input values can be verified" ){
      ACER acer( iss );

      // Card1
      CHECK( 20 == acer.card1.nendf.value );
      CHECK( 21 == acer.card1.npend.value );
      CHECK(  0 == acer.card1.ngend.value );
      CHECK( 30 == acer.card1.nace.value );
      CHECK( 31 == acer.card1.ndir.value );

      // Card2
      CHECK(  8 == acer.card2.iopt.value );
      CHECK(  1 == acer.card2.iprint.value );
      CHECK(  2 == acer.card2.itype.value );
      CHECK( .80 == acer.card2.suff.value );
      CHECK(  0 == acer.card2.nxtra.value );

      // Card3
      CHECK( sCard3 == acer.card3.hk.value );

      CHECK( not acer.card4 );
      CHECK( not acer.dataVariant );
    }
  }
}
