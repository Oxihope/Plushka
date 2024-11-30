#include "Storage.h"

Ticket Storage::Get_Ticket_list() const {
	return 	Ticket_list;
	;
}

int Storage::Get_Ticket_Number() const {
	return Ticket_Number;
}

void Storage::Add_Ticket() {
	Ticket_Number++;
}

void Storage::Delete_Ticket() {
	Ticket_Number--;
}

vector<Food> Storage::Get_Food_list() const {
	return Food_list;
}

void Storage::Add_Food(Food food) {
	Food_list.push_back(food);
}

void Storage::Delete_Food(int food_id) {
	int food_index = Search_Food(food_id);
	if (food_index != -1) {
		Food_list.erase(Food_list.begin() + food_index);
	}
}
	

vector<Medicine> Storage::Get_Medicine_list() const {
	return Medicine_list;
}

void Storage::Add_Medicine(Medicine medicine) {
	Medicine_list.push_back(medicine);
}

void Storage::Delete_Medicine(int medicine_id) {
	int medicine_index = Search_Medicine(medicine_id);
	if (medicine_index != -1) {
		Medicine_list.erase(Medicine_list.begin() + medicine_index);
	}
}

int Storage::Search_Food(int food_id) const {
	for (int i = 0; i < Food_list.size(); i++) {
		if (Food_list[i].Get_Contact_Info().Get_ID() == food_id)
			return i;
	}
	return -1;
}

int Storage::Search_Medicine(int medicine_id) const {
	for (int i = 0; i < Medicine_list.size(); i++) {
		if (Medicine_list[i].Get_Contact_Info().Get_ID() == medicine_id)
			return i;
	}
	return -1;
}