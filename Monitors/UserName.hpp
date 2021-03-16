// Operating system name and kernel version module

#ifndef USERNAME_HPP_
#define USERNAME_HPP_

#include "../Monitor.hpp"
#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "string.h"
#include <ncurses.h>
#include <unistd.h>

class UserName : public Monitor
{
    private:
        sf::Font font;
        std::string _UserName;
    public:
        UserName();
        ~UserName();
        void init() override;
        void update() override;
        void displayGraphical() override;
        void displayText() override;
};

#endif
