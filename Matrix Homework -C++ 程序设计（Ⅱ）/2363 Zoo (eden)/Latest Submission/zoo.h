#ifndef ZOO
#define ZOO
#include <string>
#include <vector>
#include "animal.h"
using std::string;
class Zoo {
 private:
  std::vector<Animal*> all;
  int CatCount, DogCount;

 public:
  Zoo();
  void addAnimal(Animal* newone);
  int getCatCount();
  int getDogCount();
  void deleteAnimalByName(string name);
  void deleteAnimalByAge(int age);
  void print();
  ~Zoo() {}
};
#endif
