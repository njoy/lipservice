class PLOTR {
public:
  /* nested types */
  #include "legacyInputVerification/PLOTR/Card0.hpp"
  #include "legacyInputVerification/PLOTR/Card1.hpp"
  #include "legacyInputVerification/PLOTR/Card2.hpp"
  #include "legacyInputVerification/PLOTR/Card3.hpp"
  #include "legacyInputVerification/PLOTR/Card3a.hpp"
  #include "legacyInputVerification/PLOTR/Card4.hpp"
  #include "legacyInputVerification/PLOTR/Card5.hpp"
  #include "legacyInputVerification/PLOTR/Card5a.hpp"
  #include "legacyInputVerification/PLOTR/Card6.hpp"
  #include "legacyInputVerification/PLOTR/Card6a.hpp"
  #include "legacyInputVerification/PLOTR/Card7.hpp"
  #include "legacyInputVerification/PLOTR/Card7a.hpp"
  #include "legacyInputVerification/PLOTR/Card8.hpp"
  #include "legacyInputVerification/PLOTR/Card9.hpp"
  #include "legacyInputVerification/PLOTR/Card10.hpp"
  #include "legacyInputVerification/PLOTR/Card10a.hpp"
  #include "legacyInputVerification/PLOTR/Card11.hpp"
  #include "legacyInputVerification/PLOTR/Card12.hpp"
  #include "legacyInputVerification/PLOTR/Card13.hpp"

  #include "legacyInputVerification/PLOTR/src/readCard7.hpp"
  #include "legacyInputVerification/PLOTR/src/Plot.hpp"
  #include "legacyInputVerification/PLOTR/src/readPlot.hpp"
  #include "legacyInputVerification/PLOTR/src/readCard9.hpp"
  #include "legacyInputVerification/PLOTR/src/readCard10.hpp"
  #include "legacyInputVerification/PLOTR/src/readCard10a.hpp"
  #include "legacyInputVerification/PLOTR/src/readCard11.hpp"
  #include "legacyInputVerification/PLOTR/src/readCard13List.hpp"
  #include "legacyInputVerification/PLOTR/src/Freeform.hpp"
  #include "legacyInputVerification/PLOTR/src/readFreeform.hpp"
  #include "legacyInputVerification/PLOTR/src/Curves.hpp"
  #include "legacyInputVerification/PLOTR/src/readCurves.hpp"

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
