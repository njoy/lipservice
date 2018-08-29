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

  template< typename Istream, typename Nextra >
  auto readCard4( Istream& is, const Nextra& nxtra ){
    return nxtra.value ?
      std::optional< Card4 >{ std::in_place, is, nxtra } :
      std::nullopt;
  }

  template< typename Istream >
  DataVariant readDataVariant( Istream& is, int iopt ){
    assert( (iopt > 0) and (iopt < 6) );
    switch( iopt ){
    case 1: {
      Card5 card5( is );
      Card6 card6( is );
      Card7 card7( is );
      return std::make_tuple< Card5, Card6, Card7 >( std::move( card5 ),
                                                     std::move( card6 ),
                                                     std::move( card7 ) );
    }
    case 2: {
      Card8 card8( is );
      Card8a card8a( is );
      Card9 card9( is );
      return std::make_tuple< Card8, Card8a, Card9 >( std::move( card8 ),
                                                      std::move( card8a ),
                                                      std::move( card9 ) );
    }
    case 3: {
      return Card10( is );
    }
    case 4:
    case 5: {
      return Card11( is );
    }
    }
    /* unreachable but necessary to silence compiler warning */
    throw std::exception();
  }
  
  template< typename Istream >
  ACER( Istream& is )
    try:
      card1( is ),
      card2( is ),
      card3( is ),
      card4( readCard4( is, this->card2.nxtra ) ),
      dataVariant( ( this->card2.iopt.value < 6 ) ?
                   std::optional<DataVariant>{
                     readDataVariant( is,
                                      this->card2.iopt.value )
                   } : std::nullopt ){
   } catch( std::exception& e ) {
     Log::info( "Trouble validating ACER input." );
     throw e;
   }

};