#include "standard.hpp"
#include <iostream>

D::D(int i, int j, int m, int n, int k) : B(i, j), member(m, n) { this->k = k; }
void D::print(void) const {
  cout << "Printing from Base:" << endl;
  B::print();
  cout << "Printing from member:" << endl;
  (this->member).print();
  cout << "Printing from D field:" << endl;
  cout << k;
}
