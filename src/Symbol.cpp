#include <Symbol.hpp>

Symbol::Symbol() { value = ""; }
Symbol::Symbol(string inValue) { value = inValue; }
Symbol::Symbol(const Symbol& inSymbol) { value = inSymbol.value; }

bool Symbol::operator==(Symbol inSymbol) {
  return (this->value == inSymbol.value);
}
bool Symbol::operator<=(Symbol inSymbol) {
  return (*this < inSymbol || *this == inSymbol);
}

bool Symbol::operator!=(Symbol inSymbol) { return !(*this == inSymbol); }

string Symbol::toString() { return value; }

void Symbol::operator=(Symbol statein) { value = statein.value; }
