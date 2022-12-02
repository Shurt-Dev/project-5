#include <string>
#pragma once

using namespace std;

class Combat2 {
	public:
		int Poke1_level;
		int Poke2_level;
		int Poke1_atk;
		int Poke2_atk;
		int Poke1_def;
		int Poke2_def;
		int Poke1_speatk;
		int Poke2_speatk;
		int Poke1_spedef;
		int Poke2_spedef;
		int Poke1_speed;
		int Poke2_speed;
		string Poke1_name;
		string Poke2_name;
		string Attacking_poke;
		int Poke1_hp;
		int Poke2_hp;
		Combat2();
		~Combat2();
};
