#include <Alphabet.hpp>

Alphabet::Alphabet() {}

void Alphabet::insert(Symbol newSymbol) { setOfSymbol.insert(newSymbol); }

bool Alphabet::contains(Symbol foundSymbol) {
  return (setOfSymbol.find(foundSymbol) != setOfSymbol.end());
}
