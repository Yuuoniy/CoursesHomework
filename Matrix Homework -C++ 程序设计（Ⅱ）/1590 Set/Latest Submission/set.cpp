#include <cstring>
#include "set.hpp"
 Set:: Set(){
     size = 0;
 }
    // Create an set with some element.
 Set:: Set(int* m, int s){
   size = 0;
     int flag = 1;
        for(int i = 0;i<s;i++){
            for(int j = 0;j<size;j++){
                if(members[j]==m[i]){  
                    flag = 0;             
                    break;
                }
            }
            if(flag){
                members[size] = m[i];
                size++;
            }
           
           // append(m[i]);
        }
    }
    
    // append a element to set.
    // If element in the set, return false.
    // Or insert in set and return true.
bool Set::append(int e){
        for(int i = 0;i<size;i++){
            if(members[i]==e)
                return false;
        }
        members[size] = e;
        size++;
        return true;

    }
    
    // remove a element by its value from set.
    // If element in the set, then remove it and return true.
    // Or return false.
bool Set::remove(int e){
    for(int i = 0;i<size;i++){
        if(members[i]==e){
            for(int j = i;j<size-1;j++){
                members[j] = members[j+1];
            }
            size--;
            return true;
        }
    }
    return false;
}
    
    // return true if the set is empty, or return false.
bool Set::isEmptySet(){
    return size?false:true;
}
    
    // return set.
int* Set::getMembers(){
        return members;
    }
    

int Set::getSize(){
        return size;
    }
 
    // return false if element not in the set, or return true.
bool Set::isInSet(int e){
     for(int i = 0;i<size;i++){
            if(members[i]==e)
                return true;
    }
    return false;
}