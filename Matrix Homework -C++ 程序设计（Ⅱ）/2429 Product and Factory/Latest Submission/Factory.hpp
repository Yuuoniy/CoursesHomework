#ifndef FACTORY
#define FACTORY

#include "Product.hpp"
class Factory {
 public:
  Factory() {}
  virtual Laptop* produceLaptop() = 0;
  virtual MobilePhone* produceMobilePhone() = 0;
  virtual ~Factory() {}
};

class AppleFactory : public Factory {
 public:
  AppleFactory() : Factory() {}
  AppleLaptop* produceLaptop() { return new AppleLaptop(); }
  AppleMobilePhone* produceMobilePhone() { return new AppleMobilePhone(); }
  ~AppleFactory() {}
};

class XiaomiFactory : public Factory {
 public:
  XiaomiFactory() : Factory() {}
  XiaomiLaptop* produceLaptop() { return new XiaomiLaptop(); }
  XiaomiMobilePhone* produceMobilePhone() { return new XiaomiMobilePhone(); }
  ~XiaomiFactory() {}
};
#endif
