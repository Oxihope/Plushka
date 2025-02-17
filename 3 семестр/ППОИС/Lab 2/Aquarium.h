#pragma once
#include <vector>
#include "Animal.h"
#include "Plant.h"

class Aquarium {
public:

	Aquarium(Contact_Info contact_info_aquarium) : Info(contact_info_aquarium) {};

	Contact_Info Get_Contact_Info() const;

	vector<Animal>& Get_Animal_list();

	void Add_Animal(Animal animal);

	void Delete_Animal(int animal_id);

	vector<Plant>& Get_Plant_list();

	void Add_Plant(Plant plant);

	void Delete_Plant(int plant_id);

private:
	Contact_Info Info;
	vector<Animal> Animal_list;
	vector<Plant> Plant_list;

	int Search_Animal(int animal_id) const;

	int Search_Plant(int plant_id) const;
};
