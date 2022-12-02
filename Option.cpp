#include "Option.hpp"
#include "menu.hpp"

Option::Option() {
    font = new sf::Font();
    image = new sf::Texture();
    bg = new sf::Sprite();

    set_values();
}

Option::~Option() {
    delete font;
    delete image;
    delete bg;
}

void Option::set_values() {

    pos = 0;
    pressed = theselect = false;
    font->loadFromFile("./pokemon-bw.ttf");
    image->loadFromFile("./fond menu.png");

    bg->setTexture(*image);

    options = { "Option", "Volume", "100", "Retour : press Echap" };
    texts.resize(4);
    coords = { {425,80},{300,300},{600,300},{590,610} };
    sizes = { 60,60,60,40 };

    for (std::size_t i{}; i < texts.size(); ++i) {
        texts[i].setFont(*font);
        texts[i].setString(options[i]);
        texts[i].setCharacterSize(sizes[i]);
        texts[i].setOutlineColor(sf::Color::Black);
        texts[i].setPosition(coords[i]);
    }
    
    pos = 2;

    texts[pos].setOutlineThickness(10);
}

void Option::loop_events(sf::RenderWindow* window, sf::SoundBuffer* buffer, sf::Sound* sound) {
    sf::Event event;
    int volume = 30;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed) {
            if (pos = 2) {
                pressed = true;
                if (sound->getVolume() < 91) {
                    sound->setVolume(sound->getVolume() + 10);
                    volume = volume + 10;
                    texts[2] = texts[char(volume)];
                    //texts[2].setString(char(volume));
                    // .setString(options[2])
                }
                pressed = false;
                theselect = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed) {
            if (pos = 2) {
                pressed = true;
                if (sound->getVolume() > 10) {
                    sound->setVolume(sound->getVolume() - 10);
                    volume = volume - 10;
                    texts[2] = texts[char(volume)];
                }
                pressed = false;
                theselect = false;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && !theselect) {
            theselect = true;
            Menu* menu = new Menu();
            menu->run_menu(window, buffer, sound);
            delete menu;
            menu = nullptr;
        }
    }
}

void Option::draw_all(sf::RenderWindow* window, sf::SoundBuffer* buffer, sf::Sound* sound) {
    window->clear();
    window->draw(*bg);
    for (auto t : texts) {
        window->draw(t);
    }
    window->display();
}

void Option::run_option(sf::RenderWindow* window, sf::SoundBuffer* buffer, sf::Sound* sound) {
    while (window->isOpen()) {
        loop_events(window, buffer, sound);
        draw_all(window, buffer, sound);
    }
}
