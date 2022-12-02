#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <Windows.h>
#include "../headers/Combat2.h"

using namespace std;

bool spacePressed = 0;

int main2() {
	srand(time(nullptr));
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Combat test", sf::Style::Titlebar | sf::Style::Close);

	Combat2 combat;

	sf::Texture Arceus;
	if (!Arceus.loadFromFile("images/Arceus.png")) {
		cout << "Error while loading image" << endl;
	};

	sf::Texture Bidoof;
	if (!Bidoof.loadFromFile("images/Bidoof.png")) {
		cout << "Error while loading image" << endl;
	};

	sf::Font font;
	if (!font.loadFromFile("font/SourceSansPro-SemiBold.ttf")) {
		cout << "Error while loading font" << endl;
	}

	sf::Text Poke1_text;
	Poke1_text.setFont(font);
	Poke1_text.setFillColor(sf::Color(0, 0, 0));
	Poke1_text.setCharacterSize(30);
	Poke1_text.setPosition(30,625);
	Poke1_text.setString(combat.Poke1_name + " : " + to_string(combat.Poke1_hp) + " HP");
	
	sf::Text Poke2_text;
	Poke2_text.setFont(font);
	Poke2_text.setFillColor(sf::Color(0, 0, 0));
	Poke2_text.setCharacterSize(30);
	Poke2_text.setPosition(30, 665);
	Poke2_text.setString(combat.Poke2_name + " : " + to_string(combat.Poke2_hp) + " HP");

	sf::Text PokeWinner;
	PokeWinner.setFont(font);
	PokeWinner.setFillColor(sf::Color(0, 0, 0));
	PokeWinner.setCharacterSize(30);
	PokeWinner.setPosition(30, 705);

	sf::Text PokeAttack;
	PokeAttack.setFont(font);
	PokeAttack.setFillColor(sf::Color(0, 0, 0));
	PokeAttack.setCharacterSize(30);
	PokeAttack.setPosition(750, 625);

	sf::Sprite OwnPoke;
	OwnPoke.setTexture(Bidoof);
	OwnPoke.setPosition(50, 317);

	sf::Sprite FoePoke;
	FoePoke.setTexture(Arceus);
	FoePoke.setPosition(600, 100);

	while (window.isOpen()) 
	{
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed) 
			{
				window.close();
			}
			if (event.type == sf::Event::KeyPressed) 
			{
				if (event.key.code == sf::Keyboard::Space) 
				{ 
					spacePressed = 1; 
				}
				else
				{
					spacePressed = 0;
				}
			}
		}
		if (spacePressed)
		{
			if (combat.Poke1_hp > 0 && combat.Poke2_hp > 0) 
			{
				if (combat.Poke1_speed < combat.Poke2_speed) 
				{
					combat.Poke1_hp = combat.Poke1_hp - ((((combat.Poke2_level * 0.4 + 2) * combat.Poke2_atk/* *power*/) / (combat.Poke1_def * 50) + 2)/* *CM*/);
					combat.Attacking_poke = combat.Poke2_name + " attacks first ";
					if (combat.Poke1_hp > 0) 
					{
						combat.Poke2_hp = combat.Poke2_hp - ((((combat.Poke1_level * 0.4 + 2) * combat.Poke1_atk/* *power*/) / (combat.Poke2_def * 50) + 2)/* *CM*/);
					}
				}
				else if (combat.Poke1_speed > combat.Poke2_speed) 
				{
					combat.Poke2_hp = combat.Poke2_hp - ((((combat.Poke1_level * 0.4 + 2) * combat.Poke1_atk/* *power*/) / (combat.Poke2_def * 50) + 2)/* *CM*/);
					combat.Attacking_poke = combat.Poke1_name + " attacks first ";
					if (combat.Poke2_hp > 0) 
					{
						combat.Poke1_hp = combat.Poke1_hp - ((((combat.Poke2_level * 0.4 + 2) * combat.Poke2_atk/* *power*/) / (combat.Poke1_def * 50) + 2)/* *CM*/);
					}
				}
				else 
				{
					int poketurn = rand() % 2;
					if (poketurn == 0) 
					{
						combat.Poke1_hp = combat.Poke1_hp - ((((combat.Poke2_level * 0.4 + 2) * combat.Poke2_atk/* *power*/) / (combat.Poke1_def * 50) +2)/* *CM*/);
						combat.Attacking_poke = combat.Poke2_name + " attacks first ";
						if (combat.Poke1_hp > 0) 
						{
							combat.Poke2_hp = combat.Poke2_hp - ((((combat.Poke1_level * 0.4 + 2) * combat.Poke1_atk/* *power*/) / (combat.Poke2_def * 50) +2)/* *CM*/);
						}
					}
					else if (poketurn == 1) 
					{
						combat.Poke2_hp = combat.Poke2_hp - ((((combat.Poke1_level * 0.4 + 2) * combat.Poke1_atk/* *power*/) / (combat.Poke2_def * 50) +2)/* *CM*/);
						combat.Attacking_poke = combat.Poke1_name + " attacks first ";
						if (combat.Poke2_hp > 0) 
						{
							combat.Poke1_hp = combat.Poke1_hp - ((((combat.Poke2_level * 0.4 + 2) * combat.Poke2_atk/* *power*/) / (combat.Poke1_def * 50) +2)/* *CM*/);
						}
					}
				}
				PokeAttack.setString(combat.Attacking_poke);
				Poke1_text.setString(combat.Poke1_name + " : " + to_string(combat.Poke1_hp) + " HP");
				Poke2_text.setString(combat.Poke2_name + " : " + to_string(combat.Poke2_hp) + " HP");
			}
		}
		sf::Texture fond;
		if (!fond.loadFromFile("images/fond_combat.png")) {
			cout << "Error while loading image" << endl;
		};

		sf::Sprite Fond;
		Fond.setTexture(fond);

		if (combat.Poke1_hp <= 0 && combat.Poke2_hp > 0) {
			PokeWinner.setString(combat.Poke2_name + " won the fight.");
		}
		else if (combat.Poke2_hp <= 0 && combat.Poke1_hp > 0) {
			PokeWinner.setString(combat.Poke1_name + " won the fight.");
		}

		window.clear();
		window.draw(Fond);
		window.draw(Poke1_text);
		window.draw(Poke2_text);
		window.draw(PokeAttack);
		window.draw(PokeWinner);
		window.draw(OwnPoke);
		window.draw(FoePoke);
		window.display();
	}
	
	return 0;
}