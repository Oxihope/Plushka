#include "Game_Development.h"

vector<Game> Game_Development::Get_Game_list() {
	return Game_list;
}

void Game_Development::Add_Game(Game game) {
	Game_list.push_back(game);
}

void Game_Development::Delete_Game(string game_name) {
	int game_index = Game_Search(game_name);
	if (game_index == -1) {
		throw invalid_argument("No game found");
	}
	else
		Game_list.erase(Game_list.begin() + game_index);
}

void Game_Development::Set_Budget(int budget) {
	Budget = budget;
}

int Game_Development::Get_Budget() {
	return Budget;
}

void Game_Development::Pay_Worker(Worker& worker) {
	int worker_salary = worker.Get_Worker_Salary();
	if (Budget < worker_salary) {
		throw invalid_argument("There is not enough budget to pay");
	}
	Budget = Budget - worker_salary;
	worker.Take_Salary(worker_salary);
}

void Game_Development::Release_Game(string game_name) {
	Delete_Game(game_name);
	cout << game_name << " is releasing";
}

void Game_Development::Take_Sponce(int money_amount) {
	if (money_amount <= 0) {
		throw invalid_argument("Amount of money must be positive");
	}
	Budget = Budget + money_amount;
}

int Game_Development::Game_Search(string game_name) {
	for (int i = 0; i < Game_list.size(); i++) {
		if (Game_list[i].Get_Game_Name() == game_name) {
			return i;
		}
	}
	return -1;
}