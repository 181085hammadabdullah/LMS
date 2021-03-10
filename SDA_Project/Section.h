#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <fstream>
#include <conio.h>
#include "Evaluation.h"
#include "Teacher.h"
#include "Attendance.h"
#include "Marks.h"
using namespace std;
class Section 
{
private:
	//For usage of Aced_Off
	string Name;
	int no_of_seats;
	string course_code;
	Teacher T;
	int id;
	int total_Occupy_seats;
	
public:
	Section();
	Section(string N,int n_of_seat,string code);
	void setCourseCode(string code);
	void setdata1(string name,string course_code,int total_seats,int occupy_seats,string Teacher_username);
	void setTecaher(const Teacher obj);
	Section(const Section &obj);
	string getuser();
	friend  istream& operator>>(istream &in,Section &obj)
	{
		system("pause");
		cout<<"Enter the Name of Section(str): ";
		in>>obj.Name;
		while(obj.searchSection(obj.course_code,obj.Name)!=-1)
		{
		cout<<"A section with this Name in this Course is already Present Plz Enter a valid Name of Section(str): ";
		in>>obj.Name;
		}
		cout<<"Enter Total seats of section(int): ";
		in>>obj.no_of_seats;
		obj.total_Occupy_seats=0;
		obj.T.setusername("NO");
		return in;

	}
	friend  ostream& operator<<(ostream &out,Section &obj)
	{
		out<<obj.course_code<<" "<<obj.Name<<" "<<obj.no_of_seats<<" "<<obj.total_Occupy_seats<<" "<<obj.T.getusername()<<endl;
		return out;
	}
	//For Teachers
	void setEvulationNo(int n);
	void AddNewEvaluation(Evaluation obj);
	int getid();
	void Printdata();
	bool isSpace();
	void incseats();
	void decseats();
	string CourseCode();
	string GetName();
	string getTeacherid();
	void UpdateInput(string n);
	int searchSection(string course_Code,string section_name);
};
