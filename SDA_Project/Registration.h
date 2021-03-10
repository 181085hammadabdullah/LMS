#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <fstream>
#include <conio.h>
#include "Section.h"
#include "Semester.h"
#include "Student.h"
using namespace std;
class Registration
{
private:
	Section Sec;
	Student  Stud;
	Semester Sem;
	string grade;
public:
	Registration();
	Registration(Section sec,Student stu,Semester sem);
	void setdata(Section sec,Student stu,Semester sem);
	void setdata1(Section sec,Student stu,Semester sem,string g);
	friend  ostream& operator<<(ostream &out, Registration&obj)
	{
		out<<obj.Stud.getroll()<<" "<<obj.Sem.getname()<<" "<<obj.Sec.CourseCode()<<" "<<obj.Sec.GetName()<<" "<<obj.grade<<endl;
		return out;
	}
	Registration(const Registration &obj);
	void updategrade(string g);
	string CourseCode();
	string Stud_RollNo();
	string semName();
	string secname();
	string getGrade();
	void updatesem_name(string name);
};