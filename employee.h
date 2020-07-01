#pragma once
#include<iostream>
using namespace std;
#include "employeeAbstract.h"

class Employee: public EmployeeAbstract {

public:

	Employee(int id, string name, int type);

	void showInfo();

};