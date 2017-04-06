 #include "date.hpp"

 int Date::year() const{
 	return year_;
 }
 
  int Date::month() const{
  	return month_;
  }
  int Date::day() const{
  	return day_;
  }
  void Date::setDate(int year, int month, int day){
  	year_ = year;
  	month_ = month;
  	day_ = day;
  }
int Date::daysOfMonth(int year, int month) const{
  	int flag = 0,daysof = 0;
  	if(year%400==0||(year%4==0&&year%100!=0))
  		flag = 1;
	if((month<8&&month%2!=0)||(month>=8&&month%2==0))
		daysof = 31;
	else if(month ==2)
		daysof = 28+flag;
	else
		daysof = 30;
	return daysof;  
  }
 
  void Date::increment(){
  	int daysof = daysOfMonth(year(),month());
  	day_ = ++day_;
  	if(day_>daysof){	  
  		month_++;
  		day_ = day_%daysof;
  	}
  	if(month_>12){
  		year_++;
  		month_ %= 12;
	  }
  	
  }
  void Date::decrement(){
  	
  	int temp = month()-1,daysof = 0;
  	if(temp ==0 )
  		daysof = 31;
  	else
  		daysof = daysOfMonth(year(),temp);
  	day_--;
  	if(day_ == 0){
  		day_ = daysof;
  		month_--;
	  }
	if(month_==0){
		month_ = 12;
		year_ --;
	}
}