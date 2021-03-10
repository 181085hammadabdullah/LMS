#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <fstream>
#include <conio.h>
using namespace std;
class Evaluation
{
private:
	string type;
	int max_weitage;
public:
	Evaluation();
	Evaluation(string t,int w);
	friend  istream& operator>>(istream &in,Evaluation &obj)
	{
		
		cout<<"Enter Type of Evaluation(str): ";
		in>>obj.type;
		while(obj.searchEvaluation(obj.type)!=-1)
		{
		cout<<"Evaluation with This Type is Already Present Plz Enter valid Type(str):";
		in>>obj.type;
		}
		cout<<"Enter Max Weitage(int): ";
		in>>obj.max_weitage;
		return in;

	}
	friend  ostream& operator<<(ostream &out, Evaluation&obj)
	{
		out<<obj.type<<" "<<obj.max_weitage<<endl;;
		return out;
	}
	void setdata(string t,int w);
	string gettype();
	void Printdata();
	int get_weitage();
	int searchEvaluation(string type);
	void UpdateInput();
	void settype(string t);
	void getinput();
};