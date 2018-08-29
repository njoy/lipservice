class MATXSR {
public:
  /* nested types */
  #include "lipservice/MATXSR/Card1.hpp"
  #include "lipservice/MATXSR/Card2.hpp"
  #include "lipservice/MATXSR/Card3.hpp"
  #include "lipservice/MATXSR/Card4.hpp"
  #include "lipservice/MATXSR/Card5.hpp"
  #include "lipservice/MATXSR/Card6.hpp"
  #include "lipservice/MATXSR/Card7.hpp"
  #include "lipservice/MATXSR/Card8.hpp"
  #include "lipservice/MATXSR/Card9.hpp"
  #include "lipservice/MATXSR/Card10.hpp"

  #include "lipservice/MATXSR/src/readCard4List.hpp"
  #include "lipservice/MATXSR/src/readCard10List.hpp"

  Card1 card1;
  Card2 card2;
  Card3 card3;
  std::vector< Card4 > card4List;
  Card5 card5;
  Card6 card6;
  Card7 card7;
  Card8 card8;
  Card9 card9;
  std::vector< Card10 > card10List;

  template< typename Istream >
  MATXSR( Istream& is )
  try:
    card1( is ),
    card2( is ),
    card3( is ),
    card4List( readCard4List( is, this->card3.nholl.value ) ),
    card5( is, this->card3.npart.value ),
    card6( is, this->card3.npart.value ),
    card7( is, this->card3.ntype.value ),
    card8( is, this->card3.ntype.value ),
    card9( is, this->card3.ntype.value ),
    card10List( readCard10List( is, this->card3.nmat.value ) )
  {
  }
  catch( std::exception& e ){
    Log::info( "Trouble validating MATXSR input." );
    throw e;
  }
};
