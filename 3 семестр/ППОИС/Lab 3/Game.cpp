#include "Game.h"

Game::Game(string name, string game_ganre) : Game_Name(name), Game_Ganre(game_ganre) {}

string Game::Get_Game_Name() {
	return Game_Name;
}

string Game::Get_Game_Ganre() {
	return Game_Ganre;
}

void Game::Add_Level(Level level) {
	Level_list.push_back(level);
}
vector<Level> Game::Get_Level_list() {
	return Level_list;
}

void Game::Add_Sound_Effect(Sound_Effect sound_effect) {
	Sound_Effect_list.push_back(sound_effect);
}
vector<Sound_Effect> Game::Get_Sound_Effect_list() {
	return Sound_Effect_list;
}

void Game::Add_Developer(Developer developer) {
	Developer_list.push_back(developer);
}

vector<Developer> Game::Get_Developer_list() {
	return Developer_list;
}

void Game::Add_Designer(Designer designer) {
	Designer_list.push_back(designer);
}
vector<Designer> Game::Get_Designer_list() {
	return Designer_list;
}

void Game::Add_Tester(Tester tester) {
	Tester_list.push_back(tester);
}
vector<Tester> Game::Get_Tester_list() {
	return Tester_list;
}