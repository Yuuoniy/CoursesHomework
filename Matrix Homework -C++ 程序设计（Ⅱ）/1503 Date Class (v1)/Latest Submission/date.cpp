#include "date.hpp"

Date::Date(int year_ = 2017,int month_ = 1,int day_ = 28){
  year = year_;
  month = month_;
  day = day_;
  normalize();
}
Date::Date(){
  year = 2017;
  month = 1;
  day = 28;
}
bool Date::equals(const Date& another)const{
  if(another.year==year&&another.month==month&&another.day==day)
    return true;
  else
    return false;
}
bool Date::smallerThan(const Date& comp)const{
if(year<comp.year)
  return true;
else if(year==comp.year&&month<comp.month)
  return true;
else if(year==comp.year&&month==comp.month&&day<comp.day)
  return true;
else 
  return false;
}
void Date::normalize(){
  if(month>12){
    year +=(month/12);
    month %= 12;
  }
  if(month==0){
     month = 12;
     --year;
   }
  
  while(day>daysOfMonth(year,month)){   
   day -=daysOfMonth(year,month);
     month++;
    if(month>12){
      year++;
      month = 1;
    }
  } 
}