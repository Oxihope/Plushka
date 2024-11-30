#pragma once
#include "Plant.h"

class Seaweed : public Plant {
public:
	Seaweed(Contact_Info contact_info_seaweed) : Plant(contact_info_seaweed) {
		this->Set_Size(40);
		this->Set_Growth_Degree(20);
		this->Set_Color("Dark Olive");
		this->Set_Plant_Type("Seaweed");
	}
};