#include "Plant.h"

Contact_Info Plant::Get_Contact_Info() const {
	return Info;
}

double Plant::Get_Size() const {
	return Size;
}

void Plant::Set_Size(double size) {
	Size = size;
}

double Plant::Get_Growth_Degree() const {
	return Growth_Degree;
}

void Plant::Set_Growth_Degree(double growth_degree) {
	Growth_Degree = growth_degree;
}

string Plant::Get_Color() const {
	return Color;
}

void Plant::Set_Color(string plant_color) {
	Color = plant_color;
}

string Plant::Get_Plant_Type() const {
	return Plant_Type;
}

void Plant::Set_Plant_Type(string plant_type) {
	Plant_Type = plant_type;
}

void Plant::Growth() {
	Size = Size * (1 + Growth_Degree / 100);
}

void Plant::Size_Decline(double size_decline) {
	Size = Size * (1 - size_decline / 100);
}