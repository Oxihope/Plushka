#pragma once
#include "Contact_Info.h"

class Medicine {
public:
	Medicine(Contact_Info contact_info_medicine, double health_improvement, double satiety_decline) : Info(contact_info_medicine), Health_Improvement(health_improvement), Satiety_Decline(satiety_decline) {}

	Contact_Info Get_Contact_Info() const;

	double Get_Health_Improvement() const;

	double Get_Satiety_Decline() const;

private:
	Contact_Info Info;
	double Health_Improvement;
	double Satiety_Decline;
};