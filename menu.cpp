#include "Accueil.hpp"
#include "menu.hpp"
#include "A_Propos.hpp"
#include "Option.hpp"

Menu::Menu() {

    font = new sf::Font();
    image = new sf::Texture();
    bg = new sf::Sprite();

    set_values();
}

Menu::~Menu() {
    delete font;
    delete image;
    delete bg;
}

void Menu::set_values() {

    pos = 0;
    pressed = theselect = false;
    font->loadFromFile("./pokemon-bw.ttf");
    image->loadFromFile("./Menu_fini_sans_texte.png");

    bg->setTexture(*image);

    options = { "JOUER", "OPTIONS", "À PROPOS", "QUITTER" };
    texts.resize(4);
    coords = { {175,233},{682,233},{175,410},{682,410} };
    sizes = { 60,60,60,60 };

    for (std::size_t i{}; i < texts.size(); ++i) {
        texts[i].setFont(*font);
        texts[i].setString(options[i]);
        texts[i].setCharacterSize(sizes[i]);
        texts[i].setOutlineColor(sf::Color::Black);
        texts[i].setPosition(coords[i]);
    }
    texts[0].setOutlineThickness(10);

}

void Menu::loop_events(sf::RenderWindow* window, sf::SoundBuffer* buffer, sf::Sound* sound) {
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !pressed) {
            if (pos < 3) {
                ++pos;
                pressed = true;
                texts[pos].setOutlineThickness(10);
                texts[pos - 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !pressed) {
            if (pos > 0) {
                --pos;
                pressed = true;
                texts[pos].setOutlineThickness(10);
                texts[pos + 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed) {
            if (pos > 1) {
                pos = pos - 2;
                pressed = true;
                texts[pos].setOutlineThickness(10);
                texts[pos + 2].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed) {
            if (pos < 2) {
                pos = pos + 2;
                pressed = true;
                texts[pos].setOutlineThickness(10);
                texts[pos - 2].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect) {
            theselect = true;
            if (pos == 1) {
                window->clear();
                Option* option = new Option();
                option->run_option(window, buffer, sound);
                delete option;
                option = nullptr;
            }
            else if (pos == 2) {
                window->clear();
                A_Propos* a_propos = new A_Propos();
                a_propos->run_a_propos(window, buffer, sound);
                delete a_propos;
                a_propos = nullptr;
            } 
            else if (pos == 3) {
                window->close();
            }
            std::cout << options[pos] << '\n';
        }
    }
}

void Menu::draw_all(sf::RenderWindow* window, sf::SoundBuffer* buffer, sf::Sound* sound) {
    window->clear();
    window->draw(*bg);
    for (auto t : texts) {
        window->draw(t);
    }
    window->display();
}

void Menu::run_menu(sf::RenderWindow* window, sf::SoundBuffer* buffer, sf::Sound* sound) {
    /*sound->stop();
    buffer->loadFromFile("28-Pokémon-Gym.wav");
    sound->setBuffer(*buffer);
    sound->play();*/
    
    while (window->isOpen()) {
        loop_events(window, buffer, sound);
        draw_all(window, buffer, sound);
    }
}