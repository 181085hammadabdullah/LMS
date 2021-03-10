#pragma once
#include "Person.h"
#include "Semester.h"
#include <ctime>
class Student:public Person
{
private:
	int Matric_Marks;
	int Inter_Marks;
	string Roll_No;
	int batch;
	Semester current_sem;
	bool AddCourse(string course,string section);
	bool DropCourse(string course);
	bool WithDrawCourse(string course);
public:
	Student();
	Student(string N,string FN,int a,string A,Date dob,int M_Marks,int I_Marks,string roll,int b,Semester curr_sem);
	friend  istream& operator>>(istream &in,Student &obj)
	{
		cout<<"Note RollNo cannot be change or update afterwords so write it carefully!!!"<<endl;
		cout<<"Enter Roll No The of Student(str): ";
		in>>obj.Roll_No;
		while(obj.searchstudent(obj.Roll_No)!=-1)
		{
			cout<<"This Roll_No is Already Been used Plz Enter New Roll_No The of Student(str): ";
			in>>obj.Roll_No;
		}
		cout<<"Enter Name The of Student(str): ";
		in>>obj.Name;
		cout<<"Enter Father Name The of Student(str): ";
		in>>obj.FName;
		cout<<"Enter Age The of Student(int): ";
		in>>obj.age;
		cout<<"Enter Address The of Student(city): ";
		in>>obj.Address;
		cout<<"Enter Date Of Birth The of Student: "<<endl;
		in>>obj.DOB;
		cout<<"Enter Matric Marks The of Student(int): ";
		in>>obj.Matric_Marks;
		cout<<"Enter Inter Marks The of Student(int): ";
		in>>obj.Inter_Marks;
		cout<<"Enter Batch The of Student(Year): ";
		in>>obj.batch;
		cout<<"Enter The Semester of Student: "<<endl;
		in>>obj.current_sem;
		return in;

	}
	friend  ostream& operator<<(ostream &out,Student &obj)
	{

		out<<obj.Roll_No<<" "<<obj.batch<<" "<<obj.Name<<" "<<obj.FName<<" "<<obj.age<<" "<<obj.Address<<" "
			<<obj.DOB<<" "<<obj.Matric_Marks<<" "<<obj.Inter_Marks<<" "<<obj.current_sem.getname()<<endl;
		return out;

	}
	void setdata(string N,string FN,int a,string A,Date dob,int M_Marks,int I_Marks,string roll,int b,Semester curr_sem);
	string getroll();
	void Printdata();
	void Addcourse();
	void Dropcourse();
	void WithDrawcourse();
	string getname();
	void seeAttendance();
	void seeMarks();
	float GradeToPoints(string g);
	void ViewTranscript();
	void updateInput();
	void setRollNo(string roll);
	float GetGT(string course,string section);
	int searchstudent(string roll);
	void updatesem(string name);
	void PrintCourseDates();
	void PrintWithDrawDates();
	void printCourses();
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
	void PrintNotification1()
	{
		Notification *arr=fetchNotification_Stud(Roll_No);
		int count=fetchNotification_Stud1(Roll_No);
		if(count>0)
			cout<<"Student!!!!Important Notification!!!!!!!"<<endl;
		for(int i=0;i<count;i++)
		{
			cout<<arr[i].message<<endl;
		}
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
			if(r.compare(roll)==0 && st.compare("Yes")==0)
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
			if(r.compare(roll)==0 && st.compare("Yes")==0)
				j++;
		}
		PrintNotification(clearNotification_Stud(roll),clearNotification_Stud1(roll));
		fin.close();
		return j;
	}
	Notification *clearNotification_Stud(string roll)
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
			if(r.compare(roll)!=0 || st.compare("No")==0)
				arr[j++].set1(r,c,s,m,st);
		}

		fin.close();
		return arr;
	}
	int clearNotification_Stud1(string roll)
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
			if(r.compare(roll)!=0 || st.compare("No")==0)
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