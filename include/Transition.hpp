#pragma once

#include <State.hpp>
#include <Symbol.hpp>
#include <Tape.hpp>
#include <iostream>
#include <queue>
#include <stack>

struct Transition {
  State initialState;
  Symbol tapeSymbol;
  State finalState;
  Symbol symbolToWrite;
  int moveHead;

  Transition(State&, Symbol&, State&, Symbol&, int);

  friend ostream& operator<<(ostream& os, Transition& transition) {
    os << transition.initialState.toString() << " - "
       << transition.tapeSymbol.toString() << " -> "
       << transition.finalState.toString() << " | "
       << transition.symbolToWrite.toString() << " | ";

    switch (transition.moveHead) {
      case LEFT /* constant-expression */:
        os << "L";
        break;
      case RIGHT:
        os << "R";
        break;
      case STOP:
        os << "S";
        break;

      default:
        break;
    }

    return os << endl;
  }
};