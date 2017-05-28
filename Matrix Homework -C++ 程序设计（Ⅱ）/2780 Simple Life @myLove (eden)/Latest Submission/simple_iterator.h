#include <cstdlib>

class simple_iterator {
 public:
  simple_iterator(char* ptr = NULL) : pointer(ptr) {}
  char& base() {}
  simple_iterator begin() {
    simple_iterator temp = (*this), pre = (*this);
    while (true) {
      pre = temp;
      temp--;
      if (*temp == '\0') return pre;
    }
  }

  simple_iterator end() {
    simple_iterator temp = (*this), pre = (*this);
    while (true) {
      pre = temp;
      temp++;
      if (*temp == '\0') return pre;
    }
  }
  simple_iterator prev() { return simple_iterator(pointer - 1); }
  simple_iterator next() { return simple_iterator(pointer + 1); }
  simple_iterator& operator++() {
    ++pointer;
    return *this;
  }
  simple_iterator& operator--() {
    pointer--;

    return (*this);
  }
  simple_iterator operator--(int) {
    simple_iterator temp = (*this);
    --pointer;
    return temp;
  }
  simple_iterator operator++(int) {
    simple_iterator temp = (*this);
    ++pointer;
    return temp;
  }
  bool operator==(simple_iterator other) {
    return *pointer == *(other.pointer);
  }
  bool operator!=(simple_iterator other) { return !(*this == other); }
  bool operator<(simple_iterator other) {
    return (*pointer) < *(other.pointer);
  }
  bool operator>(simple_iterator other) {
    return (*pointer) > *(other.pointer);
  }
  bool operator>=(simple_iterator other) { return !(*this < other); }
  bool operator<=(simple_iterator other) { return !(*this > other); }
  simple_iterator operator+(int n) { return simple_iterator(pointer + n); }
  simple_iterator operator-(int n) { return simple_iterator(pointer - n); }
  char operator*() { return *pointer; }

 private:
  char* pointer;
};
