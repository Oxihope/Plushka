#pragma once
#include "Developer.h"

class Interface_Developer : public Developer {
public:
	Interface_Developer(string worker_name, int worker_salary);

	void Develop();
};