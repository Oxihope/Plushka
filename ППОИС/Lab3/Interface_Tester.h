#pragma once
#include "Tester.h"

class Interface_Tester : public Tester {
public:
	Interface_Tester(string worker_name, int worker_salary);

	void Test() override;
};