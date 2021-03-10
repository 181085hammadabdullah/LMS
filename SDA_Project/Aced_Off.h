#pragma once
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include "Section.h"
#include "Course_Reg_Info.h"
#include "Evaluation.h"
using namespace std;
class Aced_Off:public Person
{
private:
	string Qualification;
	string skill;
	string username;

public:
	Aced_Off();
	Aced_Off(string N,string FN,int a,string A,Date dob,string q,string s,string u);
	friend  istream& operator>>(istream &in,Aced_Off &obj)
	{

		cout<<"Note Username cannot be change or update afterwords so write it carefully!!!"<<endl;
		cout<<"Enter Username The of Aced_Off(str): ";
		in>>obj.username;
		while(obj.searchAced_Off(obj.username)!=-1)
		{
			cout<<"This Username is Already Been used Plz Enter New Username The of Aced_Off(str): ";
			in>>obj.username;
		}
		cout<<"Enter Name The of Aced_Off(str): ";
		in>>obj.Name;
		cout<<"Enter Father Name The of Aced_Off(str): ";
		in>>obj.FName;
		cout<<"Enter Age The of Aced_Off(int): ";
		in>>obj.age;
		cout<<"Enter Address The of Aced_Off(city): ";
		in>>obj.Address;
		cout<<"Enter Date Of Birth The of Aced_Off: "<<endl;
		in>>obj.DOB;
		cout<<"Enter Qualification The of Aced_Off(int): ";
		in>>obj.Qualification;
		cout<<"Enter Skill The of Aced_Off(int): ";
		in>>obj.skill;
		return in;

	}
	friend  ostream& operator<<(ostream &out,Aced_Off &obj)
	{

		out<<obj.username<<" "<<obj.Name<<" "<<obj.FName<<" "<<obj.age<<" "<<obj.Address<<" "
			<<obj.DOB<<" "<<obj.Qualification<<" "<<obj.skill<<" "<<endl;
		return out;

	}
	void setdata(string N,string FN,int a,string A,Date dob,string q,string s,string u);
	string getusername();
	void Printdata();
	Date parsedate(string date);
	//Student Functions
	void AddNewStud();
	Student * fetchstudents();
	void deleteStudent();
	void editStudent();
	int searchstudent(string roll);
	Student searchstudent1(string roll);
	int totalstudent();
	void Print_Students();
	// Tecaher Functions
	void AddNewTeacher();
	Teacher * fetchteachers();
	void deleteTeacher();
	void editTeacher();
	int searchteacher(string roll);
	Teacher searchteacher1(string roll);
	int totalteacher();
	void Print_Teachers();
	//Aced_Off functions
	void AddNewAced_Off();
	Aced_Off * fetchAced_Offs();
	void deleteAced_Off();
	void editAced_Off();
	int searchAced_Off(string roll);
	Aced_Off searchAced_Off1(string roll);
	int totalAced_Off();
	void Print_Aced_Offs();
	//Courses Functions
	void AddNewCourse();
	int SearchCourse(string code);
	Course SearchCourse1(string code);
	int totalcourses();
	Course * fetchCourses();
	void EditCourse();
	void deleteCourse();
	void Print_Courses();
	//Section Functions
	void addnewsection();
	Section *fetchsections();
	void editSection();
	void deleteSection();
	int searchSection(string course_Code,string secion_name);
	Section searchSection1(string course_Code,string secion_name);
	int totalsections();
	void setTeacher();
	void Print_Sections();
	//Semester Functions
	void addnewSemester();
	Semester *fetchSemesters();
	void editSemester();
	void deleteSemester();
	int searchSemester(string sem_name);
	Semester searchSemester1(string sem_name);
	int totalSemesters();
	void Update_Student_Sem();
	void Print_Semesters();
	//Course_Reg_Info Functions
	void addnewCourse_Reg_Info();
	Course_Reg_Info *fetchCourse_Reg_Info();
	void editCourse_Reg_Info();
	void deleteCourse_Reg_Info();
	int searchCourse_Reg_Info(string sem_name);
	Course_Reg_Info searchCourse_Reg_Info1(string sem_name);
	int totalCourse_Reg_Info();
	void openreg();
	void closereg();
	void openwithdraw();
	void closewithdraw();
	void updatewithdrawdate();
	void Print_Course_Reg_Info();
	//Evalution Functions
	void addnewEvaluation();
	Evaluation *fetchEvaluation();
	void editEvaluation();
	void deleteEvaluation();
	int searchEvaluation(string sem_name);
	Evaluation searchEvaluation1(string sem_name);
	int totalEvaluation();
	void updateInput(string u);
	void Print_Evaluations();
};