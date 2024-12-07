#pragma once
#include <iostream>
#include "Worker.h"

using namespace std;

class Designer :public Worker {
public:
	Designer(string worker_name, int worker_salary);

	virtual void Design();
};

