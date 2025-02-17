#include "Sound_Effect_Designer.h"

Sound_Effect_Designer::Sound_Effect_Designer(string worker_name, int worker_salary) : Designer(worker_name, worker_salary) {}

void Sound_Effect_Designer::Design() {
	cout << this->Get_Worker_Name() << " start design some game sound effect\n";
}