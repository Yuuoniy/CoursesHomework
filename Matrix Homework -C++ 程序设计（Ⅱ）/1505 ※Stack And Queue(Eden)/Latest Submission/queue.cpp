 #include "queue.hpp"

 // you can not push an element when the storage is full
  void queue::push(int value){
      if(isFull())
        return ;
      else {
        storage[rear++] = value;
        rear%=max_size;
      }

  }

  // you can not pop an element when the storage is empty
  void queue::pop(void){
      if(isEmpty())
        return ;
      else{
        head++;
        head %=max_size;
      }

  }

  // when the queue is empty, you should return 0
  int queue::front(void){
      if(isEmpty())
        return 0;
      else
        return storage[head];
  }

  // when the queue is empty, you should return 0
  int queue::back(void){
      if(isEmpty())
        return 0;
      else
        return storage[rear-1];
  }

  bool queue::isFull(void){
      return (rear+1)%max_size==head?true:false;
  }

  bool queue::isEmpty(void){
      return (head==rear)?true:false;
  }

  void queue::clear(void){
      head = rear = 0;
  }