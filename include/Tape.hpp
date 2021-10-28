#pragma once

#include <Symbol.hpp>
#include <deque>

using namespace std;

const enum dir { LEFT, RIGHT, STOP };

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
};

ostream& operator<<(ostream& os, Symbol);