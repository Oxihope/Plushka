#include "Interface_Developer.h"

Interface_Developer::Interface_Developer(string worker_name, int worker_salary) : Developer(worker_name, worker_salary) {}

void Interface_Developer::Develop() {
	cout << this->Get_Worker_Name() << " start develop game interface\n";
}