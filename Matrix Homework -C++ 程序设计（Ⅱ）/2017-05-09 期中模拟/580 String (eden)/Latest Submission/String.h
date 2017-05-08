#include <cstring>
#include <iostream>
using namespace std;
class String {
 public:
  String() {
    _buff = NULL;
    _size = 0;
  }
  explicit String(const char* src) {
    _size = strlen(src);
    _buff = new char[_size + 1];
    strcpy(_buff, src);
  }
  String(const String& src) {
    _buff = NULL;
    (*this) = src;
  }

  ~String() { delete[] _buff; }

  String& operator=(const String& src) {
    if (_buff != NULL) delete[] _buff;
    _size = src._size;
    _buff = new char[_size + 1];
    strcpy(_buff, src.c_str());
  }
  const char* c_str() const { return _buff; }  // return _buff
  inline char& operator[](int i) { return _buff[i]; }

  friend ostream& operator<<(ostream& os, const String& src) {
    cout << src._buff;
  }

 private:
  char* _buff;
  int _size;
};
