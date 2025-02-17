#include "Animal.h"

Contact_Info Animal::Get_Contact_Info() const {
	return Info;
}

double Animal::Get_Health() const {
	return Health;
}

void Animal::Set_Health(double health) {
	Health = health;
}

double Animal::Get_Satiety() const {
	return Satiety;
}

void Animal::Set_Satiety(double satiety) {
	Satiety = satiety;
}

string Animal::Get_Animal_Type() const {
	return Animal_Type;
}

void Animal::Set_Animal_Type(string animal_type) {
	Animal_Type = animal_type;
}

void Animal::Eat_Food(Food food) {
	Satiety_Improvement(food.Get_Satiety_Improvement());
	Health_Decline(food.Get_Health_Decline());
}

void Animal::Take_Medicine(Medicine medicine) {
	Health_Improvement(medicine.Get_Health_Improvement());
	Satiety_Decline(medicine.Get_Satiety_Decline());
}

string Animal::Speak() {
	return "Sound";
};

void Animal::Health_Improvement(double health_improvement) {
	Health = Health * (1 + health_improvement / 100);
}

void Animal::Health_Decline(double health_decline) {
	Health = Health * (1 - health_decline / 100);
}

void Animal::Satiety_Improvement(double satiety_improvement) {
	Satiety = Satiety * (1 + satiety_improvement / 100);
}

void Animal::Satiety_Decline(double satiety_decline) {
	Satiety = Satiety * (1 - satiety_decline / 100);
}