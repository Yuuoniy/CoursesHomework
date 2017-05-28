#include "Vector.h"
#include <iostream>

 Vector::Vector(string _name, int length , int *other):name(_name),dimension(length){
  param = new int[length+1];
  for (int i = 0; i < length; ++i)
  {
  	param[i] = other[i];
  }
  cout << "construct a vector called "<< name << ".\n";
 }
 Vector::Vector(const Vector &otherVec){
 	name = otherVec.name;
 	dimension = otherVec.dimension;
 	param = new int [dimension+1];
 	for (int i = 0; i < dimension; ++i)
 	{
 		param[i] = otherVec.param[i];
 	}
 	  cout << "copy a vector called "<< name << ".\n";

 }
 Vector::~Vector(){
 	cout << "release memory from a vector called " << name << ".\n";
 	delete [] param;
 }
 void Vector::isEqual(const Vector & other){
 	int nameflag = 0;
 	int valueflag = 0,loop = 0;
 	if(name ==other.name){
		nameflag = 1;
 	}
 	if (other.dimension!=dimension){valueflag = 0;}
 	else{
 		for ( loop = 0; loop < dimension; ++loop)
 			if(param[loop]!=other.param[loop])
 				break;					
 		if (loop==dimension)
 			valueflag = 1;
 	}
 	if(nameflag) 
 		cout << "same name, ";
 	else
 		cout<< "different name, ";
 	if(valueflag)
 		cout << "same value.\n";
 	else
 		cout << "different value.\n";
 }
 void Vector::setName(string _name){
 	name = _name;
 }
 void Vector::print(){
 	cout << name << "(";
 	for (int i = 0; i < dimension-1; ++i)
 	{
 		cout << param[i] << ", ";
 	}
 	cout << param[dimension-1]<< ")" << endl;
 }