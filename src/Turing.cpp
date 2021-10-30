#include <Turing.hpp>

Turing::Turing(set<State>& setStates, Alphabet& inAlphabet,
               Alphabet& stackAlphabet, State& initialState,
               Symbol& blankSymbol, vector<Transition>& transitionVector,
               set<State>& finalStates, Tape& tapeIn) {
  Turing::setStates = setStates;
  Turing::tapeAlphabet = inAlphabet;
  Turing::machineAlphabet = machineAlphabet;
  Turing::initialState = initialState;
  Turing::transitionVector = transitionVector;
  Turing::blankSymbol = blankSymbol;
  Turing::tapeIn = tapeIn;
  Turing::finalStates = finalStates;
}

bool Turing::run() {
  actualState = initialState;
  bool doTransition;
  cout << "Cadena [Head]\tTransición\n";
  do {
    Symbol actualSymbol = tapeIn.read();
    cout << tapeIn << "\t";
    doTransition = false;
    for (size_t i = 0; i < transitionVector.size(); i++) {
      if (transitionVector[i].initialState == actualState) {
        if (transitionVector[i].tapeSymbol == actualSymbol) {
          string movement;
          tapeIn.write(transitionVector[i].symbolToWrite);
          switch (transitionVector[i].moveHead) {
            case LEFT:
              tapeIn.left();
              movement = "L";
              break;
            case RIGHT:
              tapeIn.right();
              movement = "R";
              break;
            case STOP:
              tapeIn.stop();
              movement = "S";
              break;
            default:
              break;
          }
          cout << actualState << ", " << actualSymbol << " -> "
               << transitionVector[i].finalState << ", "
               << transitionVector[i].symbolToWrite << ", " << movement << endl;

          actualState = transitionVector[i].finalState;
          doTransition = true;

          break;
        }
      }
    }
    if (!doTransition) cout << "\tNo hay Transición";
  } while (doTransition);
  cout << endl;
  if (finalStates.find(actualState) != finalStates.end()) {
    return true;
  }
  return false;
}
