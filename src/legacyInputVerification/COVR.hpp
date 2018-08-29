class COVR {
public:
#include "legacyInputVerification/COVR/Card1.hpp"
#include "legacyInputVerification/COVR/Card2.hpp"
#include "legacyInputVerification/COVR/Card2z.hpp"
#include "legacyInputVerification/COVR/Card2a.hpp"
#include "legacyInputVerification/COVR/Card3a.hpp"
#include "legacyInputVerification/COVR/Card2b.hpp"
#include "legacyInputVerification/COVR/Card3b.hpp"
#include "legacyInputVerification/COVR/Card3c.hpp"
#include "legacyInputVerification/COVR/Card4.hpp"

#include "legacyInputVerification/COVR/src/readCard23a.hpp"
#include "legacyInputVerification/COVR/src/readCard23b.hpp"
#include "legacyInputVerification/COVR/src/readCard4List.hpp"
    
Card1 card1;
optional< std::tuple< Card2, optional< Card2z >, Card2a, Card3a > > card23a;
optional< std::tuple< Card2b, Card3b, Card3c > > card23b;
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
