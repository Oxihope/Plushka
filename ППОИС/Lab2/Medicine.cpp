#include "Medicine.h"

Contact_Info Medicine::Get_Contact_Info() const {
	return Info;
}

double Medicine::Get_Health_Improvement() const {
	return Health_Improvement;
}

double Medicine::Get_Satiety_Decline() const {
	return Satiety_Decline;
}