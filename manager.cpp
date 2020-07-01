#include "manager.h"


Manager::Manager(int id, string name, int type) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_Type = type;
}

void Manager::showInfo() {
	cout << "Employee Id: " << this->m_Id << "\t"
		<< "Employee name: " << this->m_Name << "\t"
		<< "Type: manager" << endl;
}
