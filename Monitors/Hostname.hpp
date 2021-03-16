// Hostname and username module

#ifndef HOST_NAME_HPP_
#define HOST_NAME_HPP_

#include "../Monitor.hpp"
#include "../Monitor.hpp"
#include <iostream>
#include <chrono>
#include <ctime>
#include <fstream>
#include <unistd.h>
#include <ncurses.h>

class Hostname : public Monitor
{
    public:
        Hostname();
        ~Hostname();

        void init() override;
        void update() override;
        void displayGraphical() override;
        void displayText() override;
    private:
        std::string _hostname;
        sf::Font font;
};


#endif