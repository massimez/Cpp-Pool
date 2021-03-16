#ifndef MONITOR_HPP_
#define MONITOR_HPP_

#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <ncurses.h>

class Monitor : public IMonitorDisplay, public IMonitorModule {
  public:
    Monitor()
        : window{new sf::RenderWindow(
            sf::VideoMode(200, 200), "BASE CLASS WINDOW", sf::Style::None)}
    {
        window->setVisible(false);
        initscr();
        cbreak(); // Enable Ctrl+c to exit
        noecho(); // Doesnt show user input
       
    };
    ~Monitor()
    {
        delete window;
        endwin();
    };

    virtual void init() = 0;
    virtual void update() = 0;
    virtual void displayGraphical() = 0;
    virtual void displayText() = 0;

    void setWindowPosition(const int x, const int y)
    {
        window->setPosition({x, y});
    }

  protected:
    // i couldnt think of any variables all monitors share (for now)
    // feel free to add if you think of something
    sf::RenderWindow *window;

};

#endif