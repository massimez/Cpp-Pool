#include "Hostname.hpp"

Hostname::Hostname()
{
    font.loadFromFile("assets/Roboto-Regular.ttf");
}

Hostname::~Hostname()
{
}

void Hostname::init()
{
    char name[1024];
    if (gethostname(name, sizeof(name)) == -1) {
        return;
    }
    this->_hostname = name;
}

void Hostname::update()
{
}

void Hostname::displayGraphical()
{
    sf::Text t;
    sf::Text title;
    window->setVisible(true);
    window->clear(sf::Color::Cyan);

    t.setFont(font);
    t.setCharacterSize(10);
    t.setString(_hostname.data());
    t.setFillColor(sf::Color::Magenta);
    t.setPosition(15, 100);

    title.setFont(font);
    title.setCharacterSize(16);
    title.setString("Host name");
    title.setFillColor(sf::Color::White);

    window->draw(t);
    window->draw(title);
    window->display();
}

void Hostname::displayText()
{
    mvprintw(3, 0, "Hostname: %s", _hostname.data());
}