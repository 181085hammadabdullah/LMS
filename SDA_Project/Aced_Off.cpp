#pragma once
#include "Aced_Off.h"
#include "System.h"
Aced_Off::Aced_Off():Person()
{
	this->Qualification=this->skill="";
}
Aced_Off::Aced_Off(string N,string FN,int a,string A,Date dob,string q,string s,string u)
	:Person(N,FN,a,A,dob)
{
	this->Qualification=q;
	this->skill=s;
	this->username=u;
}
Date Aced_Off::parsedate(string date){
	char arr[5];
	Date obj;
	int index=0;
	int i=0;
	int a;
	//Read Day
	for(i=0;date[index]!='/';i++)
	{
		arr[i]=date[index++];
	}
	arr[i]='\0';
	a=atoi(arr);
	obj.setday(a);
	index++;
	//Read Month
	for(i=0;date[index]!='/';i++)
	{
		arr[i]=date[index++];
	}
	arr[i]='\0';
	a=atoi(arr);
	obj.setmonth(a);
	index++;
	//Read Year
	for(i=0;date[index]!='\0';i++)
	{
		arr[i]=date[index++];
	}
	arr[i]='\0';
	a=atoi(arr);
	obj.setyear(a);
	index++;
	return obj;
}
void Aced_Off::setdata(string N,string FN,int a,string A,Date dob,string q,string s,string u)
{
	this->Name=N;
	this->FName=FN;
	this->age=a;
	this->Address=A;
	this->DOB=dob;
	this->Qualification=q;
	this->skill=s;
	this->username=u;
}
void Aced_Off::Printdata(){
	cout<<"Name: "<<this->Name<<endl;
	cout<<"Father Name: "<<this->FName<<endl;
	cout<<"UserName: "<<this->username<<endl;
	cout<<"Address: "<<this->Address<<endl;
	cout<<"Age: "<<this->age<<endl;
	cout<<"DOB: "<<this->DOB<<endl;
	cout<<"Qualification: "<<this->Qualification<<endl;
	cout<<"Experience: "<<this->skill<<endl;
}
string Aced_Off::getusername(){
	return username;
}
void Aced_Off::updateInput(string u)
{
	this->username=u;
	cout<<"Enter Name The of Aced_Off(str): ";
	cin>>this->Name;
	cout<<"Enter Father Name The of Aced_Off(str): ";
	cin>>this->FName;
	cout<<"Enter Age The of Aced_Off(int): ";
	cin>>this->age;
	cout<<"Enter Address The of Aced_Off(city): ";
	cin>>this->Address;
	cout<<"Enter Date Of Birth The of Aced_Off: "<<endl;
	cin>>this->DOB;
	cout<<"Enter Qualification The of Aced_Off(int): ";
	cin>>this->Qualification;
	cout<<"Enter Skill The of Aced_Off(int): ";
	cin>>this->skill;
}
//Student Functions
void Aced_Off::AddNewStud(){
	System s;
	s.AddNewStud();
}
void Aced_Off::deleteStudent(){
	System s;
	s.deleteStudent();
}
Student * Aced_Off::fetchstudents(){
	System s;
	return s.fetchstudents();
}
void Aced_Off::editStudent(){
	System s;
	s.editStudent();

}
int Aced_Off::searchstudent(string roll){
	System s;
	return s.searchstudent(roll);

}
Student Aced_Off::searchstudent1(string roll){
	System s;
	return s.searchstudent1(roll);

}
int Aced_Off::totalstudent(){
	System s;
	return s.totalstudent();
}
void Aced_Off::Print_Students()
{
	Student *arr=fetchstudents();
	for(int i=0;i<totalstudent();i++)
		cout<<arr[i];
}
//Teacher Functions
void Aced_Off::AddNewTeacher(){
	System s;
	s.AddNewTeacher();
}
Teacher * Aced_Off::fetchteachers(){
	System s;
	return s.fetchteachers();
}
void Aced_Off::deleteTeacher(){
	System s;
	s.deleteTeacher();
}
int Aced_Off::searchteacher(string username){
	System s;
	return s.searchteacher(username);

}
Teacher Aced_Off::searchteacher1(string username){
	System s;
	return s.searchteacher1(username);

}
int Aced_Off::totalteacher(){
	System s;
	return s.totalteacher();
}
void Aced_Off::editTeacher(){
	System s;
	s.editTeacher();
}
void Aced_Off::Print_Teachers()
{
	Teacher *arr=fetchteachers();
	for(int i=0;i<totalteacher();i++)
		cout<<arr[i];
}
//Aced_Off Functions
void Aced_Off::AddNewAced_Off(){
	System s;
	s.AddNewAced_Off();
}
Aced_Off* Aced_Off::fetchAced_Offs(){
	System s;
	return s.fetchAced_Offs();
}
void Aced_Off::deleteAced_Off(){
	System s;
	s.deleteAced_Off();
}
int Aced_Off::searchAced_Off(string username){
	System s;
	return s.searchAced_Off(username);
}
Aced_Off Aced_Off::searchAced_Off1(string username){
	System s;
	return s.searchAced_Off1(username);
}
int Aced_Off::totalAced_Off(){
	int count;
	ifstream fin("Aced_Off.txt");
	fin>>count;
	fin.close();
	return count;
}
void Aced_Off::editAced_Off(){
	System s;
	s.editAced_Off();
}
void Aced_Off::Print_Aced_Offs()
{
	Aced_Off *arr=fetchAced_Offs();
	for(int i=0;i<totalAced_Off();i++)
		cout<<arr[i];
}
//Courses Functions
void Aced_Off::AddNewCourse(){	
	System s;
	s.AddNewCourse();
}
int Aced_Off::SearchCourse(string code)
{
	System s;
	return s.SearchCourse(code);
}
Course Aced_Off::SearchCourse1(string code)
{
	System s;
	return s.SearchCourse1(code);
}
int Aced_Off::totalcourses()
{
	System s;
	return s.totalcourses();
}
Course * Aced_Off::fetchCourses()
{
	System s;
	return s.fetchCourses();
}
void Aced_Off::EditCourse()
{
	System s;
	s.EditCourse();
}
void Aced_Off::deleteCourse()
{
	System s;
	s.deleteCourse();
}
void Aced_Off::Print_Courses()
{
	Course *arr=fetchCourses();
	for(int i=0;i<totalcourses();i++)
		cout<<arr[i];
}
//Section Functions
void Aced_Off::addnewsection()
{
	System s;
	s.addnewsection();
}
Section *Aced_Off::fetchsections()
{
	System s;
	return s.fetchsections();
}
int Aced_Off::totalsections()
{
	System s;
	return s.totalsections();
}
int Aced_Off::searchSection(string course_Code,string section_name)
{
	System s;
	return s.searchSection(course_Code,section_name);
}
Section Aced_Off::searchSection1(string course_Code,string section_name)
{
	System s;
	return s.searchSection1(course_Code,section_name);
}
void Aced_Off::editSection()
{
	System s;
	s.editSection();
}
void Aced_Off::deleteSection()
{
	System s;
	s.deleteSection();
}
void Aced_Off::setTeacher()
{
	System s;
	s.setTeacher();
}
void Aced_Off::Print_Sections()
{
	Section *arr=fetchsections();
	for(int i=0;i<totalsections();i++)
		cout<<arr[i];
}
//Semester Functions
void Aced_Off::addnewSemester()
{
	System s;
	s.addnewSemester();

}
Semester *Aced_Off::fetchSemesters()
{
	System s;
	return s.fetchSemesters();
}
int Aced_Off::searchSemester(string sem_name)
{
	System s;
	return s.searchSemester(sem_name);
}
Semester Aced_Off::searchSemester1(string sem_name)
{
	System s;
	return s.searchSemester1(sem_name);
}
int Aced_Off::totalSemesters()
{
	System s;
	return s.totalSemesters();
}
void Aced_Off::editSemester()
{
	System s;
	s.editSemester();

}
void Aced_Off::deleteSemester()
{
	System s;
	s.deleteSemester();
}
void Aced_Off::Update_Student_Sem()
{
	System s;
	s.Update_Student_Sem();
}
void Aced_Off::Print_Semesters()
{
	Semester *arr=fetchSemesters();
	for(int i=0;i<totalSemesters();i++)
		cout<<arr[i];
}
//Course_Reg_Info
void Aced_Off::addnewCourse_Reg_Info()
{
	System s;
	s.addnewCourse_Reg_Info();
}
Course_Reg_Info *Aced_Off::fetchCourse_Reg_Info()
{
	System s;
	return s.fetchCourse_Reg_Info();
}
void Aced_Off::editCourse_Reg_Info()
{
	System s;
	s.editCourse_Reg_Info();
}
void Aced_Off::deleteCourse_Reg_Info()
{
	System s;
	s.deleteCourse_Reg_Info();
}
int Aced_Off::searchCourse_Reg_Info(string sem_name)
{
	System s;
	return s.searchCourse_Reg_Info(sem_name);
}
Course_Reg_Info Aced_Off::searchCourse_Reg_Info1(string sem_name)
{
	System s;
	return s.searchCourse_Reg_Info1(sem_name);
}
int Aced_Off::totalCourse_Reg_Info()
{
	System s;
	return s.totalCourse_Reg_Info();
}
void Aced_Off::openreg()
{
	System s;
	s.openreg();
}
void Aced_Off::closereg()
{
	System s;
	s.closereg();
}
void Aced_Off::openwithdraw()
{
	System s;
	s.openwithdraw();
}
void Aced_Off::closewithdraw()
{
	System s;
	s.closewithdraw();
}
void Aced_Off::updatewithdrawdate()
{
	System s;
	s.updatewithdrawdate();
}
void Aced_Off::Print_Course_Reg_Info()
{
	Course_Reg_Info *arr=fetchCourse_Reg_Info();
	for(int i=0;i<totalCourse_Reg_Info();i++)
		cout<<arr[i];
}
//Evlaution Functions
void Aced_Off::addnewEvaluation()
{
	System s;
	s.addnewEvaluation();
}
void Aced_Off::editEvaluation()
{
	System s;
	s.editEvaluation();
}
void Aced_Off::deleteEvaluation()
{
	System s;
	s.deleteEvaluation();
}
int Aced_Off::searchEvaluation(string type)
{
	System s;
	return s.searchEvaluation(type);
}
Evaluation Aced_Off::searchEvaluation1(string type)
{
	System s;
	return s.searchEvaluation1(type);
}
int Aced_Off::totalEvaluation()
{
	System s;
	return s.totalEvaluation();
}
void Aced_Off::Print_Evaluations()
{
	System s;
	int count =totalEvaluation();
	Evaluation *arr=s.fetchEvaluation();
	for(int i=0;i<count;i++)
		cout<<arr[i];
}




