 #include <cstring>
#include <iostream>
#include <type_traits>
#include <typeinfo>
using namespace std;

template <typename T>

bool cmp(T a, T b) {
  return a == b;
}

template <>
bool cmp<int*>(int* a, int* b) {
  return (*a) == (*b);
};
template <>
bool cmp<float*>(float* a, float* b) {
  return (*a) == (*b);
};
template <>
bool cmp<double*>(double* a, double* b) {
  return (*a) == (*b);
};
template <>
bool cmp<char*>(char* a, char* b) {
  return strcmp(a, b) == 0;
};
