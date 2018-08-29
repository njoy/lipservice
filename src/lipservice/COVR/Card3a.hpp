class Card3a {
  public:
    #include "lipservice/COVR/Card3a/Irelco.hpp"
    #include "lipservice/COVR/Card3a/Ncase.hpp"
    #include "lipservice/COVR/Card3a/Noleg.hpp"
    #include "lipservice/COVR/Card3a/Nstart.hpp"
    #include "lipservice/COVR/Card3a/Ndiv.hpp"
          
    Argument< Irelco > irelco;
    Argument< Ncase > ncase;
    Argument< Noleg> noleg;
    Argument< Nstart > nstart;
    Argument< Ndiv > ndiv;

    template< typename Char >
    Card3a( iRecordStream<Char>& is )
    try:
      irelco ( argument::extract< Irelco >( is ) ),
      ncase( argument::extract< Ncase >( is ) ),
      noleg( argument::extract< Noleg >( is ) ),
      nstart( argument::extract< Nstart >( is ) ),
      ndiv( argument::extract< Ndiv >( is ) )
      {
        Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble while validating COVR Card3a" );
      throw e;
    }
};
