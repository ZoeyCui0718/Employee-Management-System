#pragma once
#include <iostream>
using namespace std;
# include "employeeAbstract.h"

class Manager : public EmployeeAbstract {

public:

	Manager(int id, string name, int type);

	void showInfo();

};