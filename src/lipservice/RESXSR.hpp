class RESXSR {
public:

  /* nested types */
  #include "lipservice/RESXSR/Card1.hpp"
  #include "lipservice/RESXSR/Card2.hpp"
  #include "lipservice/RESXSR/Card3.hpp"
  #include "lipservice/RESXSR/Card4.hpp"
  #include "lipservice/RESXSR/Card5.hpp"

  #include "lipservice/RESXSR/src/readCard4List.hpp"
  #include "lipservice/RESXSR/src/readCard5List.hpp"

  Card1 card1;
  Card2 card2;
  Card3 card3;
  std::vector< Card4 > card4List;
  std::vector< Card5 > card5List;

  template< typename Istream >
  RESXSR( Istream& is )
  try:
    card1( is ),
    card2( is ),
    card3( is ),
    card4List( readCard4List( is, this->card2.nholl.value ) ),
    card5List( readCard5List( is, this->card2.nmat.value ) )
  {
  }
  catch( std::exception& e ){
    Log::info( "Trouble validating RESXSR input." );
    throw e;
  }
};
