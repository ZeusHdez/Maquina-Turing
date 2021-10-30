#pragma once

#include <Alphabet.hpp>
#include <State.hpp>
#include <Symbol.hpp>
#include <Tape.hpp>
#include <Transition.hpp>
#include <iostream>
#include <stack>

using namespace std;

class Turing {
  set<State> setStates;
  Alphabet tapeAlphabet;
  Alphabet machineAlphabet;
  State initialState;
  Symbol initialStackSymbol;
  vector<Transition> transitionVector;
  Symbol blankSymbol;
  Tape tapeIn;

  State actualState;

 public:
  Turing(set<State>&, Alphabet&, Alphabet&, State&, Symbol&,
         vector<Transition>&, Tape&);

  bool run();
};