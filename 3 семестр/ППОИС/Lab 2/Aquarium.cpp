#include "Aquarium.h"

Contact_Info Aquarium::Get_Contact_Info() const {
	return Info;
}

vector<Animal>& Aquarium::Get_Animal_list() {
	return Animal_list;
}

void Aquarium::Add_Animal(Animal animal) {
	Animal_list.push_back(animal);
}

void Aquarium::Delete_Animal(int animal_id) {
	int animal_index = Search_Animal(animal_id);
	if (animal_index != -1) {
		Animal_list.erase(Animal_list.begin() + animal_index);
	}
}

vector<Plant>& Aquarium::Get_Plant_list() {
	return Plant_list;
}

void Aquarium::Add_Plant(Plant plant) {
	Plant_list.push_back(plant);
}

void Aquarium::Delete_Plant(int plant_id) {
	int plant_index = Search_Plant(plant_id);
	if (plant_index != -1) {
		Plant_list.erase(Plant_list.begin() + plant_index);
	}
}

int Aquarium::Search_Animal(int animal_id) const {
	for (int i = 0; i < Animal_list.size(); i++) {
		if (Animal_list[i].Get_Contact_Info().Get_ID() == animal_id)
			return i;
	}
	return -1;
}

int Aquarium::Search_Plant(int plant_id) const {
	for (int i = 0; i < Plant_list.size(); i++) {
		if (Plant_list[i].Get_Contact_Info().Get_ID() == plant_id)
			return i;
	}
	return -1;
}