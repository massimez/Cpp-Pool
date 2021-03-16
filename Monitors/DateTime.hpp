// Date and time module

#ifndef DATE_TIME_HPP_
#define DATE_TIME_HPP_

#include <chrono>
#include <ctime>
#include <iostream>
#include "../Monitor.hpp"

class DateTime : public Monitor {
  private:
    std::string _time;
    std::string _date;
    sf::Font font;
  public:
    DateTime();
    ~DateTime()
    {
    }
    void init() override;
    void update() override;
    void displayGraphical() override;
    void displayText() override;
};

#endif