#include "MyInteger.hpp"
#include <math.h>
#include <cstring>

MyInteger:: MyInteger(int value_){
	value = value_;
 }

int MyInteger::getValue() const{
    	return value;
    }
bool MyInteger:: isEven() const{
	return value%2==0?true:false;
    }
bool MyInteger:: isOdd() const{
    	return value%2==0?false:true;
    }
bool MyInteger:: isPrime() const{
	if(value==2)
		return true;
	else if(value==1)
		return false;
	else{
		int find = 1;
		for(int i =2;i<=sqrt(value);i++){
			if(value%i==0){
				find = 0;
				break;
			}
		}
		return find?true:false;		
	}
	
}
bool MyInteger::isEven(int value_){
	return value_%2==0?true:false;
    }
bool MyInteger:: isOdd(int value_){
	return value_%2==0?false:true;
}
bool MyInteger:: isPrime(int value_){
	if(value_==2)
		return true;
	else if(value_==1)
		return false;
	else{
		int find = 1;
		for(int i =2;i<=sqrt(value_);i++){
			if(value_%i==0){
				find = 0;
				break;
			}
		}
		return find?true:false;		
	}
}
bool MyInteger:: isEven(const MyInteger& other){
	return (other.value)%2==0?true:false;
}
bool MyInteger:: isOdd(const MyInteger& other){
    	return (other.value)%2==0?false:true;
    }
bool MyInteger:: isPrime(const MyInteger& other){
	if(other.value==2)
		return true;
	else if(other.value==1)
		return false;
	else{
		int find = 1;
		for(int i =2;i<=sqrt(other.value);i++){
			if(other.value%i==0){
				find = 0;
				break;
			}
		}
		return find?true:false;		
	}
	//return find?true:false;
}
bool MyInteger:: equals(int other){
	return other==value?true:false;
}
bool MyInteger::equals(const MyInteger& other){
	return (other.value)==value?true:false;
}
int MyInteger:: parseInt(const std::string& str){
	int len = str.length();
	int len2 = len,value = 0;
	
	if(str[0]=='-'){
		for(int i = 1;i<len;i++){
			value = value*10+str[i]-'0';			
		}
		return -value;
	}
	else{
		for(int i = 0;i<len;i++){
		value = value*10+str[i]-'0';		
		}
		return value;
	}
	
	//return value;
	//int num = integer.parseInt(str);
}
