#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <fstream>
#include <conio.h>
#include "Semester.h"
#include "Date.h"
using namespace std;
class Course_Reg_Info
{
private:
	Date Reg_Starting_Date;
	Date Reg_Ending_Date;
	Date With_Draw_Deadline;
	bool actve_Reg;
	bool active_with_drawdeadline;
	Semester s;
public:
	Course_Reg_Info();
	Course_Reg_Info(Date s,Date e,Date wd,Semester sem);
	friend  istream& operator>>(istream &in, Course_Reg_Info &obj)
	{
		system("pause");
		cout<<"Enter Name of Semester: ";
		string name;
		in>>name;
		obj.s.setname(name);
		while(obj.searchSemester(obj.getsemname())==-1)
		{
			cout<<"The semester Name u enter is Not Found Present Plz Enter A Valid Semester name: ";
			in>>name;
			obj.s.setname(name);
		}
		while(obj.searchCourse_Reg_Info(obj.getsemname())!=-1)
		{
			cout<<"The semester Name u enter Has Already Course Registration Info Enter Another Semester : ";
			in>>name;
			obj.s.setname(name);
		}
		
		cout<<"Enter Registration starting date: ";
		in>>obj.Reg_Starting_Date;
		cout<<"Enter Registration Ending date: ";
		in>>obj.Reg_Ending_Date;
		cout<<"Enter With Draw Deadline date: ";
		in>>obj.With_Draw_Deadline;
		obj.actve_Reg=false;
		obj.active_with_drawdeadline=false;
		return in;

	}
	friend  ostream& operator<<(ostream &out, Course_Reg_Info &obj)
	{
		out<<obj.s.getname()<<" "<<obj.Reg_Starting_Date<<" "<<obj.Reg_Ending_Date<<" "<<obj.With_Draw_Deadline<<" "
			<<obj.actve_Reg<<" "<<obj.active_with_drawdeadline<<endl;
		return out;
	}
	void setdata(Date s,Date e,Date wd,string sem,bool reg,bool withdraw);
	void Printdata();
	void openReg();
	void closedReg();
	void openwithdraw();
	void closedwithdraw();
	bool checkregperiod();
	bool checkwithdrawPeriod();
	void updatesemname(string name);
	void updatewithdrawdate(Date d);
	string getsemname();
	int searchCourse_Reg_Info(string sem_name);
	int searchSemester(string sem_name);
	void updateInput();
	void setsem_name(string name);
	void PrintCourseDates();
	void PrintWithDrawDates();
	Date getwithdraw();
};