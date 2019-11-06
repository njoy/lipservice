class Card {
  template< typename Char >
  using IStream = utility::stream::basic_RecordOrientedStream
                  < std::basic_istream, Char >;
  
public:

  #include "lipservice/Card/src/clear.hpp"
};
