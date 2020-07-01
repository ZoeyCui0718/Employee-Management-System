#pragma once
#include<iostream>
using namespace std;

class EmployeeAbstract {

public:

	virtual void showInfo() = 0;

	int m_Id;

	string m_Name;

	string m_Type;

};