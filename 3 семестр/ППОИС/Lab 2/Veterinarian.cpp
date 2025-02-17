#include "Veterinarian.h"

void Veterinarian::Heal_Animal(Animal& animal, Medicine medicine, Storage& storage) {
	animal.Take_Medicine(medicine);
	storage.Delete_Medicine(medicine.Get_Contact_Info().Get_ID());
}

void Veterinarian::Cut_Plant(Plant& plant, double cutting_degree) {
	plant.Size_Decline(cutting_degree);
}