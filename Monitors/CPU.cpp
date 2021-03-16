#include "CPU.hpp"

CPU::CPU() : font{sf::Font()}
{
    font.loadFromFile("assets/Roboto-Regular.ttf");
    std::string src = "/proc/cpuinfo";
    std::ifstream file(src.c_str(), std::ios::in);
    std::string line;
    std::string model;

    if (file)
        while (!file.eof()) {
            std::getline(file, line);
            if (line.find("model name") != line.npos)
                model = line.substr(13, 50);
        }
    file.close();
    cpu_model = model;
}

static coreData parseCoreActivity(const std::string &rawData)
{
    std::stringstream ss(rawData);
    std::string temp;
    int times[10];

    ss >> temp;
    for (int i = 0; i < 10; ++i)
        ss >> times[i];
    coreData out = {0, 0};
    for (int i = 0; i < 10; ++i)
        if (i != 3 && i != 4)
            out.timeActive += times[i];
    out.idleTime = times[3] + times[4];
    return out;
}

void CPU::init()
{
    data = parseCoreActivity(Utils::exec("cat /proc/stat | grep -i \"cpu \""));
}

void CPU::update()
{
    init();
}

void CPU::displayGraphical()
{
    float ratioSize =
        100.0 * ((float) data.timeActive / (float) data.totalTime());
    sf::RectangleShape r;
    sf::RectangleShape border;
    sf::Text t;
    sf::Text title;
    window->setVisible(true);
    window->clear(sf::Color::Black);

    r.setFillColor(sf::Color::Red);
    r.setSize({100, 200});
    r.setOrigin(50, 100);
    r.setPosition(100, 25);
    r.rotate(180);
    r.setSize({100, ratioSize});

    border.setOutlineColor(sf::Color::White);
    border.setOutlineThickness(3);
    border.setSize({100, 100});
    border.setPosition(50, 25);
    border.setFillColor(sf::Color::Transparent);

    t.setFont(font);
    t.setCharacterSize(30);
    t.setString(std::to_string(ratioSize) + "%");
    t.setFillColor(sf::Color::White);
    t.setPosition(15, 150);

    title.setFont(font);
    title.setCharacterSize(16);
    title.setString("CPU");
    title.setFillColor(sf::Color::White);

    window->draw(border);
    window->draw(r);
    window->draw(t);
    window->draw(title);
    window->display();
}

void CPU::displayText()
{
    move(5, 0);
    printw("CPU: ");
    move(7, 5);
    printw("Core %d", sysconf(_SC_NPROCESSORS_ONLN));
    move(6, 5);
    printw("CPU Ratio:%f",
        100.0 * ((float) data.timeActive / (float) data.totalTime()));
    mvprintw(5, 5, "CPU model :%s", cpu_model.data());
}
