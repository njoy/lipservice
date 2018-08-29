namespace argument{

#include "lipservice/argument/policy.hpp"
#include "lipservice/argument/Type.hpp"
#include "lipservice/argument/parser.hpp"
#include "lipservice/argument/common.hpp"

#include "lipservice/argument/src/echoLine.hpp"
#include "lipservice/argument/src/construct.hpp"
#include "lipservice/argument/src/extract.hpp"
#include "lipservice/argument/src/domainError.hpp"

}

template< typename Policy >
using Argument = argument::Type< Policy >;
