#include "Worker.h"

Worker::Worker(string worker_name, int worker_salary) : Worker_Name(worker_name), Worker_Salary(worker_salary) {
	if (worker_salary < 0) {
		throw invalid_argument("Worker salary must be positive");
	}
}

string Worker::Get_Worker_Name() {
	return Worker_Name;
}

int Worker::Get_Worker_Salary() {
	return Worker_Salary;
}
void Worker::Set_Worker_Salary(int salary) {
	if (salary < 0) {
		throw invalid_argument("Salary must be positive");
	}
	Worker_Salary = salary;
}

int Worker::Get_Worker_Budget() {
	return Worker_Budget;
}

void Worker::Take_Salary(int salary) {
	if (salary < 0) {
		throw invalid_argument("Salary must be positive");
	}
	Worker_Budget = Worker_Budget + salary;
}