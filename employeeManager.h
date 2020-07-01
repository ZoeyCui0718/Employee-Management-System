#pragma once
#include<iostream>
using namespace std;
#include "employeeAbstract.h"
#include "employee.h"
#include "manager.h"
#include <fstream>
#define FILENAME "empFile.txt"

class EmployeeManager {

public:

	EmployeeManager();

	void showMenu();

	void exitSystem();

	int m_EmpNum;

	EmployeeAbstract** m_EmpArray;

	void add_Emp();

	void save();

	bool m_IsEmpty;

	int getEmpNum();

	void init_Emp();

	void showEmp();

	void del_Emp();

	int isExist(int id);

	void edit_Emp();

	void search_Emp();

	void sort_Emp();

	void clear_File();

	~EmployeeManager();

};