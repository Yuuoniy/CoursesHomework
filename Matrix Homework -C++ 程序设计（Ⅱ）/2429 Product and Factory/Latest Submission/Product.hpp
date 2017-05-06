#ifndef PRODUCT
#define PRODUCT
#include <iostream>
using namespace std;

class Laptop {
 public:
  Laptop() {}
  virtual void compileCppProgram() = 0;
  virtual ~Laptop() {}
};

class MobilePhone {
 public:
  MobilePhone() {}
  virtual void sendShortMessage() = 0;
  virtual ~MobilePhone() {}
};

class AppleLaptop : public Laptop {
 public:
  AppleLaptop() : Laptop() {}
  void compileCppProgram() {
    cout << "Apple Laptop compiles a cpp program." << endl;
  }
  ~AppleLaptop() {}
};

class XiaomiLaptop : public Laptop {
 public:
  XiaomiLaptop() : Laptop() {}
  void compileCppProgram() {
    cout << "Xiaomi Laptop compiles a cpp program." << endl;
  }
  ~XiaomiLaptop() {}
};

class AppleMobilePhone : public MobilePhone {
 public:
  AppleMobilePhone() : MobilePhone() {}
  void sendShortMessage() {
    cout << "Apple MobilePhone sends a short message." << endl;
  }
  ~AppleMobilePhone() {}
};

class XiaomiMobilePhone : public MobilePhone {
 public:
  XiaomiMobilePhone() : MobilePhone() {}
  void sendShortMessage() {
    cout << "Xiaomi MobilePhone sends a short message." << endl;
  }
  ~XiaomiMobilePhone() {}
};
#endif
