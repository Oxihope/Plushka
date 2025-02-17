#pragma once
#include <iostream>

using namespace std;

class Ticket {
public:
	Ticket(string okeanarium_name) : Ticket_Name(okeanarium_name) {}

	string Get_Ticket_Name() const;
private:
	string Ticket_Name;
};