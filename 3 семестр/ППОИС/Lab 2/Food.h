#pragma once
#include "Contact_Info.h"

class Food {
public:
	Food(Contact_Info contact_info_food, double health_decline, double satiety_improvement) : Info(contact_info_food), Health_Decline(health_decline), Satiety_Improvement(satiety_improvement) {}

	Contact_Info Get_Contact_Info() const;

	double Get_Satiety_Improvement() const;

	double Get_Health_Decline() const;

private:
	Contact_Info Info;
	double Health_Decline;
	double Satiety_Improvement;
};