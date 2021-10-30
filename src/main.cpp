#include <Turing.hpp>

using namespace std;

int main(int argc, char const *argv[]) {
  Symbol zero("0");
  Symbol one("1");
  Symbol blank(Symbol("."));
  State Par("Par");
  State Impar("Impar");

  Alphabet alfabetoCinta;
  alfabetoCinta.insert(one);
  alfabetoCinta.insert(zero);

  Alphabet alfabetoMaquina;
  alfabetoMaquina.insert(one);
  alfabetoMaquina.insert(zero);
  alfabetoMaquina.insert(blank);

  Transition t1(Par, zero, Impar, zero, RIGHT);
  Transition t2(Par, one, Par, one, RIGHT);
  Transition t3(Impar, zero, Par, zero, RIGHT);
  Transition t4(Impar, one, Impar, one, RIGHT);

  vector<Transition> transitionVector;
  transitionVector.push_back(t1);
  transitionVector.push_back(t2);
  transitionVector.push_back(t3);
  transitionVector.push_back(t4);

  set<State> conjuntoEstados;
  conjuntoEstados.insert(Par);
  conjuntoEstados.insert(Impar);

  Tape tape;

  for (size_t i = 0; i < 5; i++) {
    tape.write(zero);
    tape.right();
  }
  for (size_t i = 0; i < 5; i++) {
    tape.left();
  }

  Turing maquina1(conjuntoEstados, alfabetoCinta, alfabetoMaquina, Par, blank,
                  transitionVector, tape);

  maquina1.run();

  return 0;
}
