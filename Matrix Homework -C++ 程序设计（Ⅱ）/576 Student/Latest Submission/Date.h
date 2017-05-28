#ifndef DATE_H
#define DATE_H
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
class Date {
 private:
  int _year;
  int _month;
  int _day;

 public:
  Date(int y, int m, int d) : _year(y), _month(m), _day(d) {}
  Date(string dateString) {
    char tmp;
    std::stringstream ss;
    ss << dateString;
    ss >> _year >> tmp >> _month >> tmp >> _day;
  }  // the format of dateString is like "2017-5-7"
  int getYear() const { return _year; }
  void setYear(int y) { _year = y; }
  int getMonth() const { return _month; }
  void setMonth(int m) { _month = m; }
  int getDay() const { return _day; }
  void setDay(int d) { _day = d; }
  bool operator==(Date& other) const {
    if (_year == other._year && _month == other._month && _day == other._day)
      return true;
    else
      return false;
  }
  bool operator<(Date& other) const {
    if (!(*this == other) && !(*this > other))
      return true;
    else
      return false;
  }
  bool operator>(Date& other) const {
    if ((_year > other._year) ||
        (_year == other._year && _month > other._month) ||
        _year == other._year && _month == other._month && _day > other._day)
      return true;
    else
      return false;
  }
  std::string toString() const {  // return a string like "year-month-day"
    ostringstream op;
    op << _year << "-" << _month << "-" << _day;
    return op.str();
  }
};

#endif
