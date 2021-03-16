#include "DateTime.hpp"
#include <fstream>
#include <ncurses.h>

DateTime::DateTime()
{
    font.loadFromFile("assets/Roboto-Regular.ttf");
}

void DateTime::init()
{
    std::string src = "/proc/driver/rtc";
    std::ifstream file(src.c_str(), std::ios::in);
    std::string line;
    std::string time, date;

    if (file)
        while (!file.eof()) {
            std::getline(file, line);
            if (line.find("rtc_time") != line.npos)
                time = line.substr(11, 19);
            if (line.find("rtc_date") != line.npos)
                date = line.substr(11, 21);
        }
    file.close();
    this->_time = time;
    this->_date = date;
}

void DateTime::update()
{
    init();
}

void DateTime::displayGraphical()
{
    sf::Text date;
    sf::Text time;
    window->setVisible(true);
    window->clear(sf::Color::White);

    date.setFont(font);
    date.setCharacterSize(10);
    date.setString(_date.data());
    date.setFillColor(sf::Color::Black);
    date.setPosition(15, 50);

    time.setFont(font);
    time.setCharacterSize(10);
    time.setString(_time.data());
    time.setFillColor(sf::Color::Black);
    time.setPosition(15, 150);

    window->draw(date);
    window->draw(time);
    window->display();
}

void DateTime::displayText()
{
    mvprintw(0, 0, "Time: %s", _time.data());
    mvprintw(0, 20, "Date: %s", _date.data());
}
