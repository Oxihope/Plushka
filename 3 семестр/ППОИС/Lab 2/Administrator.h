#pragma once
#include "Cashier.h"
#include "Feeder.h"
#include "Veterinarian.h"

class Administrator : public Feeder, public Veterinarian, public Cashier {
public:
	Administrator(Contact_Info contact_info_administrator) : Worker(contact_info_administrator), Feeder(contact_info_administrator), Veterinarian(contact_info_administrator), Cashier(contact_info_administrator) {
		this->Set_Post("Administrator");
	}
};