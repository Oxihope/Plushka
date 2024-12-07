#include "Sponcor.h"

Sponcor::Sponcor(int budget) {
	if (budget < 0) {
		throw invalid_argument("Budget can't be negative");
	}
	Budget = budget;
}

int Sponcor::Get_Budget() {
	return Budget;
}
void Sponcor::Set_Budget(int budget) {
	Budget = budget;
}

void Sponcor::Sponce(Game_Development& game_development, int money_amount) {
	if (Budget < money_amount) {
		throw invalid_argument("There is not enough budget to sponce");
	}
	Budget = Budget - money_amount;
	game_development.Take_Sponce(money_amount);
}