#include "Cashier.h"

void Cashier::Sell_Ticket(Visitor& visitor, Ticket ticket, Storage& storage) {
	visitor.Add_Ticket(ticket);
	storage.Delete_Ticket();
}