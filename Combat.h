#pragma once
#include "headers/Pokemon.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Combat.h"

class Combat
{
	sf::Font font;
	sf::Texture backgroundTexture;
	sf::Sprite background;
	Pokemon poke1;
	Pokemon poke2;

	std::string Attacking_poke;

	sf::Text text;
	bool spaceIsPressed;
	capacity ChosenCapacityPoke1;
	capacity ChosenCapacityPoke2;
public:
	Combat(Pokemon &poke1, Pokemon &poke2);
	void Turn();
	void Texte(float, float);
	void Texte(std::string, float, float);
	void ChoseCapacity(Pokemon& poke);
	void RandomCapacity(Pokemon& poke);
	float CalculProductCoeffPoke1();
	float CalculProductCoeffPoke2();
	sf::Sprite getBackground();
	sf::Text getText();
	sf::Sprite getPokeSprite(int pokeSelect);
};

const float typeTable[9][9] = 
{	{1,1,1,1,1,1,1,1,1},
	{1,0.5,0.5,2,1,1,1,1,1},
	{1,2,0.5,0.5,1,2,1,1,1},
	{1,0.5,2,0.5,1,1,1,1,1},
	{1,0.5,1,2,0.5,1,1,1,1},
	{1,2,0.5,0.5,1,0.5,1,1,1},
	{1,1,1,1,1,1,0.5,0,1},
	{1,1,1,1,1,1,2,0.5},
	{1,0.5,1,1,1,1,1,2,1}
};

