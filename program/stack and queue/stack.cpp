#include "stack.hpp"
 // you can not push an element when the storage is full 
  void stack::push(int value){
      if(isFull())
        return ;
      else
        storage[++top] = value;

  }

  // you can not pop an element when the storage is empty 
  void stack::pop(void){
      if(isEmpty())
        return ;
      else
        top--;
  }

  // when the stack is empty, you should return 0 
  int stack::peek(void){
      if(isEmpty())
        return 0;
      else
        return storage[top];
  }

  bool stack::isEmpty(void){
      return top==-1?true:false;
  }

  bool stack::isFull(void){
      return top==max_size-1?true:false;
  }

  void stack::clear(void){
      top=-1;
  }