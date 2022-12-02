#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Capacities.h"

struct stats
{
	std::string name;
	int health;
	int level;
	int exp;
	int def;
	int atk;
	int speDef;
	int speAtk;
	int speed;
	int precision;
	int tempDefBoost = 0;
	int tempAtkBoost = 0;
	int tempSpeDefBoost = 0;
	int tempSpeAtkBoost = 0;
	int tempSpeedBoost = 0;
	int tempPrecisionBoost = 0;
	int type1;
	int type2 = TYPE_NONE;
	std::string status;
	capacity chosenCapacity;
};

struct capacities
{
	struct capacity lutte;
	struct capacity capacity1;
	struct capacity capacity2;
	struct capacity capacity3;
	struct capacity capacity4;
};

class Pokemon
{
	struct capacities capacity;
	struct stats stat;
public:
	sf::Sprite sprite;
	Pokemon();
	Pokemon(std::string name, int health, int level, int exp, int def, int atk, int speDef, int speAtk, int speed, int precision , struct capacity capacity1, struct capacity capacity2, struct capacity capacity3, struct capacity capacity4, int type1, int type2, std::string status);
	Pokemon(Pokemon& copy);
	capacities &getCapacities();
	stats &getStats();
	sf::Sprite getSprite();
};

