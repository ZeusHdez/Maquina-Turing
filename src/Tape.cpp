#include <Tape.hpp>

Tape::Tape() {
  pointer = 0;
  offset = 0;
}

Tape::Tape(Tape& tapeIn) {
  chain.resize(tapeIn.chain.size());

  for (size_t i = 0; i < tapeIn.chain.size(); i++) {
    chain[i] = tapeIn.chain[i];
  }
  pointer = tapeIn.pointer;
  offset = tapeIn.offset;
}

Tape::Tape(string cadena) {
  for (auto x : cadena) chain.push_back(Symbol(std::string(1, x)));
}

int Tape::size() { return chain.size(); }

void Tape::left() { pointer--; }

void Tape::right() { pointer++; }

void Tape::stop() {}

void Tape::write(Symbol symbolToWrite) {
  if ((pointer + offset) < 0) {
    chain.push_front(symbolToWrite);
    offset++;
    chain.shrink_to_fit();
  } else if (pointer + offset == chain.size()) {
    chain.push_back(symbolToWrite);
    chain.shrink_to_fit();
  } else {
    chain[pointer + offset] = symbolToWrite;
  }
}

Symbol Tape::read() {
  Symbol returnSymbol;
  if ((pointer + offset) < chain.size() && (pointer + offset) >= 0)
    returnSymbol = chain[pointer + offset];
  else
    returnSymbol = Symbol(".");
  return returnSymbol;
}

void Tape::removeEmpty() {
  while (chain.back() == Symbol(".")) {
    chain.pop_back();
  }
}
