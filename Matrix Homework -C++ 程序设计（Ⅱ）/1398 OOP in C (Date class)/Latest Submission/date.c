#include "date.h"
#include <stdlib.h>
#include <stddef.h>
int daysOfMonth(int year, int month) {
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
Date* CreateDate(int year, int month, int day){
	Date* temp=(Date*) malloc(sizeof(Date));
	temp->day = day;
	temp->month = month;
	temp->year = year;
	return temp;
}
void DestroyDate(Date** p){
	free(*p);
	*p = NULL;
}
Date* CopyDate(const Date* date){
	Date * temp = (Date*)malloc(sizeof(Date));
	temp->day = date->day;
	temp->month = date->month;
	temp->year = date->year;
	return temp;
}

int GetYear(const Date* date){
	return date->year;
}
int GetMonth(const Date* date){
	return date->month;
}
int GetDay(const Date* date){
	return date->day;
}
void SetYear(Date* date, int year){
	date->year = year;
}
void SetMonth(Date* date, int month){
	date->month = month;
}
void SetDay(Date* date, int day){
	date->day = day;
}
void SetDate(Date* date, int year, int month, int day){
	date->day = day;
	date->month = month;
	date->year = year;
}

char* GetDateString(const Date* date){
	int length_of_date_string = 10;
    char *date_string = (char*)malloc(length_of_date_string + 1);
    snprintf(date_string,
            length_of_date_string + 1,
            "%04d-%02d-%02d",
            date->year, date->month, date->day);
    return date_string;
}
void DestroyDateString(char** p){
	free(*p);
	*p = NULL;
}

void IncreaseDate(Date* date){
  	int daysof = daysOfMonth(date->year,date->month);
  	date->day++; 
  	if(date->day>daysof){	  
  		date->month++;
  		date->day = 1;
  	}
  	if(date->month>12){
  		date->year++;
  		date->month %= 12;
	  }
}
void DecreaseDate(Date* date){
	int temp = date->month-1,daysof = 0;
  	if(temp ==0 )
  		daysof = 31;
  	else
  		daysof = daysOfMonth(date->year,temp);
  	date->day--;
  	if(date->day == 0){
  		date->day = daysof;
  		date->month--;
	  }
	if(date->month==0){
		date->month = 12;
		date->year--;
	}
}
