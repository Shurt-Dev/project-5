#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "../headers/Combat2.h"

using namespace std;

Combat2::Combat2(){
	Poke1_name = "Bidoof";
	Poke1_level = 100;
	Poke1_hp = 322;
	Poke1_atk = 207;
	Poke1_def = 196;
	Poke1_speatk = 185;
	Poke1_spedef = 196;
	Poke1_speed = 177;
	Poke2_name = "Arceus";
	Poke2_level = 100;
	Poke2_hp = 444;
	Poke2_atk = 372;
	Poke2_def = 372;
	Poke2_speatk = 372;
	Poke2_spedef = 372;
	Poke2_speed = 372;
	Attacking_poke = "";
}

Combat2::~Combat2(){

}
