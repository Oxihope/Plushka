#include "Visitor.h"

Contact_Info Visitor::Get_Contact_Info() const {
	return Info;
}

void Visitor::Add_Ticket(Ticket ticket) {
	Visitor_Ticket_list.push_back(ticket);
}

void Visitor::Delete_Ticket(string ticket_name) {
	int ticket_index = Search_Ticket(ticket_name);
	if (ticket_index != -1) {
		Visitor_Ticket_list.erase(Visitor_Ticket_list.begin() + ticket_index);
	}
}

vector<Ticket> Visitor::Get_Visitor_Ticket_list() const {
	return Visitor_Ticket_list;
}

vector<Aquarium> Visitor::Visit_Okeanarium(Okeanarium& okeanarium, Ticket ticket) {
	this->Delete_Ticket(ticket.Get_Ticket_Name());
	return okeanarium.Get_Aquarium_list();
}

int Visitor::Search_Ticket(string ticket_name) const {
	for (int i = 0; i < Visitor_Ticket_list.size(); i++) {
		if (Visitor_Ticket_list[i].Get_Ticket_Name() == ticket_name) {
			return i;
		}
	}
	return -1;
}