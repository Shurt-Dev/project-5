#include "Accueil.hpp"
#include "menu.hpp"

Accueil::Accueil() {
    font = new sf::Font();
    image = new sf::Texture();
    bg = new sf::Sprite();

    set_values();
}

Accueil::~Accueil() {
    delete font;
    delete image;
    delete bg;
}

void Accueil::set_values() {

    pressed = theselect = false;
    font->loadFromFile("./pokemon-bw.ttf");
    image->loadFromFile("./Accueil_pokelike 2.jpg");

    bg->setTexture(*image);

    options = { "Appuyez sur entrée" };
    texts.resize(1);
    coords = { {225,675} };
    sizes = { 60 };

    for (std::size_t i{}; i < texts.size(); ++i) {
        texts[i].setFont(*font);
        texts[i].setString(options[i]);
        texts[i].setCharacterSize(sizes[i]);
        texts[i].setOutlineColor(sf::Color::Black);
        texts[i].setPosition(coords[i]);
    }

}

void Accueil::loop_events(sf::RenderWindow* window, sf::SoundBuffer* buffer, sf::Sound* sound) {
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect) {
            theselect = true;

            sound->stop();
            buffer->loadFromFile("28-Pokémon-Gym.wav");
            sound->setBuffer(*buffer);
            sound->play();

            Menu* menu = new Menu();
            menu->run_menu(window, buffer, sound);
            delete menu;
            menu = nullptr;
        }
    }
}

void Accueil::draw_all(sf::RenderWindow* window, sf::SoundBuffer* buffer, sf::Sound* sound) {
    window->clear();
    window->draw(*bg);
    for (auto t : texts) {
        window->draw(t);
    }
    window->display();
}

void Accueil::run_accueil(sf::RenderWindow* window, sf::SoundBuffer* buffer, sf::Sound* sound) {
    buffer->loadFromFile("02-Opening-Movie.wav");
    sound->setBuffer(*buffer);
    sound->play();
    
    while (window->isOpen()) {
        loop_events(window, buffer, sound);
        draw_all(window, buffer, sound);
    }
}
