#pragma once
#include "Person.h"

class Teacher:public Person
{
private:
	string Qualification;
	string Experience;
	string username;
public:
	Teacher();
	Teacher(string N,string FN,int a,string A,Date dob,string q,string e,string u);
	friend  istream& operator>>(istream &in,Teacher &obj)
	{
	
		cout<<"Note Username cannot be change or update afterwords so write it carefully!!!"<<endl;
		cout<<"Enter Username The of Teacher(str): ";
		in>>obj.username;
		while(obj.searchteacher(obj.username)!=-1)
		{
			cout<<"This Username is Already Been used Plz Enter New Username The of Aced_Off(str): ";
			in>>obj.username;
		}
		cout<<"Enter Name The of Teacher(str): ";
		in>>obj.Name;
		cout<<"Enter Father Name The of Teacher(str): ";
		in>>obj.FName;
		cout<<"Enter Age The of Teacher(int): ";
		in>>obj.age;
		cout<<"Enter Address The of Teacher(city): ";
		in>>obj.Address;
		cout<<"Enter Date Of Birth The of Teacher: "<<endl;
		in>>obj.DOB;
		cout<<"Enter Qualification The of Teacher(int): ";
		in>>obj.Qualification;
		cout<<"Enter Experience The of Teacher(int): ";
		in>>obj.Experience;
		return in;

	}
	friend  ostream& operator<<(ostream &out,Teacher &obj)
	{

		out<<obj.username<<" "<<obj.Name<<" "<<obj.FName<<" "<<obj.age<<" "<<obj.Address<<" "
			<<obj.DOB<<" "<<obj.Qualification<<" "<<obj.Experience<<" "<<endl;
		return out;

	}
	void setdata(string N,string FN,int a,string A,Date dob,string Qual,string Exp,string u);
	string getusername();
	void Printdata();
	void setusername(string u)
	{
		this->username=u;
	}
	void AddMarks();
	void updateMarks();
	void deleteMarks();
	void AddAttendance();
	void updateAttendance();
	void deleteAttendance();
	void updateInput(string u);
	void setGrades();
	int searchteacher(string username);
	void  fetchsections_Teachers();
};