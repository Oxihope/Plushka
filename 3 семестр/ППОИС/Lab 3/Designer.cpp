#include "Designer.h"

Designer::Designer(string worker_name, int worker_salary) : Worker(worker_name, worker_salary) {}

void Designer::Design() {
	cout << this->Get_Worker_Name() << " start disign something\n";
}