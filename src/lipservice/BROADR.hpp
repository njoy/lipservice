class BROADR {
public:
  /* nested types */
  #include "lipservice/BROADR/Card1.hpp"
  #include "lipservice/BROADR/Card2.hpp"
  #include "lipservice/BROADR/Card3.hpp"
  #include "lipservice/BROADR/Card4.hpp"
  #include "lipservice/BROADR/Card5.hpp"
  #include "lipservice/BROADR/src/readCard5List.hpp"

  /* fields */
  Card1 card1;
  Card2 card2;
  Card3 card3;
  Card4 card4;
  std::vector< Card5 > card5List;

  template< typename Char >
  BROADR( iRecordStream<Char>& is )
    try :
      card1( is ),
      card2( is ),
      card3( is ),
      card4( is, this->card2.ntemp2,
                 this->card2.istrap,
                 this->card2.temp1 ),
      card5List( readCard5List( is, this->card2 ) ){
    } catch( std::exception& e ){
      Log::info("Trouble while validating BROADR input");
      throw e;
    }
};
