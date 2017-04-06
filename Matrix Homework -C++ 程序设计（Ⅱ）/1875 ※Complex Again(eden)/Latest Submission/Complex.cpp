 #include "Complex.hpp"

Complex:: Complex(double real_, double imag_){
	real = real_;
	imag = imag_;
 }
 Complex::Complex(const Complex& other){
   	real = other.real;
   	imag = other.imag;
 }

ostream& operator << (ostream& os,Complex the){
	if(the.imag<0){
		if(the.real==0)
			os << the.imag << "i"<<endl;
		else
			os << the.real  << the.imag << "i"<<endl;
	}
	else if(the.imag==0){
		os << the.real;
	}
	else if(the.imag>0){
		if(the.real==0)
			os << the.imag << "i"<<endl;
		else
			os << the.real << "+" << the.imag << "i"<<endl;
	}
	return os;
}
 
 Complex& Complex::operator+=(const Complex& other){
	real = real + other.real;
	imag = imag + other.imag;
	return *this;
}

Complex& Complex::operator-=(const Complex& other){	
	real = real - other.real;
	imag = imag - other.imag;
	return *this;
 }

 Complex& Complex::operator*=(const Complex& other){
 	Complex temp;
	temp.real = real * other.real-imag*other.imag;
	temp.imag = real*other.imag+imag*other.real;
	*this = temp;
	return *this;
  }

 Complex& Complex::operator/=(const Complex& other){
 	Complex temp;
	temp.real = (real*(other.real)+imag*(other.imag))/(other.real*other.real+other.imag*other.imag);
	temp.imag = ((imag*other.real)-real*other.imag)/(other.real*other.real+other.imag*other.imag);
	*this = temp;
	return (*this);
   }     //A friend function to print Complex numbers like a+bi where a is the real part and b is the imaginary part

Complex Complex::operator+(const Complex& other){
	Complex temp;
	temp.real = real + other.real;
	temp.imag = imag + other.imag;
	return temp;
}

Complex Complex::operator-(const Complex& other){
 	Complex temp;
	temp.real = real - other.real;
	temp.imag = imag - other.imag;
	return temp;
 }

 Complex Complex::operator*(const Complex& other){
  	Complex temp;
	temp.real = real * other.real-imag*other.imag;
	temp.imag = real*other.imag+imag*other.real;
	return temp;
  }

 Complex Complex::operator/(const Complex& other){
  	Complex temp;
	temp.real = (real*(other.real)+imag*(other.imag))/(other.real*other.real+other.imag*other.imag);
	temp.imag = ((imag*other.real)-real*(other.imag))/(other.real*other.real+other.imag*other.imag);
	return temp;
   }
 bool Complex::operator==( const Complex &other){
   	if(real==other.real&&imag==other.imag)
   		return true;
   	else
   		return false;
   }
 bool Complex::operator!=(const Complex &other){
 	return (*this)==other?false:true;
 }


