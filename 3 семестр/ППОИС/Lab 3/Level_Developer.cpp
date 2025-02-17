#include "Level_Developer.h"

Level_Developer::Level_Developer(string worker_name, int worker_salary) : Developer(worker_name, worker_salary) {}

void Level_Developer::Develop() {
	cout << this->Get_Worker_Name() << " start develop some game level\n";
}