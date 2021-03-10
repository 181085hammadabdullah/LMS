#include "Semester.h"
#include "System.h"
Semester::Semester()
{
	name="";
}
Semester::Semester(string n)
{
	this->name=n;
}
Semester::Semester(const Semester &obj)
{
	this->name=obj.name;
}
string Semester::getname(){
	return this->name;
}
void Semester::setname(string name){
	this->name=name;
}
void Semester::Printdata()
{
	cout<<"Semester Name :"<<this->name<<endl;
}
int  Semester::searchSemester(string sem_name)
{
	System s;
	return s.searchSemester(sem_name);
}
