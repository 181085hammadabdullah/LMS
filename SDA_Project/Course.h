#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <fstream>
#include <conio.h>
#include "Section.h"

using namespace std;
class Course
{
private:
	string Name;
	string code;
	int credit_Hours;
	int total_sections;
	Section *sections;
	int section_no;

public:
	Course();
	Course(string n,string c,int c_h,int no_of_s);
	Course(const Course &obj);
	friend  istream& operator>>(istream &in,Course &obj)
	{
		
		cout<<"Enter the Name of Course(str): ";
		in>>obj.Name;
		cout<<"Enter The Course Code(str): ";
		in>>obj.code;
		while(obj.SearchCourse(obj.code)!=-1)
		{
			cout<<"The Code U Enter is Already been used Plz Enter the  valid Course Code(str): ";
			in>>obj.code;
		}
		cout<<"Enter Credit Hours(int): ";
		in>>obj.credit_Hours;
		cout<<"Enter Total Sections(int): ";
		in>>obj.total_sections;
		return in;

	}
	friend  ostream& operator<<(ostream &out,Course &obj)
	{
		out<<obj.code<<" "<<obj.Name<<" "<<obj.credit_Hours<<" "<<obj.total_sections<<endl;
		return out;
	}
	void Addsection(const Section obj);
	string getcode();
	void setTotalsections(int n);
	void setdata(string n,string c,int c_h,int no_of_s,Section *secs,int sec_no);
	void setdata1(string n,string c,int c_h,int no_of_s);
	void Printdata();
	float GetHours();
	void updatedInput(string u);
	int SearchCourse(string code);
};