#include "A_Propos.hpp"
#include "menu.hpp"

A_Propos::A_Propos() {
    font = new sf::Font();
    image = new sf::Texture();
    bg = new sf::Sprite();

    set_values();
}

A_Propos::~A_Propos() {
    delete font;
    delete image;
    delete bg;
}

void A_Propos::set_values() {

    pressed = theselect = false;
    font->loadFromFile("./pokemon-bw.ttf");
    image->loadFromFile("./fond menu.png");

    bg->setTexture(*image);

    options = { "A Propos", "AUNEAU Alexandre", "SEGUR John", "TAILLAT Axel", "JAFFE Thomas", "Retour : press Echap" };
    texts.resize(6);
    coords = { {400,80},{50,200},{50,300},{50,400},{50,500},{590,610} };
    sizes = { 60,60,60,60,60,40 };

    for (std::size_t i{}; i < texts.size(); ++i) {
        texts[i].setFont(*font);
        texts[i].setString(options[i]);
        texts[i].setCharacterSize(sizes[i]);
        texts[i].setOutlineColor(sf::Color::Black);
        texts[i].setPosition(coords[i]);
    }

}

void A_Propos::loop_events(sf::RenderWindow* window, sf::SoundBuffer* buffer, sf::Sound* sound) {
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
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

void A_Propos::draw_all(sf::RenderWindow* window, sf::SoundBuffer* buffer, sf::Sound* sound) {
    window->clear();
    window->draw(*bg);
    for (auto t : texts) {
        window->draw(t);
    }
    window->display();
}

void A_Propos::run_a_propos(sf::RenderWindow* window, sf::SoundBuffer* buffer, sf::Sound* sound) {
    while (window->isOpen()) {
        loop_events(window, buffer, sound);
        draw_all(window, buffer, sound);
    }
}
