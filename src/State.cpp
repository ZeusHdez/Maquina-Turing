#include <State.hpp>
State::State() { identifier = ""; }

State::State(string id) { identifier = id; }

State::State(const State& stateIn) { identifier = stateIn.identifier; }

string State::toString() const { return identifier; }
