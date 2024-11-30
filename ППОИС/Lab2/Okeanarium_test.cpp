#include <iostream>
#include <sstream>
#include "Administrator.h"
#include "Dolphin.h"
#include "Fish.h"
#include "Shark.h"
#include "Coral.h"
#include "Seagrass.h"
#include "Seaweed.h"
#include <gtest/gtest.h>


TEST(OkeanariumTest, Get_Contact_Info_TEST) {
	Ticket ticket("Luzha");
	int ticket_number = 5;
	vector<Food> storage_food;
	vector<Medicine> storage_medicine;;
	Storage storage(ticket, ticket_number, storage_food, storage_medicine);
	Contact_Info okeanarium_info("Luzha");
	Okeanarium okeanarium(okeanarium_info, storage);
	EXPECT_EQ(okeanarium.Get_Contact_Info().Get_Name(), okeanarium_info.Get_Name());
	EXPECT_EQ(okeanarium.Get_Contact_Info().Get_ID(), okeanarium_info.Get_ID());
}
TEST(OkeanariumTest, Get_Aquarium_list_TEST) {
	Ticket ticket("Luzha");
	int ticket_number = 5;
	vector<Food> storage_food;
	vector<Medicine> storage_medicine;
	Storage storage(ticket, ticket_number, storage_food, storage_medicine);
	Contact_Info okeanarium_info("Luzha");
	Okeanarium okeanarium(okeanarium_info, storage);
	Contact_Info aquarium_info1("Water_World");
	Aquarium aquarium1(aquarium_info1);
	Contact_Info aquarium_info2("World_for_swim");
	Aquarium aquarium2(aquarium_info2);
	EXPECT_EQ(okeanarium.Get_Aquarium_list().size(), 0);
	okeanarium.Add_Aquarium(aquarium1);
	okeanarium.Add_Aquarium(aquarium2);
	EXPECT_EQ(okeanarium.Get_Aquarium_list().size(), 2);
	EXPECT_EQ(okeanarium.Get_Aquarium_list()[0].Get_Contact_Info().Get_ID(), aquarium1.Get_Contact_Info().Get_ID());
	EXPECT_EQ(okeanarium.Get_Aquarium_list()[1].Get_Contact_Info().Get_ID(), aquarium2.Get_Contact_Info().Get_ID());
	okeanarium.Delete_Aquarium(aquarium1.Get_Contact_Info().Get_ID());
	okeanarium.Delete_Aquarium(-1);
	EXPECT_EQ(okeanarium.Get_Aquarium_list().size(),1);
	EXPECT_EQ(okeanarium.Get_Aquarium_list()[0].Get_Contact_Info().Get_ID(), aquarium2.Get_Contact_Info().Get_ID());
}
TEST(OkeanariumTest, Get_Worker_list_TEST) {
	Ticket ticket("Luzha");
	int ticket_number = 5;
	vector<Food> storage_food;
	vector<Medicine> storage_medicine;
	Storage storage(ticket, ticket_number, storage_food, storage_medicine);
	Contact_Info okeanarium_info("Luzha");
	Okeanarium okeanarium(okeanarium_info, storage);
	EXPECT_EQ(okeanarium.Get_Worker_list().size(), 0);
	Contact_Info worker_info1("Anton");
	Worker worker1(worker_info1);
	Contact_Info worker_info2("Mary");
	Worker worker2(worker_info2);
	okeanarium.Add_Worker(worker1);
	okeanarium.Add_Worker(worker2);
	EXPECT_EQ(okeanarium.Get_Worker_list()[0].Get_Contact_Info().Get_ID(), worker1.Get_Contact_Info().Get_ID());
	EXPECT_EQ(okeanarium.Get_Worker_list()[1].Get_Contact_Info().Get_ID(), worker2.Get_Contact_Info().Get_ID());
	okeanarium.Delete_Worker(worker1.Get_Contact_Info().Get_ID());
	okeanarium.Delete_Worker(-1);
	EXPECT_EQ(okeanarium.Get_Worker_list().size(), 1);
	EXPECT_EQ(okeanarium.Get_Worker_list()[0].Get_Contact_Info().Get_ID(), worker2.Get_Contact_Info().Get_ID());
}
TEST(OkeanariumTest, Get_Storage_TEST) {
	Ticket ticket("Luzha");
	int ticket_number = 5;
	Contact_Info food_info1("Bread");
	Food food1(food_info1, 50, 50);
	Contact_Info food_info2("Feed");
	Food food2(food_info2, 5, 90);
	vector<Food> storage_food;
	storage_food.push_back(food1);
	storage_food.push_back(food2);
	Contact_Info medicine_info1("Vitamin A");
	Medicine medicine1(medicine_info1, 90, 20);
	Contact_Info medicine_info2("Vitamin C");
	Medicine medicine2(medicine_info2, 80, 15);
	vector<Medicine> storage_medicine;
	storage_medicine.push_back(medicine1);
	storage_medicine.push_back(medicine2);
	Storage storage(ticket, ticket_number, storage_food, storage_medicine);
	Contact_Info okeanarium_info("Luzha");
	Okeanarium okeanarium(okeanarium_info, storage);
	EXPECT_EQ(okeanarium.Get_Okeanarium_Storage().Get_Ticket_list().Get_Ticket_Name(), storage.Get_Ticket_list().Get_Ticket_Name());
	EXPECT_EQ(okeanarium.Get_Okeanarium_Storage().Get_Ticket_Number(), storage.Get_Ticket_Number());
	int food_list_size = okeanarium.Get_Okeanarium_Storage().Get_Food_list().size();
	for (int i = 0; i < food_list_size; i++) {
		EXPECT_EQ(okeanarium.Get_Okeanarium_Storage().Get_Food_list()[i].Get_Contact_Info().Get_ID(), storage.Get_Food_list()[i].Get_Contact_Info().Get_ID());
	}
	int medicine_list_size = okeanarium.Get_Okeanarium_Storage().Get_Medicine_list().size();
	for (int i = 0; i < medicine_list_size; i++) {
		EXPECT_EQ(okeanarium.Get_Okeanarium_Storage().Get_Medicine_list()[i].Get_Contact_Info().Get_ID(), storage.Get_Medicine_list()[i].Get_Contact_Info().Get_ID());
	}
}

TEST(AnimalTest, Get_Contact_Info_TEST) {
	Contact_Info animal_info("Doggy");
	Animal animal(animal_info);
	EXPECT_EQ(animal.Get_Contact_Info().Get_Name(), animal_info.Get_Name());
	EXPECT_EQ(animal.Get_Contact_Info().Get_ID(), animal_info.Get_ID());
}
TEST(AnimalTest, Get_Health_TEST) {
	Contact_Info animal_info("Doggy");
	Animal animal(animal_info);
	EXPECT_EQ(animal.Get_Health(), 100);
	animal.Set_Health(50);
	EXPECT_EQ(animal.Get_Health(), 50);
}
TEST(AnimalTest, Get_Satiety_TEST) {
	Contact_Info animal_info("Doggy");
	Animal animal(animal_info);
	EXPECT_EQ(animal.Get_Satiety(), 70);
	animal.Set_Satiety(100);
	EXPECT_EQ(animal.Get_Health(), 100);
}
TEST(AnimalTest, Get_Animal_Type_TEST) {
	Contact_Info animal_info("Doggy");
	Animal animal(animal_info);
	animal.Set_Animal_Type("Dog");
	EXPECT_EQ(animal.Get_Animal_Type(), "Dog");
}
TEST(AnimalTest, Speak_TEST) {
	Contact_Info animal_info("Doggy");
	Animal animal(animal_info);
	EXPECT_EQ(animal.Speak(), "Sound");
}
TEST(AnimalTest, Eat_Food_TEST) {
	Contact_Info animal_info("Doggy");
	Animal animal(animal_info);
	Contact_Info food_info("Feed");
	Food food(food_info, 5, 90);
	animal.Eat_Food(food);
	EXPECT_EQ(animal.Get_Health(), 95);
	EXPECT_EQ(animal.Get_Satiety(), 133);
}
TEST(AnimalTest, Take_Medicine_TEST) {
	Contact_Info animal_info("Doggy");
	Animal animal(animal_info);
	animal.Set_Health(50);
	Contact_Info medicine_info("Vitamin D");
	Medicine medicine(medicine_info, 80, 10);
	animal.Take_Medicine(medicine);
	EXPECT_EQ(animal.Get_Health(), 90);
	EXPECT_EQ(animal.Get_Satiety(), 63);
}

TEST(WorkerTest, Get_Post) {
	Contact_Info worker_info("Sasha");
	Worker worker(worker_info);
	EXPECT_EQ(worker.Get_Post(),"");
	worker.Set_Post("Worker");
	EXPECT_EQ(worker.Get_Post(), "Worker");
}

TEST(StorageTest, Ticket_TEST) {
	Ticket ticket("Luzha");
	int ticket_number = 5;
	Contact_Info food_info1("Feed");
	Contact_Info food_info2("Bread");
	Food food1(food_info1, 5, 90);
	Food food2(food_info2, 50, 50);
	vector<Food> food_list;
	food_list.push_back(food1);
	food_list.push_back(food2);
	Contact_Info medicine_info1("Vitamine D");
	Contact_Info medicine_info2("Vitamine C");
	Medicine medicine1(medicine_info1, 70, 10);
	Medicine medicine2(medicine_info2, 80, 15);
	vector<Medicine> medicine_list;
	medicine_list.push_back(medicine1);
	medicine_list.push_back(medicine2);
	Storage storage(ticket, ticket_number, food_list, medicine_list);
	storage.Add_Ticket();
	storage.Add_Ticket();
	storage.Add_Ticket();
	EXPECT_EQ(storage.Get_Ticket_Number(),8);
	storage.Delete_Ticket();
	storage.Delete_Ticket();
	EXPECT_EQ(storage.Get_Ticket_Number(), 6);
}
TEST(StorageTest, Food_TEST) {
	Ticket ticket("Luzha");
	int ticket_number = 5;
	Contact_Info food_info1("Feed");
	Contact_Info food_info2("Bread");
	Food food1(food_info1, 5, 90);
	Food food2(food_info2, 50, 50);
	vector<Food> food_list;
	food_list.push_back(food1);
	food_list.push_back(food2);
	Contact_Info medicine_info1("Vitamine D");
	Contact_Info medicine_info2("Vitamine C");
	Medicine medicine1(medicine_info1, 70, 10);
	Medicine medicine2(medicine_info2, 80, 15);
	vector<Medicine> medicine_list;
	medicine_list.push_back(medicine1);
	medicine_list.push_back(medicine2);
	Storage storage(ticket, ticket_number, food_list, medicine_list);
	Contact_Info food_info3("Plankton");
	Food food3(food_info3, 10, 30);
	storage.Add_Food(food3);
	EXPECT_EQ(storage.Get_Food_list()[0].Get_Contact_Info().Get_ID(), food1.Get_Contact_Info().Get_ID());
	EXPECT_EQ(storage.Get_Food_list()[1].Get_Contact_Info().Get_ID(), food2.Get_Contact_Info().Get_ID());
	EXPECT_EQ(storage.Get_Food_list()[2].Get_Contact_Info().Get_ID(), food3.Get_Contact_Info().Get_ID());
	storage.Delete_Food(food1.Get_Contact_Info().Get_ID());
	storage.Delete_Food(-1);
	EXPECT_EQ(storage.Get_Food_list()[0].Get_Contact_Info().Get_ID(), food2.Get_Contact_Info().Get_ID());
	EXPECT_EQ(storage.Get_Food_list()[1].Get_Contact_Info().Get_ID(), food3.Get_Contact_Info().Get_ID());
}
TEST(StorageTest, Medicine_TEST) {
	Ticket ticket("Luzha");
	int ticket_number = 5;
	Contact_Info food_info1("Feed");
	Contact_Info food_info2("Bread");
	Food food1(food_info1, 5, 90);
	Food food2(food_info2, 50, 50);
	vector<Food> food_list;
	food_list.push_back(food1);
	food_list.push_back(food2);
	Contact_Info medicine_info1("Vitamine D");
	Contact_Info medicine_info2("Vitamine C");
	Medicine medicine1(medicine_info1, 70, 10);
	Medicine medicine2(medicine_info2, 80, 15);
	vector<Medicine> medicine_list;
	medicine_list.push_back(medicine1);
	medicine_list.push_back(medicine2);
	Storage storage(ticket, ticket_number, food_list, medicine_list);
	Contact_Info medicine_info3("Plankton");
	Medicine medicine3(medicine_info3, 10, 30);
	storage.Add_Medicine(medicine3);
	EXPECT_EQ(storage.Get_Medicine_list()[0].Get_Contact_Info().Get_ID(), medicine1.Get_Contact_Info().Get_ID());
	EXPECT_EQ(storage.Get_Medicine_list()[1].Get_Contact_Info().Get_ID(), medicine2.Get_Contact_Info().Get_ID());
	EXPECT_EQ(storage.Get_Medicine_list()[2].Get_Contact_Info().Get_ID(), medicine3.Get_Contact_Info().Get_ID());
	storage.Delete_Medicine(medicine1.Get_Contact_Info().Get_ID());
	storage.Delete_Medicine(-1);
	EXPECT_EQ(storage.Get_Medicine_list()[0].Get_Contact_Info().Get_ID(), medicine2.Get_Contact_Info().Get_ID());
	EXPECT_EQ(storage.Get_Medicine_list()[1].Get_Contact_Info().Get_ID(), medicine3.Get_Contact_Info().Get_ID());
}

TEST(AquariumTest, Get_Animal_list_TEST) {
	Contact_Info animal_info1("Nemo");
	Contact_Info animal_info2("Lucy");
	Contact_Info animal_info3("Dory");
	Animal animal1(animal_info1);
	Animal animal2(animal_info2);
	Animal animal3(animal_info3);
	Contact_Info aquarium_info("Aqua world");
	Aquarium aquarium(aquarium_info);
	aquarium.Add_Animal(animal1);
	aquarium.Add_Animal(animal2);
	aquarium.Add_Animal(animal3);
	EXPECT_EQ(aquarium.Get_Animal_list()[0].Get_Contact_Info().Get_ID(), animal1.Get_Contact_Info().Get_ID());
	EXPECT_EQ(aquarium.Get_Animal_list()[1].Get_Contact_Info().Get_ID(), animal2.Get_Contact_Info().Get_ID());
	EXPECT_EQ(aquarium.Get_Animal_list()[2].Get_Contact_Info().Get_ID(), animal3.Get_Contact_Info().Get_ID());
	aquarium.Delete_Animal(animal1.Get_Contact_Info().Get_ID());
	aquarium.Delete_Animal(-1);
	EXPECT_EQ(aquarium.Get_Animal_list()[0].Get_Contact_Info().Get_ID(), animal2.Get_Contact_Info().Get_ID());
	EXPECT_EQ(aquarium.Get_Animal_list()[1].Get_Contact_Info().Get_ID(), animal3.Get_Contact_Info().Get_ID());
}
TEST(AquariumTest, Get_Plant_list_TEST) {
	Contact_Info plant_info1("Lepestok");
	Contact_Info plant_info2("Wave");
	Contact_Info plant_info3("Sinus");
	Plant plant1(plant_info1);
	Plant plant2(plant_info2);
	Plant plant3(plant_info3);
	Contact_Info aquarium_info("Aqua world");
	Aquarium aquarium(aquarium_info);
	aquarium.Add_Plant(plant1);
	aquarium.Add_Plant(plant2);
	aquarium.Add_Plant(plant3);
	EXPECT_EQ(aquarium.Get_Plant_list()[0].Get_Contact_Info().Get_ID(), plant1.Get_Contact_Info().Get_ID());
	EXPECT_EQ(aquarium.Get_Plant_list()[1].Get_Contact_Info().Get_ID(), plant2.Get_Contact_Info().Get_ID());
	EXPECT_EQ(aquarium.Get_Plant_list()[2].Get_Contact_Info().Get_ID(), plant3.Get_Contact_Info().Get_ID());
	aquarium.Delete_Plant(plant1.Get_Contact_Info().Get_ID());
	aquarium.Delete_Plant(-1);
	EXPECT_EQ(aquarium.Get_Plant_list()[0].Get_Contact_Info().Get_ID(), plant2.Get_Contact_Info().Get_ID());
	EXPECT_EQ(aquarium.Get_Plant_list()[1].Get_Contact_Info().Get_ID(), plant3.Get_Contact_Info().Get_ID());
}

TEST(PlantTest, Get_Size_TEST) {
	Contact_Info plant_info("Lepistok");
	Plant plant(plant_info);
	EXPECT_EQ(plant.Get_Size(), 0);
	plant.Set_Size(40);
	EXPECT_EQ(plant.Get_Size(), 40);
}
TEST(PlantTest, Get_Growth_Degree_TEST) {
	Contact_Info plant_info("Lepistok");
	Plant plant(plant_info);
	EXPECT_EQ(plant.Get_Growth_Degree(), 0);
	plant.Set_Growth_Degree(40);
	EXPECT_EQ(plant.Get_Growth_Degree(), 40);
}
TEST(PlantTest, Get_Color_TEST) {
	Contact_Info plant_info("Lepistok");
	Plant plant(plant_info);
	EXPECT_EQ(plant.Get_Color(), "");
	plant.Set_Color("Rainbow");
	EXPECT_EQ(plant.Get_Color(), "Rainbow");
}
TEST(PlantTest, Get_Plant_Type_TEST) {
	Contact_Info plant_info("Lepistok");
	Plant plant(plant_info);
	EXPECT_EQ(plant.Get_Plant_Type(), "");
	plant.Set_Plant_Type("Seagrass");
	EXPECT_EQ(plant.Get_Plant_Type(), "Seagrass");
}
TEST(PlantTest, Growth_TEST) {
	Contact_Info plant_info("Lepistok");
	Plant plant(plant_info);
	EXPECT_EQ(plant.Get_Size(), 0);
	plant.Set_Size(20);
	EXPECT_EQ(plant.Get_Size(), 20);
	plant.Set_Growth_Degree(10);
	plant.Growth();
	EXPECT_EQ(plant.Get_Size(), 22);
}
TEST(PlantTest, Size_Decline_TEST) {
	Contact_Info plant_info("Lepistok");
	Plant plant(plant_info);
	EXPECT_EQ(plant.Get_Size(), 0);
	plant.Set_Size(50);
	EXPECT_EQ(plant.Get_Size(), 50);
	plant.Size_Decline(10);
	EXPECT_EQ(plant.Get_Size(), 45);
}

TEST(VeterinarianTest, Heal_Animal_TEST) {
	Contact_Info veterinarian_info("Matvey");
	Veterinarian veterinarian(veterinarian_info);
	Contact_Info animal_info("Doggy");
	Animal animal(animal_info);
	animal.Set_Health(50);

	Ticket ticket("Luzha");
	int ticket_number = 5;
	Contact_Info food_info1("Bread");
	Contact_Info food_info2("Feed");
	Food food1(food_info1, 50, 50);
	Food food2(food_info2, 5, 90);
	vector<Food> storage_food;
	storage_food.push_back(food1);
	storage_food.push_back(food2);
	Contact_Info medicine_info1("Vitamin A");
	Contact_Info medicine_info2("Vitamin C");
	Medicine medicine1(medicine_info1, 90, 10);
	Medicine medicine2(medicine_info2, 80, 15);
	vector<Medicine> storage_medicine;
	storage_medicine.push_back(medicine1);
	storage_medicine.push_back(medicine2);
	Storage storage(ticket, ticket_number, storage_food, storage_medicine);
	veterinarian.Heal_Animal(animal, storage.Get_Medicine_list()[0], storage);
	EXPECT_EQ(storage.Get_Medicine_list()[0].Get_Contact_Info().Get_ID(), medicine2.Get_Contact_Info().Get_ID());
	EXPECT_EQ(animal.Get_Health(), 95);
	EXPECT_EQ(animal.Get_Satiety(), 63);
}
TEST(VeterinarianTest, Cut_Plant_TEST) {
	//Формирование полей метода Heal_Animal
	Contact_Info veterinarian_info("Matvey");
	Veterinarian veterinarian(veterinarian_info);
	Contact_Info plant_info("Wave");
	Plant plant(plant_info);
	plant.Set_Size(60);
	veterinarian.Cut_Plant(plant, 50);
	EXPECT_EQ(plant.Get_Size(), 30);
}

TEST(FeederTest, Feed_Animal_TEST) {
	Contact_Info feeder_info("Matvey");
	Feeder feeder(feeder_info);
	Contact_Info animal_info("Doggy");
	Animal animal(animal_info);
	animal.Set_Health(50);

	Ticket ticket("Luzha");
	int ticket_number = 5;
	Contact_Info food_info1("Bread");
	Contact_Info food_info2("Feed");
	Food food1(food_info1, 50, 50);
	Food food2(food_info2, 5, 90);
	vector<Food> storage_food;
	storage_food.push_back(food1);
	storage_food.push_back(food2);
	Contact_Info medicine_info1("Vitamin A");
	Contact_Info medicine_info2("Vitamin C");
	Medicine medicine1(medicine_info1, 90, 10);
	Medicine medicine2(medicine_info2, 80, 15);
	vector<Medicine> storage_medicine;
	storage_medicine.push_back(medicine1);
	storage_medicine.push_back(medicine2);
	Storage storage(ticket, ticket_number, storage_food, storage_medicine);
	feeder.Feed_Animal(animal, storage.Get_Food_list()[0], storage);
	EXPECT_EQ(storage.Get_Food_list()[0].Get_Contact_Info().Get_ID(), food2.Get_Contact_Info().Get_ID());
	EXPECT_EQ(animal.Get_Health(), 25);
	EXPECT_EQ(animal.Get_Satiety(), 105);
}

TEST(CashierTest, Sell_Ticket_TEST) {
	Contact_Info cashier_info("Matvey");
	Cashier cashier(cashier_info);
	Contact_Info visitor_info("Doggy");
	Visitor visitor(visitor_info);

	Ticket ticket("Luzha");
	int ticket_number = 5;
	Contact_Info food_info1("Bread");
	Contact_Info food_info2("Feed");
	Food food1(food_info1, 50, 50);
	Food food2(food_info2, 5, 90);
	vector<Food> storage_food;
	storage_food.push_back(food1);
	storage_food.push_back(food2);
	Contact_Info medicine_info1("Vitamin A");
	Contact_Info medicine_info2("Vitamin C");
	Medicine medicine1(medicine_info1, 90, 10);
	Medicine medicine2(medicine_info2, 80, 15);
	vector<Medicine> storage_medicine;
	storage_medicine.push_back(medicine1);
	storage_medicine.push_back(medicine2);
	Storage storage(ticket, ticket_number, storage_food, storage_medicine);
	cashier.Sell_Ticket(visitor, storage.Get_Ticket_list(), storage);
	EXPECT_EQ(storage.Get_Ticket_Number(), 4);
	EXPECT_EQ(visitor.Get_Visitor_Ticket_list()[0].Get_Ticket_Name(), storage.Get_Ticket_list().Get_Ticket_Name());
}

TEST(AdministratorTest, Compilation_TEST) {
	Contact_Info admin_info("Pavel");
	Administrator admin(admin_info);
	EXPECT_EQ(admin.Get_Post(), "Administrator");
}

TEST(VisitorTest, Get_Contact_Info_TEST) {
	Contact_Info visitor_info("Vanya");
	Visitor visitor(visitor_info);
	EXPECT_EQ(visitor.Get_Contact_Info().Get_Name(), visitor_info.Get_Name());
	EXPECT_EQ(visitor.Get_Contact_Info().Get_ID(), visitor_info.Get_ID());
}
TEST(VisitorTest, Visit_Okeanarium_TEST) {
	Ticket ticket("Luzha");
	int ticket_number = 5;
	Contact_Info food_info1("Feed");
	Food food1(food_info1, 5, 90);
	vector<Food> food_list;
	food_list.push_back(food1);
	Contact_Info medicine_info1("Vitamine D");
	Medicine medicine1(medicine_info1, 70, 10);
	vector<Medicine> medicine_list;
	medicine_list.push_back(medicine1);
	Storage storage(ticket, ticket_number, food_list, medicine_list);
	Contact_Info okeanarium_info("Luzha");
	Okeanarium okeanarium(okeanarium_info, storage);
	Contact_Info aquarium_info1("Water World");
	Aquarium aquarium1(aquarium_info1);
	Contact_Info aquarium_info2("Deepest soup");
	Aquarium aquarium2(aquarium_info2);
	okeanarium.Add_Aquarium(aquarium1);
	okeanarium.Add_Aquarium(aquarium2);
	Contact_Info visitor_info("Victoriya");
	Visitor visitor(visitor_info);
	visitor.Add_Ticket(ticket);
	visitor.Delete_Ticket("");
	vector<Aquarium> visited_aquarium;
	visited_aquarium = visitor.Visit_Okeanarium(okeanarium, visitor.Get_Visitor_Ticket_list()[0]);
	EXPECT_EQ(visited_aquarium[0].Get_Contact_Info().Get_ID(), aquarium1.Get_Contact_Info().Get_ID());
	EXPECT_EQ(visited_aquarium[1].Get_Contact_Info().Get_ID(), aquarium2.Get_Contact_Info().Get_ID());
	EXPECT_EQ(visitor.Get_Visitor_Ticket_list().size(), 0);
}

TEST(CoralTest, Compilation_TEST) {
	Contact_Info coral_info("Coral");
	Coral coral(coral_info);
	EXPECT_EQ(coral.Get_Size(),25);
	EXPECT_EQ(coral.Get_Growth_Degree(),10);
	EXPECT_EQ(coral.Get_Color(),"Red-Orange");
	EXPECT_EQ(coral.Get_Plant_Type(),"Coral");
}

TEST(SeagrassTest, Compilation_TEST) {
	Contact_Info seagrass_info("Seagrass");
	Seagrass seagrass(seagrass_info);
	EXPECT_EQ(seagrass.Get_Size(), 15);
	EXPECT_EQ(seagrass.Get_Growth_Degree(), 15);
	EXPECT_EQ(seagrass.Get_Color(), "Bright Green");
	EXPECT_EQ(seagrass.Get_Plant_Type(), "Seagrass");
}

TEST(SeaweedTest, Compilation_TEST) {
	Contact_Info seaweed_info("Seagrass");
	Seaweed seaweed(seaweed_info);
	EXPECT_EQ(seaweed.Get_Size(), 40);
	EXPECT_EQ(seaweed.Get_Growth_Degree(), 20);
	EXPECT_EQ(seaweed.Get_Color(), "Dark Olive");
	EXPECT_EQ(seaweed.Get_Plant_Type(), "Seaweed");
}

TEST(DolphinTest, Speak_TEST) {
	Contact_Info dolphin_info("Dolphin");
	Dolphin dolphin(dolphin_info);
	EXPECT_EQ(dolphin.Get_Animal_Type(), "Dolphin");
	EXPECT_EQ(dolphin.Speak(), "Ee Ee Ee");
}

TEST(FishTest, Speak_TEST) {
	Contact_Info fish_info("Fish");
	Fish fish(fish_info);
	EXPECT_EQ(fish.Get_Animal_Type(), "Fish");
	EXPECT_EQ(fish.Speak(), "Blub Blub");
}

TEST(SharkTset, Speak_TEST) {
	Contact_Info shark_info("Shark");
	Shark shark(shark_info);
	EXPECT_EQ(shark.Get_Animal_Type(), "Shark");
	EXPECT_EQ(shark.Speak(), "Grrrrr");
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}