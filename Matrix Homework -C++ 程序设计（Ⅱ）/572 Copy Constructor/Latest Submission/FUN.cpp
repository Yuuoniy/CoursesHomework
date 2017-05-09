#include "FUN.hpp"
#include <cstring>
#include <iostream>
using namespace std;
FUN::FUN(char* s) {
  str = new char[strlen(s) + 1];
  strcpy(str, s);
}

FUN::FUN(const FUN& C) {
  int len = strlen(C.str);
  str = new char[len + 1];
  strcpy(str, C.str);
}

void FUN::show() { cout << str << endl; }
