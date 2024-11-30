#include "Food.h"

Contact_Info Food::Get_Contact_Info() const {
	return Info;
}

double Food::Get_Satiety_Improvement() const {
	return Satiety_Improvement;
}

double Food::Get_Health_Decline() const {
	return Health_Decline;
}