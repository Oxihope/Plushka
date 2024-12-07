#include "Level_Tester.h"

Level_Tester::Level_Tester(string worker_name, int worker_salary) : Tester(worker_name, worker_salary) {}

void Level_Tester::Test() {
	cout << this->Get_Worker_Name() << " start test some game level\n";
}