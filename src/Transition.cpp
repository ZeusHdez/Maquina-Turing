#include <Transition.hpp>

Transition::Transition(State& stateIn, Symbol& symbolRead, State& stateOut,
                       Symbol& symbolWrite, int dir) {
  initialState = stateIn;
  tapeSymbol = symbolRead;
  finalState = stateOut;
  symbolToWrite = symbolWrite;
  moveHead = dir;
}
