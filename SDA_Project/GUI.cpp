#pragma once
#include <iostream>
using namespace std;
#include "Aced_Off.h"
#include "System.h"
int main()
{
	int n=0;
	cout<<"						Welcome To Online Learning Management System!!!"<<endl;
	cout<<"Press 1 if U are Acedmic Officer"<<endl;
	cout<<"Press 2 if U are Teacher"<<endl;
	cout<<"Press 3 if U are Student"<<endl;
	cin>>n;
	//AcedMic Officer Functions
	if(n==1)
	{
		string username;
		cout<<"Enter UserName to LoginIn:";
		cin>>username;
		System s;
		int index=s.searchAced_Off(username);
		if(index!=-1)
		{
			Aced_Off a=s.searchAced_Off1(username);
			while(1){
				system("CLS");
				cout<<"Press 1 for Acedmic Officer Functions"<<endl;
				cout<<"Press 2 for Teacher Functions"<<endl;
				cout<<"Press 3 for Student Functions"<<endl;
				cout<<"Press 4 for Semester Functions"<<endl;
				cout<<"Press 5 for Course Registration Function"<<endl;
				cout<<"Press 6 for Course Functions"<<endl;
				cout<<"Press 7 for Section Functions"<<endl;
				cout<<"Press 8 for Evaluation Functions"<<endl;
				cin>>n;
				if(n==1)
				{
					system("CLS");
					cout<<"You Choose Functions of Acedmic Officer"<<endl;
					cout<<"Press 1 for Add New Acedmic Officer"<<endl;
					cout<<"Press 2 for Delete an Acedmic Officer"<<endl;
					cout<<"Press 3 for Edit Acedmic Officer"<<endl;
					cin>>n;
					if(n==1)
					{
						a.AddNewAced_Off();
					}
					else if(n==2)
					{
						a.Print_Aced_Offs();
						a.deleteAced_Off();
					}
					else if(n==3)
					{
						a.Print_Aced_Offs();
						a.editAced_Off();
					}
				}
				else if(n==2)
				{
					system("CLS");
					cout<<"You Choose Functions of Teacher"<<endl;
					cout<<"Press 1 for Add New Teacher"<<endl;
					cout<<"Press 2 for Delete a Teacher"<<endl;
					cout<<"Press 3 for Edit Teacher"<<endl;
					cin>>n;
					if(n==1)
					{

						a.AddNewTeacher();
					}
					else if(n==2)
					{
						a.Print_Teachers();
						a.deleteTeacher();
					}
					else if(n==3)
					{
						a.Print_Teachers();
						a.editTeacher();
					}
				}
				else if(n==3)
				{
					system("CLS");
					cout<<"You Choose Functions of Student"<<endl;
					cout<<"Press 1 for Add New Student"<<endl;
					cout<<"Press 2 for Delete a Student"<<endl;
					cout<<"Press 3 for Edit Student"<<endl;
					cin>>n;
					if(n==1)
					{
						a.AddNewStud();
					}
					else if(n==2)
					{
						a.Print_Students();
						a.deleteStudent();
					}
					else if(n==3)
					{
						a.Print_Students();
						a.editStudent();
					}
				}
				else if(n==4)
				{
					system("CLS");
					cout<<"You Choose Functions of Semester"<<endl;
					cout<<"Press 1 for Add New Semester"<<endl;
					cout<<"Press 2 for Delete a Semester"<<endl;
					cout<<"Press 3 for Edit Semester"<<endl;
					cout<<"Press 4 for Update Students New Semester"<<endl;
					cin>>n;
					if(n==1)
					{
						a.addnewSemester();
					}
					else if(n==2)
					{
						a.Print_Semesters();
						a.deleteSemester();
					}
					else if(n==3)
					{
						a.Print_Semesters();
						a.editSemester();
					}
					else if(n==4)
					{
						a.Print_Semesters();
						a.Update_Student_Sem();
					}
				}
				else if(n==5)
				{
					system("CLS");
					cout<<"You Choose Functions of Course Registration"<<endl;
					cout<<"Press 1 for Add New Course Registration"<<endl;
					cout<<"Press 2 for Delete a Course Registration"<<endl;
					cout<<"Press 3 for Edit Course Registration"<<endl;
					cout<<"Press 4 for Open The Course Registration"<<endl;
					cout<<"Press 5 for Close The Course Registration"<<endl;
					cout<<"Press 6 for Open WithDraw Period"<<endl;
					cout<<"Press 7 for Close WithDraw Period"<<endl;
					cout<<"Press 8 for Update WithDraw Deadline"<<endl;
					cin>>n;
					if(n==1)
					{
						a.addnewCourse_Reg_Info();
					}
					else if(n==2)
					{
						a.Print_Course_Reg_Info();
						a.deleteCourse_Reg_Info();
					}
					else if(n==3)
					{
						a.Print_Course_Reg_Info();
						a.editCourse_Reg_Info();
					}
					else if(n==4)
					{
						a.Print_Course_Reg_Info();
						a.openreg();
					}
					else if(n==5)
					{
						a.Print_Course_Reg_Info();
						a.closereg();
					}
					else if(n==6)
					{
						a.openwithdraw();
					}
					else if(n==7)
					{
						a.Print_Course_Reg_Info();
						a.closewithdraw();
					}
					else if(n==8)
					{
						a.Print_Course_Reg_Info();
						a.updatewithdrawdate();
					}
				}
				else if(n==6)
				{
					system("CLS");
					cout<<"You Choose Functions of Course"<<endl;
					cout<<"Press 1 for Add New Course"<<endl;
					cout<<"Press 2 for Delete a Course"<<endl;
					cout<<"Press 3 for Edit Course"<<endl;
					cin>>n;
					if(n==1)
					{
						a.AddNewCourse();
					}
					else if(n==2)
					{
						a.Print_Courses();
						a.deleteCourse();
					}
					else if(n==3)
					{
						a.Print_Courses();
						a.EditCourse();
					}
				}
				else if(n==7)
				{
					system("CLS");
					cout<<"You Choose Functions of Section"<<endl;
					cout<<"Press 1 for Add New Section"<<endl;
					cout<<"Press 2 for Delete a Section"<<endl;
					cout<<"Press 3 for Edit Section"<<endl;
					cout<<"Press 4 for Set a Teacher For a Particular Section"<<endl;
					cin>>n;
					if(n==1)
					{
						a.addnewsection();
					}
					else if(n==2)
					{
						a.Print_Sections();
						a.deleteSection();
					}
					else if(n==3)
					{
						a.Print_Sections();
						a.editSection();
					}
					else if(n==4)
					{

						a.Print_Sections();
						cout<<"Available Teachers Are:"<<endl;
						a.Print_Teachers();
						a.setTeacher();
					}
				}
				else if(n==8)
				{
					system("CLS");
					cout<<"You Choose Functions of Evaluation"<<endl;
					cout<<"Press 1 for Add New Evaluation"<<endl;
					cout<<"Press 2 for Delete a Evaluation"<<endl;
					cout<<"Press 3 for Edit Evaluation"<<endl;
					cin>>n;
					if(n==1)
					{
						a.addnewEvaluation();
					}
					else if(n==2)
					{
						a.Print_Evaluations();
						a.deleteEvaluation();
					}
					else if(n==3)
					{
						a.Print_Evaluations();
						a.editEvaluation();
					}
				}
				system("pause");
			}
		}
		else
		{
			cout<<"Login Fails!!!Invalid Username!!!"<<endl;
		}


	}
	else if(n==2)
	{
		string username;
		cout<<"Enter UserName to LoginIn:";
		cin>>username;
		System s;
		int index=s.searchteacher(username);
		if(index!=-1)
		{
			while(1){
				system("CLS");
				Teacher t=s.searchteacher1(username);
				t.fetchsections_Teachers();
				cout<<"Press 1 for Attendance Functions"<<endl;
				cout<<"Press 2 for Marks Functions"<<endl;
				cout<<"Press 3 for Enter Grades"<<endl;
				cin>>n;
				if(n==1)
				{
					system("CLS");
					t.fetchsections_Teachers();
					cout<<"You Choose Functions of Attendance"<<endl;
					cout<<"Press 1 for Add New Attendance"<<endl;
					cout<<"Press 2 for Update Attendance of a Student"<<endl;
					cout<<"Press 3 for Delete a Attendance"<<endl;
					cin>>n;
					if(n==1)
					{
						t.AddAttendance();
					}
					else if(n==2)
					{
						t.updateAttendance();
					}
					else if(n==3)
					{
						t.deleteAttendance();
					}
				}
				else if(n==2)
				{
					system("CLS");
					t.fetchsections_Teachers();
					cout<<"You Choose Functions of Marks"<<endl;
					cout<<"Press 1 for Add New Marks"<<endl;
					cout<<"Press 2 for Update Marks of a Student"<<endl;
					cout<<"Press 3 for Delete Marks"<<endl;
					cin>>n;
					if(n==1)
					{
						t.AddMarks();
					}
					else if(n==2)
					{
						t.updateMarks();
					}
					else if(n==3)
					{
						t.deleteMarks();
					}
				}
				else if(n==3)
				{
					system("CLS");
					t.fetchsections_Teachers();
					cout<<"You Choose Functions of Enter Grades"<<endl;
					t.setGrades();
				}
				system("pause");
			}
		}
		else
			cout<<"Invalid UserName!!!"<<endl;
	}
	else if(n==3)
	{
		string roll;
		cout<<"Enter Rollno to LoginIn:";
		cin>>roll;
		System s;
		int index=s.searchstudent(roll);
		if(index!=-1)
		{
			while(1){
				system("CLS");
				Student t=s.searchstudent1(roll);
				t.PrintNotification1();
				cout<<"Press 1 to See Course Registration Dates"<<endl;
				cout<<"Press 2 to see course withdraw Deadline"<<endl;
				cout<<"Press 3 to add New Course"<<endl;
				cout<<"Press 4 to Drop New Course"<<endl;
				cout<<"Press 5 to WithDraw Course"<<endl;
				cout<<"Press 6 to View Transcript"<<endl;
				cout<<"Press 7 to View Attendance of a Course"<<endl;
				cout<<"Press 8 to View Marks of a Particular Course"<<endl;
				cin>>n;
				if(n==1)
				{
					t.PrintCourseDates();
				}
				else if(n==2)
				{
					t.PrintWithDrawDates();
				}
				else if(n==3)
				{
					t.Addcourse();
				}
				else if(n==4)
				{
					t.Dropcourse();
				}
				else if(n==5)
				{
					t.WithDrawcourse();
				}
				else if(n==6)
				{
					t.ViewTranscript();
				}
				else if(n==7)
				{
					t.seeAttendance();
				}
				else if(n==8)
				{
					t.seeMarks();
				}
				system("pause");
			}
		}
		else
		{
			cout<<"Invalid RollNO..."<<endl;
		}

	}

	system("pause");
	return 0;
}