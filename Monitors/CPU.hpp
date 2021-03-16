// Date and time module

#ifndef CPU_HPP_
#define CPU_HPP_

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <vector>
#include "../Monitor.hpp"
#include "../Utils.hpp"

struct coreData {
    int timeActive;
    int idleTime;
    int totalTime()
    {
        return timeActive + idleTime;
    }
};

class CPU : public Monitor {
  private:
    int coreCount;
    coreData data;
    sf::Font font;
    std::string cpu_model;
    

  public:
    CPU();
    ~CPU() = default;

    void init() override;
    void update() override;
    void displayGraphical() override;
    void displayText() override;
};

#endif