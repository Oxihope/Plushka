#pragma once
#include "Plant.h"

class Coral : public Plant {
public:
	Coral(Contact_Info contact_info_coral) : Plant(contact_info_coral) {
		this->Set_Size(25);
		this->Set_Growth_Degree(10);
		this->Set_Color("Red-Orange");
		this->Set_Plant_Type("Coral");
	}
};
