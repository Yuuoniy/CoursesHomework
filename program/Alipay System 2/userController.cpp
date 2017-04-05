#include "userController.hpp"
#include <sstream>
#include <cstring>
#include <iostream>

using namespace Alipay;
using namespace std;

int userController::getUserIndex(const char* username) const{
  for(int i = 0;i<usercount;i++){
    if(strcmp(username,users[i]->getUsername())==0)
      return i;
  }
}
 

userController::userController(double interest_rate){
    this->interest_rate = interest_rate;
    usercount = 0;   
}

userController::~userController(){
  for(int i = 0;i<usercount;i++){
    delete users[i];
  }
}
bool userController::createUser(const char* username, const char* password){
  if(usercount>=MAX_USER)
      return  false;
  
  int userlen = strlen(username);
  int passlen = strlen(password);
  if(userlen>20||userlen<6||passlen>20||passlen<8)
    return false;
  else{
     users[usercount] = new user(username,password);
     usercount++;
     return true;
  }
}

bool userController::deposite(const char* username, double amount){
  for(int i = 0;i<usercount;i++){
     if(strcmp(username,users[i]->getUsername())==0){
       users[i]->deposite(amount);
       return true;
     }
  }
  return false;
}

bool userController::withdraw(const char* username, double amount){
    for(int i = 0;i<usercount;i++){
     if(strcmp(username,users[i]->getUsername())==0){
       return users[i]->withdraw(amount)?true:false;
     }
  }
  return false;
}

std::string userController::getUserInfoByName(const char* username) const{
   for(int i = 0;i<usercount;i++){
     if(strcmp(username,users[i]->getUsername())==0){
        ostringstream info;
        info <<"username:"<<users[i]->getUsername()<<"\npassword:*********"<<"\nbalance:"<< users[i]->getBalance();
        return info.str();
     }
  }
  string temp;
  return temp;
}
int userController::getUserCount(void) const{
  return usercount;
}

bool userController::removeUserByUsername(const char* username){
  for(int i = 0;i<usercount;i++){
     if(strcmp(username,users[i]->getUsername())==0){
      user* temp =  users[i];
      for(i;i<usercount-1;i++){
        users[i] = users[i+1];
      }
      usercount--;
      delete temp;
      return true;
     }
  }
  return false;
}
bool userController::setInterest(double interest){ 
      if(interest<0)
        return false;
      else
        interest_rate = interest;
      return true;
}
void userController::payInterest(void){
  for(int i = 0;i<usercount;i++){
    users[i]->deposite(users[i]->getBalance()*interest_rate);
  }
}
