#pragma once
#include "Designer.h"

class Level_Designer : public Designer {
public:
	Level_Designer(string worker_name, int worker_salary);

	void Design() override;
};