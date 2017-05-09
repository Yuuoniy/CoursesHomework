#ifndef SHAPE
#define SHAPE
#include <cmath>

// #define pi acos(-1. 0)

class base {
 public:
  base() { pi = acos(-1.0); }
  ~base() {}
  virtual double area() {}

 protected:
  double pi;
};

class circle : public base {
 public:
  circle(double rad_) : base() { rad = rad_; }
  ~circle() {}
  double area() { return pi * rad * rad; }

 private:
  double rad;
};
class rectangle : public base {
 public:
  rectangle(double x_, double y_) : base() {
    x = x_;
    y = y_;
  }
  ~rectangle();
  double area() { return x * y; }

 protected:
  double x;
  double y;
};

class square : public rectangle {
 public:
  square(double x_) : rectangle(x_, x_) {}
  ~square() {}
  double area() { return rectangle::area(); }
};

;
class triangle : public base {
 public:
  triangle(double x_, double y_, double z_) : base() {
    x = x_;
    y = y_;
    z = z_;
  }
  ~triangle();
  double area() {
    double p = (x + y + z) / 2;
    double result = sqrt(p * (p - x) * (p - y) * (p - z));
    return result;
  }

 private:
  double x;
  double y;
  double z;
};
#endif
