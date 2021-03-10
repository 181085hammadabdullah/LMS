#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <fstream>
#include <conio.h>
using namespace std;
class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(int d,int m,int y);
	Date(const Date &obj);
	friend  ostream& operator<<(ostream &out, Date &obj)
	{
		out<<obj.day<<"/"<<obj.month<<"/"<<obj.year;
		return out;
	}
	friend  istream& operator>>(istream &in, Date &obj)
	{
		cout<<"Enter The Day: ";
		in>>obj.day;
		while(obj.validday(obj.day)==false)
		{
			
			cout<<"Plz Enter The Correct Day: ";
			in>>obj.day;
		}
		cout<<"Enter The Month: ";
		in>>obj.month;
		while(obj.validmon(obj.month)==false)
		{
			cout<<"Plz Enter The Correct Month: ";
			in>>obj.month;
		}
		cout<<"Enter The Year: ";
		in>>obj.year;
		while(obj.validyear(obj.year)==false)
		{
			cout<<"Plz Enter The Correct Year: ";
			in>>obj.year;
		}
		return in;
	}
	void setday(int d);
	void setmonth(int m);
	void setyear(int y);
	bool validday(int d);
	bool validmon(int d);
	bool validyear(int d);
	int getd();
	int getm();
	int gety();
};