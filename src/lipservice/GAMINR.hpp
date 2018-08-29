class GAMINR {
public:
  /* nested types */
  #include "lipservice/GAMINR/Card1.hpp"
  #include "lipservice/GAMINR/Card2.hpp"
  #include "lipservice/GAMINR/Card3.hpp"
  #include "lipservice/GAMINR/Card4.hpp"
  #include "lipservice/GAMINR/Card5.hpp"
  #include "lipservice/GAMINR/Card6.hpp"
  #include "lipservice/GAMINR/Card7.hpp"
  #include "lipservice/GAMINR/src/Material.hpp"

  #include "lipservice/GAMINR/src/readArbitraryGammaStructure.hpp"
  #include "lipservice/GAMINR/src/readArbitraryWeights.hpp"
  #include "lipservice/GAMINR/src/readCard6List.hpp"
  #include "lipservice/GAMINR/src/readMaterials.hpp"

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
