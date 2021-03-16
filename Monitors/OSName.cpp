#include "OSName.hpp"

OSName::OSName()
{
    font.loadFromFile("assets/Roboto-Regular.ttf");
}

OSName::~OSName()
{
}

void OSName::init()
{
    struct utsname name;
    if (uname(&name))
        return;
    char *n = strcat(name.release, "@");
    this->_osName = strcat(n, name.sysname);
}

void OSName::update()
{
}

void OSName::displayGraphical()
{
    sf::Text t;
    sf::Text title;
    window->setVisible(true);
    window->clear(sf::Color::Red);

    t.setFont(font);
    t.setCharacterSize(10);
    t.setString(_osName.data());
    t.setFillColor(sf::Color::Green);
    t.setPosition(15, 100);

    title.setFont(font);
    title.setCharacterSize(16);
    title.setString("OS name");
    title.setFillColor(sf::Color::White);

    window->draw(t);
    window->draw(title);
    window->display();
}

void OSName::displayText()
{
    mvprintw(2, 0, "Osname: %s", _osName.data());
}
