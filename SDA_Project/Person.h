#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <fstream>
#include <conio.h>
#include "Date.h"
using namespace std;
class Person
{
protected:
	string Name;
	string FName;
	int age;
	string Address;
	Date DOB;
public:
	Person();
	Person(string N,string FN,int a,string A,Date dob);
	Person(const Person &obj);

};