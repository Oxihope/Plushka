#pragma once
#include <iostream>

using namespace std;

class Sound_Effect {
public:
	Sound_Effect(int sound_effect_number, string sound);

	string Get_Sound();

	int Get_Sound_Effect_Number();

private:
	string Sound;
	int Sound_Effect_Number;
};
