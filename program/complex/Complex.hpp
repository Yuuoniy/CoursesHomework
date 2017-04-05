 #ifndef Complex_hpp
#define Complex_hpp
#include <iostream>
using namespace std;
class Complex {

      friend ostream& operator<<(ostream& os,Complex the);//A friend function to print Complex numbers like a+bi where a is the real part and b is the imaginary part

public:
   Complex(double real_= 0.0, double imag_= 0.0);
   Complex( const Complex& other);

   Complex& operator+=(const Complex &other);

   Complex& operator-=(const Complex &other);


   Complex& operator*=(const Complex &other);

   Complex& operator/=(const Complex &other);
   Complex operator+(const Complex &other);

   Complex operator-(const Complex &other);


   Complex operator*(const Complex &other);

   Complex operator/(const Complex &other);
   bool operator==(const Complex &other);
   bool operator!=(const Complex &other);


   void SetReal(double re){real = re;};
   void SetImag(double im){imag = im;};
private:
   double real; 
   double imag; 
};

#endif
