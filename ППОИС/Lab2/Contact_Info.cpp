#include "Contact_Info.h"

string Contact_Info::Get_Name() const {
	return Name;
}

int Contact_Info::Get_ID() const {
	return ID;
}
int Contact_Info::Generate_ID() {
	static int currentId = 0;
	return ++currentId;
}