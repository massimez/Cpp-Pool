#include "UserName.hpp"

UserName::UserName()
{
    font.loadFromFile("assets/Roboto-Regular.ttf");
}

UserName::~UserName()
{
}

void UserName::init()
{
    this->_UserName = getlogin();
}

void UserName::update()
{
}

void UserName::displayGraphical()
{
    sf::Text t;
    sf::Text title;
    window->setVisible(true);
    window->clear(sf::Color::Blue);

    t.setFont(font);
    t.setCharacterSize(20);
    t.setString(_UserName.data());
    t.setFillColor(sf::Color::Yellow);
    t.setPosition(15, 100);

    title.setFont(font);
    title.setCharacterSize(16);
    title.setString("Username");
    title.setFillColor(sf::Color::White);

    window->draw(t);
    window->draw(title);
    window->display();
}

void UserName::displayText()
{
    mvprintw(4, 0, "UserName: %s", _UserName.data());
}
