// Operating system name and kernel version module

#ifndef OS_NAME_HPP_
#define OS_NAME_HPP_

#include "../Monitor.hpp"
#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "string.h"
#include <ncurses.h>

class OSName : public Monitor
{
    private:
        std::string _osName;
        sf::Font font;
    public:
        OSName();
        ~OSName();
        void init() override;
        void update() override;
        void displayGraphical() override;
        void displayText() override;
};

#endif
