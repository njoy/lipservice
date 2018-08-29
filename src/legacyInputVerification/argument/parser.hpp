namespace parser {

#include "legacyInputVerification/argument/parser/src/validate.hpp"
#include "legacyInputVerification/argument/parser/FortranString.hpp"
#include "legacyInputVerification/argument/parser/src/rightShift.hpp"
#include "legacyInputVerification/argument/parser/src/read.hpp"

#include "legacyInputVerification/argument/parser/Base.hpp"
#include "legacyInputVerification/argument/parser/Required.hpp"
#include "legacyInputVerification/argument/parser/Optional.hpp"
#include "legacyInputVerification/argument/parser/Discriminating.hpp"
#include "legacyInputVerification/argument/parser/Defaulted.hpp"
#include "legacyInputVerification/argument/parser/Composition.hpp"

template< typename Policy,
	  bool defaults = argument::policy::hasDefault< Policy >,
	  bool verifies = argument::policy::requiresVerification<Policy> >
using Type = typename Composition< Policy, defaults, verifies >::type;

}
