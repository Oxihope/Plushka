#pragma once
#include <iostream>
#include <vector>
#include "Game.h"

class Game_Development {
public:
	vector<Game> Get_Game_list();
	void Add_Game(Game game);
	void Delete_Game(string game_name);

	void Set_Budget(int budget);
	int Get_Budget();

	void Pay_Worker(Worker& worker);
	void Release_Game(string game_name);
	void Take_Sponce(int money_amount);
private:
	vector<Game> Game_list;
	int Budget = 0;

	int Game_Search(string game_name);
};