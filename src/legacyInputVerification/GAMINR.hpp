class GAMINR {
public:
  /* nested types */
  #include "legacyInputVerification/GAMINR/Card1.hpp"
  #include "legacyInputVerification/GAMINR/Card2.hpp"
  #include "legacyInputVerification/GAMINR/Card3.hpp"
  #include "legacyInputVerification/GAMINR/Card4.hpp"
  #include "legacyInputVerification/GAMINR/Card5.hpp"
  #include "legacyInputVerification/GAMINR/Card6.hpp"
  #include "legacyInputVerification/GAMINR/Card7.hpp"
  #include "legacyInputVerification/GAMINR/src/Material.hpp"

  #include "legacyInputVerification/GAMINR/src/readArbitraryGammaStructure.hpp"
  #include "legacyInputVerification/GAMINR/src/readArbitraryWeights.hpp"
  #include "legacyInputVerification/GAMINR/src/readCard6List.hpp"
  #include "legacyInputVerification/GAMINR/src/readMaterials.hpp"

  Card1 card1;
  Card2 card2;
  Card3 card3;
  optional< Card4 > card4;
  optional< Card5 > card5;
  std::vector< Material > materials;

  template< typename Istream >
  GAMINR( Istream& is )
  try:
    card1( is ),
    card2( is ),
    card3( is ),
    card4(
        readArbitraryGammaStructure( is, card2.igg.value ) ),
    card5( 
        readArbitraryWeights( is, card2.iwt.value ) ),
    materials( readMaterials( is ) )
  {
  }
  catch( std::exception& e ){
    Log::info( "Trouble validating GAMINR input." );
    throw e;
  }
};
