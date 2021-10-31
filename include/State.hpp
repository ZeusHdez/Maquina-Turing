#pragma once

#include <string>

using namespace std;

class State {
  string identifier;

 public:
  State();

  State(string);

  State(const State&);
  ~State() { identifier.clear(); }

  string toString() const;

  friend bool operator<(const State state1, const State state2) {
    return state1.identifier < state2.identifier;
  }
  friend bool operator==(const State state1, const State state2) {
    return state1.identifier == state2.identifier;
  }
  friend ostream& operator<<(ostream& os, State state) {
    return os << state.toString();
  }
};