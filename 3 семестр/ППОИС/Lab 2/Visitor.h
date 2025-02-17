#pragma once
#include "Contact_Info.h"
#include "Ticket.h"
#include "Okeanarium.h"

class Visitor {
public:
	Visitor(Contact_Info contact_info_visitor) : Info(contact_info_visitor) {}

	Contact_Info Get_Contact_Info() const;

	vector<Ticket> Get_Visitor_Ticket_list() const;

	void Add_Ticket(Ticket ticket);

	void Delete_Ticket(string ticket_name);

	vector<Aquarium> Visit_Okeanarium(Okeanarium& okeanarium, Ticket ticket);

private:
	Contact_Info Info;
	vector<Ticket> Visitor_Ticket_list;

	int Search_Ticket(string ticket_name) const;
};
