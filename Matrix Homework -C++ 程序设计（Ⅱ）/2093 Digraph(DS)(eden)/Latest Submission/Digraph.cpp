#include "Digraph.hpp"
#include "Matrix.hpp"

Digraph::Digraph(BooleanMatrix const &m, Set const &s) : Relation(m, s, s) {
  set = s;
}
int Digraph::inDegree(int element) {
  if (!set.isInSet(element)) return -1;
  int index = 1, count = 0;
  for (index = 1; index <= set.getSize(); index++) {
    if (set.get(index) == element) break;
  }
  for (int i = 1; i <= set.getSize(); i++) {
    if (Matrix.getElement(i, index)) count++;
  }
  return count;
}

int Digraph::outDegree(int element) {
  if (!set.isInSet(element)) return -1;
  int index = 0, count = 0;
  for (index = 1; index <= set.getSize(); index++) {
    if (set.get(index) == element) break;
  }
  for (int i = 1; i <= set.getSize(); i++) {
    if (Matrix.getElement(index, i)) count++;
  }
  return count;
}

Digraph Digraph::pathOfLength(int length) {
  Set temp(set);
  if (length > set.getSize()) {
    cout << "in if" << endl;
    length = set.getSize();
  }
  Digraph path(this->Matrix, this->set);
  if (length == 0) {
    return path;
  }
  while (--length) {
    path.Matrix = path.Matrix.BooleanProduct(this->Matrix);
  }
  return path;
}

// Properties of Relations.    
bool Digraph::isReflexive() const {
  Set temp(set);
  for (int i = 1; i <= temp.getSize(); i++) {
    if (!Matrix.getElement(i, i)) return false;
  }
  return true;
}

bool Digraph::isIrreflexive() const {
  Set temp(set);

  for (int i = 1; i <= temp.getSize(); i++) {
    if (Matrix.getElement(i, i)) return false;
  }
  return true;
}

bool Digraph::isSymmetric() const { return Matrix.isSymmetrix(); }

bool Digraph::isAsymmetric() const {
  Set temp(set);

  for (int i = 1; i <= temp.getSize(); i++) {
    for (int j = 1; j <= temp.getSize(); j++) {
      if (Matrix.getElement(i, j)) {
        if (Matrix.getElement(j, i)) return false;
      }
    }
  }
  return true;
}

bool Digraph::isAntisymmetric() const {
  Set temp(set);
  for (int i = 1; i <= temp.getSize(); i++) {
    for (int j = 1; j <= temp.getSize(); j++) {
      if (Matrix.getElement(i, j)) {
        if (Matrix.getElement(j, i) && i != j) return false;
      }
    }
  }
  return true;
}

bool Digraph::isTransitive() const {
  Set temp(set);
  BooleanMatrix two = (this->Matrix).BooleanProduct(this->Matrix);
  for (int i = 1; i <= temp.getSize(); i++) {
    for (int j = 1; j <= temp.getSize(); j++) {
      if (two.getElement(i, j) == 1 && Matrix.getElement(i, j) != 1)
        return false;
    }
  }
  return true;
}

BooleanMatrix Digraph::getBooleanMatrix() const { return Matrix; }
