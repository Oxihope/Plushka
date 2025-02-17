#pragma once
#include "Game_Development.h"

class Sponcor {
public:
	Sponcor(int budget);

	int Get_Budget();
	void Set_Budget(int budget);

	void Sponce(Game_Development& game_development, int money_amount);

private:
	int Budget;
};