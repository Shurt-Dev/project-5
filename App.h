#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class App
{
	int windowWidth;
	int windowHeight;
	sf::RenderWindow window;

	sf::SoundBuffer buffer;
	sf::Sound sound;

	sf::Clock clock;
public:
	App();
	sf::RenderWindow* GetWindow();
	sf::Clock GetClock();
	int mainApp();
	bool AppEvent();
};

