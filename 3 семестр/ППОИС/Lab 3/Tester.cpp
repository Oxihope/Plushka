#include  "Tester.h"

Tester::Tester(string worker_name, int worker_salary) : Worker(worker_name, worker_salary) {}

void Tester::Test() {
	cout << this->Get_Worker_Name() << " start test something\n";
}