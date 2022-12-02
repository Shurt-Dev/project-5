#include "../headers/Pokemon.h"
#include "../headers/Capacities.h"


Pokemon::Pokemon(std::string name, int health, int level, int exp, int def, int atk, int speDef, int speAtk, int speed, int precision, struct capacity capacity1, struct capacity capacity2, struct capacity capacity3, struct capacity capacity4, int type1, int type2, std::string status)
{
    getStats().name = name;
    getStats().health = health;
    getStats().level = level;
    getStats().exp = exp;
    getStats().def = def;
    getStats().atk = atk;
    getStats().speDef = speDef;
    getStats().speAtk = speAtk;
    getStats().speed = speed;
    getStats().precision = precision;
    getStats().type1 = type1;
    getStats().type2 = type2;
    getStats().status = status;
    getCapacities().capacity1 = capacity1;
    getCapacities().capacity2 = capacity2;
    getCapacities().capacity3 = capacity3;
    getCapacities().capacity4 = capacity4;
}

Pokemon::Pokemon()
{};

Pokemon::Pokemon(Pokemon &copy)
{
    this->getStats().name = copy.getStats().name;
    this->getStats().health = copy.getStats().health;
    this->getStats().level = copy.getStats().level;
    this->getStats().exp = copy.getStats().exp;
    this->getStats().def = copy.getStats().def;
    this->getStats().atk = copy.getStats().atk;
    this->getStats().speDef = copy.getStats().speDef;
    this->getStats().speAtk = copy.getStats().speAtk;
    this->getStats().speed = copy.getStats().speed;
    this->getStats().precision = copy.getStats().precision;
    this->getStats().type1 = copy.getStats().type1;
    this->getStats().type2 = copy.getStats().type2;
    this->getStats().status = copy.getStats().status;
    this->getCapacities().capacity1 = copy.getCapacities().capacity1;
    this->getCapacities().capacity2 = copy.getCapacities().capacity2;
    this->getCapacities().capacity3 = copy.getCapacities().capacity3;
    this->getCapacities().capacity4 = copy.getCapacities().capacity4;
};

capacities &Pokemon::getCapacities()
{
    return this->capacity;
}

stats &Pokemon::getStats()
{
    return this->stat;
}

sf::Sprite Pokemon::getSprite()
{
    return this->sprite;
}
