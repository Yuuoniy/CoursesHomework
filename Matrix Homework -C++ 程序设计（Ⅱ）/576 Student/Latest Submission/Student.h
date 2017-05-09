#ifndef STUDENT_H
#define STUDENT_H
#include <cstdlib>
#include "Date.h"
#include "Person.h"

class Student : public Person {
 public:
  Student(string name, int age, Date date)
      : Person(name, age),
        graduateDate(date.getYear(), date.getMonth(), date.getDay()) {}

  ~Student() {}
  void set(Date date) {
    graduateDate.setYear(date.getYear());
    graduateDate.setMonth(date.getMonth());
    graduateDate.setDay(date.getDay());
  }
  void set(int age) { Person::set(age); }
  void set(string name) { Person::set(name); }
  void sayHi() const {
    Person::sayHi();
    Date today(2017, 5, 7);
    if (graduateDate > today)
      cout << "I will graduate on " << graduateDate.toString() << "." << endl;
    else if (graduateDate == today)
      cout << "I graduated today!" << endl;
    else
      cout << "I have graduated on " << graduateDate.toString() << "." << endl;
  }

 private:
  Date graduateDate;
};

#endif
