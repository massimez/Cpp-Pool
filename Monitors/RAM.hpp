// Operating system name and kernel version module

#ifndef RAM_HPP_
#define RAM_HPP_

#include "../Monitor.hpp"
#include "../Utils.hpp"
#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <iostream>
#include "string.h"
#include <ncurses.h>
#include <map>
#include <fstream>
#include <algorithm>

class RAM : public Monitor
{
    private:
        sf::Font font;
        std::map<std::string, std::string> _RAM;
    public:
        RAM();
        ~RAM();
        void init() override;
        void update() override;
        void displayGraphical() override;
        void displayText() override;
};

#endif
