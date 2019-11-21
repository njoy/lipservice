class RECONR {
public:
  /* nested types */
  #include "lipservice/RECONR/Card1.hpp"
  #include "lipservice/RECONR/Card2.hpp"
  #include "lipservice/RECONR/Card3.hpp"
  #include "lipservice/RECONR/Card4.hpp"
  #include "lipservice/RECONR/Card5.hpp"
  #include "lipservice/RECONR/Card6.hpp"

  Card1 card1;
  Card2 card2;

  using RECONR_tuple =
    std::tuple< Card3, Card4,
                std::vector< Card5 >,
                optional< Card6 > >;

  std::vector< RECONR_tuple > cardSequence;

  #include "lipservice/RECONR/src/ctor.hpp"
};
