#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Accueil {
    bool pressed, theselect;

    sf::Font* font;
    sf::Texture* image;
    sf::Sprite* bg;

    std::vector<const char*> options;
    std::vector<sf::Vector2f> coords;
    std::vector<sf::Text> texts;
    std::vector<std::size_t> sizes;

protected:
    void set_values();
    void loop_events(sf::RenderWindow*, sf::SoundBuffer*, sf::Sound*);
    void draw_all(sf::RenderWindow*, sf::SoundBuffer*, sf::Sound*);

public:
    Accueil();
    ~Accueil();
    void run_accueil(sf::RenderWindow*, sf::SoundBuffer*, sf::Sound*);
};