#include "array.hpp"
  typedef int* pointer;
  typedef unsigned int size_t;
  typedef int data_type;
 array::array(size_t size){
    _data = new int [size];
    _size = size;
  }
  // destructor
  array::~array(){
    delete [] _data;

  }

  
  // Capacity
  // Return maximum size
  size_t array::max_size(void){
    return _size;
  }
 

  data_type& array::at(const data_type& i){
    return _data[i];
  }

  data_type& array::front(){
    return _data[0];
  }

  data_type& array::back(){
    return _data[_size-1];
  }
  // Get pointer to data
  pointer array::data(){
    return _data;
  }
 

  void array::fill(const data_type& value){
    for(int i = 0;i<_size;i++){
      _data[i] = value;
    }
  }
  // Resize the array (newSize > oldSize)
  void array::resize(int newSize){
   // _size = newSize;
    int oldSize = _size;
    _size = newSize;
    int *olddata = _data;
    _data = new int [newSize];
    for(int i = 0;i<oldSize;i++){
        _data[i] = olddata[i];
    }
    delete [] olddata;

  }
  // Sort the array in the section [from, to)
  void array::sort(int from, int to){
    for(int i = from;i<to-1;i++){
      for(int j = i+1;j<to;j++){
        if(_data[j]<_data[i]){
          int temp = _data[i];
          _data[i] = _data[j];
          _data[j] = temp;

        }
      }
    }
  }

 

 