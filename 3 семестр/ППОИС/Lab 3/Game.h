#pragma once
#include <iostream>
#include <vector>
#include "Level.h"
#include "Sound_Effect.h"
#include "Developer.h"
#include "Designer.h"
#include "Tester.h"

using namespace std;

class Game {
public:
	Game(string name, string game_ganre);

	string Get_Game_Name();

	string Get_Game_Ganre();

	void Add_Level(Level level);
	vector<Level> Get_Level_list();

	void Add_Sound_Effect(Sound_Effect sound_effect);
	vector<Sound_Effect> Get_Sound_Effect_list();

	void Add_Developer(Developer developer);
	vector<Developer> Get_Developer_list();

	void Add_Designer(Designer designer);
	vector<Designer> Get_Designer_list();

	void Add_Tester(Tester tester);
	vector<Tester> Get_Tester_list();

private:
	string Game_Name;
	string Game_Ganre;
	vector<Level> Level_list;
	vector<Sound_Effect> Sound_Effect_list;
	vector<Developer> Developer_list;
	vector<Designer> Designer_list;
	vector<Tester> Tester_list;
};

