namespace parser {

#include "lipservice/argument/parser/src/validate.hpp"
#include "lipservice/argument/parser/FortranString.hpp"
#include "lipservice/argument/parser/src/rightShift.hpp"
#include "lipservice/argument/parser/src/read.hpp"

#include "lipservice/argument/parser/Base.hpp"
#include "lipservice/argument/parser/Required.hpp"
#include "lipservice/argument/parser/Optional.hpp"
#include "lipservice/argument/parser/Discriminating.hpp"
#include "lipservice/argument/parser/Defaulted.hpp"
#include "lipservice/argument/parser/Composition.hpp"

template< typename Policy,
	  bool defaults = argument::policy::hasDefault< Policy >,
	  bool verifies = argument::policy::requiresVerification<Policy> >
using Type = typename Composition< Policy, defaults, verifies >::type;

}
