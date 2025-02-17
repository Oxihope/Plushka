#include "Interface_Tester.h"

Interface_Tester::Interface_Tester(string worker_name, int worker_salary) : Tester(worker_name, worker_salary) {}

void Interface_Tester::Test() {
	cout << this->Get_Worker_Name() << " start test game interface\n";
}