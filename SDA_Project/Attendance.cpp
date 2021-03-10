#include "Attendance.h"
Attendance::Attendance(){}
Attendance::Attendance(Date d,char s)
{
	this->date=d;
	this->Status=s;
}
void Attendance::setdata(Date d,char s,Student stud,string sec,string cour,int lecno)
{
	date=d;
	Status=s;
	student=stud;
	section=sec;
	course=cour;
	this->lecno=lecno;
}
void Attendance::setStatus(char s)
{
	Status=s;
}
Date Attendance::getDate()
{
	return date;

}
string Attendance::getroll()
{
	return student.getroll();
}
int Attendance::getlecno()
{
	return lecno;
}
string Attendance::getcourse()
{
	return course;
}
string Attendance::getsection()
{
	return section;
}