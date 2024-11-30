#pragma once
#include "Worker.h"
#include "Animal.h"
#include "Storage.h"
#include "Plant.h"

class Veterinarian : virtual public Worker {
public:
	Veterinarian(Contact_Info contact_info_veterinarian) : Worker(contact_info_veterinarian) {}

	void Heal_Animal(Animal& animal, Medicine medicine, Storage& storage);

	void Cut_Plant(Plant& plant, double cutting_degree);
};