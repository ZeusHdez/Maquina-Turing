#pragma once
#include <Turing.hpp>
#include <cassert>
#include <fstream>
#include <set>
#include <sstream>

using namespace std;
class Reader {
  ifstream inFile;
  set<State> setOfStates;
  Alphabet tapeAlphabet;
  Alphabet machineAlphabet;
  vector<Transition> transitions;
  set<State> finalStates;

  State initialState;
  Symbol blankSymbol;

  const char COMMENT_SYMBOL = '#';

 public:
  Reader(string nameOfFile);
  ~Reader() {}

  set<State> getStates();
  Alphabet getTapeAlphabet();
  Alphabet getMachineAlphabet();
  vector<Transition> getTransitions();
  State getInitialState();
  Symbol getBlankSymbol();

  set<State> getFinalStates();

 private:
  stringstream quitComments();
  void readStates(stringstream&);
  void readAlphabets(stringstream&);
  void readInitials(stringstream&);
  void readTransitions(stringstream&);
};