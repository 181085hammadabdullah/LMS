#include "Date.h"
Date::Date(){
	day=-1;
	month=-1;
	year=-1;
}
Date::Date(int d,int m,int y){
	this->day=d;
	this->month=m;
	this->year=y;
}
Date::Date(const Date &obj){
	day=obj.day;
	month=obj.month;
	year=obj.year;
}
void Date::setday(int d)
{
	this->day=d;
}
void Date::setmonth(int m)
{
	this->month=m;
}
void Date::setyear(int y)
{
	this->year=y;
}
bool Date::validday(int d)
{
	if(d>0 && d<32)
		return true;
	else
		return false;
}
bool Date::validmon(int d)
{
	if(d>0 && d<13)
		return true;
	else
		return false;
}
bool Date::validyear(int d)
{
	if(d>1975 && d<2025)
		return true;
	else
		return false;
}
int Date::getd()
{
	return day;
}
int Date::getm()
{
	return month;
}
int Date::gety()
{
	return year;
}