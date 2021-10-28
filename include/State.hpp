#pragma once

#include <string>

using namespace std;

class State {
  string identifier;

 public:
  State();

  State(string);

  State(const State&);

  string toString() const;

  friend bool operator<(const State state1, const State state2) {
    return state1.toString() < state2.toString();
  }
  friend bool operator==(const State state1, const State state2) {
    return state1.toString() == state2.toString();
  }
};