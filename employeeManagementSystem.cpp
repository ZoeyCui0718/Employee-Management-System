#include <iostream>
using namespace std;
#include "employeeManager.h"
#include "employeeAbstract.h"
#include "employee.h"
#include "manager.h"

int main() {

	EmployeeManager Em;

	int choice = 0;

	while (true)
	{
		Em.showMenu();

		cin >> choice;

		switch (choice) {
		case 0: // exit the system 
			Em.exitSystem();
			break;
		case 1: // add a new employee
			Em.add_Emp();
			break;
		case 2: // show the employee's info
			Em.showEmp();
			break;
		case 3: // remove the former employee
			Em.del_Emp();
			break;
		case 4: // edit the employee's info
			Em.edit_Emp();
			break;
		case 5: // search an employee
			Em.search_Emp();
			break;
		case 6: // sort all employees
			Em.sort_Emp();
			break;
		case 7: // clear the system
			break;
		default:
			system("cls");
			break;
		}
	}



	system("pause");

	return 0;
}