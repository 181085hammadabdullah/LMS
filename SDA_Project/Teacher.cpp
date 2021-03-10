#include "Teacher.h"
#include "System.h"
#include "Section.h"
Teacher::Teacher(){
	this->Experience=this->Experience="";
}
Teacher::Teacher(string N,string FN,int a,string A,Date dob,string q,string e,string u)
	:Person(N,FN,a,A,dob)
{
	this->Qualification=q;
	this->Experience=e;
	this->username=u;
}
void Teacher::setdata(string N,string FN,int a,string A,Date dob,string Qual,string Exp,string u)
{
	this->Name=N;
	this->FName=FN;
	this->age=a;
	this->Address=A;
	this->DOB=dob;
	this->Qualification=Qual;
	this->Experience=Exp;
	this->username=u;
}
string Teacher::getusername(){
	return username;
}
void Teacher::Printdata(){
	cout<<"Name: "<<this->Name<<endl;
	cout<<"Father Name: "<<this->FName<<endl;
	cout<<"UserName: "<<this->username<<endl;
	cout<<"Address: "<<this->Address<<endl;
	cout<<"Age: "<<this->age<<endl;
	cout<<"DOB: "<<this->DOB<<endl;
	cout<<"Qualification: "<<this->Qualification<<endl;
	cout<<"Experience: "<<this->Experience<<endl;
}
void Teacher::updateInput(string u)
{
	this->username=u;
	cout<<"Enter Name The of Teacher(str): ";
	cin>>this->Name;
	cout<<"Enter Father Name The of Teacher(str): ";
	cin>>this->FName;
	cout<<"Enter Age The of Teacher(int): ";
	cin>>this->age;
	cout<<"Enter Address The of Teacher(city): ";
	cin>>this->Address;
	cout<<"Enter Date Of Birth The of Teacher: "<<endl;
	cin>>this->DOB;
	cout<<"Enter Qualification The of Teacher(int): ";
	cin>>this->Qualification;
	cout<<"Enter Experience The of Teacher(int): ";
	cin>>this->Experience;

}
int Teacher::searchteacher(string username)
{
	System s;
	return s.searchteacher(username);
}
void Teacher::fetchsections_Teachers()
{
	System s;
	Section * arr=s.fetchsections_Teachers(this->username);
	int count=s.fetchsections_Teachers1(this->username);
	cout<<"You Are currently Registered Courses:"<<endl;
	for(int i=0;i<count;i++)
		cout<<arr[i];
}
//Marks
void Teacher::AddMarks()
{
	string course;
	string section;
	System s;
	cout<<"Enter Course:";
	cin>>course;
	cout<<"Enter Section:";
	cin>>section;
	if(s.searchSection(course,section)!=-1)
	{
		Section s1=s.searchSection1(course,section);
		if(s1.getTeacherid().compare(this->username)==0)
		{
			Student *arr=s.fetchRegistration_Students(course,section);
			int count=s.CountRegistration_Students(course,section);
			Marks *arr1=new Marks[count];
			Evaluation e;
			int t_marks;
			int o_marks;
			int m_index;
			cout<<"Enter Evaluation Details: ";
			e.getinput();
			int index=s.searchEvaluation2(e);
			if(index!=-1)
			{
				cout<<"Enter Total Marks:"<<endl;
				cin>>t_marks;
				cout<<"Enter Evaluation Index:"<<endl;
				cin>>m_index;
				for(int i=0;i<count;i++)
				{
					arr1[i].setdata1(t_marks,e,arr[i],course,section,m_index);
					cout<<"Enter Marks of Student with Roll No "<<arr[i].getroll()<<"  and Name "<<arr[i].getname()<<" : ";
					cin>>o_marks;
					arr1[i].setmarks(o_marks);
				}
				System s;
				s.addNewMarks(arr1,count);
				delete [] arr;
				arr=nullptr;
				//delete [] arr1;
				//arr1=nullptr;
			}
			else
			{
				cout<<"Error"<<endl;
			}
		}
		else
		{
			cout<<"Error"<<endl;
		}
	}

	else
	{
		cout<<"Error"<<endl;
	}
}
void Teacher::updateMarks()
{
	string course;
	string section;
	System s;
	cout<<"Enter Course:";
	cin>>course;
	cout<<"Enter Section:";
	cin>>section;
	if(s.searchSection(course,section)!=-1)
	{
		Section s1=s.searchSection1(course,section);
		if(s1.getTeacherid().compare(this->username)==0)
		{

			string e_type;
			int o_marks;
			int m_index;
			string roll;
			cout<<"Enter Evaluation Type: ";
			cin>>e_type;
			cout<<"Enter Evaluation Index:";
			cin>>m_index;
			cout<<"Enter RollNo of Student:";
			cin>>roll;
			System s;
			int index=s.searchMarks1(course,section,e_type,roll,m_index);
			if(index!=-1)
			{
				Marks m = s.searchMarks(course,section,e_type,roll,m_index);
				cout<<m;
				cout<<"Enter New Marks: ";
				cin>>o_marks;

				m.setmarks(o_marks);

				s.updateMarks(course,section,e_type,roll,m_index,m);
			}
			else
			{
				cout<<"Error"<<endl;
			}
		}
		else
		{
			cout<<"Error"<<endl;
		}
	}

	else
	{
		cout<<"Error"<<endl;
	}
}
void Teacher::deleteMarks()
{
	string course;
	string section;
	System s;
	cout<<"Enter Course:";
	cin>>course;
	cout<<"Enter Section:";
	cin>>section;
	if(s.searchSection(course,section)!=-1)
	{
		Section s1=s.searchSection1(course,section);
		if(s1.getTeacherid().compare(this->username)==0)
		{

			string e_type;
			int m_index;
			cout<<"Enter Evaluation Type: ";
			cin>>e_type;
			cout<<"Enter Evaluation Index:";
			cin>>m_index;
			System s;
			if(s.deleteMarks(course,section,e_type,m_index)==true)
			{
				cout<<"Success"<<endl;
			}
			else
			{
				cout<<"Error"<<endl;
			}
		}
		else
		{
			cout<<"Error"<<endl;
		}
	}

	else
	{
		cout<<"Error"<<endl;
	}
}
//Attendance
void Teacher::AddAttendance()
{
	string course;
	string section;
	System s;
	cout<<"Enter Course:";
	cin>>course;
	cout<<"Enter Section:";
	cin>>section;
	if(s.searchSection(course,section)!=-1)
	{
		Section s1=s.searchSection1(course,section);
		if(s1.getTeacherid().compare(this->username)==0)
		{
			Student *arr=s.fetchRegistration_Students(course,section);
			int count=s.CountRegistration_Students(course,section);
			Attendance *arr1=new Attendance[count];
			int lecno;
			Date date;
			char status;
			cout <<"Enter Date of Lecture:";
			cin>>date;
			cout<<"Enter LecNo:";
			cin>>lecno;
			for(int i=0;i<count;i++)
			{
				status=' ';
				arr1[i].setdata(date,status,arr[i],section,course,lecno);
				cout<<"Enter Attendance of Student with Roll No "<<arr[i].getroll()<<"  and Name "<<arr[i].getname()<<" : ";
				cin>>status;
				arr1[i].setStatus(status);
			}
			System s;
			s.addNewAttendance(arr1,count);
			delete [] arr;
			arr=nullptr;
			//delete [] arr1;
			//arr1=nullptr;
		}
		else
		{
			cout<<"Error"<<endl;
		}
	}
	else
	{
		cout<<"Error"<<endl;
	}



}
void Teacher::updateAttendance()
{
	string course;
	string section;
	System s;
	cout<<"Enter Course:";
	cin>>course;
	cout<<"Enter Section:";
	cin>>section;
	if(s.searchSection(course,section)!=-1)
	{
		Section s1=s.searchSection1(course,section);
		if(s1.getTeacherid().compare(this->username)==0)
		{
			string roll;
			int lecno;
			char status;
			cout<<"Enter Lecno:";
			cin>>lecno;
			cout<<"Enter RollNo of Student:";
			cin>>roll;
			System s;
			int index=s.searchAttendance1(course,section,lecno,roll);
			if(index!=-1)
			{
				Attendance m = s.searchAttendance(course,section,lecno,roll);
				cout<<m;
				cout<<"Enter New Status: ";
				cin>>status;
				m.setStatus(status);
				s.updateAttendance(course,section,lecno,roll,m);
			}
			else
			{
				cout<<"Error"<<endl;
			}
		}
		else
		{
			cout<<"Error"<<endl;
		}
	}

	else
	{
		cout<<"Error"<<endl;
	}
}
void Teacher::deleteAttendance()
{
	string course;
	string section;
	System s;
	cout<<"Enter Course:";
	cin>>course;
	cout<<"Enter Section:";
	cin>>section;
	if(s.searchSection(course,section)!=-1)
	{
		Section s1=s.searchSection1(course,section);
		if(s1.getTeacherid().compare(this->username)==0)
		{

			int lecno;
			cout<<"Enter Lecno:";
			cin>>lecno;
			System s;
			if(s.deleteAttendance(course,section,lecno)==true)
			{
				cout<<"Success"<<endl;
			}
			else
			{
				cout<<"Error"<<endl;
			}
		}
		else
		{
			cout<<"Error"<<endl;
		}
	}

	else
	{
		cout<<"Error"<<endl;
	}
}
void Teacher::setGrades()
{
	string course;
	string section;
	System s;
	cout<<"Enter Course:";
	cin>>course;
	cout<<"Enter Section:";
	cin>>section;
	string grade;
	if(s.searchSection(course,section)!=-1)
	{
		Section s1=s.searchSection1(course,section);
		if(s1.getTeacherid().compare(this->username)==0)
		{
			Student *arr=s.fetchRegistration_Students(course,section);
			Registration *arr1=s.fetchRegistration_Students1(course,section);
			int count=s.CountRegistration_Students(course,section);
			for(int i=0;i<count;i++)
			{
				arr[i].GetGT(course,section);
			}
			for(int i=0;i<count;i++)
			{
				if(arr1[i].getGrade()!="W")
				{
					cout<<"Enter the Grade of Student with RollNo "<<arr1[i].Stud_RollNo()<<" and absolutes "<<arr[i].GetGT(course,section)<<":";
					cin>>grade;
					arr1[i].updategrade(grade);
					s.updateRegistration(course,arr1[i].Stud_RollNo(),arr1[i].semName(),arr1[i]);
				}
			}
			delete [] arr;
			arr=nullptr;
			//delete [] arr1;
			//arr1=nullptr;
		}
	}
}

