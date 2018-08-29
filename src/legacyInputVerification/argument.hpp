namespace argument{

#include "legacyInputVerification/argument/policy.hpp"
#include "legacyInputVerification/argument/Type.hpp"
#include "legacyInputVerification/argument/parser.hpp"
#include "legacyInputVerification/argument/common.hpp"

#include "legacyInputVerification/argument/src/echoLine.hpp"
#include "legacyInputVerification/argument/src/construct.hpp"
#include "legacyInputVerification/argument/src/extract.hpp"
#include "legacyInputVerification/argument/src/domainError.hpp"

}

template< typename Policy >
using Argument = argument::Type< Policy >;
