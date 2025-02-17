#pragma once
#include "Ticket.h"
#include "Food.h"
#include "Medicine.h"
#include <vector>

class Storage {
public:
	Storage(Ticket storage_ticket, int ticket_number, vector<Food> food_list, vector<Medicine> medicine_list) : Ticket_list(storage_ticket), Ticket_Number(ticket_number), Food_list(food_list), Medicine_list(medicine_list) {}

	Ticket Get_Ticket_list() const;

	int Get_Ticket_Number() const;

	void Add_Ticket();

	void Delete_Ticket();

	vector<Food> Get_Food_list() const;

	void Add_Food(Food food);

	void Delete_Food(int food_id);

	vector<Medicine> Get_Medicine_list() const;

	void Add_Medicine(Medicine medicine);

	void Delete_Medicine(int medicine_id);

private:
	Ticket Ticket_list;
	int Ticket_Number = 0;
	vector<Food> Food_list;
	vector<Medicine> Medicine_list;

	int Search_Food(int food_id) const;

	int Search_Medicine(int medicine_id) const;

};