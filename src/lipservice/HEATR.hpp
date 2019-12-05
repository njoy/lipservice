class HEATR {
public:
  #include "lipservice/HEATR/Card1.hpp"
  #include "lipservice/HEATR/Card2.hpp"
  #include "lipservice/HEATR/Card3.hpp"
  #include "lipservice/HEATR/Card4.hpp"
  #include "lipservice/HEATR/Card5.hpp"
  #include "lipservice/HEATR/Card5a.hpp"

  using Card5aList = std::vector<Card5a>;
  using ControlTuple = std::tuple< Card4, Card5, Card5aList >;

  #include "lipservice/HEATR/src/buildCard3.hpp"
  #include "lipservice/HEATR/src/buildControlTuple.hpp"
  #include "lipservice/HEATR/src/ctor.hpp"

  Card1 card1;
  Card2 card2;
  std::optional<Card3> card3;
  std::optional<ControlTuple> controlTuple;

};
