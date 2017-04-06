#include "user.hpp"
bool alipay::User::verifyPasswordFormat(const std::string &password){
	int len = password.length();
  if(len>20||len<8)
		return false; 
  for(int i = 0;i<len;i++){
    if((password[i]<'0'||password[i]>'9')&&(password[i]<'a'||password[i]>'z')&&(password[i]<'A'||password[i]>'Z'))
      return false;
  }
  
}
bool alipay::User::verifyUsernameFormat(const std::string &username){
		int len = username.length();
  if(len>20||len<6)
		return false; 
  for(int i = 0;i<len;i++){
    if((username[i]<'0'||username[i]>'9')&&(username[i]<'a'||username[i]>'z')&&(username[i]<'A'||username[i]>'Z'))
      return false;
  }
}
bool alipay::User::verifyPhoneFormat(const std::string &phone){
	int len = phone.length();
  if(len!=13)
		return false; 
  for(int i = 0;i<len;i++){
    if((phone[i]<'0'||phone[i]>'9'))
      return false;
  }
	
}
 
 
bool alipay::User::setUsername(const char *username){
  if(verifyUsernameFormat(username)){
    this->username = username;
     return true;
  }
   
  else 
    return false;
 } 
  bool alipay::User::setPassword(const char *new_password, const char *old_password){
    std::string oldpassword = old_password;
    if(oldpassword==password&&verifyPasswordFormat(new_password)){
      this->password = new_password;
      return true;
    }
    else
      return false;
} 
  bool alipay::User::setPhone(const char *new_phone){
    if(verifyPhoneFormat(new_phone)){
      this->phone = new_phone;
      return true;
    }
    else 
      return false;
} 
  bool alipay::User::setGender(Gender::Gender gender){
    if(gender==Gender::Unknown)
      return false;
    else{    
    this->gender = gender;
    return true;
    }
} 
 
 
  std::string alipay::User::getUsername(void){
    return username;
  } 
  std::string alipay::User::getPhone(void){
    return phone;
  } 
  alipay::Gender::Gender alipay::User::getGender(void){
    return gender;
  } 
  

  long long int alipay::User::getMoneyAmount(const char *password){
    if(this->password==password)
      return balance;
  } 
  bool alipay::User::deposit(long long int amount){
    this->balance +=amount;
    return true;
  } 
  bool alipay::User::withdraw(long long int amount, const char *password){
    if(this->password==password&&amount<=balance&&amount>=0){
      balance-=amount;
      return true;
    }
    else
      return false;
  } 


 