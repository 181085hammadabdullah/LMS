#include "Marks.h"
Marks::Marks()
{
	T_marks=O_marks=0;
}
Marks::Marks(int T_m,int O_m,Evaluation e_t)
{
	this->T_marks=T_m;
	this->O_marks=O_m;
	E_type=e_t;
}
void Marks::setdata(int T_m,Evaluation e_t,Student s,int o_marks,string cour,string sec,int i)
{
	this->T_marks=T_m;
	E_type=e_t;
	student=s;
	O_marks=o_marks;
	section=sec;
	course=cour;
	index=i;
}
void Marks::setdata1(int T_m,Evaluation e_t,Student s,string cour,string sec,int i)
{
	this->T_marks=T_m;
	E_type=e_t;
	student=s;
	section=sec;
	course=cour;
	index=i;
}
void Marks::setmarks(int marks)
{
	O_marks=marks;
}
string Marks::gettype()
{
	return E_type.gettype();

}
string Marks::getroll()
{
	return student.getroll();
}
int Marks::getindex()
{
	return index;
}
string Marks::getcourse()
{
	return course;
}
string Marks::getsection()
{
	return section;
}
float Marks::geto()
{
	return O_marks;
}
float Marks::gett()
{
	return T_marks;
}
float Marks::getw()
{
	return E_type.get_weitage();
}