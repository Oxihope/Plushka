#pragma once
#include "Designer.h"

class Sound_Effect_Designer : public Designer {
public:
	Sound_Effect_Designer(string worker_name, int worker_salary);

	void Design() override;
};