#include "Level_Designer.h"

Level_Designer::Level_Designer(string worker_name, int worker_salary) : Designer(worker_name, worker_salary) {}

void Level_Designer::Design() {
	cout << this->Get_Worker_Name() << " start design some game level\n";
}