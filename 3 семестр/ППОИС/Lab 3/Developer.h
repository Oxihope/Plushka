#pragma once
#include <iostream>
#include "Worker.h"

using namespace std;

class Developer : public Worker {
public:
	Developer(string worker_name, int worker_salary);

	void Develop();
};