#pragma once
#include "Animal.h"

class Shark : public Animal {
public:
	Shark(Contact_Info contact_info_shark) : Animal(contact_info_shark) {
		this->Set_Animal_Type("Shark");
	}

	string Speak() override;
};