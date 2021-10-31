#include <Reader.hpp>

Reader::Reader(string nameOfFile) {
  stringstream fileWithOutComments;
  inFile.open(nameOfFile);
  fileWithOutComments = quitComments();
  inFile.close();

  string aux;

  readStates(fileWithOutComments);
  readAlphabets(fileWithOutComments);
  readInitials(fileWithOutComments);
  readTransitions(fileWithOutComments);
}

stringstream Reader::quitComments() {
  stringstream out;
  string auxString;
  while (getline(inFile, auxString)) {
    string outString;
    for (size_t i = 0; i < auxString.size(); i++) {
      char auxChar = auxString[i];
      if (auxChar == COMMENT_SYMBOL) break;
      outString.push_back(auxChar);
    }
    if (!outString.empty()) {
      out << outString;
      out << endl;
    }
  }
  return out;
}

void Reader::readStates(stringstream& line) {
  string auxString;
  stringstream auxBuffer;
  // Reading States
  if (getline(line, auxString)) {
    auxBuffer << auxString;

    string nameOfState;
    while (!auxBuffer.eof()) {
      auxBuffer >> nameOfState;
      setOfStates.emplace(nameOfState);
    }
  }
}

void Reader::readAlphabets(stringstream& line) {
  stringstream auxBuffer;
  string auxString;
  // Reading Tape Alphabet
  if (getline(line, auxString)) {
    auxBuffer << auxString;

    string symbolValue;
    while (!auxBuffer.eof()) {
      auxBuffer >> symbolValue;
      tapeAlphabet.insert(Symbol(symbolValue));
    }
  }
  stringstream auxBuffer2;

  if (getline(line, auxString)) {
    auxBuffer2 << auxString;

    string symbolValue;
    while (!auxBuffer2.eof()) {
      auxBuffer2 >> symbolValue;
      machineAlphabet.insert(Symbol(symbolValue));
    }
  }
}

void Reader::readInitials(stringstream& line) {
  stringstream auxBuffer;
  string auxString;
  // Initial State
  if (getline(line, auxString)) {
    auxBuffer << auxString;
    string initialStateValue;
    auxBuffer >> initialStateValue;
    assert(setOfStates.find(State(initialStateValue)) != setOfStates.end());
    initialState = State(initialStateValue);
  }

  stringstream auxBuffer2;
  string auxString2;
  // Initial State
  if (getline(line, auxString2)) {
    auxBuffer2 << auxString2;
    string blank;
    auxBuffer2 >> blank;
    Symbol blankS(blankSymbol);
    blankSymbol = blankS;
  }

  stringstream auxBuffer3;
  string auxString3;
  if (getline(line, auxString3)) {
    auxBuffer3 << auxString3;

    string stateValue;
    while (!auxBuffer3.eof()) {
      auxBuffer3 >> stateValue;
      finalStates.insert(State(stateValue));
    }
  }
}

void Reader::readTransitions(stringstream& buffer) {
  stringstream auxBuffer;
  string auxString;
  // Initial State
  while (getline(buffer, auxString)) {
    auxBuffer.clear();
    auxBuffer << auxString;

    string initialStateValue;
    string symbolValue;
    string finalStateValue;
    string direction;
    int dir;

    stack<Symbol> symbols;

    auxBuffer >> initialStateValue;
    State initialState(initialStateValue);

    auxBuffer >> symbolValue;
    Symbol transitionSymbol(symbolValue);

    auxBuffer >> finalStateValue;
    State finalState(finalStateValue);

    auxBuffer >> symbolValue;
    Symbol symbolToWrite(symbolValue);

    auxBuffer >> direction;
    if (direction == "L") {
      dir = LEFT;
    } else if (direction == "R") {
      dir = RIGHT;
    } else if (direction == "S") {
      dir = STOP;
    } else
      dir = -1;

    Transition auxTransition(initialState, transitionSymbol, finalState,
                             symbolToWrite, dir);

    transitions.push_back(auxTransition);
  }
}

set<State> Reader::getStates() { return setOfStates; }
Alphabet Reader::getTapeAlphabet() { return tapeAlphabet; }
Alphabet Reader::getMachineAlphabet() { return machineAlphabet; }
State Reader::getInitialState() { return initialState; }
Symbol Reader::getBlankSymbol() { return blankSymbol; }
vector<Transition> Reader::getTransitions() { return transitions; }
set<State> Reader::getFinalStates() { return finalStates; }