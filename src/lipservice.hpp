#ifndef LIPSERVICE_HPP
#define LIPSERVICE_HPP

#include <variant>
#include <optional>

#include "boost/hana.hpp"
namespace hana = boost::hana;

#include "nlohmann/json.hpp"
// Need this to turn optionals into JSON objects
#include "lipservice/nlohmann.hpp"

#include "utility.hpp"
#include "ENDFtk/TabulationRecord.hpp"
#include "Log.hpp"

namespace njoy {
namespace njoy21 {
namespace lipservice {

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

#include "lipservice/src/to_json.hpp"

} // namespace lipservice
} // namespace njoy21
} // namespace njoy

#endif // LIPSERVICE_HPP
