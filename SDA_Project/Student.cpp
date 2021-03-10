#include "Student.h"
#include "System.h"
#include "Registration.h"
Student::Student(){
	this->Matric_Marks=this->Inter_Marks=this->batch=0;
	Roll_No="";
}
Student::Student(string N,string FN,int a,string A,Date dob,int M_Marks,int I_Marks,string roll,int b,Semester curr_sem)
	:Person(N,FN,a,A,dob)
{
	this->Matric_Marks=M_Marks;
	this->Inter_Marks=I_Marks;
	this->Roll_No=roll;
	this->batch=b;
	this->current_sem=curr_sem;

}
void Student::setdata(string N,string FN,int a,string A,Date dob,int M_Marks,int I_Marks,string roll,int b,Semester curr_sem)
{
	this->Name=N;
	this->FName=FN;
	this->age=a;
	this->Address=A;
	this->DOB=dob;
	this->Matric_Marks=M_Marks;
	this->Inter_Marks=I_Marks;
	this->Roll_No=roll;
	this->batch=b;
	this->current_sem=curr_sem;
}
string Student::getroll(){
	return Roll_No;
}
void Student::Printdata(){
	cout<<"Name: "<<this->Name<<endl;
	cout<<"Father Name: "<<this->FName<<endl;
	cout<<"Roll No: "<<this->Roll_No<<endl;
	cout<<"Batch: "<<this->batch<<endl;
	cout<<"Address: "<<this->Address<<endl;
	cout<<"Age: "<<this->age<<endl;
	cout<<"DOB: "<<this->DOB<<endl;
	cout<<"Matric Marks: "<<this->Matric_Marks<<endl;
	cout<<"Inter Marks: "<<this->Inter_Marks<<endl;
	cout<<"Current Semester: "<<this->current_sem.getname()<<endl;
}
void Student::Addcourse()
{
	System *s=new System();
	string cname;
	string sname;


	if(s->searchSemester(current_sem.getname())==-1 || s->searchCourse_Reg_Info(current_sem.getname())==-1 || s->checkopenreg(current_sem.getname())==0)
	{
		cout<<"Error!!!Plz Try Later"<<endl;
		return;
	}
	else
	{
		printCourses();
		cout<<"Enter The course Code u want to Register: "<<endl;
		cin>>cname;
		if(s->SearchCourse(cname)==-1)
		{
			cout<<"Error!!!Invalid Course Code"<<endl;
			return;
		}
		else
		{
			Section *arr=s->fetchsections(cname);
			int count=s->totalsections(cname);
			cout<<"Sections of Course "<<cname<<" are:";
			for(int i=0;i<count;i++)
			{

				cout<<arr[i].GetName()<<" ";

			}
			cout<<endl;
			cout<<"Now Enter Section in which u want Registered :";
			cin>>sname;
			int check=0;
			for(int i=0;i<count;i++)
			{
				if(arr[i].GetName().compare(sname)==0){

					if(arr[i].isSpace()==true)
					{
						check=1;
						arr[i].incseats();
						s->updateSection(cname,sname,arr[i]);

					}
					else
					{
						cout<<"Sections Are Full!!!We will notify u if any of seats will be empty!!!"<<endl;
						s->addNewNoti(Roll_No,cname,sname,"Dear Student the seats of Course "+cname+" in section "+sname+ " is available");
					}

				}
			}
			if(check==1)
			{
				int r=s->searchRegistration(cname,this->getroll(),current_sem.getname());
				if(r==-1)
					this->AddCourse(cname,sname);
				else
				{
					cout<<"U are already Registered in this Course!!!"<<endl;
				}
			}
			else
			{
				cout<<"Invalid Section!!!"<<endl;
			}
		}
	}
}
bool Student::AddCourse(string course,string section)
{
	Registration R;
	System s;
	Student stud=s.searchstudent1(this->Roll_No);
	Section sec=s.searchSection1(course,section);
	R.setdata(sec,stud,current_sem);
	s.AddRegistration(R);
	return true;
}
void Student::Dropcourse()
{
	System *s=new System();
	string cname;
	string sname;


	if(s->searchSemester(current_sem.getname())==-1 || s->searchCourse_Reg_Info(current_sem.getname())==-1 || s->checkopenreg(current_sem.getname())==0)
	{
		cout<<"Error!!!Plz Try Later"<<endl;
		return;
	}
	else
	{
		Registration *r=s->fetchRegistration_Studs(Roll_No,current_sem.getname());
		int count=s->fetchRegistration_Studs1(Roll_No,current_sem.getname());;
		if(count>0){
			cout<<"You Are currently Registred In Following Courses:"<<endl;
			for(int i=0;i<count;i++)
				cout<<r[i];
			cout<<"Enter The course Code u want to Drop: "<<endl;
			cin>>cname;
			if(s->SearchCourse(cname)==-1 || s->searchRegistration(cname,this->getroll(),current_sem.getname())==-1)
			{
				cout<<"Error!!!Invalid Course Code or Course Not Registered"<<endl;
				return;
			}
			else
			{
				Registration r=s->searchRegistration1(cname,this->getroll(),current_sem.getname());
				int check=DropCourse(cname);
				if(check==true){

					Section sec=s->searchSection1(cname,r.secname());
					Notification *arr=fetchNotification();
					int count2 =totalnotification();
					for(int i=0;i<count2;i++)
					{
						if(arr[i].course.compare(cname)==0 && arr[i].section.compare(r.secname())==0)
							arr[i].status="Yes";
					}
					PrintNotification(arr,count2);
					sec.decseats();
					s->updateSection(cname,r.secname(),sec);
				}
				else
				{
					cout<<"Invalid Course Name!!!"<<endl;
				}
			}
		}
	}
}
bool Student::DropCourse(string course)
{
	System s;
	int check=s.searchRegistration(course,this->getroll(),current_sem.getname());
	if(check!=-1)
	{
		s.deleteRegistration(course,this->getroll(),current_sem.getname());
		return true;
	}
	return false;
}
void Student::WithDrawcourse()
{
	System s;
	string cname;
	string sname;
	Date d=s.getwithdraw(current_sem.getname());
	time_t now = time(0);
	tm *ltm = localtime(&now);
	int y=1900 + ltm->tm_year;
	int d1=ltm->tm_mday;
	int m=1 + ltm->tm_mon;

	if(y<=d.gety() && m<=d.getm() && d1<=d.getd())
	{


		if(s.searchSemester(current_sem.getname())==-1 || s.searchCourse_Reg_Info(current_sem.getname())==-1 || s.checkopenwd(current_sem.getname())==0)
		{
			cout<<"Error!!!Plz Try Later"<<endl;
			return;
		}
		else
		{
			Registration *r=s.fetchRegistration_Studs(Roll_No,current_sem.getname());
			int count=s.fetchRegistration_Studs1(Roll_No,current_sem.getname());;
			if(count>0){
				cout<<"You Are currently Registred In Following Courses:"<<endl;
				for(int i=0;i<count;i++)
					cout<<r[i];
				cout<<"Enter The course Code u want to WithDraw: "<<endl;
				cin>>cname;
				int r=s.searchRegistration(cname,this->getroll(),current_sem.getname());
				if(r!=-1)
				{
					this->WithDrawCourse(cname);
				}
				else
					cout<<"Error!!!"<<endl;
			}
		}
	}
	else
	{
		cout<<"Withdraw Deadline has been passed....Contact Admistartor!!!"<<endl;
	}
}
bool Student::WithDrawCourse(string course)
{
	System s;
	Registration r=s.searchRegistration1(course,this->getroll(),current_sem.getname());
	r.updategrade("W");
	s.updateRegistration(course,this->getroll(),current_sem.getname(),r);
	return true;
}
void Student::seeAttendance()
{
	string course;
	string section;
	System s;
	Registration *r=s.fetchRegistration_Studs(Roll_No,current_sem.getname());
	int count=s.fetchRegistration_Studs1(Roll_No,current_sem.getname());;
	if(count>0){
		cout<<"You Are currently Registred In Following Courses:"<<endl;
		for(int i=0;i<count;i++)
			cout<<r[i];
		cout<<"Enter Course:";
		cin>>course;
		cout<<"Enter Section:";
		cin>>section;
		if(s.searchSection(course,section)!=-1)
		{
			int count = s.searchAttendance_stud1(course,section,Roll_No);
			if(count>0)
			{
				Attendance *arr = s.searchAttendance_stud(course,section,Roll_No);
				for(int i=0;i<count;i++)
					cout<<arr[i];
			}
			else
			{
				cout<<"No Record Found!!!"<<endl;
			}
		}
		else
		{
			cout<<"Invalid CourseCode or Section Name!!!"<<endl;
		}
	}
}
void Student::ViewTranscript()
{
	System s;
	Registration *R=s.fetchRegistration_Stud(Roll_No);
	int count=s.fetchRegistration_Stud1(Roll_No);
	string *arr1=new string[8];
	int *arr2=new int[8];
	arr1[0]=R[0].semName();
	arr2[0]=0;
	int j=0;
	for(int i=1;i<count;i++)
	{
		if(R[i].semName().compare(arr1[j])!=0)
		{

			j++;
			arr1[j]=R[i].semName();
			arr2[j]=i;
		}
	}
	j++;
	arr2[j]=count;
	int k=0;
	float sgpa=0.0;
	float cgpa=0.0;
	float ch=0.0;
	string grade;
	float points;
	float t_ch=0.0;
	float s_ch=0.0;
	for(int i=arr2[k];i<arr2[k+1] && i<count;i++)
	{
		if(i==arr2[k])
		{
			cout<<R[i].semName()<<endl;
		}


		cout<<R[i];
		Course course=s.SearchCourse1(R[i].CourseCode());
		grade=R[i].getGrade();
		if(grade!="I" && grade!="W")
		{
			points=GradeToPoints(grade);
			ch=course.GetHours();
			sgpa=sgpa+(ch*points);
			t_ch=t_ch+ch;
			s_ch=s_ch+ch;
		}
		if(i==arr2[k+1]-1)
		{
			cgpa=cgpa+sgpa;
			sgpa=sgpa/s_ch;
			cout<<"Sgpa of Semester of "<<arr1[k]<<" is "<<sgpa<<endl;
			sgpa=0.0;
			s_ch=0.0;
			k++;
		}
	}
	cout<<"Cgpa is "<<cgpa/t_ch;
}
string Student::getname()
{
	return this->Name;
}
float Student::GradeToPoints(string g)
{
	if(g.compare("A+")==0)
		return 4.0;
	else if(g.compare("A")==0)
		return 4.0;
	else if(g.compare("A-")==0)
		return 3.67;
	else if(g.compare("B+")==0)
		return 3.33;
	else if(g.compare("B")==0)
		return 3.0;
	else if(g.compare("B-")==0)
		return 2.67;
	else if(g.compare("C+")==0)
		return 2.33;
	else if(g.compare("C")==0)
		return 2.0;
	else if(g.compare("C-")==0)
		return 1.67;
	else if(g.compare("D+")==0)
		return 1.33;
	else if(g.compare("D")==0)
		return 1.0;
	else if(g.compare("F")==0)
		return 0;
}
void Student::updateInput()
{
	cout<<"You cannot Update Student Roll No!!!!"<<endl;
	cout<<"Enter Name The of Student(str): ";
	cin>>this->Name;
	cout<<"Enter Father Name The of Student(str): ";
	cin>>this->FName;
	cout<<"Enter Age The of Student(int): ";
	cin>>this->age;
	cout<<"Enter Address The of Student(city): ";
	cin>>this->Address;
	cout<<"Enter Date Of Birth The of Student: "<<endl;
	cin>>this->DOB;
	cout<<"Enter Matric Marks The of Student(int): ";
	cin>>this->Matric_Marks;
	cout<<"Enter Inter Marks The of Student(int): ";
	cin>>this->Inter_Marks;
	cout<<"Enter Batch The of Student(Year): ";
	cin>>this->batch;
	cout<<"Enter The Semester of Student: "<<endl;
	cin>>this->current_sem;
}
void Student::setRollNo(string roll)
{
	this->Roll_No=roll;
}
void Student::seeMarks()
{
	string course;
	string section;
	System s;
	float om,tm,weitage,m;;
	float gt=0.0;
	float t_abs=0.0;
	Registration *r=s.fetchRegistration_Studs(Roll_No,current_sem.getname());
	int count=s.fetchRegistration_Studs1(Roll_No,current_sem.getname());;
	if(count>0){
		cout<<"You Are currently Registred In Following Courses:"<<endl;
		for(int i=0;i<count;i++)
			cout<<r[i];

		cout<<"Enter Course:";
		cin>>course;
		cout<<"Enter Section:";
		cin>>section;
		if(s.searchSection(course,section)!=-1)
		{
			int count = s.searchMarks_Stud1(course,section,Roll_No);
			if(count>0)
			{
				Marks *arr = s.searchMarks_Stud(course,section,Roll_No);
				for(int i=0;i<count;i++)
				{
					om=arr[i].geto();
					tm=arr[i].gett();
					weitage=arr[i].getw();
					m=om/tm;
					m=m*weitage;
					gt=gt+m;
					t_abs=t_abs+weitage;
					cout<<arr[i];
				}
				cout<<"Your Grand Total is "<<gt<<"  Out of "<<t_abs<<endl;
				delete [] arr;
				arr=nullptr;

			}
			else
			{
				cout<<"No Record Found!!!"<<endl;
			}
		}
		else
		{
			cout<<"Invalid CourseCode or Section Name!!!"<<endl;
		}
	}
}
float Student::GetGT(string course,string section)
{
	System s;
	float om,tm,weitage,m;;
	float gt=0.0;
	float t_abs=0.0;
	if(s.searchSection(course,section)!=-1)
	{
		int count = s.searchMarks_Stud1(course,section,Roll_No);
		if(count>0)
		{
			Marks *arr = s.searchMarks_Stud(course,section,Roll_No);
			for(int i=0;i<count;i++)
			{
				om=arr[i].geto();
				tm=arr[i].gett();
				weitage=arr[i].getw();
				m=om/tm;
				m=m*weitage;
				gt=gt+m;
				t_abs=t_abs+weitage;
			}

			cout<<"Student with Roll No "<<Roll_No<<" Got "<<gt<<" Absolutes"<<endl;
			delete [] arr;
			arr=nullptr;
			return gt;
		}

	}
}
int Student::searchstudent(string roll)
{
	System s;
	return s.searchstudent(roll);
}
void Student::updatesem(string name)
{
	System s;
	Semester s1=s.searchSemester1(name);
	current_sem=s1;
}
void Student::PrintCourseDates()
{
	System s;
	s.PrintCourseDates(current_sem.getname());
}
void Student::PrintWithDrawDates()
{
	System s;
	s.PrintWithDrawDates(current_sem.getname());
}
void Student::printCourses()
{
	System s;
	cout<<"Offered Courses Are Given Below:"<<endl;
	s.PrintCourses();
}

