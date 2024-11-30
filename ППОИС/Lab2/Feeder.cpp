#include "Feeder.h"

void Feeder::Feed_Animal(Animal& animal, Food food, Storage& storage) {
	animal.Eat_Food(food);
	storage.Delete_Food(food.Get_Contact_Info().Get_ID());
}