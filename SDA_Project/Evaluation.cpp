#include "Evaluation.h"
#include "System.h"
Evaluation::Evaluation(){
	max_weitage=0;
	type="";
}
Evaluation::Evaluation(string t,int w){
	this->type=t;
	this->max_weitage=w;
}
void Evaluation::setdata(string t,int w)
{
	this->type=t;
	this->max_weitage=w;
}
string Evaluation::gettype()
{
	return this->type;
}
void Evaluation::Printdata()
{
	cout<<"Type :"<<this->type<<endl;
	cout<<"Max_Weitage :"<<this->max_weitage<<endl;
}
int Evaluation::get_weitage()
{
	return this->max_weitage;
}
int Evaluation::searchEvaluation(string type)
{
	System s;
	return s.searchEvaluation(type);
}
void Evaluation::UpdateInput()
{
	cout<<"Enter Max Weitage(int): ";
	cin>>max_weitage;
}
void Evaluation::settype(string t)
{
	type=t;
}
void Evaluation::getinput()
{
	cout<<"Enter Type of Evaluation(str): ";
	cin>>type;
	while(searchEvaluation(type)==-1)
	{
		cout<<"Evaluation Type Not Found Plz Enter valid Type(str):";
		cin>>type;
	}
	cout<<"Enter Max Weitage(int): ";
	cin>>max_weitage;
}