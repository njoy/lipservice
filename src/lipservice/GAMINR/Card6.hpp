class Card6 {
public:
  #include "lipservice/GAMINR/Card6/Mfd.hpp"
  using Mtd = GROUPR::Card9::Mtd;
  #include "lipservice/GAMINR/Card6/Mtname.hpp"

  #include "lipservice/GAMINR/Card6/src/readRest.hpp"

 Argument< Mfd > mfd;
 std::optional< std::pair< Argument< Mtd >, Argument< Mtname > > > rest;

  template< typename Char >
  Card6( iRecordStream< Char >& is )
    try:
      mfd( argument::extract< Mfd >( is ) ),
      rest( readRest( is, this->mfd.value ) )
    {   
      Card::clear( is );
    }
    catch( std::exception& e ){
      Log::info( "Trouble validating Card6");
      throw e;
    }
};
