#pragma once
#include <iostream>
#include "Worker.h"

using namespace std;

class Tester : public Worker {
public:
	Tester(string worker_name, int worker_salary);

	virtual void Test();
};