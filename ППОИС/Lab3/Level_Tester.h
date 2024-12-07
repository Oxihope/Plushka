#pragma once
#include "Tester.h"

class Level_Tester : public Tester {
public:
	Level_Tester(string worker_name, int worker_salary);

	void Test() override;
};