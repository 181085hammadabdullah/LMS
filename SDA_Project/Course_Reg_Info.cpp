#include "Course_Reg_Info.h"
#include "System.h"
Course_Reg_Info::Course_Reg_Info()
{
	this->actve_Reg=false;
	this->active_with_drawdeadline=false;
}
Course_Reg_Info::Course_Reg_Info(Date s,Date e,Date wd,Semester sem)
{
	this->Reg_Starting_Date=s;
	this->Reg_Ending_Date=e;
	this->With_Draw_Deadline=wd;
	this->actve_Reg=false;
	this->active_with_drawdeadline=false;
	this->s=sem;
}
void Course_Reg_Info::openReg(){
	this->actve_Reg=true;
}
void Course_Reg_Info::closedReg(){
	this->actve_Reg=false;
}
void Course_Reg_Info::openwithdraw(){
	this->active_with_drawdeadline=true;
}
void Course_Reg_Info::closedwithdraw(){
	this->active_with_drawdeadline=false;
}
bool Course_Reg_Info::checkregperiod()
{
	return this->actve_Reg;
}
bool Course_Reg_Info::checkwithdrawPeriod()
{
	return this->active_with_drawdeadline;
}
void Course_Reg_Info::setdata(Date s,Date e,Date wd,string sem,bool reg,bool withdraw){
	this->Reg_Starting_Date=s;
	this->Reg_Ending_Date=e;
	this->With_Draw_Deadline=wd;
	this->actve_Reg=reg;
	this->active_with_drawdeadline=withdraw;
	this->s.setname(sem);
}
void Course_Reg_Info::Printdata()
{
	cout<<"Semester Name: "<<this->s.getname()<<endl;
	cout<<"Starting Reg Date: "<<this->Reg_Starting_Date<<endl;
	cout<<"Ending Reg Date: "<<this->Reg_Ending_Date<<endl;
	cout<<"Withdraw Deadline: "<<this->With_Draw_Deadline<<endl;
}
void Course_Reg_Info::updatesemname(string name)
{
	this->s.setname(name);
}
void Course_Reg_Info::updatewithdrawdate(Date d)
{
	this->With_Draw_Deadline=d;
}
string Course_Reg_Info::getsemname(){
	return this->s.getname();
}
int Course_Reg_Info::searchCourse_Reg_Info(string sem_name)
{
	System s;
	return s.searchCourse_Reg_Info(sem_name);
}
int Course_Reg_Info::searchSemester(string sem_name)
{
	System s;
	return s.searchSemester(sem_name);
}
void Course_Reg_Info::updateInput()
{
	cout<<"Enter Registration starting date: ";
	cin>>Reg_Starting_Date;
	cout<<"Enter Registration Ending date: ";
	cin>>Reg_Ending_Date;
	cout<<"Enter With Draw Deadline date: ";
	cin>>With_Draw_Deadline;
	actve_Reg=false;
	active_with_drawdeadline=false;
}
void Course_Reg_Info::setsem_name(string name)
{
	s.setname(name);
}
void Course_Reg_Info::PrintCourseDates()
{
	cout<<"Registration Starting Date is:"<<Reg_Starting_Date<<endl;
	cout<<"Registration Ending Date is :"<<Reg_Ending_Date<<endl;
}
void Course_Reg_Info::PrintWithDrawDates()
{
	cout<<"WithDraw Deadline date is: "<<With_Draw_Deadline<<endl;;
}
Date  Course_Reg_Info::getwithdraw()
{
	return this->With_Draw_Deadline;
}