#include "Level.h"

Level::Level(int level_number) {
	if (level_number < 0) {
		throw invalid_argument("Level can't have nagative number");
	}
	Level_Number = level_number;
}

int Level::Get_Level_Number() {
	return Level_Number;
}

string Level::Get_Level_Difficulty() {
	return Level_Difficulty;
}
void Level::Set_Level_Difficulty(string level_difficulty) {
	Level_Difficulty = level_difficulty;
}