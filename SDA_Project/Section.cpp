#pragma once
#include "Section.h"
#include "System.h"
Section::Section(){
	this->Name="";
	this->no_of_seats=0;
	this->total_Occupy_seats=0;

}
Section::Section(string N,int n_of_seat,string code)
{
	//For Acedmic Officers
	this->Name=N;
	this->no_of_seats=n_of_seat;
	this->total_Occupy_seats=0;
	this->course_code=code;
}
void Section::setCourseCode(string code){
	this->course_code=code;
}
void Section::setTecaher(const Teacher obj)
{
	this->T=obj;
}
Section::Section(const Section &obj){
	//For Acedmic Officers
	this->Name=obj.Name;
	this->no_of_seats=obj.no_of_seats;
	this->total_Occupy_seats=obj.total_Occupy_seats;
	this->course_code=obj.course_code;
	this->T=obj.T;
}
void Section::setdata1(string name,string course_code,int total_seats,int occupyseats,string Teacher_username)
{
	this->Name=name;
	this->course_code=course_code;
	this->no_of_seats=total_seats;
	this->total_Occupy_seats=occupyseats;
	this->T.setusername(Teacher_username);
}
bool Section::isSpace()
{
	if(total_Occupy_seats<no_of_seats)
		return true;
	return false;
}
void Section::incseats(){
	if(total_Occupy_seats<no_of_seats)
		total_Occupy_seats++;

}
void Section::decseats(){
	if(total_Occupy_seats>0)
		total_Occupy_seats--;

}
string Section::CourseCode(){
	return this->course_code;
}
string Section::GetName()
{
	return this->Name;
}
string Section::getuser(){
	return T.getusername();
}
void Section::Printdata(){
	cout<<"Section Name: "<<this->Name<<endl;
	cout<<"Course Code: "<<this->course_code<<endl;
	cout<<"Total Seats: "<<this->no_of_seats<<endl;
	cout<<"Occupied Seats: "<<this->total_Occupy_seats<<endl;
}
string Section::getTeacherid()
{
	return T.getusername();
}
void Section::UpdateInput(string n)
{
	this->Name=n;
	cout<<"Enter Total seats of section(int): ";
	cin>>this->no_of_seats;
}
int Section::searchSection(string course_Code,string section_name)
{
	System s;
	return s.searchSection(course_Code,section_name);
}
