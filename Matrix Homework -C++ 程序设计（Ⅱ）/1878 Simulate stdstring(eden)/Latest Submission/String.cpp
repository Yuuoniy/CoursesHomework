#include "String.h"
#include <cstring>
#include <string>
using namespace std;

char String::_error_sign = '0';
String::String(){
    _length = _size = 0;
    _buff = NULL;
 }
String::String(const char *src){
    _length = _size = 0;
    _buff = NULL;
    (*this) = src;
 }
String::String(const String &src){
    _length = _size = 0;
    _buff = NULL;
   (*this) = src;
 }

String::~String(){
    delete [] _buff;
    }
    // member methods
void  String::assign(const char *src){
    delete [] _buff;
    _length = strlen(src);
    _size = _length+1;
    _buff = new char[_size];
    strcpy(_buff,src);
 }

void  String::append(const char &other){
    if(_length==0){
        _buff = new char[2]; 
        _buff[0] = other;
        _buff[1] = '\0';
        _length++;
    }
    else{
        char temp[_length+1]={0};
        strncpy(temp,_buff,_length);
        delete []_buff;
        _length++;
        _size = _length+1;
        _buff = new char[_size];
        strncpy(_buff,temp,_length);
        _buff[_length-1] = other;
        _buff[_length] = '\0';
        
        
    }
 }


void  String::clear(){
    delete [] _buff;
    _buff = NULL;
    _size = _length = 0;
 }
int  String::compare(const String &other) const{
    int result = strcmp(_buff,other._buff);
    if(result>0)
        return 1;
    else
        return result==0?0:-1;
 }

const char*  String::c_str() const{
    return _buff;
 }

bool  String::empty() const{
    return _length==0?true:false;
 }
 
int  String::find(const String &other, int pos ) const{
    char *pch = strstr(_buff,other._buff);
    int diff = pch-_buff;
    return pch==NULL?_length:diff;
 }

int  String::length() const{
    return _length;
 }

String  String::substr(const int &pos, const int &count) const{
    String temp;
    temp._length = count;
    temp._size = temp._length+1;
    temp._buff = new char[temp._size];
    strncpy(temp._buff,_buff+pos,count);
    temp._buff[count] = '\0';
    return temp;
 }
    // overload operators
char&  String::operator[](const int &index){
    return _buff[index];
 }

void  String::operator=(const String &other){  
    clear();
    _length = other._length;
    _size = _length+1;
    _buff = new char[_size];
    strncpy(_buff,other._buff,_size);
    
}

void  String::operator=(const char *src){
    clear();
    _length = strlen(src);
    _size = _length+1;
    _buff = new char[_size];
    strncpy(_buff,src,_size);
 }

String  String::operator+(const String &other) const{
    String temp;
    temp._length = (*this).length()+other.length();
    temp._size = temp._length+1;
    temp._buff = new char[temp._size];
    for(int i = 0;i<temp._size;i++)
        temp._buff[i] = '\0';
    strncpy(temp._buff,_buff,_length);
    strncat(temp._buff,other.c_str(),other._length+1);
    return temp;
 }

bool  String::operator<(const String &other) const{
    return compare(other)==-1?true:false;
 }

bool  String::operator<=(const String &other) const{
    return compare(other)==1?false:true;
 }

bool  String::operator>(const String &other) const{
    return compare(other)==1?true:false;
 }

bool  String::operator>=(const String &other) const{
    return compare(other)==-1?false:true;
 }

bool  String::operator==(const String &other) const{
    return compare(other)==0?true:false;
 }

bool  String::operator!=(const String &other) const{
    return compare(other)!=0?true:false;
 }
 std::ostream& operator<<(std::ostream& out, const String &str){
    if(str._length!=0)
        out << str._buff;
    return out;
 }

