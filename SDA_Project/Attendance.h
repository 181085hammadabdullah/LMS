#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <fstream>
#include <conio.h>
#include "Student.h"
using namespace std;
class Attendance
{
private:
	Date date;
	char Status;
	Student  student;
	string section;
	string course;
	int lecno;
public:
	Attendance();
	Attendance(Date d,char s);
	void setdata(Date d,char s,Student stud,string sec,string cour,int lecno);
	friend  ostream& operator<<(ostream &out,Attendance &obj)
	{
		out<<obj.course<<" "<<obj.section<<" "<<obj.student.getroll()<<" "<<obj.date<<" "<<obj.lecno<<" "<<obj.Status<<endl;
		return out;
	}
	void setStatus(char s);
	Date getDate();
	string getroll();
	int getlecno();
	string getcourse();
	string getsection();
};