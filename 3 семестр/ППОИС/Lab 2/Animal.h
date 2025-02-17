#pragma once
#include "Contact_Info.h"
#include "Food.h"
#include "Medicine.h"

class Animal {
public:
	Animal(Contact_Info contact_info_animal) : Info(contact_info_animal) {}

	virtual ~Animal() {}

	Contact_Info Get_Contact_Info() const;

	double Get_Health() const;

	void Set_Health(double health);

	double Get_Satiety() const;

	void Set_Satiety(double satiety);

	string Get_Animal_Type() const;

	void Set_Animal_Type(string animal_type);
	
	void Eat_Food(Food food);

	void Take_Medicine(Medicine medicine);

	virtual string Speak();

private:
	Contact_Info Info;
	double Health = 100;
	double Satiety = 70;
	string Animal_Type = "";

	void Health_Improvement(double health_improvement);

	void Health_Decline(double health_decline);

	void Satiety_Improvement(double satiety_improvement);

	void Satiety_Decline(double satiety_decline);
};