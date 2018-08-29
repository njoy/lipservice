template< typename Char >
class FortranString {
  std::basic_string<Char>& core;
  typename std::char_traits<Char>::int_type buffer;
  char quote;

#include "legacyInputVerification/argument/parser/FortranString/src/isQuote.hpp"
#include "legacyInputVerification/argument/parser/FortranString/src/quoted.hpp"
#include "legacyInputVerification/argument/parser/FortranString/src/unquoted.hpp"

public:
  FortranString( std::basic_string<Char>& core ) : core( core ){
    this->core.clear();
  }
  
#include "legacyInputVerification/argument/parser/FortranString/src/read.hpp"
};
