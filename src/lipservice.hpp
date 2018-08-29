#include <variant>

#ifdef USING_CPP17
  #include <optional>
#else 
  #include <experimental/optional>

  namespace std {
    using namespace std::experimental;
  }
#endif

#include "utility.hpp"
#include "dimwits.hpp"

namespace njoy {
namespace njoy21 {
namespace lipservice {

using namespace std::experimental;
using namespace dimwits;

template< typename Char >
using iRecordStream =
  utility::stream::basic_RecordOrientedStream< std::basic_istream, Char >;


#include "lipservice/Card.hpp"
#include "lipservice/Label.hpp"
#include "lipservice/argument.hpp"

#include "lipservice/MODER.hpp"
#include "lipservice/RECONR.hpp"
#include "lipservice/BROADR.hpp"
#include "lipservice/PURR.hpp"
#include "lipservice/UNRESR.hpp"
#include "lipservice/ACER.hpp"
#include "lipservice/GASPR.hpp"
#include "lipservice/HEATR.hpp"
#include "lipservice/GROUPR.hpp"
#include "lipservice/VIEWR.hpp"
#include "lipservice/MIXR.hpp"
#include "lipservice/DTFR.hpp"
#include "lipservice/THERMR.hpp"
#include "lipservice/ERRORR.hpp"
#include "lipservice/LEAPR.hpp"
#include "lipservice/RESXSR.hpp"
#include "lipservice/MATXSR.hpp"
#include "lipservice/GAMINR.hpp"
#include "lipservice/PLOTR.hpp"
#include "lipservice/COVR.hpp"
#include "lipservice/WIMSR.hpp"
#include "lipservice/POWR.hpp"
#include "lipservice/CCCCR.hpp"

} // namespace lipservice
} // namespace njoy21
} // namespace njoy
