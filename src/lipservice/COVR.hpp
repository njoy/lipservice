class COVR {
public:
#include "lipservice/COVR/Card1.hpp"
#include "lipservice/COVR/Card2.hpp"
#include "lipservice/COVR/Card2z.hpp"
#include "lipservice/COVR/Card2a.hpp"
#include "lipservice/COVR/Card3a.hpp"
#include "lipservice/COVR/Card2b.hpp"
#include "lipservice/COVR/Card3b.hpp"
#include "lipservice/COVR/Card3c.hpp"
#include "lipservice/COVR/Card4.hpp"

#include "lipservice/COVR/src/readCard23a.hpp"
#include "lipservice/COVR/src/readCard23b.hpp"
#include "lipservice/COVR/src/readCard4List.hpp"
    
Card1 card1;
std::optional< std::tuple< Card2, std::optional< Card2z >, Card2a, Card3a > > card23a;
std::optional< std::tuple< Card2b, Card3b, Card3c > > card23b;
std::vector< Card4 > card4List;

template <typename Istream> 
COVR( Istream& is )
try:
  card1( is ),
  card23a( readCard23a( is, this->card1.nout.value ) ),
  card23b( readCard23b( is, this->card1.nout.value ) ),
  card4List( readCard4List( is, this->card23a, this->card23b ) )
{
}
  catch( std::exception &e ){
    Log::info( "Trouble with validating COVR input" );
    throw e;
  }
};
