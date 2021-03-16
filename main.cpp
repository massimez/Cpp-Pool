#include <iostream>
#include <string.h>
#include <vector>

#include "Monitor.hpp"
#include "Monitors/CPU.hpp"
#include "Monitors/DateTime.hpp"
#include "Monitors/Hostname.hpp"
#include "Monitors/OSName.hpp"
#include "Monitors/RAM.hpp"
#include "Monitors/UserName.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Syntax error: write only one parameter:" << std::endl
                  << "  0 = text mode" << std::endl
                  << "  1 = graphical mode" << std::endl;
        return 1;
    } else if (strcmp(av[1], "0") != 0 && strcmp(av[1], "1") != 0) {
        std::cerr << "Syntax error: invalid code:" << std::endl
                  << "  0 = text mode" << std::endl
                  << "  1 = graphical mode" << std::endl;
        return 2;
    }

    std::vector<Monitor *> monitors;
    monitors.push_back(new OSName);
    monitors.push_back(new DateTime);
    monitors.push_back(new UserName);
    monitors.push_back(new Hostname);
    monitors.push_back(new CPU);
    monitors.push_back(new RAM);

    for (auto monitor : monitors)
        monitor->init();

    if (strcmp(av[1], "1") == 0) {
        while (true) {
            int currentPosition = 0;
            int rowCounter = 0;
            for (auto monitor : monitors) {
                monitor->setWindowPosition(
                    ((rowCounter++ / 5) * 200), (currentPosition % 1000) + 20);
                currentPosition += 200;
                monitor->update();
                monitor->displayGraphical();
            }
            sleep(1);
        }
    } else {
        while (true) {
            for (auto monitor : monitors) {
                monitor->update();
                monitor->displayText();
            }
            napms(1000);
            refresh();
        }
        getch();
    }
    return 0;
}
