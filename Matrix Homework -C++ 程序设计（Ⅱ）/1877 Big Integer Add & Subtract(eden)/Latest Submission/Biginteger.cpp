#include "Biginteger.h"
#include <cstring>
using namespace std;
BigInteger operator+(const BigInteger& left, const BigInteger& right){
   if(left.size_<right.size_){
     return (right+left);
  }
  else{
    BigInteger temp;
   temp.size_ = left.size_+1;
   temp.data_ = new int[left.size_+1];
   temp.data_[0]=0;
   for(int i = 1;i<=right.size_;i++){
      temp.data_[left.size_-i+1] = right.data_[right.size_-i]+left.data_[left.size_-i];
   }
   for(int i = 0;i<(left.size_-right.size_);i++){
      temp.data_[i+1] = left.data_[i]; 
   }
   for(int i = left.size_;i>0;--i){
      if(temp.data_[i]>9){
          temp.data_[i-1] += temp.data_[i]/10;
          temp.data_[i] %= 10;
      }
  }
   return temp;
 }
}

BigInteger operator-(const BigInteger& left, const BigInteger& right){
  BigInteger temp;
  temp.size_ = left.size_;
  temp.data_ = new int[left.size_];
  int flag = 0,sub = 0;
  for(int i = 1;i<=right.size_;i++){
      sub = left.data_[left.size_-i]+10-right.data_[right.size_-i]-flag;
      temp.data_[left.size_-i] = (left.data_[left.size_-i]+10-right.data_[right.size_-i]-flag)%10;
      flag = sub<10?1:0;
  }

  int diff = left.size_ - right.size_;
  for(int i = diff;i>0;i--){
      temp.data_[i-1] = left.data_[i-1]-flag;
      flag = 0;
  }
  return temp;
}

ostream& operator<<(ostream& out, const BigInteger& Bint){
  int flag = 1, i = 0;
  while(Bint.data_[i++]==0&&i<=Bint.size_)
    continue;
  if(i>Bint.size_)
    out << "0\n";
  else{
    for(i--;i<Bint.size_;i++)
      out << Bint.data_[i];
   // out << endl;  
  }
  return out;
}
 

  BigInteger::BigInteger(){
      size_ = 0;
      data_ = NULL;
  }

  BigInteger:: BigInteger(const string& number){
    size_ = number.length();
    data_ = new int[size_];
    for(int i = 0;i<size_ ;i++){
      data_[i] = number[i]-'0';
    }
  }

  BigInteger::BigInteger(const BigInteger& other){
    size_ = other.size_;
    data_ = new int[size_];
    memcpy(data_,other.data_,sizeof(int)*size_);
  }

  BigInteger::~BigInteger(){

    delete [] data_;
  }

 
