#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <fstream>
#include <conio.h>
#include "Evaluation.h"
#include "Student.h"
using namespace std;
class Marks
{
private:
	int T_marks;
	int O_marks;
	Evaluation E_type;
	Student  student;
	string section;
	string course;
	int index;
public:
	Marks();
	Marks(int T_m,int O_m,Evaluation e_t);
	void setdata(int T_m,Evaluation e_t,Student s,int o_marks,string cour,string sec,int i);
	void setdata1(int T_m,Evaluation e_t,Student s,string cour,string sec,int i);
	void setmarks(int marks);
	friend  ostream& operator<<(ostream &out,Marks &obj)
	{
		out<<obj.section<<" "<<obj.course<<" "<<obj.student.getroll()<<" "<<obj.student.getname()<<" "<<obj.T_marks
			<<" "<<obj.O_marks<<" "<<obj.E_type.gettype()<<" "<<obj.index<<" "<<obj.E_type.get_weitage()<<endl;;
		return out;
	}
	string gettype();
	string getroll();
	int getindex();
	string getcourse();
	string getsection();
	float geto();
	float gett();
	float getw();
};