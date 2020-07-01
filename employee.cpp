#include"employee.h"

Employee::Employee(int id, string name, int type) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_Type = 1;
}

void Employee::showInfo() {
	cout << "Employee Id: " << this->m_Id << "\t"
		<< "Employee name: " << this->m_Name << "\t"
		<< "Type: regular staff " << endl;
}
