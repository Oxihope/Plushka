#include "Developer.h"

Developer::Developer(string worker_name, int worker_salary) : Worker(worker_name, worker_salary) {}

void Developer::Develop() {
	cout << this->Get_Worker_Name() << " start develop something\n";
}