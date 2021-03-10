#pragma once
#include "Course.h"
#include "System.h"
Course::Course(){
	Name=code="";
	credit_Hours=total_sections=0;
	sections=nullptr;
	section_no=0;
}
Course::Course(string n,string c,int c_h,int no_of_s){
	this->Name=n;
	this->code=c;
	this->credit_Hours=c_h;
	this->total_sections=no_of_s;
	this->sections=new Section[total_sections];
	for(int i=0;i<this->total_sections;i++)
		sections[i].setCourseCode(this->code);
	this->section_no=0;
}
Course::Course(const Course &obj){
	this->Name=obj.Name;
	this->code=obj.code;
	this->credit_Hours=obj.credit_Hours;
	this->total_sections=obj.total_sections;
	this->sections=new Section[total_sections];
	this->section_no=obj.section_no;
	for(int i=0;i<obj.section_no;i++)
		this->sections[i]=obj.sections[i];

}
void Course::Addsection(const Section obj)
{
	if(section_no<total_sections)
		sections[this->section_no++]=obj;
}
string Course::getcode(){
	return this->code;
}
void Course::setTotalsections(int n)
{
	this->total_sections=n;
}
void Course::setdata(string n,string c,int c_h,int no_of_s,Section *secs,int sec_no)
{
	this->Name=n;
	this->code=c;
	this->credit_Hours=c_h;
	this->total_sections=no_of_s;
	this->sections=new Section[total_sections];

	for(int i=0;i<sec_no;i++)
		this->sections[i]=secs[i];
	this->section_no=sec_no;
}
void Course::setdata1(string n,string c,int c_h,int no_of_s)
{
	this->Name=n;
	this->code=c;
	this->credit_Hours=c_h;
	this->total_sections=no_of_s;
	sections=new Section[this->total_sections];
	section_no=0;
}
void Course::Printdata(){
	cout<<"Course Name: "<<this->Name<<endl;
	cout<<"Course Code: "<<this->code<<endl;
	cout<<"Credit Hours: "<<this->credit_Hours<<endl;
	cout<<"No of sections: "<<this->total_sections<<endl;
}
float Course::GetHours()
{
	return this->credit_Hours;
}
void Course::updatedInput(string u)
{
	this->code=u;
	cout<<"Enter the Name of Course(str): ";
	cin>>this->Name;
	cout<<"Enter Credit Hours(int): ";
	cin>>this->credit_Hours;
	cout<<"Enter Total Sections(int): ";
	cin>>this->total_sections;
}
int Course::SearchCourse(string code)
{
	System s;
	return s.SearchCourse(code);
}