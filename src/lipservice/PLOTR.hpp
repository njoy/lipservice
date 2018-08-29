class PLOTR {
public:
  /* nested types */
  #include "lipservice/PLOTR/Card0.hpp"
  #include "lipservice/PLOTR/Card1.hpp"
  #include "lipservice/PLOTR/Card2.hpp"
  #include "lipservice/PLOTR/Card3.hpp"
  #include "lipservice/PLOTR/Card3a.hpp"
  #include "lipservice/PLOTR/Card4.hpp"
  #include "lipservice/PLOTR/Card5.hpp"
  #include "lipservice/PLOTR/Card5a.hpp"
  #include "lipservice/PLOTR/Card6.hpp"
  #include "lipservice/PLOTR/Card6a.hpp"
  #include "lipservice/PLOTR/Card7.hpp"
  #include "lipservice/PLOTR/Card7a.hpp"
  #include "lipservice/PLOTR/Card8.hpp"
  #include "lipservice/PLOTR/Card9.hpp"
  #include "lipservice/PLOTR/Card10.hpp"
  #include "lipservice/PLOTR/Card10a.hpp"
  #include "lipservice/PLOTR/Card11.hpp"
  #include "lipservice/PLOTR/Card12.hpp"
  #include "lipservice/PLOTR/Card13.hpp"

  #include "lipservice/PLOTR/src/readCard7.hpp"
  #include "lipservice/PLOTR/src/Plot.hpp"
  #include "lipservice/PLOTR/src/readPlot.hpp"
  #include "lipservice/PLOTR/src/readCard9.hpp"
  #include "lipservice/PLOTR/src/readCard10.hpp"
  #include "lipservice/PLOTR/src/readCard10a.hpp"
  #include "lipservice/PLOTR/src/readCard11.hpp"
  #include "lipservice/PLOTR/src/readCard13List.hpp"
  #include "lipservice/PLOTR/src/Freeform.hpp"
  #include "lipservice/PLOTR/src/readFreeform.hpp"
  #include "lipservice/PLOTR/src/Curves.hpp"
  #include "lipservice/PLOTR/src/readCurves.hpp"

  Card0 card0;
  Card1 card1;
  std::vector< std::pair< Card2, Curves > > curves;

  template< typename Istream >
  PLOTR( Istream& is )
  try:
    card0( is ),
    card1( is ),
    curves( readCurves( is, this->card1.lori ) )
  {
  }
  catch( std::exception& e ){
    Log::info( "Trouble validating PLOTR input." );
    throw e;
  }
};
