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

int Tape::size() { return chain.size(); }

void Tape::left() { pointer--; }

void Tape::right() { pointer++; }

void Tape::stop() {}

void Tape::write(Symbol symbolToWrite) {
  if (pointer < 0) {
    chain.push_front(symbolToWrite);
    offset++;
  } else if (pointer == chain.size()) {
    chain.push_back(symbolToWrite);
  } else {
    chain[pointer + offset] = symbolToWrite;
  }
}

Symbol Tape::read() { return chain[pointer + offset]; }
