#pragma once 
#include "Storage.h"
#include "Aquarium.h"
#include "Worker.h"

class Okeanarium {
public:
	Okeanarium(Contact_Info contact_info_okeanarium, Storage okeanarium_storage) : Info(contact_info_okeanarium), Okeanarium_Storage(okeanarium_storage) {}

	Contact_Info Get_Contact_Info() const;

	vector<Aquarium>& Get_Aquarium_list();

	void Add_Aquarium(Aquarium aquarium);

	void Delete_Aquarium(int aquarium_id);

	vector<Worker>& Get_Worker_list();

	void Add_Worker(Worker worker);

	void Delete_Worker(int worker_id);

	Storage& Get_Okeanarium_Storage();

private:
	Contact_Info Info;
	vector<Aquarium> Aquarium_list;
	vector<Worker> Worker_list;
	Storage Okeanarium_Storage;

	int Search_Aquarium(int aquarium_id) const;

	int Search_Worker(int worker_id) const;
};