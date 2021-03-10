#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <fstream>
#include <conio.h>
#include "Student.h"
#include "Course_Reg_Info.h"
#include "Course.h"
#include "Registration.h"
#include "Aced_Off.h"
using namespace std;
class System
{


public:
	struct Notification
	{
		string Roll;
		string course;
		string section;
		string message;
		string status;
		void set(string r,string c,string s,string m)
		{
			Roll=r;
			course=c;
			section=s;
			message=m;
			status="No";
		}
		void set1(string r,string c,string s,string m,string st)
		{
			Roll=r;
			course=c;
			section=s;
			message=m;
			status=st;
		}
		void setYes()
		{
			status="Yes";
		}
		void setNo()
		{
			status="No";
		}
	};
	System();
	//Acedmic Officer Functions
	void AddNewAced_Off(){
		Aced_Off a;
		cin>>a;
		this->AddNewAced_Off(a);
	}
	Aced_Off* fetchAced_Offs(){
		Aced_Off *arr=new Aced_Off[100];
		string N;
		string FN;
		int a;
		string A;
		Date dob;
		string q;
		string s;
		string u;
		string date;
		char arr1[5];
		int count;
		ifstream fin("Aced_Off.txt");
		fin>>count;
		for(int i=0;i<count;i++){
			fin>>u;
			fin>>N;
			fin>>FN;
			fin>>a;
			fin>>A;
			fin>>date;
			fin>>q;
			fin>>s;
			dob=this->parsedate(date);
			fin.getline(arr1,5);
			arr[i].setdata(N,FN,a,A,dob,q,s,u);
		}

		fin.close();

		return arr;
	}
	void AddNewAced_Off(Aced_Off a)
	{
		int count;
		ifstream fin("Aced_Off.txt");
		fin>>count;
		fin.close();
		Aced_Off *arr=this->fetchAced_Offs();
		arr[count]=a;
		ofstream fout("Aced_Off.txt");
		count++;
		fout<<count<<endl;
		for(int i=0;i<count;i++)
			fout<<arr[i];
		delete [] arr;
		arr=nullptr;
		fout.close();
	}
	void deleteAced_Off(){
		string username;
		cout<<"Enter The Username u want to delete: ";
		cin>>username;
		if(this->deleteAced_Off(username)==true)
		{
			cout<<"Aced_Off with UserName "<<username<<" Has been deleted Check file!!!"<<endl;
		}
		else
		{
			cout<<"Error!!!Method Fail"<<endl;
		}
	}
	bool deleteAced_Off(string username)
	{
		int count= this->totalAced_Off();
		int index=this->searchAced_Off(username);
		Aced_Off *arr=this->fetchAced_Offs();
		if(index!=-1){
			for(int i=index;i<count-1;i++){
				arr[i]=arr[i+1];
			}
			ofstream fout("Aced_Off.txt");
			count--;
			fout<<count<<endl;
			for(int i=0;i<count;i++)
				fout<<arr[i];
			fout.close();
			delete [] arr;
			arr=nullptr;
			return true;
		}
		delete [] arr;
		arr=nullptr;
		return false;
	}
	int searchAced_Off(string username){
		Aced_Off *arr=this->fetchAced_Offs();
		int count=this->totalAced_Off();
		int index=-1;
		for(int i=0;i<count;i++){
			if(arr[i].getusername().compare(username)==0){
				index=i;
			}
		}
		delete [] arr;
		arr=nullptr;
		return index;

	}
	Aced_Off searchAced_Off1(string username){
		Aced_Off *arr=this->fetchAced_Offs();
		int count=this->totalAced_Off();
		Aced_Off a;
		for(int i=0;i<count;i++){
			if(arr[i].getusername().compare(username)==0){
				a=arr[i];
			}
		}
		delete [] arr;
		arr=nullptr;
		return a;

	}
	int totalAced_Off(){
		int count;
		ifstream fin("Aced_Off.txt");
		fin>>count;
		fin.close();
		return count;
	}
	void UpdateAced_Off(Aced_Off a,string username)
	{
		int count= this->totalAced_Off();
		int index=this->searchAced_Off(username);
		Aced_Off *arr=this->fetchAced_Offs();
		arr[index]=a;
		ofstream fout("Aced_Off.txt");
		fout<<count<<endl;
		for(int i=0;i<count;i++)
			fout<<arr[i];
		delete [] arr;
		arr=nullptr;
		fout.close();
	}
	void editAced_Off(){
		string username;
		cout<<"Enter The UserName whose data u want to edit: ";
		cin>>username;
		if(this->searchAced_Off(username)!=-1){
			Aced_Off a=this->searchAced_Off1(username);
			cout<<"Aced_Off Data as Follows!!!"<<endl;
			a.Printdata();
			Aced_Off a1;
			cout<<"Now Enter Updated data"<<endl;
			a1.updateInput(a.getusername());
			this->UpdateAced_Off(a1,username);
			cout<<"Aced_Off with username "<<username<<" Has been Updated Check file!!!"<<endl;
		}
		else{
			cout<<"Error UserName Not Found"<<endl;
		}

	}
	//Teacher Functions
	void AddNewTeacher(){
		Teacher t;
		cin>>t;
		this->AddNewTeacher(t);
	}
	Teacher * fetchteachers(){
		Teacher *arr=new Teacher[100];
		string N;
		string FN;
		int a;
		string A;
		Date dob;
		string q;
		string e;
		string u;
		string date;
		char arr1[5];
		int count;
		ifstream fin("Teacher.txt");
		fin>>count;
		for(int i=0;i<count;i++){
			fin>>u;
			fin>>N;
			fin>>FN;
			fin>>a;
			fin>>A;
			fin>>date;
			fin>>q;
			fin>>e;
			dob=this->parsedate(date);
			fin.getline(arr1,5);
			arr[i].setdata(N,FN,a,A,dob,q,e,u);
		}

		fin.close();

		return arr;
	}
	void AddNewTeacher(Teacher t)
	{
		int count;
		ifstream fin("Teacher.txt");
		fin>>count;
		fin.close();
		Teacher *arr=this->fetchteachers();
		arr[count]=t;
		ofstream fout("Teacher.txt");
		count++;
		fout<<count<<endl;
		for(int i=0;i<count;i++)
			fout<<arr[i];
		delete [] arr;
		arr=nullptr;
		fout.close();
	}
	void deleteTeacher(){
		string username;
		cout<<"Enter The Username u want to delete: ";
		cin>>username;
		if(this->deleteTeacher(username)==true)
		{
			cout<<"Teacher with UserName "<<username<<" Has been deleted Check file!!!"<<endl;
		}
		else
		{
			cout<<"Error!!!Method Fail"<<endl;
		}
	}
	bool deleteTeacher(string username)
	{
		int count= this->totalteacher();
		int index=this->searchteacher(username);
		Teacher *arr=this->fetchteachers();
		if(index!=-1){
			for(int i=index;i<count-1;i++){
				arr[i]=arr[i+1];
			}
			ofstream fout("Teacher.txt");
			count--;
			fout<<count<<endl;
			for(int i=0;i<count;i++)
				fout<<arr[i];
			fout.close();
			delete [] arr;
			arr=nullptr;
			return true;
		}
		delete [] arr;
		arr=nullptr;
		return false;
	}
	int searchteacher(string username){
		Teacher *arr=this->fetchteachers();
		int count=this->totalteacher();
		int index=-1;
		for(int i=0;i<count;i++){
			if(arr[i].getusername().compare(username)==0){
				index=i;
			}
		}
		delete [] arr;
		arr=nullptr;
		return index;

	}
	Teacher searchteacher1(string username){
		Teacher *arr=this->fetchteachers();
		int count=this->totalteacher();
		Teacher t;
		for(int i=0;i<count;i++){
			if(arr[i].getusername().compare(username)==0){
				t=arr[i];
			}
		}
		delete [] arr;
		arr=nullptr;
		return t;

	}
	int totalteacher(){
		int count;
		ifstream fin("Teacher.txt");
		fin>>count;
		fin.close();
		return count;
	}
	void UpdateTeacher(Teacher t,string username)
	{
		int count= this->totalteacher();
		int index=this->searchteacher(username);
		Teacher *arr=this->fetchteachers();
		arr[index]=t;
		ofstream fout("Teacher.txt");
		fout<<count<<endl;
		for(int i=0;i<count;i++)
			fout<<arr[i];
		delete [] arr;
		arr=nullptr;
		fout.close();
	}
	void editTeacher(){
		string username;
		cout<<"Enter The UserName whose data u want to edit: ";
		cin>>username;
		if(this->searchteacher(username)!=-1){
			Teacher t=this->searchteacher1(username);
			cout<<"Teacher Data as Follows!!!"<<endl;
			t.Printdata();
			Teacher t1;
			cout<<"Now Enter Updated data"<<endl;
			t1.updateInput(username);
			this->UpdateTeacher(t1,username);
			cout<<"Teacher with username "<<username<<" Has been Updated Check file!!!"<<endl;
		}
		else{
			cout<<"Error UserName Not Found"<<endl;
		}

	}
	//Semester Functions
	void addnewSemester()
	{
		Semester s;
		cin>>s;
		this->addNewSemester(s);
	}
	void addNewSemester(Semester s)
	{
		int count= this->totalSemesters();
		Semester *arr=this->fetchSemesters();
		arr[count]=s;
		ofstream fout("Semester.txt");
		count++;
		fout<<count<<endl;
		for(int i=0;i<count;i++)
			fout<<arr[i];
		delete [] arr;
		arr=nullptr;
		fout.close();
	}
	Semester *fetchSemesters()
	{
		Semester *arr=new Semester[100];
		string N;
		char arr1[5];
		int count;
		ifstream fin("Semester.txt");
		fin>>count;
		for(int i=0;i<count;i++){
			fin>>N;
			fin.getline(arr1,5);
			arr[i].setname(N);
		}

		fin.close();

		return arr;
	}
	int searchSemester(string sem_name)
	{
		Semester *arr=this->fetchSemesters();
		int count=this->totalSemesters();
		int index=-1;
		for(int i=0;i<count;i++){
			if(arr[i].getname().compare(sem_name)==0){
				index=i;
			}
		}
		delete [] arr;
		arr=nullptr;
		return index;
	}
	Semester searchSemester1(string sem_name)
	{
		Semester *arr=this->fetchSemesters();
		int count=this->totalSemesters();
		Semester s;
		for(int i=0;i<count;i++){
			if(arr[i].getname().compare(sem_name)==0){
				s=arr[i];
			}
		}
		delete [] arr;
		arr=nullptr;
		return s;
	}
	int totalSemesters()
	{
		int count;
		ifstream fin("Semester.txt");
		fin>>count;
		fin.close();
		return count;
	}
	void editSemester()
	{
		string name;
		cout<<"Enter The Semester Name whose data u want to edit: ";
		cin>>name;
		if(this->searchSemester(name)!=-1){
			Semester s=this->searchSemester1(name);
			cout<<"Semester Data as Follows!!!"<<endl;
			s.Printdata();
			Semester s1;
			cout<<"Now Enter Updated data"<<endl;
			cin>>s1;
			this->updateSemester(name,s1);
			cout<<"Semester with name "<<name<<" Has been Updated Check file!!!"<<endl;
		}
		else{
			cout<<"Error Semester Name Not Found"<<endl;
		}
	}
	void updateSemester(string name,Semester s)
	{
		UpdateRegistration2(name,s.getname());
		Semester *arr=this->fetchSemesters();
		int index=this->searchSemester(name);
		int count=this->totalSemesters();
		arr[index]=s;
		ofstream fout("Semester.txt");
		fout<<count<<endl;
		for(int i=0;i<count;i++)
			fout<<arr[i];
		Course_Reg_Info s1=this->searchCourse_Reg_Info1(name);
		s1.updatesemname(s.getname());

		this->updateCourse_Reg_Info(name,s1);
		fout.close();
		delete [] arr;
		arr=nullptr;
	}
	void deleteSemester()
	{
		string Name;
		cout<<"Enter Semester Name u want to delete: ";
		cin>>Name;
		if(this->deleteSemester(Name)==true)
		{

			cout<<"Semester with Name "<<Name<<" Has been deleted Check file!!!"<<endl;
		}
		else
		{
			cout<<"Error!!!Method Fail"<<endl;
		}
	}
	bool deleteSemester(string name)
	{
		deleteRegistration2(name);
		int index=this->searchSemester(name);
		Semester *arr=this->fetchSemesters();
		int count=this->totalSemesters();
		if(index!=-1){
			for(int i=index;i<count-1;i++){
				arr[i]=arr[i+1];
			}
			ofstream fout("Semester.txt");
			count--;
			fout<<count<<endl;
			for(int i=0;i<count;i++)
				fout<<arr[i];
			fout.close();
			this->deleteCourse_Reg_Info(name);
			delete [] arr;
			arr=nullptr;
			return true;
		}
		delete [] arr;
		arr=nullptr;
		return false;
	}
	void Update_Student_Sem()
	{
		string name;
		cout<<"Enter The Name of semester:";
		cin>>name;
		while(searchSemester(name)==-1)
		{
			cout<<"Plz enter The Name of Valid semester:";
			cin>>name;
		}
		int count=totalstudent();
		Student * arr=fetchstudents();
		for(int i=0;i<count;i++)
		{
			arr[i].updatesem(name);
			UpdateStudent(arr[i],arr[i].getroll());

		}
	}
	//Course_Reg_info Functions
	void addnewCourse_Reg_Info()
	{
		Course_Reg_Info cr;
		cin>>cr;
		this->addNewCourse_Reg_Info(cr);
	}
	Course_Reg_Info *fetchCourse_Reg_Info()
	{
		Course_Reg_Info *arr=new Course_Reg_Info[100];
		string N;
		Date or;
		Date cr;
		Date wd;
		bool rd;
		bool wd1;
		char arr1[5];
		int count;
		string date;
		ifstream fin("Course_Reg_Info.txt");
		fin>>count;
		for(int i=0;i<count;i++){
			fin>>N;
			fin>>date;
			or=parsedate(date);
			fin>>date;
			cr=parsedate(date);
			fin>>date;
			wd=parsedate(date);
			fin>>rd;
			fin>>wd1;
			fin.getline(arr1,5);
			arr[i].setdata(or,cr,wd,N,rd,wd1);
		}

		fin.close();
		return arr;
	}
	void addNewCourse_Reg_Info(Course_Reg_Info s)
	{
		int count= this->totalCourse_Reg_Info();
		Course_Reg_Info *arr=this->fetchCourse_Reg_Info();
		arr[count]=s;
		ofstream fout("Course_Reg_Info.txt");
		count++;
		fout<<count<<endl;
		for(int i=0;i<count;i++)
			fout<<arr[i];
		delete [] arr;
		arr=nullptr;
		fout.close();
	}
	void editCourse_Reg_Info()
	{
		string name;
		cout<<"Enter The Semester Name whose Registration info u want to edit: ";
		cin>>name;
		if(this->searchSemester(name)!=-1 && this->searchCourse_Reg_Info(name)!=-1){
			Course_Reg_Info s=this->searchCourse_Reg_Info1(name);
			cout<<"Semester Data as Follows!!!"<<endl;
			s.Printdata();
			Course_Reg_Info s1;
			cout<<"Now Enter Updated data"<<endl;
			s1.setsem_name(name);
			s1.updateInput();
			this->updateCourse_Reg_Info(name,s1);
			cout<<"Semester info with name "<<name<<" Has been Updated Check file!!!"<<endl;
		}
		else{
			cout<<"Error Semester Name Not Found"<<endl;
		}
	}
	void updateCourse_Reg_Info(string name,Course_Reg_Info s)
	{
		Course_Reg_Info *arr=this->fetchCourse_Reg_Info();
		int count=this->totalCourse_Reg_Info();
		int index=this->searchCourse_Reg_Info(name);
		arr[index]=s;
		ofstream fout("Course_Reg_Info.txt");
		fout<<count<<endl;
		for(int i=0;i<count;i++)
			fout<<arr[i];
		delete [] arr;
		arr=nullptr;
		fout.close();
	}
	void deleteCourse_Reg_Info()
	{
		string Name;
		cout<<"Enter Semester Name whose info  u want to delete: ";
		cin>>Name;
		if(this->deleteCourse_Reg_Info(Name)==true)
		{
			cout<<"Semester Info with Name "<<Name<<" Has been deleted Check file!!!"<<endl;
		}
		else
		{
			cout<<"Error!!!Method Fail"<<endl;
		}
	}
	bool deleteCourse_Reg_Info(string name)
	{
		Course_Reg_Info *arr=this->fetchCourse_Reg_Info();
		int count=this->totalCourse_Reg_Info();
		int index=this->searchCourse_Reg_Info(name);
		if(index!=-1){
			for(int i=index;i<count-1;i++){
				arr[i]=arr[i+1];
			}
			ofstream fout("Course_Reg_Info.txt");
			count--;
			fout<<count<<endl;
			for(int i=0;i<count;i++)
				fout<<arr[i];
			fout.close();
			delete [] arr;
			arr=nullptr;
			return true;
		}
		delete [] arr;
		arr=nullptr;
		return false;
	}
	int searchCourse_Reg_Info(string sem_name)
	{
		Course_Reg_Info *arr=this->fetchCourse_Reg_Info();
		int count=this->totalCourse_Reg_Info();
		int index=-1;
		for(int i=0;i<count;i++){
			if(arr[i].getsemname().compare(sem_name)==0){
				index=i;
			}
		}
		delete [] arr;
		arr=nullptr;
		return index;
	}
	Course_Reg_Info searchCourse_Reg_Info1(string sem_name)
	{
		Course_Reg_Info *arr=this->fetchCourse_Reg_Info();
		int count=this->totalCourse_Reg_Info();
		Course_Reg_Info s;
		for(int i=0;i<count;i++){
			if(arr[i].getsemname().compare(sem_name)==0){
				s=arr[i];
			}
		}
		delete [] arr;
		arr=nullptr;
		return s;
	}
	int totalCourse_Reg_Info()
	{
		int count;
		ifstream fin("Course_Reg_Info.txt");
		fin>>count;
		fin.close();
		return count;
	}
	void openreg()
	{
		string name;
		cout<<"Enter The Semester Name whose Registration U want to open: ";
		cin>>name;
		if(this->searchSemester(name)!=-1 && this->searchCourse_Reg_Info(name)!=-1){
			Course_Reg_Info s=this->searchCourse_Reg_Info1(name);
			s.openReg();
			this->updateCourse_Reg_Info(name,s);
			cout<<"Registration period Of Semester "<<name<<" has been activate Plz check file"<<endl;
		}
		else{
			cout<<"Error Semester Name Not Found"<<endl;
		}
	}
	void closereg()
	{
		string name;
		cout<<"Enter The Semester Name whose Registration u want close: ";
		cin>>name;
		if(this->searchSemester(name)!=-1 && this->searchCourse_Reg_Info(name)!=-1){
			Course_Reg_Info s=this->searchCourse_Reg_Info1(name);
			s.closedReg();
			this->updateCourse_Reg_Info(name,s);
			cout<<"Registration period Of Semester "<<name<<" has been closed Plz check file"<<endl;
		}
		else{
			cout<<"Error Semester Name Not Found"<<endl;
		}
	}
	void openwithdraw()
	{
		string name;
		cout<<"Enter The Semester Name whose WithDraw Period u want to active: ";
		cin>>name;
		if(this->searchSemester(name)!=-1 && this->searchCourse_Reg_Info(name)!=-1){
			Course_Reg_Info s=this->searchCourse_Reg_Info1(name);
			s.openwithdraw();
			this->updateCourse_Reg_Info(name,s);
			cout<<"WithDraw period Of Semester "<<name<<" has been activate Plz check file"<<endl;
		}
		else{
			cout<<"Error Semester Name Not Found"<<endl;
		}
	}
	void closewithdraw()
	{
		string name;
		cout<<"Enter The Semester Name whose WithDraw Period u want to deactive: ";
		cin>>name;
		if(this->searchSemester(name)!=-1 && this->searchCourse_Reg_Info(name)!=-1){
			Course_Reg_Info s=this->searchCourse_Reg_Info1(name);
			s.closedwithdraw();
			this->updateCourse_Reg_Info(name,s);
			cout<<"WithDraw period Of Semester "<<name<<" has been closed Plz check file"<<endl;
		}
		else{
			cout<<"Error Semester Name Not Found"<<endl;
		}
	}
	void updatewithdrawdate()
	{
		string name;
		cout<<"Enter The Semester Name whose WithDraw Date u want to update: ";
		cin>>name;
		if(this->searchSemester(name)!=-1 && this->searchCourse_Reg_Info(name)!=-1){
			Course_Reg_Info s=this->searchCourse_Reg_Info1(name);
			Date d;
			cin>>d;
			s.updatewithdrawdate(d);
			this->updateCourse_Reg_Info(name,s);
		}
		else{
			cout<<"Error Semester Name Not Found"<<endl;
		}
	}
	Date parsedate(string date){
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
	void PrintCourseDates(string sem_name)
	{
		Course_Reg_Info c=searchCourse_Reg_Info1(sem_name);
		c.PrintCourseDates();
	}
	void PrintWithDrawDates(string sem_name)
	{
		Course_Reg_Info c=searchCourse_Reg_Info1(sem_name);
		c.PrintWithDrawDates();
	}
	Date getwithdraw(string sem_name)
	{
		Course_Reg_Info *arr=this->fetchCourse_Reg_Info();
		int count=this->totalCourse_Reg_Info();
		Date date;
		for(int i=0;i<count;i++){
			if(arr[i].getsemname().compare(sem_name)==0){
				date=arr[i].getwithdraw();
			}
		}
		delete [] arr;
		arr=nullptr;
		return date;
	}
	//Course Functions
	int SearchCourse(string code)
	{
		Course *arr=this->fetchCourses();
		int count=this->totalcourses();
		int index=-1;
		for(int i=0;i<count;i++){
			if(arr[i].getcode().compare(code)==0){
				index=i;
			}
		}
		delete [] arr;
		arr=nullptr;
		return index;
	}
	Course SearchCourse1(string code)
	{
		Course *arr=this->fetchCourses();
		int count=this->totalcourses();
		Course c;
		for(int i=0;i<count;i++){
			if(arr[i].getcode().compare(code)==0){
				c=arr[i];
			}
		}
		delete [] arr;
		arr=nullptr;
		return c;
	}
	int totalcourses()
	{
		int count;
		ifstream fin("Course.txt");
		fin>>count;
		fin.close();
		return count;
	}
	Course * fetchCourses()
	{
		Course *arr=new Course[100];
		string N;
		string C;
		int C_H;
		int total_sec;
		char arr1[5];
		int count;
		ifstream fin("Course.txt");
		fin>>count;
		for(int i=0;i<count;i++){
			fin>>C;
			fin>>N;
			fin>>C_H;
			fin>>total_sec;
			fin.getline(arr1,5);
			arr[i].setdata1(N,C,C_H,total_sec);
		}

		fin.close();

		return arr;
	}
	void AddNewCourse(){
		Course c;
		cin>>c;
		this->AddNewCourse(c);
	}
	void AddNewCourse(Course c)
	{
		int count= this->totalcourses();
		Course *arr=this->fetchCourses();
		arr[count]=c;
		ofstream fout("Course.txt");
		count++;
		fout<<count<<endl;
		for(int i=0;i<count;i++)
			fout<<arr[i];
		delete [] arr;
		arr=nullptr;
		fout.close();
	}
	void EditCourse()
	{
		string code;
		cout<<"Enter The Course Code whose data u want to edit: ";
		cin>>code;
		if(this->SearchCourse(code)!=-1){
			Course c=this->SearchCourse1(code);
			cout<<"Course Data as Follows!!!"<<endl;
			c.Printdata();
			Course c1;
			cout<<"Now Enter Updated data"<<endl;
			c1.updatedInput(code);
			this->UpdateCourse(c1,code);
			cout<<"Course with code "<<code<<" Has been Updated Check file!!!"<<endl;
		}
		else{
			cout<<"Error Course Code Not Found"<<endl;
		}
	}
	void UpdateCourse(Course c,string code)
	{
		int count= this->totalcourses();
		int index=this->SearchCourse(code);
		Course *arr=this->fetchCourses();
		arr[index]=c;
		ofstream fout("Course.txt");
		fout<<count<<endl;
		for(int i=0;i<count;i++)
			fout<<arr[i];
		fout.close();
		Section *arr1=this->fetchsections();
		int count1=this->totalsections();
		for(int i=0;i<count1;i++)
		{
			if(arr1[i].CourseCode().compare(code)==0){
				arr1[i].setCourseCode(c.getcode());
				updateSection(code,arr1[i].GetName(),arr1[i]);
			}
		}
		delete [] arr;
		arr=nullptr;
		delete [] arr1;
		arr1=nullptr;


	}
	bool deleteCourse(string code)
	{
		int count= this->totalcourses();
		int index=this->SearchCourse(code);
		Course *arr=this->fetchCourses();
		if(index!=-1){
			for(int i=index;i<count-1;i++){
				arr[i]=arr[i+1];
			}
			ofstream fout("Course.txt");
			count--;
			fout<<count<<endl;
			for(int i=0;i<count;i++)
				fout<<arr[i];
			fout.close();
			Section *arr1=this->fetchsections();
			int count1=this->totalsections();
			for(int i=0;i<count1;i++)
			{
				if(arr1[i].CourseCode().compare(code)==0){
					deleteSection(code,arr1[i].GetName());
				}
			}
			delete [] arr;
			arr=nullptr;
			delete [] arr1;
			arr1=nullptr;
			return true;
		}
		delete [] arr;
		arr=nullptr;
		return false;
	}
	void deleteCourse()
	{
		string code;
		cout<<"Enter The Course Code u want to delete: ";
		cin>>code;
		if(this->deleteCourse(code)==true)
		{
			cout<<"Course with Course Code "<<code<<" Has been deleted Check file!!!"<<endl;
		}
		else
		{
			cout<<"Error!!!Method Fail"<<endl;
		}
	}
	void PrintCourses()
	{
		Course * c=fetchCourses();
		int count =totalcourses();
		for(int i=0;i<count;i++)
			cout<<c[i];
	}
	//Section Functions
	Section *fetchsections(string course)
	{
		Section *arr=new Section[100];
		int id;
		string N;
		string C;
		int total_seats;
		int occpy_seats;
		string Teacher_username;
		char arr1[5];
		int count;
		ifstream fin("Section.txt");
		fin>>count;
		int j=0;
		for(int i=0;i<count;i++){
			fin>>C;
			fin>>N;
			fin>>total_seats;
			fin>>occpy_seats;
			fin>>Teacher_username;
			fin.getline(arr1,5);
			if(C.compare(course)==0){
				arr[j++].setdata1(N,C,total_seats,occpy_seats,Teacher_username);
			}
		}

		fin.close();

		return arr;
	}
	int totalsections(string course)
	{
		Section *arr=fetchsections();
		int count=totalsections();
		int j=0;
		for(int i=0;i<count;i++)
		{
			if(arr[i].CourseCode().compare(course)==0)
				j++;
		}
		return j;
	}
	void addnewsection()
	{
		Section s;
		string course_code;
		cout<<"Enter The Course Code in which u want to add Section: ";
		cin>>course_code;
		int index=0;
		if(SearchCourse(course_code)!=-1){
			s.setCourseCode(course_code);
			cout<<"Course Found...Enter Details of Section!!!"<<endl;
			cin>>s;
			this->addNewsection(s);

		}
		else
		{
			cout<<"Course Not Found!!!"<<endl;
		}

	}
	void addNewsection(Section s)
	{
		int count= this->totalsections();
		Section *arr=this->fetchsections();
		arr[count]=s;
		ofstream fout("Section.txt");
		count++;
		fout<<count<<endl;
		for(int i=0;i<count;i++)
			fout<<arr[i];
		delete [] arr;
		arr=nullptr;
		fout.close();
	}
	Section *fetchsections()
	{
		Section *arr=new Section[100];
		int id;
		string N;
		string C;
		int total_seats;
		int occpy_seats;
		string Teacher_username;
		char arr1[5];
		int count;
		ifstream fin("Section.txt");
		fin>>count;
		for(int i=0;i<count;i++){
			fin>>C;
			fin>>N;
			fin>>total_seats;
			fin>>occpy_seats;
			fin>>Teacher_username;
			fin.getline(arr1,5);
			arr[i].setdata1(N,C,total_seats,occpy_seats,Teacher_username);
		}

		fin.close();

		return arr;
	}
	Section *fetchsections_Teachers(string username)
	{
		Section *arr=new Section[100];
		int id;
		string N;
		string C;
		int total_seats;
		int occpy_seats;
		string Teacher_username;
		char arr1[5];
		int count;
		int j=0;
		ifstream fin("Section.txt");
		fin>>count;
		for(int i=0;i<count;i++){
			fin>>C;
			fin>>N;
			fin>>total_seats;
			fin>>occpy_seats;
			fin>>Teacher_username;
			fin.getline(arr1,5);
			if(Teacher_username.compare(username)==0)
				arr[j++].setdata1(N,C,total_seats,occpy_seats,Teacher_username);
		}

		fin.close();

		return arr;
	}
	int fetchsections_Teachers1(string username)
	{

		int id;
		string N;
		string C;
		int total_seats;
		int occpy_seats;
		string Teacher_username;
		char arr1[5];
		int count;
		int j=0;
		ifstream fin("Section.txt");
		fin>>count;
		for(int i=0;i<count;i++){
			fin>>C;
			fin>>N;
			fin>>total_seats;
			fin>>occpy_seats;
			fin>>Teacher_username;
			fin.getline(arr1,5);
			if(Teacher_username.compare(username)==0)
				j++;
		}

		fin.close();

		return j;
	}
	int totalsections()
	{
		int count;
		ifstream fin("Section.txt");
		fin>>count;
		fin.close();
		return count;
	}
	int searchSection(string course_Code,string section_name)
	{

		Section *arr=this->fetchsections();
		int count=this->totalsections();
		int index=-1;
		for(int i=0;i<count;i++){
			if(arr[i].CourseCode().compare(course_Code)==0 && arr[i].GetName().compare(section_name)==0){
				index=i;
			}
		}
		delete [] arr;
		arr=nullptr;
		return index;
	}
	Section searchSection1(string course_Code,string section_name)
	{
		Section *arr=this->fetchsections();
		int count=this->totalsections();
		Section s;
		for(int i=0;i<count;i++){
			if(arr[i].CourseCode().compare(course_Code)==0 && arr[i].GetName().compare(section_name)==0){
				s=arr[i];
			}
		}
		delete [] arr;
		arr=nullptr;
		return s;
	}
	void editSection()
	{
		string course_code;
		string section_Name;
		cout<<"Enter The Name of Course whose section u want to edit: ";
		cin>>course_code;
		cout<<"Enter The Name of Section whose section u want to edit: ";
		cin>>section_Name;
		if(this->SearchCourse(course_code)!=-1){
			if(this->searchSection(course_code,section_Name)!=-1)

			{
				Section s=searchSection1(course_code,section_Name);
				cout<<"Section Data as Follows!!!"<<endl;
				s.Printdata();
				Section s1;;
				cout<<"Now Enter Updated data"<<endl;
				s1.UpdateInput(section_Name);
				this->updateSection(course_code,section_Name,s1);
				cout<<"Section "<< section_Name<<" of Course "<<course_code<<" Has been Updated Check file!!!"<<endl;
			}
			else{
				cout<<"Error Section Not Found"<<endl;
			}
		}


		else{
			cout<<"Error Course Code Not Found"<<endl;
		}
	}
	void updateSection(string Course_Code,string sectionname,Section s)
	{
		int count= this->totalsections();
		int index=this->searchSection(Course_Code,sectionname);
		Section *arr=this->fetchsections();
		arr[index]=s;
		ofstream fout("Section.txt");
		fout<<count<<endl;
		for(int i=0;i<count;i++)
			fout<<arr[i];
		delete [] arr;
		arr=nullptr;
		fout.close();
	}
	void deleteSection()
	{
		string course_code;
		string section_Name;
		cout<<"Enter The Name of Course whose section u want to edit: ";
		cin>>course_code;
		cout<<"Enter The Name of Section whose section u want to edit: ";
		cin>>section_Name;
		if(this->SearchCourse(course_code)!=-1){
			if(this->searchSection(course_code,section_Name)!=-1)

			{
				deleteSection(course_code,section_Name);
			}
			else{
				cout<<"Error Section Not Found"<<endl;
			}
		}


		else{
			cout<<"Error Course Code Not Found"<<endl;
		}
	}
	bool deleteSection(string course_Code,string sectionname)
	{
		int count= this->totalsections();
		int index=this->searchSection(course_Code,sectionname);
		Section *arr=this->fetchsections();
		if(index!=-1){
			for(int i=index;i<count-1;i++){
				arr[i]=arr[i+1];
			}
			ofstream fout("Section.txt");
			count--;
			fout<<count<<endl;
			for(int i=0;i<count;i++)
				fout<<arr[i];
			fout.close();
			delete [] arr;
			arr=nullptr;
			deleteRegistration1(course_Code,sectionname);
			deleteMarks1(course_Code,sectionname);
			deleteAttendance1(course_Code,sectionname);
			return true;
		}
		return false;
	}
	void setTeacher()
	{
		string course_code;
		string section_name;
		string t_name;
		cout<<"Enter Course Name: ";
		cin>>course_code;
		cout<<"Enter Section Name: ";
		cin>>section_name;
		cout<<"Enter Teacher username:";
		cin>>t_name;
		if(searchSection(course_code,section_name)==-1 || searchteacher(t_name)==-1)
		{
			cout<<"Error!!!Try Again"<<endl;
			return;
		}
		else
		{
			Section s = searchSection1(course_code,section_name);
			Teacher t=searchteacher1(t_name);
			s.setTecaher(t);
			updateSection(course_code,section_name,s);
		}
	}

	//Students
	Student * fetchstudents(){
		Student *arr=new Student[100];
		string N;
		string FN;
		int a;
		string A;
		Date dob;
		int M_Marks;
		int I_Marks;
		string roll;
		int b;
		Semester curr_sem;
		string date;
		string sem_name;
		char arr1[5];
		int count;
		ifstream fin("Student.txt");
		fin>>count;
		for(int i=0;i<count;i++){
			fin>>roll;
			fin>>b;
			fin>>N;
			fin>>FN;
			fin>>a;
			fin>>A;
			fin>>date;
			fin>>M_Marks;
			fin>>I_Marks;
			fin>>sem_name;
			dob=this->parsedate(date);
			curr_sem.setname(sem_name);
			fin.getline(arr1,5);
			arr[i].setdata(N,FN,a,A,dob,M_Marks,I_Marks,roll,b,curr_sem);
		}

		fin.close();

		return arr;
	}
	int searchstudent(string roll){
		Student *arr=this->fetchstudents();
		int count= this->totalstudent();
		int index=-1;
		for(int i=0;i<count;i++){
			if(arr[i].getroll().compare(roll)==0){
				index=i;
			}
		}
		delete [] arr;
		arr=nullptr;
		return index;

	}
	Student searchstudent1(string roll){
		Student *arr=this->fetchstudents();
		int count= this->totalstudent();
		Student s;
		for(int i=0;i<count;i++){
			if(arr[i].getroll().compare(roll)==0){
				s=arr[i];
			}
		}
		delete [] arr;
		arr=nullptr;
		return s;

	}
	int totalstudent(){
		int count;
		ifstream fin("Student.txt");
		fin>>count;
		fin.close();
		return count;
	}
	void AddNewStud(){
		Student s;
		cin>>s;
		this->AddNewStud(s);
	}
	void deleteStudent(){
		string roll;
		cout<<"Enter The Roll_No u want to delete: ";
		cin>>roll;
		if(this->deleteStudent(roll)==true)
		{
			cout<<"Student with roll No "<<roll<<" Has been deleted Check file!!!"<<endl;
		}
		else
		{
			cout<<"Error!!!Method Fail"<<endl;
		}
	}
	void AddNewStud(Student s)
	{
		int count;
		ifstream fin("Student.txt");
		fin>>count;
		fin.close();
		Student *arr=this->fetchstudents();
		arr[count]=s;
		ofstream fout("Student.txt");
		count++;
		fout<<count<<endl;
		for(int i=0;i<count;i++)
			fout<<arr[i];
		delete [] arr;
		arr=nullptr;
		fout.close();
	}
	bool deleteStudent(string roll)
	{
		int count= this->totalstudent();
		int index=this->searchstudent(roll);
		Student *arr=this->fetchstudents();
		if(index!=-1){
			deleteAttendance_Stud(roll);
			deleteMarks_Stud(roll);
			deleteRegistration_Stud(roll);
			for(int i=index;i<count-1;i++){
				arr[i]=arr[i+1];
			}
			ofstream fout("Student.txt");
			count--;
			fout<<count<<endl;
			for(int i=0;i<count;i++)
				fout<<arr[i];
			fout.close();

			delete [] arr;
			arr=nullptr;
			return true;
		}
		delete [] arr;
		arr=nullptr;
		return false;
	}
	void UpdateStudent(Student s,string roll)
	{
		int count= this->totalstudent();
		int index=this->searchstudent(roll);
		Student *arr=this->fetchstudents();
		arr[index]=s;
		ofstream fout("Student.txt");
		fout<<count<<endl;
		for(int i=0;i<count;i++)
			fout<<arr[i];
		delete [] arr;
		arr=nullptr;
		fout.close();
	}
	void editStudent(){
		string roll;
		cout<<"Enter The Roll_No whose data u want to edit: ";
		cin>>roll;
		if(this->searchstudent(roll)!=-1){
			Student s=this->searchstudent1(roll);
			cout<<"Student Data as Follows!!!"<<endl;
			s.Printdata();
			Student s1;
			cout<<"Now Enter Updated data"<<endl;
			s1.updateInput();
			s1.setRollNo(roll);
			this->UpdateStudent(s,roll);
			cout<<"Student with roll No "<<roll<<" Has been Updated Check file!!!"<<endl;
		}
		else{
			cout<<"Error Roll No Not Found"<<endl;
		}

	}
	//Registration
	int totalRegistration()
	{
		int count;
		ifstream fin("Registration.txt");
		fin>>count;
		fin.close();
		return count;
	}
	void AddRegistration(Registration R)
	{
		Registration *arr=this->fetchRegistration();
		int count=this->totalRegistration();
		arr[count]=R;
		count++;
		ofstream fout("Registration.txt");
		fout<<count<<endl;
		for(int i=0;i<count;i++)
			fout<<arr[i];
		delete [] arr;
		arr=nullptr;
		fout.close();
	}
	Registration *fetchRegistration()
	{
		Registration *arr=new Registration[100];
		string roll,sem_name,course_code,section;
		string grade;
		Student stud;
		Semester sem;
		Section sec;
		char arr1[5];
		int count;
		string date;
		ifstream fin("Registration.txt");
		fin>>count;
		for(int i=0;i<count;i++){
			fin>>roll;
			fin>>sem_name;
			fin>>course_code;
			fin>>section;
			fin>>grade;
			fin.getline(arr1,5);
			stud=searchstudent1(roll);
			sem=searchSemester1(sem_name);
			sec=searchSection1(course_code,section);
			arr[i].setdata1(sec,stud,sem,grade);
		}

		fin.close();
		return arr;
	}
	Registration *fetchRegistration_Stud(string rollno)
	{
		Registration *arr=new Registration[100];
		string roll,sem_name,course_code,section;
		string grade;
		Student stud;
		Semester sem;
		Section sec;
		char arr1[5];
		int count;
		string date;
		ifstream fin("Registration.txt");
		fin>>count;
		int j=0;
		for(int i=0;i<count;i++){
			fin>>roll;
			fin>>sem_name;
			fin>>course_code;
			fin>>section;
			fin>>grade;
			fin.getline(arr1,5);
			stud=searchstudent1(roll);
			sem=searchSemester1(sem_name);
			sec=searchSection1(course_code,section);
			if(roll.compare(rollno)==0)
				arr[j++].setdata1(sec,stud,sem,grade);
		}

		fin.close();
		return arr;
	}
	int fetchRegistration_Stud1(string rollno)
	{

		string roll,sem_name,course_code,section;
		string grade;
		Student stud;
		Semester sem;
		Section sec;
		char arr1[5];
		int count;
		string date;
		ifstream fin("Registration.txt");
		fin>>count;
		int j=0;
		for(int i=0;i<count;i++){
			fin>>roll;
			fin>>sem_name;
			fin>>course_code;
			fin>>section;
			fin>>grade;
			fin.getline(arr1,5);
			stud=searchstudent1(roll);
			sem=searchSemester1(sem_name);
			sec=searchSection1(course_code,section);
			if(roll.compare(rollno)==0)
				j++;
		}

		fin.close();
		return j;
	}
	Registration *fetchRegistration_Studs(string rollno,string sem_name1)
	{
		Registration *arr=new Registration[100];
		string roll,sem_name,course_code,section;
		string grade;
		Student stud;
		Semester sem;
		Section sec;
		char arr1[5];
		int count;
		string date;
		ifstream fin("Registration.txt");
		fin>>count;
		int j=0;
		for(int i=0;i<count;i++){
			fin>>roll;
			fin>>sem_name;
			fin>>course_code;
			fin>>section;
			fin>>grade;
			fin.getline(arr1,5);
			stud=searchstudent1(roll);
			sem=searchSemester1(sem_name);
			sec=searchSection1(course_code,section);
			if(roll.compare(rollno)==0 && sem_name.compare(sem_name1)==0)
				arr[j++].setdata1(sec,stud,sem,grade);
		}

		fin.close();
		return arr;
	}
	int fetchRegistration_Studs1(string rollno,string sem_name1)
	{

		string roll,sem_name,course_code,section;
		string grade;
		Student stud;
		Semester sem;
		Section sec;
		char arr1[5];
		int count;
		string date;
		ifstream fin("Registration.txt");
		fin>>count;
		int j=0;
		for(int i=0;i<count;i++){
			fin>>roll;
			fin>>sem_name;
			fin>>course_code;
			fin>>section;
			fin>>grade;
			fin.getline(arr1,5);
			stud=searchstudent1(roll);
			sem=searchSemester1(sem_name);
			sec=searchSection1(course_code,section);
			if(roll.compare(rollno)==0 && sem_name.compare(sem_name1)==0)
				j++;
		}

		fin.close();
		return j;
	}
	void updateRegistration(string course,string roll,string sem_name,Registration s)
	{
		Registration *arr=this->fetchRegistration();
		int count=this->totalRegistration();
		int index=this->searchRegistration(course,roll,sem_name);
		arr[index]=s;
		ofstream fout("Registration.txt");
		fout<<count<<endl;
		for(int i=0;i<count;i++)
			fout<<arr[i];
		delete [] arr;
		arr=nullptr;
		fout.close();
	}
	bool deleteRegistration(string course,string roll,string sem_name)
	{
		Registration *arr=this->fetchRegistration();
		int count=this->totalRegistration();
		int index=this->searchRegistration(course,roll,sem_name);
		if(index!=-1){
			for(int i=index;i<count-1;i++){
				arr[i]=arr[i+1];
			}
			ofstream fout("Registration.txt");
			count--;
			fout<<count<<endl;
			for(int i=0;i<count;i++)
				fout<<arr[i];
			fout.close();
			delete [] arr;
			arr=nullptr;
			return true;
		}
		delete [] arr;
		arr=nullptr;
		return false;
	}
	void deleteRegistration1(string course,string section)
	{
		Registration *arr=this->fetchRegistration();
		int count=this->totalRegistration();
		int count2=0;
		for(int i=0;i<count;i++)
		{
			if(arr[i].CourseCode().compare(course)==0 && arr[i].secname().compare(section)==0)
			{
				for(int j=i;j<count-1;j++)
					arr[j]=arr[j+1];
				i--;
				count--;
			}

		}
		ofstream fout("Registration.txt");
		count--;
		fout<<count<<endl;
		for(int i=0;i<count;i++)
			fout<<arr[i];
		delete [] arr;
		arr=nullptr;
		fout.close();

	}
	void deleteRegistration2(string sem_name)
	{
		Registration *arr=this->fetchRegistration();
		int count=this->totalRegistration();
		int count2=0;
		for(int i=0;i<count;i++)
		{
			if(arr[i].semName().compare(sem_name)==0)
			{
				for(int j=i;j<count-1;j++)
					arr[j]=arr[j+1];
				i--;
				count--;
			}

		}
		ofstream fout("Registration.txt");
		count--;
		fout<<count<<endl;
		for(int i=0;i<count;i++)
			fout<<arr[i];
		delete [] arr;
		arr=nullptr;
		fout.close();

	}
	void UpdateRegistration2(string sem_name,string new_sem)
	{
		Registration *arr=this->fetchRegistration();
		int count=this->totalRegistration();
		int count2=0;
		for(int i=0;i<count;i++)
		{
			if(arr[i].semName().compare(sem_name)==0)
			{
				arr[i].updatesem_name(new_sem);
			}

		}
		ofstream fout("Registration.txt");
		fout<<count<<endl;
		for(int i=0;i<count;i++)
			fout<<arr[i];
		delete [] arr;
		arr=nullptr;
		fout.close();

	}
	void deleteRegistration_Stud(string roll)
	{
		Registration *arr=this->fetchRegistration();
		int count=this->totalRegistration();
		int count2=0;
		for(int i=0;i<count;i++)
		{
			if(arr[i].Stud_RollNo().compare(roll)==0)
			{
				for(int j=i;j<count-1;j++)
					arr[j]=arr[j+1];
				i--;
				count--;
			}

		}
		ofstream fout("Registration.txt");
		count--;
		fout<<count<<endl;
		for(int i=0;i<count;i++)
			fout<<arr[i];
		delete [] arr;
		arr=nullptr;
		fout.close();

	}
	int searchRegistration(string course,string roll,string sem_name)
	{
		Registration *arr=this->fetchRegistration();
		int count=this->totalRegistration();
		int index=-1;
		for(int i=0;i<count;i++){
			if(arr[i].CourseCode().compare(course)==0 && arr[i].Stud_RollNo().compare(roll)==0 && arr[i].semName().compare(sem_name)==0){
				index=i;
			}
		}
		return index;
	}
	Registration searchRegistration1(string course,string roll,string sem_name)
	{
		Registration *arr=this->fetchRegistration();
		int count=this->totalRegistration();
		Registration r;
		for(int i=0;i<count;i++){
			if(arr[i].CourseCode().compare(course)==0 && arr[i].Stud_RollNo().compare(roll)==0 && arr[i].semName().compare(sem_name)==0){
				r=arr[i];
			}
		}
		return r;
	}
	Student *fetchRegistration_Students(string course,string sec_name)
	{

		Student *arr2=new Student[100];
		int j=0;
		string roll,sem_name,course_code,section;
		string grade;
		Student stud;
		Semester sem;
		Section sec;
		char arr1[5];
		int count;
		string date;
		ifstream fin("Registration.txt");
		fin>>count;
		for(int i=0;i<count;i++){
			fin>>roll;
			fin>>sem_name;
			fin>>course_code;
			fin>>section;
			fin>>grade;
			fin.getline(arr1,5);
			stud=searchstudent1(roll);
			sem=searchSemester1(sem_name);
			sec=searchSection1(course_code,section);
			if(course_code.compare(course)==0 && section.compare(sec_name)==0)
			{
				arr2[j++]=stud;
			}

		}

		fin.close();
		return arr2;
	}
	Registration *fetchRegistration_Students1(string course,string sec_name)
	{

		Registration *arr2=new Registration[100];
		int j=0;
		string roll,sem_name,course_code,section;
		string grade;
		Student stud;
		Semester sem;
		Section sec;
		char arr1[5];
		int count;
		string date;
		ifstream fin("Registration.txt");
		fin>>count;
		for(int i=0;i<count;i++){
			fin>>roll;
			fin>>sem_name;
			fin>>course_code;
			fin>>section;
			fin>>grade;
			fin.getline(arr1,5);
			stud=searchstudent1(roll);
			sem=searchSemester1(sem_name);
			sec=searchSection1(course_code,section);
			if(course_code.compare(course)==0 && section.compare(sec_name)==0)
			{
				arr2[j++].setdata1(sec,stud,sem,grade);
			}
		}
		fin.close();
		return arr2;
	}
	int CountRegistration_Students(string course,string sec_name)
	{


		int j=0;
		string roll,sem_name,course_code,section;
		char grade;
		Student stud;
		Semester sem;
		Section sec;
		char arr1[5];
		int count;
		string date;
		ifstream fin("Registration.txt");
		fin>>count;
		for(int i=0;i<count;i++){
			fin>>roll;
			fin>>sem_name;
			fin>>course_code;
			fin>>section;
			fin>>grade;
			fin.getline(arr1,5);
			stud=searchstudent1(roll);
			sem=searchSemester1(sem_name);
			sec=searchSection1(course_code,section);
			if(course_code.compare(course)==0 && section.compare(sec_name)==0)
			{
				j++;
			}

		}

		fin.close();
		return j;
	}
	bool checkvalidRegistration(string roll,string course,string section)
	{

	}
	bool checkopenreg(string sem)
	{
		Course_Reg_Info r=searchCourse_Reg_Info1(sem);
		return r.checkregperiod();
	}
	bool checkopenwd(string sem)
	{
		Course_Reg_Info r=searchCourse_Reg_Info1(sem);
		return r.checkwithdrawPeriod();
	}

	//Evaluation
	void addnewEvaluation()
	{
		Evaluation e;
		cin>>e;
		this->addNewEvaluation(e);
	}
	Evaluation *fetchEvaluation()
	{
		Evaluation *arr=new Evaluation[100];
		string type;
		int max_weitage;
		int count=0;
		char arr1[5];
		ifstream fin("Evaluation.txt");
		fin>>count;
		for(int i=0;i<count;i++){
			fin>>type;
			fin>>max_weitage;
			fin.getline(arr1,5);
			arr[i].setdata(type,max_weitage);
		}

		fin.close();
		return arr;

	}
	void editEvaluation()
	{
		string type;
		cout<<"Enter Evaluation Type info u want to edit: ";
		cin>>type;
		if( this->searchEvaluation(type)!=-1){
			Evaluation e=this->searchEvaluation1(type);
			cout<<"Evaluation Data as Follows!!!"<<endl;
			e.Printdata();
			Evaluation e1;
			e1.settype(type);
			cout<<"Now Enter Updated data"<<endl;
			e1.UpdateInput();
			this->updateEvaluation(type,e1);
			cout<<"Evaluation info with Type "<<type<<" Has been Updated Check file!!!"<<endl;
		}
		else{
			cout<<"Error Evaluation Type Not Found"<<endl;
		}
	}
	void deleteEvaluation()
	{
		string Name;
		cout<<"Enter Evaluation Type whose info  u want to delete: ";
		cin>>Name;
		if(this->deleteEvaluation(Name)==true)
		{
			cout<<"Evaluation with type "<<Name<<" Has been deleted Check file!!!"<<endl;
		}
		else
		{
			cout<<"Error!!!Method Fail"<<endl;
		}
	}
	int searchEvaluation(string type)
	{
		Evaluation *arr=this->fetchEvaluation();
		int count=this->totalEvaluation();
		int index=-1;
		for(int i=0;i<count;i++){
			if(arr[i].gettype().compare(type)==0){
				index=i;
			}
		}

		return index;
	}
	Evaluation searchEvaluation1(string type)
	{
		Evaluation *arr=this->fetchEvaluation();
		int count=this->totalEvaluation();
		Evaluation s;
		for(int i=0;i<count;i++){
			if(arr[i].gettype().compare(type)==0){
				s=arr[i];
			}
		}
		//delete [] arr;
		//arr=nullptr;
		return s;
	}
	int totalEvaluation()
	{
		int count;
		ifstream fin("Evaluation.txt");
		fin>>count;
		fin.close();
		return count;
	}
	void addNewEvaluation(Evaluation e)
	{
		int count= this->totalEvaluation();
		Evaluation *arr=this->fetchEvaluation();
		arr[count]=e;
		ofstream fout("Evaluation.txt");
		count++;
		fout<<count<<endl;
		for(int i=0;i<count;i++)
			fout<<arr[i];
		delete [] arr;
		arr=nullptr;
		fout.close();
	}
	bool deleteEvaluation(string type)
	{
		Evaluation *arr=this->fetchEvaluation();
		int count=this->totalEvaluation();
		int index=this->searchEvaluation(type);
		if(index!=-1){
			for(int i=index;i<count-1;i++){
				arr[i]=arr[i+1];
			}
			ofstream fout("Evaluation.txt");
			count--;
			fout<<count<<endl;
			for(int i=0;i<count;i++)
				fout<<arr[i];
			fout.close();
			delete [] arr;
			arr=nullptr;
			return true;
		}
		delete [] arr;
		arr=nullptr;
		return false;
	}
	void updateEvaluation(string type,Evaluation e)
	{
		Evaluation *arr=this->fetchEvaluation();
		int count=this->totalEvaluation();
		int index=this->searchEvaluation(type);
		arr[index]=e;
		ofstream fout("Evaluation.txt");
		fout<<count<<endl;
		for(int i=0;i<count;i++)
			fout<<arr[i];
		//delete [] arr;
		//arr=nullptr;
		fout.close();
	}
	int searchEvaluation2(Evaluation e)
	{
		Evaluation *arr=this->fetchEvaluation();
		int count=this->totalEvaluation();
		int index=-1;
		for(int i=0;i<count;i++){
			if(arr[i].gettype().compare(e.gettype())==0 && arr[i].get_weitage()>=e.get_weitage()){
				index=i;
			}
		}
		///delete [] arr;
		//arr=nullptr;
		return index;
	}
	//Marks
	void addNewMarks(Marks *arr1,int count1)
	{
		int count= this->totalMarks();
		Marks *arr=this->fetchMarks();
		ofstream fout("Marks.txt");
		int count2=count+count1;
		fout<<count2<<endl;
		for(int i=0;i<count;i++)
			fout<<arr[i];
		for(int i=0;i<count1;i++)
			fout<<arr1[i];
		delete [] arr;
		arr=nullptr;
		//delete [] arr1;
		//arr1=nullptr;
		fout.close();
	}
	Marks *fetchMarks()
	{
		Marks *arr=new Marks[100];
		string type;
		int max_weitage;
		int index;
		string course;
		string sec;
		string roll;
		string name;
		int total_marks;
		int obtain_marks;
		int count=0;
		char arr1[5];
		ifstream fin("Marks.txt");
		fin>>count;
		for(int i=0;i<count;i++){
			fin>>sec;
			fin>>course;
			fin>>roll;
			fin>>name;
			fin>>total_marks;
			fin>>obtain_marks;
			fin>>type;
			fin>>index;
			fin>>max_weitage;
			fin.getline(arr1,5);
			Student s=searchstudent1(roll);
			Evaluation e;
			e.setdata(type,max_weitage);
			arr[i].setdata(total_marks,e,s,obtain_marks,course,sec,index);
		}

		fin.close();
		return arr;

	}
	Marks  searchMarks(string cour,string section,string Evuluation_type,string rollno,int ind)
	{
		Marks *arr=fetchMarks();
		int count=totalMarks();
		Marks m;
		for(int i=0;i<count;i++)
			if(arr[i].getcourse().compare(cour)==0 && arr[i].getsection().compare(section)==0 && arr[i].gettype().compare(Evuluation_type)==0
				&& arr[i].getroll().compare(rollno)==0 && arr[i].getindex()==ind)
				m=arr[i];
		delete [] arr;
		arr=nullptr;
		return m;

	}
	int  searchMarks1(string cour,string section,string Evuluation_type,string rollno,int ind)
	{
		Marks *arr=fetchMarks();
		int count=totalMarks();
		int index=-1;
		for(int i=0;i<count;i++)
			if(arr[i].getcourse().compare(cour)==0 && arr[i].getsection().compare(section)==0 && arr[i].gettype().compare(Evuluation_type)==0
				&& arr[i].getroll().compare(rollno)==0 && arr[i].getindex()==ind)
				index=i;
		delete [] arr;
		arr=nullptr;
		return index;

	}
	Marks * searchMarks_Stud(string cour,string section,string rollno)
	{
		Marks *arr=new Marks[100];
		string type;
		int max_weitage;
		string course;
		string sec;
		string roll;
		string name;
		int total_marks;
		int obtain_marks;
		int count=0;
		int ind;
		char arr1[5];
		ifstream fin("Marks.txt");
		fin>>count;
		int j=0;
		for(int i=0;i<count;i++){
			fin>>sec;
			fin>>course;
			fin>>roll;
			fin>>name;
			fin>>total_marks;
			fin>>obtain_marks;
			fin>>type;
			fin>>ind;
			fin>>max_weitage;
			fin.getline(arr1,5);
			Student s=searchstudent1(roll);
			Evaluation e;
			e.setdata(type,max_weitage);
			if(course.compare(cour)==0 && sec.compare(section)==0  && roll.compare(rollno)==0)
				arr[j++].setdata(total_marks,e,s,obtain_marks,course,sec,ind);
		}

		fin.close();
		return arr;	
	}
	int searchMarks_Stud1(string cour,string section,string rollno)
	{

		string type;
		int max_weitage;
		string course;
		string sec;
		string roll;
		string name;
		int total_marks;
		int obtain_marks;
		int count=0;
		int ind;
		char arr1[5];
		ifstream fin("Marks.txt");
		fin>>count;
		int j=0;
		for(int i=0;i<count;i++){
			fin>>sec;
			fin>>course;
			fin>>roll;
			fin>>name;
			fin>>total_marks;
			fin>>obtain_marks;
			fin>>type;
			fin>>ind;
			fin>>max_weitage;
			fin.getline(arr1,5);
			Student s=searchstudent1(roll);
			Evaluation e;
			e.setdata(type,max_weitage);
			if(course.compare(cour)==0 && sec.compare(section)==0  && roll.compare(rollno)==0)
				j++;
		}

		fin.close();
		return j;	
	}
	int totalMarks()
	{
		int count;
		ifstream fin("Marks.txt");
		fin>>count;
		fin.close();
		return count;
	}
	bool deleteMarks(string cour,string section,string Evuluation_type,int ind)
	{
		Marks *arr=this->fetchMarks();
		int count=this->totalMarks();
		int count2=0;
		for(int i=0;i<count;i++)
		{
			if(arr[i].getcourse().compare(cour)==0 && arr[i].getsection().compare(section)==0 && arr[i].gettype().compare(Evuluation_type)==0 && arr[i].getindex()==ind)
			{
				for(int j=i;j<count-1;j++)
					arr[j]=arr[j+1];
				i--;
				count--;
			}

		}
		ofstream fout("Marks.txt");
		fout<<count<<endl;
		for(int i=0;i<count;i++)
			fout<<arr[i];
		fout.close();
		delete [] arr;
		arr=nullptr;
		return true;
		delete [] arr;
		arr=nullptr;
		return false;
	}
	bool deleteMarks_Stud(string roll)
	{
		Marks *arr=this->fetchMarks();
		int count=this->totalMarks();
		int count2=0;
		for(int i=0;i<count;i++)
		{
			if(arr[i].getroll().compare(roll)==0)
			{
				for(int j=i;j<count-1;j++)
					arr[j]=arr[j+1];
				i--;
				count--;
			}

		}
		ofstream fout("Marks.txt");
		fout<<count<<endl;
		for(int i=0;i<count;i++)
			fout<<arr[i];
		fout.close();
		delete [] arr;
		arr=nullptr;
		return true;
		delete [] arr;
		arr=nullptr;
		return false;
	}
	bool deleteMarks1(string cour,string section)
	{
		Marks *arr=this->fetchMarks();
		int count=this->totalMarks();
		int count2=0;
		for(int i=0;i<count;i++)
		{
			if(arr[i].getcourse().compare(cour)==0 && arr[i].getsection().compare(section)==0)
			{
				for(int j=i;j<count-1;j++)
					arr[j]=arr[j+1];
				i--;
				count--;
			}

		}
		ofstream fout("Marks.txt");
		fout<<count<<endl;
		for(int i=0;i<count;i++)
			fout<<arr[i];
		fout.close();
		delete [] arr;
		arr=nullptr;
		return true;

		return false;
	}
	void updateMarks(string cour,string section,string Evuluation_type,string rollno,int ind,Marks m)
	{
		Marks *arr=this->fetchMarks();
		int count=this->totalMarks();
		int index=this->searchMarks1(cour,section,Evuluation_type,rollno,ind);
		arr[index]=m;
		ofstream fout("Marks.txt");
		fout<<count<<endl;
		for(int i=0;i<count;i++)
			fout<<arr[i];
		delete [] arr;
		arr=nullptr;
		fout.close();
	}
	//Attendence
	void addNewAttendance(Attendance *arr1,int count1)
	{
		int count= this->totalAttendance();
		Attendance *arr=this->fetchAttendance();
		ofstream fout("Attendance.txt");
		int count2=count+count1;
		fout<<count2<<endl;
		for(int i=0;i<count;i++)
			fout<<arr[i];
		for(int i=0;i<count1;i++)
			fout<<arr1[i];
		delete [] arr;
		arr=nullptr;
		//delete [] arr1;
		//arr1=nullptr;
		fout.close();
	}
	Attendance *fetchAttendance()
	{
		Attendance *arr=new Attendance[100];
		int lecno;
		string course;
		string sec;
		string roll;
		string date;
		char status;
		int count=0;
		char arr1[5];
		ifstream fin("Attendance.txt");
		fin>>count;
		for(int i=0;i<count;i++){
			fin>>course;
			fin>>sec;
			fin>>roll;
			fin>>date;
			fin>>lecno;
			fin>>status;
			fin.getline(arr1,5);
			Student s=searchstudent1(roll);
			Date d=parsedate(date);
			arr[i].setdata(d,status,s,sec,course,lecno);
		}

		fin.close();
		return arr;

	}
	Attendance  searchAttendance(string cour,string section,int lecno,string roll)
	{
		Attendance *arr=fetchAttendance();
		int count=totalAttendance();
		Attendance a;
		for(int i=0;i<count;i++)
			if(arr[i].getcourse().compare(cour)==0 && arr[i].getsection().compare(section)==0 && arr[i].getroll().compare(roll)==0 && arr[i].getlecno()==lecno)
				a=arr[i];
		delete [] arr;
		arr=nullptr;
		return a;

	}
	int  searchAttendance1(string cour,string section,int lecno,string roll)
	{
		Attendance *arr=fetchAttendance();
		int count=totalAttendance();
		int a;
		for(int i=0;i<count;i++)
			if(arr[i].getcourse().compare(cour)==0 && arr[i].getsection().compare(section)==0 && arr[i].getroll().compare(roll)==0 && arr[i].getlecno()==lecno)
				a=i;
		delete [] arr;
		arr=nullptr;
		return a;
	}
	Attendance * searchAttendance_stud(string cour,string section,string rollno)
	{
		Attendance *arr=new Attendance[100];
		int lecno;
		string course;
		string sec;
		string roll;
		string date;
		char status;
		int count=0;
		char arr1[5];
		ifstream fin("Attendance.txt");
		fin>>count;
		int j=0;
		for(int i=0;i<count;i++){
			fin>>course;
			fin>>sec;
			fin>>roll;
			fin>>date;
			fin>>lecno;
			fin>>status;
			fin.getline(arr1,5);
			Student s=searchstudent1(roll);
			Date d=parsedate(date);
			if(course.compare(cour)==0 && sec.compare(section)==0 && roll.compare(rollno)==0)
				arr[j++].setdata(d,status,s,sec,course,lecno);
		}

		fin.close();
		return arr;
	}
	int  searchAttendance_stud1(string cour,string section,string rollno)
	{

		int lecno;
		string course;
		string sec;
		string roll;
		string date;
		char status;
		int count=0;
		char arr1[5];
		int j=0;
		ifstream fin("Attendance.txt");
		fin>>count;
		for(int i=0;i<count;i++){
			fin>>course;
			fin>>sec;
			fin>>roll;
			fin>>date;
			fin>>lecno;
			fin>>status;
			fin.getline(arr1,5);
			Student s=searchstudent1(roll);
			Date d=parsedate(date);
			if(course.compare(cour)==0 && sec.compare(section)==0 && roll.compare(rollno)==0)
				j++;
		}

		fin.close();
		return j;
	}
	int totalAttendance()
	{
		int count;
		ifstream fin("Attendance.txt");
		fin>>count;
		fin.close();
		return count;
	}
	bool deleteAttendance(string cour,string section,int lecno)
	{
		Attendance *arr=fetchAttendance();
		int count=totalAttendance();
		int count2=0;
		for(int i=0;i<count;i++)
		{
			if(arr[i].getcourse().compare(cour)==0 && arr[i].getsection().compare(section)==0 && arr[i].getlecno()==lecno)
			{
				for(int j=i;j<count-1;j++)
					arr[j]=arr[j+1];
				i--;
				count--;
			}

		}
		ofstream fout("Attendance.txt");
		//count=count-count2;
		fout<<count<<endl;
		for(int i=0;i<count;i++)
			fout<<arr[i];
		fout.close();
		delete [] arr;
		arr=nullptr;
		return true;

		return false;
	}
	bool deleteAttendance1(string cour,string section)
	{
		Attendance *arr=fetchAttendance();
		int count=totalAttendance();
		int count2=0;
		for(int i=0;i<count;i++)
		{
			if(arr[i].getcourse().compare(cour)==0 && arr[i].getsection().compare(section)==0)
			{
				for(int j=i;j<count-1;j++)
					arr[j]=arr[j+1];
				i--;
				count--;
			}

		}
		ofstream fout("Attendance.txt");
		//count=count-count2;
		fout<<count<<endl;
		for(int i=0;i<count;i++)
			fout<<arr[i];
		fout.close();
		delete [] arr;
		arr=nullptr;
		return true;

		return false;
	}
	bool deleteAttendance_Stud(string roll)
	{
		Attendance *arr=fetchAttendance();
		int count=totalAttendance();
		int count2=0;
		for(int i=0;i<count;i++)
		{
			if(arr[i].getroll().compare(roll)==0)
			{
				for(int j=i;j<count-1;j++)
					arr[j]=arr[j+1];
				i--;
				count--;
			}

		}
		ofstream fout("Attendance.txt");
		fout<<count<<endl;
		for(int i=0;i<count;i++)
			fout<<arr[i];
		fout.close();
		delete [] arr;
		arr=nullptr;
		return true;

		return false;
	}
	void updateAttendance(string cour,string section,int lecno,string roll,Attendance m)
	{
		Attendance *arr=this->fetchAttendance();
		int count=this->totalAttendance();
		int index=this->searchAttendance1(cour,section,lecno,roll);
		arr[index]=m;
		ofstream fout("Attendance.txt");
		fout<<count<<endl;
		for(int i=0;i<count;i++)
			fout<<arr[i];
		delete [] arr;
		arr=nullptr;
		fout.close();
	}
	//Notification
	int totalnotification()
	{
		int count;
		ifstream fin("Notification.txt");
		fin>>count;
		fin.close();
		return count;
	}
	void addNewNoti(string r,string c,string s,string m)
	{
		Notification n;
		n.set(r,c,s,m);
		Notification *arr=fetchNotification();
		int count=totalnotification();
		arr[count++]=n;
		PrintNotification(arr,count);

	}
	void PrintNotification(Notification *arr,int count)
	{
		ofstream fout("Notification.txt");
		fout<<count<<endl;
		for(int i=0;i<count;i++)
		{
			fout<<arr[i].Roll<<" "<<arr[i].course<<" "<<arr[i].section<<" "<<arr[i].status<<" "<<arr[i].message<<endl;
		}
	}
	Notification *fetchNotification()
	{
		Notification *arr=new Notification[100];
		string r,c,s,m,st;
		int count=0;
		char arr1[5];
		ifstream fin("Notification.txt");
		fin>>count;
		for(int i=0;i<count;i++){
			fin>>r;
			fin>>c;
			fin>>s;
			fin>>st;
			getline(fin,m);
			arr[i].set1(r,c,s,m,st);
		}

		fin.close();
		return arr;
	}
	Notification SearchNotification(string roll,string cou,string sec)
	{
		Notification *arr=fetchNotification();
		int count=totalnotification();
		Notification n;
		for(int i=0;i<count;i++)
		{
			if(arr[i].Roll.compare(roll)==0 && arr[i].course.compare(cou)==0 && arr[i].section.compare(sec)==0)
				n=arr[i];
		}
		return n;
	}
	int SearchNotification1(string roll,string cou,string sec)
	{
		Notification *arr=fetchNotification();
		int count=totalnotification();
		int n;
		for(int i=0;i<count;i++)
		{
			if(arr[i].Roll.compare(roll)==0 && arr[i].course.compare(cou)==0 && arr[i].section.compare(sec)==0)
				n=i;
		}
		return n;
	}
	Notification *fetchNotification_Stud(string roll)
	{
		Notification *arr=new Notification[100];
		string r,c,s,m,st;
		int count=0;
		char arr1[5];
		ifstream fin("Notification.txt");
		fin>>count;
		int j=0;
		for(int i=0;i<count;i++){
			fin>>r;
			fin>>c;
			fin>>s;
			fin>>st;
			getline(fin,m);
			if(r.compare(roll)==0 && st.compare("Yes"))
				arr[j++].set1(r,c,s,m,st);
		}

		fin.close();
		return arr;
	}
	int fetchNotification_Stud1(string roll)
	{

		string r,c,s,m,st;
		int count=0;
		char arr1[5];
		ifstream fin("Notification.txt");
		fin>>count;
		int j=0;
		for(int i=0;i<count;i++){
			fin>>r;
			fin>>c;
			fin>>s;
			fin>>st;
			getline(fin,m);
			if(r.compare(roll)==0 && st.compare("Yes"))
				j++;
		}
		fin.close();
		return j;
	}
	void update(string roll,string cou,string sec,Notification n)
	{
		Notification *arr=fetchNotification();
		int index=SearchNotification1(roll,cou,sec);
		if(index!=-1)
		{
			arr[index]=n;
			PrintNotification(arr,totalnotification());
		}
	}
};