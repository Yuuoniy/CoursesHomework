#include "zoo.h"

#include <algorithm>
using namespace std;

Zoo::Zoo() { CatCount = DogCount = 0; }
void Zoo::addAnimal(Animal* newone) {
  vector<Animal*>::iterator iter = find(all.begin(), all.end(), newone);
  if (iter != all.end()) return;
  all.push_back(newone);
  if (newone->getType() == 1)
    DogCount++;
  else
    CatCount++;
}
int Zoo::getCatCount() { return CatCount; }
int Zoo::getDogCount() { return DogCount; }
void Zoo::deleteAnimalByName(string name) {
  for (int  i = 0;i<all.size();) {
    if (all[i]->getName() == name) {
      if (all[i]->getType() == DOG)
        DogCount--;
      else
        CatCount--;
      vector<Animal*>::iterator   iter   =   all.begin()+i;
      all.erase(iter);
    }
    else i++;
  }
}
void Zoo::deleteAnimalByAge(int age) {
  for (int  i = 0;i<all.size();) {
    if (all[i]->getAge() == age) {
      if (all[i]->getType() == DOG)
        DogCount--;
      else
        CatCount--;
      vector<Animal*>::iterator iter = all.begin()+i;
      all.erase(iter);
    }
    else i++;

  }
}
void Zoo::print() {
  for (int i = 0; i < all.size(); i++) all[i]->Shout();
}
