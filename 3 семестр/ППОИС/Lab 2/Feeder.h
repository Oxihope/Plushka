#pragma once
#include "Worker.h"
#include "Animal.h"
#include "Food.h"
#include "Storage.h"

class Feeder : virtual public Worker {
public:
	Feeder(Contact_Info contact_info_feeder) : Worker(contact_info_feeder) {
		this->Set_Post("Feeder");
	}

	void Feed_Animal(Animal& animal, Food food, Storage& storage);
};
