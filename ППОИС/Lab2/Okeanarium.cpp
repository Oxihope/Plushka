#include "Okeanarium.h"

Contact_Info Okeanarium::Get_Contact_Info() const {
	return Info;
}

vector<Aquarium>& Okeanarium::Get_Aquarium_list() {
	return Aquarium_list;
}

void Okeanarium::Add_Aquarium(Aquarium aquarium) {
	Aquarium_list.push_back(aquarium);
}

void Okeanarium::Delete_Aquarium(int aquarium_id) {
	int aquarium_index = Search_Aquarium(aquarium_id);
	if (aquarium_index != -1) {
		Aquarium_list.erase(Aquarium_list.begin() + aquarium_index);
	}
}

vector<Worker>& Okeanarium::Get_Worker_list() {
	return Worker_list;
}

void Okeanarium::Add_Worker(Worker worker) {
	Worker_list.push_back(worker);
}

void Okeanarium::Delete_Worker(int worker_id) {
	int worker_index = Search_Worker(worker_id);
	if (worker_index != -1) {
		Worker_list.erase(Worker_list.begin() + worker_index);
	}
}

Storage& Okeanarium::Get_Okeanarium_Storage() {
	return Okeanarium_Storage;
}

int Okeanarium::Search_Aquarium(int aquarium_id) const {
	for (int i = 0; i < Aquarium_list.size(); i++) {
		if (Aquarium_list[i].Get_Contact_Info().Get_ID() == aquarium_id) {
			return i;
		}
	}
	return -1;
}

int Okeanarium::Search_Worker(int worker_id) const {
	for (int i = 0; i < Worker_list.size(); i++) {
		if (Worker_list[i].Get_Contact_Info().Get_ID() == worker_id) {
			return i;
		}
	}
	return -1;
}
