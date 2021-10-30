#pragma once

#include <Symbol.hpp>
#include <deque>
#include <iostream>

using namespace std;

enum dir { LEFT, RIGHT, STOP };

class Tape {
  deque<Symbol> chain;

  int pointer = 0;
  int offset = 0;

 public:
  Tape();
  Tape(Tape&);
  Tape(deque<Symbol>&);
  int size();

  void left();
  void right();
  void stop();

  void write(Symbol);

  Symbol read(void);
  friend ostream& operator<<(ostream& os, Tape tape) {
    for (size_t i = 0; i < tape.chain.size(); i++) {
      if (tape.pointer + tape.offset == i) os << "[";
      os << tape.chain[i];
      if (tape.pointer + tape.offset == i) os << "]";
    }

    return os;
  }
};
