#pragma once
#include "Animal.h"

class Dolphin : public Animal {
public:
	Dolphin(Contact_Info contact_info_dolphin) : Animal(contact_info_dolphin) {
		this->Set_Animal_Type("Dolphin");
	}

	string Speak() override;
};
