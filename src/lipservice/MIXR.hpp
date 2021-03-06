class MIXR {
public: 
 #include "lipservice/MIXR/Card1.hpp"
 #include "lipservice/MIXR/Card2.hpp"
 #include "lipservice/MIXR/Card3.hpp"
 #include "lipservice/MIXR/Card4.hpp"
 #include "lipservice/MIXR/Card5.hpp"
 #include "lipservice/MIXR/Card6.hpp"

 Card1 card1;
 Card2 card2;
 Card3 card3;
 Card4 card4;
 Card5 card5;
 Card6 card6;

 template< typename Istream >
 MIXR( Istream& is )
 try:
   card1( is ),
   card2( is ),
   card3( is, this->card1.nin.size() ),
   card4( is ),
   card5( is ),
   card6( is )
 {
 }
 catch( std::exception& e ){
   Log::info( "Trouble reading MIXR input." );
   throw e;
 }
};
