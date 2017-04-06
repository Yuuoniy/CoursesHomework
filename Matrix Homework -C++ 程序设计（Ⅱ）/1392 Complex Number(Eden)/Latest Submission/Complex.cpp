 #include "Complex.hpp"

Complex::Complex( double real, double imaginary ) {
 setComplexNumber( real, imaginary );
 } // end Complex constructor

Complex Complex::add( const Complex &right ) {
	Complex temp;
	temp.realPart = realPart+right.realPart;
	temp.imaginaryPart = imaginaryPart+right.imaginaryPart;
	return temp;
}
Complex Complex::subtract( const Complex &right ) {
 /* Write a statement to return a Complex object. Subtract
  the realPart of right from the realPart of this Complex
  object and subtract the imaginaryPart of right from
  the imaginaryPart of this Complex object */
  	Complex temp;
	temp.realPart = realPart-right.realPart;
	temp.imaginaryPart = imaginaryPart-right.imaginaryPart;
	return temp;
} // end function subtract


void Complex::printComplex() {
 cout << '(' << realPart << ", " << imaginaryPart << ')';
} // end function printComplex

void Complex::setComplexNumber( double rp , double ip  ) {
 realPart = rp;
 imaginaryPart = ip;
} // end function setComplexNumber