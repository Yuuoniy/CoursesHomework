#include <cstring>
#include "EasyString.hpp"
void Assign(char * &str, int &n){
	str = new char [n+1] ;
}
void AddTwo(string &result, char * &str1, char * &str2){

	string temp1 = str1;
	string temp2 = str2;
	result = temp1+temp2;
	delete [] str1;
	delete [] str2;

}