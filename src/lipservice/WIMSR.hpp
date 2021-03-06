class WIMSR {
public:
  /* nested types */
  #include "lipservice/WIMSR/Card1.hpp"
  #include "lipservice/WIMSR/Card2.hpp"
  #include "lipservice/WIMSR/Card2a.hpp"
  #include "lipservice/WIMSR/Card3.hpp"
  #include "lipservice/WIMSR/Card4.hpp"
  #include "lipservice/WIMSR/Card5.hpp"
  #include "lipservice/WIMSR/Card6a.hpp"
  #include "lipservice/WIMSR/Card6b.hpp"
  #include "lipservice/WIMSR/Card6c.hpp"
  #include "lipservice/WIMSR/Card7.hpp"
  #include "lipservice/WIMSR/Card8.hpp"

  #include "lipservice/WIMSR/src/readCard2a.hpp"
  #include "lipservice/WIMSR/src/readCard56.hpp"
  #include "lipservice/WIMSR/src/readCard7.hpp"
  #include "lipservice/WIMSR/src/readCard8.hpp"

  Card1 card1;
  Card2 card2;
  std::optional< Card2a > card2a;
  Card3 card3;
  Card4 card4;
  std::optional< std::tuple< Card5, Card6a, Card6b,
            std::optional< std::vector< Card6c > > > > card56List;
  Card7 card7;
  std::optional< Card8 > card8;

  template< typename Istream >
  WIMSR( Istream& is )
  try:
    card1( is ),
    card2( is ),
    card2a( readCard2a( is, this->card2.igroup.value ) ),
    card3( is ),
    card4( is ),
    card56List( readCard56( is, this->card3.iburn.value ) ),
    card7( readCard7( is, this->card2.igroup.value, this->card2a ) ),
    card8( readCard8( is, this->card4.jp1.value ) )
  {
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading WIMSR input." );
    throw e;
  }
};
