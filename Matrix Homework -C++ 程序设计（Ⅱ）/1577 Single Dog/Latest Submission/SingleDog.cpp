 #include <cstring>
#include "SingleDog.h"

int SingleDog::count = 0;

SingleDog::SingleDog(int id_, char* name_):id(id_){
    
    int len = strlen(name_);
    name = new char[len+1];
    strcpy(name,name_);
    count++;
}

SingleDog::SingleDog(const SingleDog &other):id(other.id){
  
    int len = strlen(other.name);
    name = new char[len+1];
    strcpy(name,other.name);
    count++;
    }
SingleDog::~SingleDog(){
        delete [] this->name;
        count--;
    }
 int SingleDog::getCount(){
        return count;
    }
