#ifndef INSERVICE      
#define INSERVICE
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
class Person
{
private:
  string name;
  int sex;
public:
  Person( string _name,int _sex){
    name = _name;
    sex = _sex;
    cout << "Construct Person" <<endl;
  }
  string getName();
  int getSex();
  ~Person(){
    cout << "Destruct Person" <<endl;
  }
  
};

class Student:public virtual Person 
{
private:
  string sno;
public:
  Student(string _name,int _sex,string _sno):Person(_name,_sex){
    sno = _sno;
   cout << "Construct Student" <<endl; 
  }
  string getSno();
  ~Student(){
    cout << "Destruct Student" <<endl;
  }
  
};

class Worker:public virtual  Person
{
private:
  string wno;
public:
  Worker(string _name,int _sex,string _wno):Person(_name,_sex){
    wno = _wno;
    cout << "Construct Worker" <<endl;
  }
  ~Worker(){
    cout << "Destruct Worker" <<endl;
  }
  string getWno();
  
};
class InService:public Student,public Worker
{
public:
  InService(string _name,int _sex,string _sno,string _wno):Person(_name,_sex),Worker(_name,_sex,_wno),Student(_name,_sex,_sno){
    cout << "Construct InService" <<endl;
  }
  ~InService(){
    cout << "Destruct InService" << endl;
  }
  
};

string Person::getName(){
  return name ;
}
int Person::getSex(){
  return sex ;
}
string Student::getSno(){
  return sno ;
}
string Worker:: getWno(){
 return wno ;
}
#endif
