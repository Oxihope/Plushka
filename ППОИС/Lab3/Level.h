#pragma once
#include <iostream>

using namespace std;

class Level {
public:
	Level(int level_number);

	int Get_Level_Number();

	string Get_Level_Difficulty();
	void Set_Level_Difficulty(string level_difficulty);

private:
	string Level_Difficulty="";
	int Level_Number;
};