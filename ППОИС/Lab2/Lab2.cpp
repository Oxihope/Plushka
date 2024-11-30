#include <iostream>
#include <iomanip>
#include "Administrator.h"
#include "Dolphin.h"
#include "Fish.h"
#include "Shark.h"
#include "Coral.h"
#include "Seagrass.h"
#include "Seaweed.h"

int main() {
	setlocale(LC_ALL, "ru_RU.UTF-8");
	Ticket ticket_1("Лужа");
	int tickets_number = 10;
	Contact_Info Info_1("Корм");
	Contact_Info Info_2("Хлеб");
	Contact_Info Info_3("Насекомое");
	Food food_1_1(Info_1, 5, 90);
	Food food_1_2(Info_2, 50, 50);
	Food food_1_3(Info_3, 10, 30);
	vector<Food> Food_list_1;
	Food_list_1.push_back(food_1_1);
	Food_list_1.push_back(food_1_2);
	Food_list_1.push_back(food_1_3);
	Contact_Info Info_4("Витамин А");
	Contact_Info Info_5("Витамин B");
	Contact_Info Info_6("Витамин C");
	Medicine medicine_1_1(Info_4, 80, 20);
	Medicine medicine_1_2(Info_5, 70, 15);
	Medicine medicine_1_3(Info_6, 90, 15);
	vector<Medicine> Medicine_list_1;
	Medicine_list_1.push_back(medicine_1_1);
	Medicine_list_1.push_back(medicine_1_2);
	Medicine_list_1.push_back(medicine_1_3);
	Storage storage_1(ticket_1, tickets_number, Food_list_1, Medicine_list_1);
	Contact_Info Info_7("Дима");
	Contact_Info Info_8("Вова");
	Visitor visitor_1_1(Info_7);
	Visitor visitor_1_2(Info_8);
	Contact_Info Info_9("Максим");
	Contact_Info Info_10("Артём");
	Contact_Info Info_11("Глеб");
	Contact_Info Info_12("Влад");
	Plant plant_1_1_1(Info_9);
	plant_1_1_1.Set_Size(50);
	plant_1_1_1.Set_Color("Blue");
	plant_1_1_1.Set_Growth_Degree(20);
	plant_1_1_1.Set_Plant_Type("Special_Seaweed");
	Seaweed seaweed_1_1_1(Info_10);
	Seagrass seagrass_1_1_1(Info_11);
	Coral coral_1_1_1(Info_12);
	Contact_Info Info_13("Илья");
	Contact_Info Info_14("Кирилл");
	Contact_Info Info_15("Слава");
	Contact_Info Info_16("Рома");
	Animal animal_1_1_1(Info_13);
	Fish fish_1_1_1(Info_14);
	Dolphin dolphin_1_1_1(Info_15);
	Shark shark_1_1_1(Info_16);
	Contact_Info Info_17("Мир морской");
	Aquarium aquarium_1_1(Info_17);
	aquarium_1_1.Add_Plant(plant_1_1_1);
	aquarium_1_1.Add_Plant(seaweed_1_1_1);
	aquarium_1_1.Add_Plant(seagrass_1_1_1);
	aquarium_1_1.Add_Plant(coral_1_1_1);
	aquarium_1_1.Add_Animal(animal_1_1_1);
	aquarium_1_1.Add_Animal(fish_1_1_1);
	aquarium_1_1.Add_Animal(dolphin_1_1_1);
	aquarium_1_1.Add_Animal(shark_1_1_1);
	Contact_Info Info_18("Максим");
	Contact_Info Info_19("Артём");
	Contact_Info Info_20("Глеб");
	Contact_Info Info_21("Влад");
	Plant plant_1_2_1(Info_18);
	plant_1_2_1.Set_Size(40);
	plant_1_2_1.Set_Color("Purple");
	plant_1_2_1.Set_Growth_Degree(25);
	plant_1_2_1.Set_Plant_Type("Special_Coral");
	Seaweed seaweed_1_2_1(Info_19);
	Seagrass seagrass_1_2_1(Info_20);
	Coral coral_1_2_1(Info_21);
	Contact_Info Info_22("Илья");
	Contact_Info Info_23("Кирилл");
	Contact_Info Info_24("Слава");
	Contact_Info Info_25("Рома");
	Animal animal_1_2_1(Info_22);
	Fish fish_1_2_1(Info_23);
	Dolphin dolphin_1_2_1(Info_24);
	Shark shark_1_2_1(Info_25);
	Contact_Info Info_26("Подводный мир");
	Aquarium aquarium_1_2(Info_26);
	aquarium_1_2.Add_Plant(plant_1_2_1);
	aquarium_1_2.Add_Plant(seaweed_1_2_1);
	aquarium_1_2.Add_Plant(seagrass_1_2_1);
	aquarium_1_2.Add_Plant(coral_1_2_1);
	aquarium_1_2.Add_Animal(animal_1_2_1);
	aquarium_1_2.Add_Animal(fish_1_2_1);
	aquarium_1_2.Add_Animal(dolphin_1_2_1);
	aquarium_1_2.Add_Animal(shark_1_2_1);
	Contact_Info Info_27("Руслан");
	Contact_Info Info_28("Артур");
	Contact_Info Info_29("Яна");
	Contact_Info Info_30("Вика");
	Contact_Info Info_31("Даша");
	Worker worker_1_1(Info_27);
	Feeder feeder_1_1(Info_28);
	Veterinarian veterinarian_1_1(Info_29);
	Cashier cashier_1_1(Info_30);
	Administrator administrator(Info_31);
	Contact_Info Info_32("Лужа");
	Okeanarium okeanarium_1(Info_32, storage_1);
	okeanarium_1.Add_Worker(worker_1_1);
	okeanarium_1.Add_Worker(feeder_1_1);
	okeanarium_1.Add_Worker(veterinarian_1_1);
	okeanarium_1.Add_Worker(cashier_1_1);
	okeanarium_1.Add_Worker(administrator);
	okeanarium_1.Add_Aquarium(aquarium_1_1);
	okeanarium_1.Add_Aquarium(aquarium_1_2);
	cashier_1_1.Sell_Ticket(visitor_1_1, ticket_1, storage_1);
	cashier_1_1.Sell_Ticket(visitor_1_2, ticket_1, storage_1);
	vector<Aquarium> visitor_aquarium = visitor_1_1.Visit_Okeanarium(okeanarium_1, ticket_1);
	for (int i = 0; i < visitor_aquarium.size(); i++)
	{
		cout << "Название аквариума: " << setw(10) << visitor_aquarium[i].Get_Contact_Info().Get_Name() << " ID: " << visitor_aquarium[i].Get_Contact_Info().Get_ID() << endl;
		cout << "Животные аквариума: " << endl;
		vector<Animal> aquarium_animal = visitor_aquarium[i].Get_Animal_list();
		for (int j = 0; j < aquarium_animal.size(); j++)
		{
			cout << "Имя животного: " << setw(10) << aquarium_animal[j].Get_Contact_Info().Get_Name() << " ID: " << aquarium_animal[j].Get_Contact_Info().Get_ID() << " Здоровье: " << setw(4) << aquarium_animal[j].Get_Health() << " Сытость: " << setw(4) << aquarium_animal[j].Get_Satiety() << endl;
		}
		cout << endl;
		cout << "Растения аквариума: " << endl;
		vector<Plant> aquarium_plant = visitor_aquarium[i].Get_Plant_list();
		for (int j = 0; j < aquarium_plant.size(); j++)
		{
			cout << "Имя животного: " << setw(10) << aquarium_plant[j].Get_Contact_Info().Get_Name() << " ID: " << aquarium_plant[j].Get_Contact_Info().Get_ID() << " Размер: " << setw(4) << aquarium_plant[j].Get_Size() << " Степень роста: " << setw(4) << aquarium_plant[j].Get_Growth_Degree() << " Цвет: " << setw(15) << aquarium_plant[j].Get_Color() << " Тип растения: " << setw(10) << aquarium_plant[j].Get_Plant_Type() << endl;
		}
		cout << "__________________________________________________________________________________________________________________________________" << endl;
	}
	return 0;
}
