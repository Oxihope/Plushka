#include "Sound_Effect.h"

Sound_Effect::Sound_Effect(int sound_effect_number, string sound) : Sound(sound) {
	if (sound_effect_number < 0) {
		throw invalid_argument("Sound effect can't have nagative number");
	}
	Sound_Effect_Number = sound_effect_number;
}

string Sound_Effect::Get_Sound() {
	return Sound;
}

int Sound_Effect::Get_Sound_Effect_Number() {
	return Sound_Effect_Number;
}