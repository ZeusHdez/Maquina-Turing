#pragma once
#include <string>

using namespace std;

class Symbol {
  string value;

 public:
  Symbol();
  Symbol(string);

  Symbol(const Symbol&);
  ~Symbol() { value.clear(); }

  string toString();

  void operator=(Symbol);
  bool operator==(Symbol);
  bool operator<=(const Symbol);
  bool operator!=(Symbol);
  friend bool operator<(const Symbol& symbol1, const Symbol& symbol2) {
    return symbol1.value < symbol2.value;
  }
  friend ostream& operator<<(ostream& os, Symbol symbol1) {
    return os << symbol1.value;
  }
};
