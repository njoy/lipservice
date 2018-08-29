class HEATR {
public:
  #include "legacyInputVerification/HEATR/Card1.hpp"
  #include "legacyInputVerification/HEATR/Card2.hpp"
  #include "legacyInputVerification/HEATR/Card3.hpp"
  #include "legacyInputVerification/HEATR/Card4.hpp"
  #include "legacyInputVerification/HEATR/Card5.hpp"
  #include "legacyInputVerification/HEATR/Card5a.hpp"

  using Card5aList = std::vector<Card5a>;
  using ControlTuple = std::tuple< Card4, Card5, Card5aList >;

  #include "legacyInputVerification/HEATR/src/buildCard3.hpp"
  #include "legacyInputVerification/HEATR/src/buildControlTuple.hpp"
  #include "legacyInputVerification/HEATR/src/ctor.hpp"

  Card1 card1;
  Card2 card2;
  optional<Card3> card3;
  optional<ControlTuple> controlTuple;

};
