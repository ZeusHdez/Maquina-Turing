#include <Turing.hpp>

Turing::Turing(set<State>& setStates, Alphabet& inAlphabet,
               Alphabet& stackAlphabet, State& initialState,
               Symbol& initialStackSymbol, vector<Transition>& transitionVector,
               Tape& tapeIn) {
  Turing::setStates = setStates;
  Turing::tapeAlphabet = inAlphabet;
  Turing::machineAlphabet = machineAlphabet;
  Turing::initialState = initialState;
  Turing::transitionVector = transitionVector;
  Turing::tapeIn = tapeIn;
}

bool Turing::run() {
  actualState = initialState;
  Symbol actualSymbol = tapeIn.read();
  bool doTransition;
  do {
    doTransition = false;
    for (size_t i = 0; i < transitionVector.size(); i++) {
      if (transitionVector[i].initialState == actualState) {
        if (transitionVector[i].tapeSymbol == actualSymbol) {
          tapeIn.write(transitionVector[i].symbolToWrite);
          switch (transitionVector[i].moveHead) {
            case LEFT:
              tapeIn.left();
              break;
            case RIGHT:
              tapeIn.right();
              break;
            case STOP:
              tapeIn.stop();
              break;

            default:
              break;
          }

          actualState = transitionVector[i].finalState;
          doTransition = true;
          break;
        }
      }
    }
  } while (doTransition);
}
