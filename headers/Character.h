#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Character
{
protected:
	sf::Texture texture;
	sf::Clock charClock;
	float posY;
	float posX;
	int frameNum;
	int frameDir;
	int dirX;
	int dirY;
	bool keyIsPressed;
	bool nextTileIsWalkable;

	int windowHeight;
	int windowWidth;
public:
	sf::Sprite spriteChar;
	sf::Sprite spriteMap;


	Character(std::string path);
	void Move();
	bool Walk();
	void SetWindowSize(int w, int h);
	void CharCollision();
};

