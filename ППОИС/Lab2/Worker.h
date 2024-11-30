#pragma once
#include "Contact_Info.h"

class Worker {
public:
	Worker(Contact_Info contact_info_worker) : Info(contact_info_worker) {}

	virtual ~Worker() {}

	Contact_Info Get_Contact_Info() const;

	string Get_Post() const;

	void Set_Post(string post);

private:
	Contact_Info Info;
	string Post = "";
};