#include "employeeManager.h"

EmployeeManager::EmployeeManager() {

	ifstream ifs;

	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open()) {

		cout << "The file doesn't exist." << endl;

		this->m_EmpNum = 0;

		this->m_EmpArray = NULL;

		this->m_IsEmpty = true;

		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof()) {

		cout << "The file is empty." << endl;

		this->m_EmpNum = 0;

		this->m_EmpArray = NULL;

		this->m_IsEmpty = true;

		ifs.close();
		return;

	}



	int num = this->getEmpNum();
	cout << "The number of employees: " << num << endl;
	this->m_EmpNum = num;

	this->m_EmpArray = new EmployeeAbstract * [this->m_EmpNum];
	this->init_Emp();

}

void EmployeeManager::showMenu() {

	cout << "Welcome to Employee Management System!" << endl;
	cout << "0. exit the system" << endl;	
	cout << "1. add a new employee" << endl;
	cout << "2. show the employee's info" << endl;
	cout << "3. remove the former employee" << endl;
	cout << "4. edit the employee's info" << endl;
	cout << "5. search an employee" << endl;
	cout << "6. sort all employees" << endl;
	cout << "7. clear the system" << endl;

}

void EmployeeManager::exitSystem() {
	system("pause");
	exit(0);
}

void EmployeeManager::add_Emp() {

	cout << "How many new employees would you want to add?" << endl;

	int num = 0;
	cin >> num;

	if (num > 0) {

		int newSize = this->m_EmpNum + num;

		EmployeeAbstract** newSpace = new EmployeeAbstract * [newSize];

		if (this->m_EmpArray != NULL) {

			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		for (int i = 0; i < num; i++) {
			
			int id;
			string name;
			int type;

			cout << "The id of new employee: " << endl;
			cin >> id;

			cout << "The name of new employee: " << endl;
			cin >> name;

			cout << "The type of new employee: (1 for regular stuff or 2 for manager) " << endl;
			cin >> type;

			EmployeeAbstract* worker = NULL;
			switch (type)
			{
			case 1:
				worker = new Employee(id, name, 1);
			case 2:
				worker = new Manager(id, name, 2);
			default:
				break;
			}

			newSpace[this->m_EmpNum + i] = worker;
		}

		delete[] this->m_EmpArray;
		this->m_EmpArray = newSpace;
		this->m_EmpNum = newSize;
		this->m_IsEmpty = false;

		cout << "Successfully added" << endl;

		this->save();

	}
	else {
		cout << "invalid number" << endl;
	}

	system("pause");
	system("cls");

}

void EmployeeManager::save() {

	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_Type << endl;
	}

	ofs.close();
}

int EmployeeManager::getEmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int type;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> type) {
		num++;
	}

	return num;
}

void EmployeeManager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int type;

	int i = 0;
	while (ifs >> id && ifs >> name && ifs >> type) {
		
		EmployeeAbstract* worker = NULL;

		if (type == 1) {
			worker = new Employee(id, name, 1);
		}
		else if (type == 2) {
			worker = new Manager(id, name, 2);
		}
		this->m_EmpArray[i] = worker;
		i++;
	}

	ifs.close();
}

void EmployeeManager::showEmp(){
	if (this->m_IsEmpty) {
		cout << "No employees" << endl;
	}
	else {
		for (int i = 0; i < m_EmpNum; i++) {
			this->m_EmpArray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
}

void EmployeeManager::del_Emp() {

	if (this->m_IsEmpty) {
		cout << "There is no file for employees" << endl;
	}
	else {
		cout << "The id of former employee: " << endl;
		int id = 0;
		cin >> id;

		int index = this->isExist(id);

		if (index != -1) {
			for (int i = index; i < this->m_EmpNum - 1; i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->save();

			cout << "Successfully deleted" << endl;

		}
		else {
			cout << "Error! Cannot find this employee." << endl;
		}
	}

	system("pause");
	system("cls");
}

void EmployeeManager::edit_Emp() {

	if (this->m_IsEmpty) {
		cout << "Empty file" << endl;
	}
	else {
		 
		cout << "The id of the employee: " << endl;
		int id;
		cin >> id;

		int ret = this->isExist(id);

		if (ret != -1) {
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int newType = 0;

			cout << "New Id: " << endl;
			cin >> newId;

			cout << "New name: " << endl;
			cin >> newName;

			cout << "New type: ( 1 for regular staff, 2 for manager" << endl;
			cin >> newType;

			EmployeeAbstract* worker = NULL;
			switch (newType)
			{
			case 1:
				worker = new Employee(newId, newName, 1);
				break;
			case 2:
				worker = new Manager(newId, newName, 2);
				break;
			default:
				break;
			}

			this->m_EmpArray[ret] = worker;
			this->save();

		}
		else {
			cout << "No such employee" << endl;
		}
	}
}

int EmployeeManager::isExist(int id) {

	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_Id == id) {
			index = i;
			break;
		}
	}

	return index;
}

void EmployeeManager::search_Emp() {

	if (this->m_IsEmpty) {
		cout << "Empty file for employees" << endl;
	}
	else {

		cout << "Press 1 to search by Id or Press 2 to search by Name" << endl;

		int select = 0;
		cin >> select;

		if (select == 1) {

			int id;
			cout << "Enter the id: " << endl;
			cin >> id;

			int ret = isExist(id);
			if (ret != -1) {
				this->m_EmpArray[ret]->showInfo();
			}
			else {
				cout << "No such employee" << endl;
			}
		}
		else if (select == 2) {

			string name;
			cout << "Enter the name: " << endl;
			cin >> name;

			bool flag = false;

			for (int i = 0; i < m_EmpNum; i++) {
				if (this->m_EmpArray[i]->m_Name == name) {
					
					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (!flag) {
				cout << "No such employee" << endl;
			}

		}
		else {
			cout << "Invalid input" << endl;
		}
	}
	system("pause");
	system("cls");
}

void EmployeeManager::sort_Emp() {

	if (this->m_IsEmpty) {
		cout << "Empty file for employees" << endl;
	}
	else {

		cout << "Press 1 to sort in ascending order or Press 2 to sort in descending order" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++) {
			int extrema = i;
			for (int j = i + 1; i < this->m_EmpNum; j++) {

				if (select == 1) {
					if (this->m_EmpArray[extrema]->m_Id > this->m_EmpArray[j]->m_Id) {
						extrema = j;
					}
				}
				else {
					if (this->m_EmpArray[extrema]->m_Id < this->m_EmpArray[j]->m_Id) {
						extrema = j;
					}
				}

				if (i != extrema) {
					EmployeeAbstract* temp = this->m_EmpArray[i];
					this->m_EmpArray[i] = this->m_EmpArray[extrema];
					this->m_EmpArray[extrema] = temp;
				}

				this->save();
				this->showEmp();
			}
		}
	}
}

void EmployeeManager::clear_File() {

	ofstream ofs(FILENAME, ios::trunc);

	ofs.close();

	if (this->m_EmpArray != NULL) {
		for (int i = 0; i < this->m_EmpNum; i++) {
			delete this->m_EmpArray[i];
			this->m_EmpArray[i] = NULL;
		}

		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_IsEmpty = true;
	}

	system("pause");
	system("cls");
}

EmployeeManager::~EmployeeManager() {

	if (this->m_EmpArray != NULL) {
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}

}