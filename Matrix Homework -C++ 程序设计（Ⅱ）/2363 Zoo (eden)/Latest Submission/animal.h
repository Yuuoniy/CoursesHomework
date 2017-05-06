 #ifndef ANIMAL
#define ANIMAL
#include <iostream>
#include <string>

using namespace std;
enum Type { CAT, DOG };

class Animal {
 public:
  Animal() {}
  Animal(string _name, int _age) : name(_name), age(_age) {}
  virtual void Shout() const = 0;
  virtual Type getType() const = 0;
  std::string getName() const { return name; }

  int getAge() const { return age; }

 private:
  std::string name;
  int age;
};
class Dog : public Animal {
 public:
  Dog() : Animal() {}
  Dog(string _name, int _age) : Animal(_name, _age) {}
  void Shout() const { cout << getName() << ": bark!!" << endl; }
  Type getType() const { return DOG; }
  ~Dog() {}
};

class Cat : public Animal {
 public:
  Cat() : Animal() {}
  Cat(string _name, int _age) : Animal(_name, _age) {}
  Type getType() const { return CAT; }
  void Shout() const { cout << getName() << ": meow~~" << endl; }
  ~Cat() {}
};

#endif
