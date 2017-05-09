 #include <iostream>
#include <string>
using namespace std;

class Object {
 public:
  Object() { str = "Object"; }
  virtual ~Object() {}
  friend string instanceOf(Object *obj);

 protected:
  string str;
};
class Animal : public Object {
 public:
  Animal() : Object() { str = "Animal"; }
  ~Animal() {}
};
class Dog : public Animal {
 public:
  Dog() : Animal() { str = "Dog"; }
  ~Dog() {}
};
class Cat : public Animal {
 public:
  Cat() : Animal() { str = "Cat"; }
  ~Cat() {}
};
class Vehicle : public Object {
 public:
  Vehicle() : Object() { str = "Vehicle"; }
  ~Vehicle() {}
};
class Bus : public Vehicle {
 public:
  Bus() : Vehicle() { str = "Bus"; }
  ~Bus() {}
};
class Car : public Vehicle {
 public:
  Car() : Vehicle() { str = "Car"; }
  ~Car() {}
};
string instanceOf(Object *obj) {
  if (obj == NULL)
    return "NULL";
  else
    return obj->str;
}
