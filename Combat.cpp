#include <string>
#include "Combat.h"
#include "headers/Pokemon.h"

Combat::Combat(Pokemon& poke1, Pokemon& poke2)
{
	srand(time(nullptr));
	this->poke1 = poke1;
	this->poke2 = poke2;

	if (!this->font.loadFromFile("font/SourceSansPro-SemiBold.ttf")) {
		std::cout << "Error while loading font" << std::endl;
	}

	if (!this->backgroundTexture.loadFromFile("images/fond_combat.png")) {
		std::cout << "Error while loading image" << std::endl;
	};
	this->background;
	this->background.setTexture(this->backgroundTexture);

	sf::Text text;
	text.setFont(font);
	text.setFillColor(sf::Color(0, 0, 0));
	text.setCharacterSize(30);

	this->spaceIsPressed = 0;
};

void Combat::Turn()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		this->spaceIsPressed = 1;
	}
	if (spaceIsPressed)
	{
		if ( poke1.getStats().health > 0 && poke2.getStats().health > 0)
		{
			ChoseCapacity(this->poke1);
			float ProductCoeffPoke1 = CalculProductCoeffPoke1();
			float ProductCoeffPoke2 = CalculProductCoeffPoke2();
			if (ChosenCapacityPoke1.category == "Special")
			{
				if (poke1.getStats().speed < poke2.getStats().speed)
				{
					poke1.getStats().health = poke1.getStats().health - int((((poke2.getStats().level * 0.4 + 2) * poke2.getStats().speAtk * poke2.getStats().tempSpeAtkBoost * this->ChosenCapacityPoke1.power) / (poke1.getStats().speDef * 50 * poke1.getStats().tempSpeDefBoost) + 2)/* *CM*/);
					Attacking_poke = poke2.getStats().name + " attacks first ";
					if (poke1.getStats().health > 0)
					{
						poke2.getStats().health = poke2.getStats().health - int((((poke1.getStats().level * 0.4 + 2) * poke1.getStats().speAtk * poke1.getStats().tempSpeAtkBoost * this->ChosenCapacityPoke1.power) / (poke2.getStats().speDef * 50 * poke2.getStats().tempSpeDefBoost) + 2)/* *CM*/);
					}
				}
				else if (poke1.getStats().speed > poke2.getStats().speed)
				{
					poke2.getStats().health = poke2.getStats().health - int((((poke1.getStats().level * 0.4 + 2) * poke1.getStats().speAtk * poke2.getStats().tempSpeAtkBoost * this->ChosenCapacityPoke1.power) / (poke2.getStats().speDef * 50 * poke1.getStats().tempSpeDefBoost) + 2)/* *CM*/);
					Attacking_poke = poke1.getStats().name + " attacks first ";
					if (poke2.getStats().health > 0)
					{
						poke1.getStats().health = poke1.getStats().health - int((((poke2.getStats().level * 0.4 + 2) * poke2.getStats().speAtk	* poke1.getStats().tempSpeAtkBoost  * this->ChosenCapacityPoke1.power) / (poke1.getStats().speDef * 50 * poke2.getStats().tempSpeDefBoost) + 2)/* *CM*/);
					}
				}
				else
				{
					int poketurn = rand() % 2;
					if (poketurn == 0)
					{
						poke1.getStats().health = poke1.getStats().health - int((((poke2.getStats().level * 0.4 + 2) * poke2.getStats().speAtk	* poke2.getStats().tempSpeAtkBoost  * this->ChosenCapacityPoke1.power) / (poke1.getStats().speDef * 50 * poke1.getStats().tempSpeDefBoost) + 2)/* *CM*/);
						Attacking_poke = poke2.getStats().name + " attacks first ";
						if (poke1.getStats().health > 0)
						{
							poke2.getStats().health = poke2.getStats().health - int((((poke1.getStats().level * 0.4 + 2) * poke1.getStats().speAtk * poke1.getStats().tempSpeAtkBoost * this->ChosenCapacityPoke1.power) / (poke2.getStats().speDef * 50 * poke2.getStats().tempSpeDefBoost) + 2)/* *CM*/);
						}
					}
					else if (poketurn == 1)
					{
						poke2.getStats().health = poke2.getStats().health - int((((poke1.getStats().level * 0.4 + 2) * poke1.getStats().speAtk * poke2.getStats().tempSpeAtkBoost * this->ChosenCapacityPoke1.power) / (poke2.getStats().speDef * 50 * poke1.getStats().tempSpeDefBoost) + 2)/* *CM*/);
						Attacking_poke = poke1.getStats().name + " attacks first ";
						if (poke2.getStats().health > 0)
						{
							poke1.getStats().health = poke1.getStats().health - int((((poke2.getStats().level * 0.4 + 2) * poke2.getStats().speAtk	* poke1.getStats().tempSpeAtkBoost  * this->ChosenCapacityPoke1.power) / (poke1.getStats().speDef * 50 * poke2.getStats().tempSpeDefBoost) + 2)/* *CM*/);
						}
					}
				}

			}
			else if (ChosenCapacityPoke1.category == "Physique")
			{
				if (poke1.getStats().speed < poke2.getStats().speed)
				{
					poke1.getStats().health = poke1.getStats().health - int((((poke2.getStats().level * 0.4 + 2) * poke2.getStats().atk * this->ChosenCapacityPoke1.power) / (poke1.getStats().def * 50) + 2)/* *CM*/);
					Attacking_poke = poke2.getStats().name + " attacks first ";
					if (poke1.getStats().health > 0)
					{
						poke2.getStats().health = poke2.getStats().health - int((((poke1.getStats().level * 0.4 + 2) * poke1.getStats().atk * this->ChosenCapacityPoke1.power) / (poke2.getStats().def * 50) + 2)/* *CM*/);
					}
				}
				else if (poke1.getStats().speed > poke2.getStats().speed)
				{
					poke2.getStats().health = poke2.getStats().health - int((((poke1.getStats().level * 0.4 + 2) * poke1.getStats().atk * this->ChosenCapacityPoke1.power) / (poke2.getStats().def * 50) + 2)/* *CM*/);
					Attacking_poke = poke1.getStats().name + " attacks first ";
					if (poke2.getStats().health > 0)
					{
						poke1.getStats().health = poke1.getStats().health - int((((poke2.getStats().level * 0.4 + 2) * poke2.getStats().atk * this->ChosenCapacityPoke1.power) / (poke1.getStats().def * 50) + 2)/* *CM*/);
					}
				}
				else
				{
					int poketurn = rand() % 2;
					if (poketurn == 0)
					{
						poke1.getStats().health = poke1.getStats().health - int((((poke2.getStats().level * 0.4 + 2) * poke2.getStats().atk * this->ChosenCapacityPoke1.power) / (poke1.getStats().def * 50) + 2)/* *CM*/);
						Attacking_poke = poke2.getStats().name + " attacks first ";
						if (poke1.getStats().health > 0)
						{
							poke2.getStats().health = poke2.getStats().health - int((((poke1.getStats().level * 0.4 + 2) * poke1.getStats().atk * this->ChosenCapacityPoke1.power) / (poke2.getStats().def * 50) + 2)/* *CM*/);
						}
					}
					else if (poketurn == 1)
					{
						poke2.getStats().health = poke2.getStats().health - int((((poke1.getStats().level * 0.4 + 2) * poke1.getStats().atk * this->ChosenCapacityPoke1.power) / (poke2.getStats().def * 50) + 2)/* *CM*/);
						Attacking_poke = poke1.getStats().name + " attacks first ";
						if (poke2.getStats().health > 0)
						{
							poke1.getStats().health = poke1.getStats().health - int((((poke2.getStats().level * 0.4 + 2) * poke2.getStats().atk * this->ChosenCapacityPoke1.power) / (poke1.getStats().def * 50) + 2)/* *CM*/);
						}
					}
				}
			}
			else if(ChosenCapacityPoke1.category == "None")
			{
				if (poke1.getStats().speed < poke2.getStats().speed)
				{
					poke2.getStats().health += ChosenCapacityPoke1.healthBoost;
					poke2.getStats().tempDefBoost += ChosenCapacityPoke1.defBoost;
					poke2.getStats().tempAtkBoost += ChosenCapacityPoke1.atkBoost;
					poke2.getStats().tempSpeDefBoost += ChosenCapacityPoke1.speDefBoost;
					poke2.getStats().tempSpeAtkBoost += ChosenCapacityPoke1.speAtkBoost;
					poke2.getStats().tempSpeedBoost += ChosenCapacityPoke1.speedBoost;
					poke2.getStats().tempPrecisionBoost += ChosenCapacityPoke1.precisionBoost;

					poke1.getStats().tempDefBoost += ChosenCapacityPoke1.defDeBuff;
					poke1.getStats().tempAtkBoost += ChosenCapacityPoke1.atkDeBuff;
					poke1.getStats().tempSpeDefBoost += ChosenCapacityPoke1.speDefDeBuff;
					poke1.getStats().tempSpeAtkBoost += ChosenCapacityPoke1.speAtkDeBuff;
					poke1.getStats().tempSpeedBoost += ChosenCapacityPoke1.speedDeBuff;
					poke1.getStats().tempPrecisionBoost += ChosenCapacityPoke1.precisionDeBuff;
					if (rand() % 101 <= ChosenCapacityPoke1.appliedStatusChance)
					{
						poke1.getStats().status = ChosenCapacityPoke1.appliedStatus;
					}
				}
				else if (poke1.getStats().speed > poke2.getStats().speed)
				{
					poke2.getStats().health = poke2.getStats().health - int((((poke1.getStats().level * 0.4 + 2) * poke1.getStats().speAtk * poke1.getStats().tempSpeAtkBoost * this->ChosenCapacityPoke1.power) / (poke2.getStats().speDef * 50) + 2)/* *CM*/);
					Attacking_poke = poke1.getStats().name + " attacks first ";
					if (poke2.getStats().health > 0)
					{
						poke1.getStats().health = poke1.getStats().health - int((((poke2.getStats().level * 0.4 + 2) * poke2.getStats().speAtk * poke1.getStats().tempSpeAtkBoost * this->ChosenCapacityPoke1.power) / (poke1.getStats().speDef * 50) + 2)/* *CM*/);
					}
				}
				else
				{
					int poketurn = rand() % 2;
					if (poketurn == 0)
					{
						poke1.getStats().health = poke1.getStats().health - int((((poke2.getStats().level * 0.4 + 2) * poke2.getStats().speAtk * poke1.getStats().tempSpeAtkBoost * this->ChosenCapacityPoke1.power) / (poke1.getStats().speDef * 50) + 2)/* *CM*/);
						Attacking_poke = poke2.getStats().name + " attacks first ";
						if (poke1.getStats().health > 0)
						{
							poke2.getStats().health = poke2.getStats().health - int((((poke1.getStats().level * 0.4 + 2) * poke1.getStats().speAtk * poke1.getStats().tempSpeAtkBoost * this->ChosenCapacityPoke1.power) / (poke2.getStats().speDef * 50) + 2)/* *CM*/);
						}
					}
					else if (poketurn == 1)
					{
						poke2.getStats().health = poke2.getStats().health - int((((poke1.getStats().level * 0.4 + 2) * poke1.getStats().speAtk * poke1.getStats().tempSpeAtkBoost * this->ChosenCapacityPoke1.power) / (poke2.getStats().speDef * 50) + 2)/* *CM*/);
						Attacking_poke = poke1.getStats().name + " attacks first ";
						if (poke2.getStats().health > 0)
						{
							poke1.getStats().health = poke1.getStats().health - int((((poke2.getStats().level * 0.4 + 2) * poke2.getStats().speAtk * poke1.getStats().tempSpeAtkBoost * this->ChosenCapacityPoke1.power) / (poke1.getStats().speDef * 50) + 2)/* *CM*/);
						}
					}
				}
			}

			Texte(30, 625);
		}
	}
	if (poke1.getStats().health <= 0 && poke2.getStats().health > 0) {
		text.setString(poke1.getStats().name + " : " + std::to_string(poke1.getStats().health) + " HP\n" + poke2.getStats().name + " : " + std::to_string(poke2.getStats().health) + " HP\n" + poke2.getStats().name + " won the fight.");
	}
	else if (poke2.getStats().health <= 0 && poke1.getStats().health > 0) {
		text.setString(poke1.getStats().name + " : " + std::to_string(poke1.getStats().health) + " HP\n" + poke2.getStats().name + " : " + std::to_string(poke2.getStats().health) + " HP\n" + poke1.getStats().name + " won the fight.");
	}
}

void Combat::Texte(float x, float y)
{
	this->text.setPosition(x, y);
	this->text.setString(poke1.getStats().name + " : " + std::to_string(poke1.getStats().health) + " HP\n" + poke2.getStats().name + " : " + std::to_string(poke2.getStats().health) + " HP\n");
}

void Combat::Texte(std::string text , float x = 30, float y = 625)
{
	this->text.setPosition(x, y);
	this->text.setString(text);
}

void Combat::ChoseCapacity(Pokemon &poke)
{
	int chosenCapacity;
	this->text.setPosition(30, 625);
	this->text.setString("Choose the capacity to use:\n1." + poke.getCapacities().capacity1.capacityName + "                  " + "2." + poke.getCapacities().capacity2.capacityName + "\n" + "3." + poke.getCapacities().capacity3.capacityName + "                  " + "4." + poke.getCapacities().capacity4.capacityName);
	std::cin >> chosenCapacity;
	switch (chosenCapacity) 
	{
	case 1:
		this->ChosenCapacityPoke1 = poke.getCapacities().capacity1;
		poke.getCapacities().capacity1.useLeft -= 1;
	case 2:
		this->ChosenCapacityPoke1 = poke.getCapacities().capacity2;
		poke.getCapacities().capacity2.useLeft -= 1;
	case 3:
		this->ChosenCapacityPoke1 = poke.getCapacities().capacity3;
		poke.getCapacities().capacity3.useLeft -= 1;
	case 4:
		this->ChosenCapacityPoke1 = poke.getCapacities().capacity4;
		poke.getCapacities().capacity4.useLeft -= 1;
	default:
		std::cout << "Error capacity" << std::endl;
	}
}

void Combat::RandomCapacity(Pokemon& poke)
{
	int randomCapacity = rand() % 3;
	switch (randomCapacity)
	{
	case 1:
		this->ChosenCapacityPoke1 = poke.getCapacities().capacity1;
		poke.getCapacities().capacity1.useLeft -= 1;
	case 2:
		this->ChosenCapacityPoke1 = poke.getCapacities().capacity2;
		poke.getCapacities().capacity2.useLeft -= 1;
	case 3:
		this->ChosenCapacityPoke1 = poke.getCapacities().capacity3;
		poke.getCapacities().capacity3.useLeft -= 1;
	case 4:
		this->ChosenCapacityPoke1 = poke.getCapacities().capacity4;
		poke.getCapacities().capacity4.useLeft -= 1;
	default:
		std::cout << "Error capacity" << std::endl;
	}
}
;

float Combat::CalculProductCoeffPoke1()
{
	float tempValue = 1;
	if ((rand() % 101) <= ChosenCapacityPoke1.precision)
	{
		this->text.setString(poke1.getStats().name + " missed!\n" + this->text.getString());
		return 0;
	}
	if ((rand() % 101) <= poke1.getStats().precision * Capacities::boostAndDebuffs[poke1.getStats().tempPrecisionBoost] )
	{
		this->text.setString(poke1.getStats().name + " missed!\n" + this->text.getString());
		return 0;
	}
	tempValue *= typeTable[ChosenCapacityPoke1.categoryInt][poke2.getStats().type1];
	tempValue *= typeTable[ChosenCapacityPoke1.categoryInt][poke2.getStats().type2];
	if (ChosenCapacityPoke1.categoryInt == poke1.getStats().type1 || ChosenCapacityPoke1.categoryInt == poke1.getStats().type1)
	{
		tempValue *= 1.5;
	}
	if ((rand() % 101) / 2400 <= 1 / 24)
	{
		tempValue *= 1.5;
		this->text.setString("Coup Critique!\n" + this->text.getString());
	}
	tempValue *= ((rand() % 15 + 84) / 100);
	return tempValue;
}

float Combat::CalculProductCoeffPoke2()
{
	float tempValue = 1;
	if ((rand() % 101) <= ChosenCapacityPoke2.precision)
	{
		this->text.setString(poke2.getStats().name + " missed!\n" + this->text.getString());
		return 0;
	}
	if ((rand() % 101) <= poke2.getStats().precision * Capacities::boostAndDebuffs[poke2.getStats().tempPrecisionBoost])
	{
		this->text.setString(poke2.getStats().name + " missed!\n" + this->text.getString());
		return 0;
	}
	tempValue *= typeTable[ChosenCapacityPoke1.categoryInt][poke1.getStats().type1];
	tempValue *= typeTable[ChosenCapacityPoke1.categoryInt][poke1.getStats().type2];
	if (ChosenCapacityPoke1.categoryInt == poke2.getStats().type1 || ChosenCapacityPoke1.categoryInt == poke1.getStats().type1)
	{
		tempValue *= 1.5;
	}
	if ((rand() % 101) / 2400 <= 1 / 24)
	{
		tempValue *= 1.5;
		this->text.setString("Coup Critique!\n" + this->text.getString());
	}
	tempValue *= ((rand() % 15 + 84) / 100);
	return tempValue;
}

sf::Sprite Combat::getBackground()
{
	return this->background;
}

sf::Text Combat::getText()
{
	return this->text;
}

sf::Sprite Combat::getPokeSprite(int pokeSelect)
{
	switch (pokeSelect)
	{
	case 1:
		return this->poke1.sprite;
	case 2:
		return this->poke2.sprite;
	}
}