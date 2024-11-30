#pragma once
#include "Animal.h"

class Fish : public Animal {
public:
	Fish(Contact_Info contact_info_fish) : Animal(contact_info_fish) {
		this->Set_Animal_Type("Fish");
	}

	string Speak() override;
};