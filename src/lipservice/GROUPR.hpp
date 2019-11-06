template< typename T >
struct echo;

class GROUPR {
public:
  /* nested types */
  #include "lipservice/GROUPR/Card1.hpp"
  #include "lipservice/GROUPR/Card2.hpp"
  #include "lipservice/GROUPR/Card3.hpp"
  #include "lipservice/GROUPR/Card4.hpp"
  #include "lipservice/GROUPR/Card5.hpp"
  #include "lipservice/GROUPR/Card6a.hpp"
  #include "lipservice/GROUPR/Card6b.hpp"
  #include "lipservice/GROUPR/Card7a.hpp"
  #include "lipservice/GROUPR/Card7b.hpp"
  #include "lipservice/GROUPR/Card8a.hpp"
  #include "lipservice/GROUPR/Card8b.hpp"
  #include "lipservice/GROUPR/Card8c.hpp"
  #include "lipservice/GROUPR/Card8d.hpp"
  #include "lipservice/GROUPR/Card9.hpp"
  #include "lipservice/GROUPR/Card10.hpp"

  using Card8Variant = std::variant< std::monostate, Card8b, Card8c, Card8d >;

  using reactionList_t = std::vector< Card9 >;
  using tempReactionListPair_t = std::vector< std::pair< 
      double, reactionList_t > >;
  using materialReactionsPair_t = std::pair< 
      Card10::Matd::Value_t, tempReactionListPair_t >;
  using reactionMatrix_t = std::vector< materialReactionsPair_t >;

  #include "lipservice/GROUPR/src/readArbitraryNeutronStructure.hpp"
  #include "lipservice/GROUPR/src/readArbitraryGammaStructure.hpp"
  #include "lipservice/GROUPR/src/readFluxCalculatorParameters.hpp"
  #include "lipservice/GROUPR/src/readFluxParameters.hpp"
  #include "lipservice/GROUPR/src/readReactionMatrix.hpp"
  #include "lipservice/GROUPR/src/makeMaterialReactions.hpp"
  #include "lipservice/GROUPR/src/readCard9List.hpp"

  Card1 card1;
  Card2 card2;
  Card3 card3;
  Card4 card4;
  Card5 card5;
  optional< std::pair< Card6a, Card6b > > arbitraryNeutronStructureCards;
  optional< std::pair< Card7a, Card7b > > arbitraryGammaStructureCards;
  optional< Card8a > card8a;
  Card8Variant card8Variant;
  reactionMatrix_t reactionMatrix;

  template< typename Istream >
  GROUPR( Istream& is )
  try:
    card1( is ),
    card2( is ),
    card3( is ),
    card4( is, card2.ntemp ),
    card5( is, card2.nsigz ),
    arbitraryNeutronStructureCards( 
        readArbitraryNeutronStructure( is, card2.ign.value ) ),
    arbitraryGammaStructureCards( 
        readArbitraryGammaStructure( is, card2.igg.value ) ),
    card8a( readFluxCalculatorParameters( is, card2.iwt.value, card1 ) ),
    card8Variant( readFluxParameters( is, card2.iwt.value, card1 ) ),
    reactionMatrix( readReactionMatrix( is, card2.matb, card4 ) )
  {
  }
  catch( std::exception& e ){
    Log::info( "Trouble validating GROUPR input." );
    throw e;
  }
};
