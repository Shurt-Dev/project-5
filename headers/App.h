#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class App
{
	int windowWidth;
	int windowHeight;

	sf::SoundBuffer buffer;
	sf::Sound sound;

	sf::RenderWindow window;
	sf::Clock clock;
public:
	App();
	sf::RenderWindow* GetWindow();
	sf::Clock GetClock();
	int mainApp();
	bool AppEvent();
};

