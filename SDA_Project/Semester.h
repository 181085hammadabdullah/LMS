#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <fstream>
#include <conio.h>
using namespace std;
class Semester
{
private:
	string name;
public:
	Semester();
	Semester(string n);
	Semester(const Semester &obj);
	friend  istream& operator>>(istream &in, Semester &obj)
	{
		cout<<"Enter Name of Semester: ";
		in>>obj.name;
		while(obj.searchSemester(obj.getname())!=-1)
		{
			cout<<"The semester Name u enter is already Present Plz Enter A New Semester name: ";
			in>>obj.name;
		}
		return in;

	}
	friend  ostream& operator<<(ostream &out, Semester &obj)
	{
		out<<obj.name<<endl;
		return out;
	}
	string getname();
	void setname(string name);
	void Printdata();
	int searchSemester(string sem_name);
	
};