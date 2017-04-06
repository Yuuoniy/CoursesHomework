#include <cstring>
#include <cstdio>
#include <iostream>

std::string change1(const char* cstr){
	std::string s = cstr;
	return s;
}
void change2(std::string str, char* cstr){
	int len = str.length();
	str.copy(cstr,len,0);	
}
