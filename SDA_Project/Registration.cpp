#include "Registration.h"
Registration::Registration(){}
Registration::Registration(Section sec,Student stu,Semester sem)
{
	this->Sec=sec;
	this->Stud=stu;
	this->Sem=sem;
	this->grade='I';
}
void Registration::setdata(Section sec,Student stu,Semester sem)
{
	this->Sec=sec;
	this->Stud=stu;
	this->Sem=sem;
	this->grade='I';
}
void Registration::setdata1(Section sec,Student stu,Semester sem,string g)
{
	this->Sec=sec;
	this->Stud=stu;
	this->Sem=sem;
	this->grade=g;
}
Registration::Registration(const Registration &obj)
{
	this->Sec=obj.Sec;
	this->Stud=obj.Stud;
	this->Sem=obj.Sem;
	this->grade=obj.grade;
}
void Registration::updategrade(string g)
{
	this->grade=g;
}
string Registration::CourseCode()
{
	return Sec.CourseCode();
}
string Registration::Stud_RollNo()
{
	return this->Stud.getroll();
}
string Registration::semName()
{
	return this->Sem.getname();
}
string Registration::secname()
{
	return this->Sec.GetName();
}
string Registration::getGrade()
{
	return this->grade;
}
void Registration::updatesem_name(string name)
{
	Sem.setname(name);
}
