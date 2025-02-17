#pragma once
#include "Worker.h"
#include "Visitor.h"
#include "Storage.h"

class Cashier : virtual public Worker {
public:
	Cashier(Contact_Info contact_info_cashiefr) : Worker(contact_info_cashiefr) {
		this->Set_Post("Cashier");
	}

	void Sell_Ticket(Visitor& visitor, Ticket ticket, Storage& storage);
};