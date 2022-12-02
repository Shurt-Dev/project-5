#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "../headers/Character.h"
#include "../headers/App.h"
#include "../headers/Pokemon.h"
#include "../headers/Capacities.h"
#include "../headers/Combat2.h"
#include "../Combat.h"
#include "../Accueil.hpp"

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

        default:
            break;
        }
    }
    return false;
};


int App::mainApp()
{
    srand(time(nullptr));
    Character Player("C:/Users/Shurturgal/source/repos/PokeLike/images/Arceus.png");
    Player.SetWindowSize(this->windowWidth, this->windowHeight);
    static Capacities Capacity;
    Pokemon Voltali("Voltali", 100, 20, 0, 58, 49, 56, 68, 32, 80, Capacity.Charge(), Capacity.Eclair(), Capacity.Mimi_Queue(), Capacity.Rugissement(), TYPE_ELECTRIK, TYPE_NONE, "None");
    Pokemon Voltali2("Voltali2", 100, 20, 0, 58, 49, 56, 68, 32, 80, Capacity.Charge(), Capacity.Eclair(), Capacity.Mimi_Queue(), Capacity.Rugissement(), TYPE_ELECTRIK, TYPE_NONE, "None");
    sf::Clock clock;
    Combat combat(Voltali, Voltali2);

    while (this->window.isOpen())
    {
        AppEvent();
        this->window.clear();
        Player.Move();
        combat.Turn();
        
        Accueil* accueil = new Accueil();
        accueil->run_accueil(&window, &buffer, &sound);
        delete accueil;
        accueil = nullptr;

        //this->window.draw(combat.getBackground());
        //this->window.draw(combat.getText());
        //this->window.draw(combat.getPokeSprite(1));
        //this->window.draw(combat.getPokeSprite(2));
        //this->window.draw(Player.sprite);
        this->window.display();
    }
    return 0;
};