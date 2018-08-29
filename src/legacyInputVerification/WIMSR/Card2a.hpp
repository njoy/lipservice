class Card2a {
public:

  #include "legacyInputVerification/WIMSR/Card2a/Ngnd.hpp"
  #include "legacyInputVerification/WIMSR/Card2a/Nfg.hpp"
  #include "legacyInputVerification/WIMSR/Card2a/Nrg.hpp"
  #include "legacyInputVerification/WIMSR/Card2a/Igref.hpp"

  Argument< Ngnd > ngnd;
  Argument< Nfg > nfg;
  Argument< Nrg > nrg;
  Argument< Igref > igref;

  template< typename Istream >
  Card2a( iRecordStream< Istream >& is )
  try:
    ngnd( argument::extract< WIMSR::Card2a::Ngnd >( is ) ),
    nfg( argument::extract< WIMSR::Card2a::Nfg >( is, this->ngnd.value ) ),
    nrg( argument::extract< WIMSR::Card2a::Nrg >( is, this->ngnd.value ) ),
    igref( argument::extract< WIMSR::Card2a::Igref >( is, this->nfg.value,
           this->ngnd.value ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card2a." );
    throw e;
  }
};
