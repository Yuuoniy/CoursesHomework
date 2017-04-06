#ifndef COMPLEX_HPP_
#define COMPLEX_HPP_

#include <string>
#include <cstdio>
#include <iostream>
using namespace std ;

class Complex{
	public:
		Complex( double real = 0.0, double imaginary = 0.0 ) ;			
		Complex add( const Complex &right ) ;
		Complex subtract( const Complex &right ) ;
		void printComplex() ;
		void setComplexNumber( double rp , double ip );
	private:
		double realPart;
		double imaginaryPart;
};
#endif
