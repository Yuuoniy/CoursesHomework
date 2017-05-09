 #include <iostream>
using namespace std;

class Calculator {
 public:
  Calculator(int v = 0) { value = v; }
  void operator++() {
    if (value < 99)
      value++;
    else
      value = 0;
    cout << "counter = " << value << endl;
  }
  void operator--() {
    if (value > 0)
      value--;
    else
      value = 0;
    cout << "counter = " << value << endl;
  }
  ~Calculator() {}

 private:
  unsigned int value;
};
