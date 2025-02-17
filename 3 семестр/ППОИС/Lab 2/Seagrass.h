#pragma once
#include "Plant.h"

class Seagrass : public Plant {
public:
	Seagrass(Contact_Info contact_info_seagrass) : Plant(contact_info_seagrass) {
		this->Set_Size(15);
		this->Set_Growth_Degree(15);
		this->Set_Color("Bright Green");
		this->Set_Plant_Type("Seagrass");
	}
};