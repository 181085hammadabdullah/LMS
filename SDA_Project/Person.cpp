#include "Person.h"
Person::Person(){
	Name=FName=Address="";
	age=-1;
}
Person::Person(string N,string FN,int a,string A,Date dob)
{
	this->Name=N;
	this->FName=FN;
	this->age=a;
	this->Address=A;
	this->DOB=dob;
}
Person::Person(const Person &obj)
{
	this->Name=obj.Name;
	this->FName=obj.FName;
	this->age=obj.age;
	this->Address=obj.Address;
	this->DOB=obj.DOB;
}