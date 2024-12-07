#pragma once
#include <iostream>

using namespace std;

class Worker {
public:
	Worker(string worker_name, int worker_salary);
	virtual ~Worker() {}

	string Get_Worker_Name();

	int Get_Worker_Salary();
	void Set_Worker_Salary(int salary);

	int Get_Worker_Budget();

	void Take_Salary(int salary);

private:
	string Worker_Name="";
	int Worker_Salary;
	int Worker_Budget = 0;
};