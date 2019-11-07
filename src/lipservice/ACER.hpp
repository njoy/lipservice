class ACER {
public:
  /* nested types */
  #include "lipservice/ACER/Card1.hpp"
  #include "lipservice/ACER/Card2.hpp"
  #include "lipservice/ACER/Card3.hpp"
  #include "lipservice/ACER/Card4.hpp"
  #include "lipservice/ACER/Card5.hpp"
  #include "lipservice/ACER/Card6.hpp"
  #include "lipservice/ACER/Card7.hpp"
  #include "lipservice/ACER/Card8.hpp"
  #include "lipservice/ACER/Card8a.hpp"
  #include "lipservice/ACER/Card9.hpp"
  #include "lipservice/ACER/Card10.hpp"
  #include "lipservice/ACER/Card11.hpp"

  Card1 card1;
  Card2 card2;
  Card3 card3;
  std::optional< Card4 > card4;

  using FastCards = std::tuple< Card5, Card6, Card7 >;
  using ThermalCards = std::tuple< Card8, Card8a, Card9 >;
  using DataVariant = std::variant< FastCards, ThermalCards, Card10, Card11 >;

  std::optional< DataVariant > dataVariant;

  #include "lipservice/ACER/src/readCard4.hpp"
  #include "lipservice/ACER/src/readDataVariant.hpp"
  
  template< typename Istream >
  ACER( Istream& is )
  try:
    card1( is ),
    card2( is ),
    card3( is ),
    card4( readCard4( is, this->card2.nxtra ) ),
    dataVariant( 
      ( this->card2.iopt.value < 6 ) ?
        std::optional<DataVariant>{
          readDataVariant( is, this->card2.iopt.value ) } : 
        std::nullopt )
  {
  } catch( std::exception& e ) {
    Log::info( "Trouble validating ACER input." );
    throw e;
  }

};
