#pragma once
#include "Developer.h"

class Level_Developer : public Developer {
public:
	Level_Developer(string worker_name, int worker_salary);

	void Develop();
};