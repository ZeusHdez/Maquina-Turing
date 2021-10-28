#pragma once

#include <Symbol.hpp>
#include <set>

using namespace std;
class Alphabet {
  set<Symbol> setOfSymbol;

 public:
  Alphabet();
  void insert(Symbol);
  bool contains(Symbol);
};