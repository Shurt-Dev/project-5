#include "../headers/Character.h"

bool keyIsPressed = 0;
bool nextTileIsWalkable;

Character::Character(std::string path)
{
    if (!texture.loadFromFile(path))
    {
        std::cout << "texture create failed" << std::endl;
    }
    this->spriteChar.setTextureRect(sf::IntRect(0, 0, 64, 64));
    this->spriteChar.setTexture(this->texture);
    this->charClock;
    this->charClock.restart();
    this->frameNum = 0;
    this->frameDir = 0;
    this->dirX = 0;
    this->dirY = 0;
    this->posX = 0;
    this->posY = 0;

    if (!texture.loadFromFile(path))
    {
        std::cout << "texture create failed" << std::endl;
    }
    this->spriteChar.setTextureRect(sf::IntRect(0, 0, 64, 64));
    this->spriteChar.setTexture(this->texture);
}

void Character::Move()
{
    if (this->charClock.getElapsedTime().asSeconds() > 0.10f)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
            this->frameDir = 3;
            this->keyIsPressed = 1;
            this->dirX = 0;
            this->dirY = -1;
            this->frameNum = (this->frameNum + 1) % 4;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            this->frameDir = 1;
            this->keyIsPressed = 1;
            this->dirX = -1;
            this->dirY = 0;
            this->frameNum = (this->frameNum + 1) % 4;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            this->frameDir = 0;
            this->keyIsPressed = 1;
            this->dirX = 0;
            this->dirY = 1;
            this->frameNum = (this->frameNum + 1) % 4;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            this->frameDir = 2;
            this->keyIsPressed = 1;
            this->dirX = 1;
            this->dirY = 0;
            this->frameNum = (this->frameNum + 1) % 4;
        }
        else
        {
            this->keyIsPressed = 0;
            this->dirX = 0;
            this->dirY = 0;
        }

        CharCollision();
        if (this->nextTileIsWalkable == 1)
        {
            Walk();
        }
        this->charClock.restart();
    }
};

void Character::CharCollision()
{
    //std::cout << "posX " << posX << "\nposY " << posY << "\nwindowWidth " << windowWidth << "\nwindowHeight " << windowHeight << std::endl;

    if (this->posX + dirX * 20 < 0 || this->posX + dirX * 20 > this->windowWidth-64 || this->posY + dirY * 20 < 0 || this->posY + dirY * 20 > this->windowHeight-64)
    {
        this->nextTileIsWalkable = 0;
    }
    else
    {
        this->nextTileIsWalkable = 1;
    }
    std::cout << this->nextTileIsWalkable << " : " << dirX << " : " << dirY << std::endl;
};

bool Character::Walk()
{
    this->spriteChar.setTextureRect(sf::IntRect(64 * this->frameNum * this->keyIsPressed, 64 * this->frameDir, 64, 64));

    this->posX = posX + this->keyIsPressed * this->dirX * 20.f;
    this->posY = posY + this->keyIsPressed * this->dirY * 20.f;
    this->spriteChar.move(sf::Vector2f(this->keyIsPressed * this->dirX * 20.f, this->keyIsPressed * this->dirY * 20.f));
    return 0;
};

void Character::SetWindowSize(int w, int h)
{
    this->windowWidth = w;
    this->windowHeight = h;
};
