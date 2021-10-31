#include <Reader.hpp>
#include <Turing.hpp>
using namespace std;

int main(int argc, char const *argv[]) {
  Reader fileReader(argv[1]);
  string cadena;

  set<State> conjuntoEstados = fileReader.getStates();
  Alphabet alfabetoCinta = fileReader.getTapeAlphabet();
  Alphabet alfabetoMaquina = fileReader.getMachineAlphabet();
  State estadoInicial = fileReader.getInitialState();
  Symbol simboloBlanco = fileReader.getBlankSymbol();
  vector<Transition> vectorTransiciones = fileReader.getTransitions();
  set<State> conjuntoEstadosFinales = fileReader.getFinalStates();

  do {
    cout << "Introduzca la cadena a comprobar: ";
    cin >> cadena;

    Tape tape(cadena);

    Turing maquina1(conjuntoEstados, alfabetoCinta, alfabetoMaquina,
                    estadoInicial, simboloBlanco, vectorTransiciones,
                    conjuntoEstadosFinales, tape);

    cout << ((maquina1.run()) ? "Aceptada" : "Rechazada");
  } while (cadena != "");

  return 0;
}
