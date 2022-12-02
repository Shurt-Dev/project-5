#include <SFML/Graphics.hpp>
//#include "Character.h"
#include "App.h"
#include "Accueil.hpp"
//#include "Pokemon.h"
//#include "Capacities.h"

App::App(): window(sf::VideoMode(1024, 768), "PokeLike", sf::Style::Close)
{
    this->window.setFramerateLimit(60);
    this->windowWidth = 1024;
    this->windowHeight = 768;
}

sf::RenderWindow* App::GetWindow()
{
    sf::RenderWindow* windowPointer = &window;
    return windowPointer;
};

sf::Clock App::GetClock()
{
    return this->clock;
}

bool App::AppEvent()
{
    sf::Event event;
    while (this->window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            this->window.close();
            break;

        case sf::Event::Resized:
            this->windowWidth = event.size.width;
            this->windowHeight = event.size.height;
            //const sf::Vector2 size = (windowWidth, windowHeight);
            //window.setSize(size);
            break;

        default:
            break;
        }
    }
    return false;
};


int App::mainApp()
{
    //Character Player("C:/Users/aauneau/Downloads/trainer.png");
    //Player.SetWindowSize(this->windowWidth, this->windowHeight);
    //Pokemon Pikachu;
    //Pikachu.capacity.capacity1.power * Pikachu.stats.atk;
    sf::Clock clock;

    while (this->window.isOpen())
    {
        AppEvent();
        this->window.clear();

        Accueil* accueil = new Accueil();
        accueil->run_accueil(&window, &buffer, &sound);
        delete accueil;
        accueil = nullptr;

        //Player.Move();
        //this->window.draw(Player.sprite);
        this->window.display();
    }
    return 0;
};