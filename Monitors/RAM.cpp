
#include "RAM.hpp"

RAM::RAM()
{
    font.loadFromFile("assets/Roboto-Regular.ttf");
}

RAM::~RAM()
{
}

void RAM::init()
{
    std::ifstream config("/proc/meminfo");

    std::map<std::string, std::string> map;
    if (config.fail())
        return;
    std::string str;
    while (std::getline(config, str)) {
        std::string tmp = str.substr(str.find(':') + 1, std::string::npos);
        tmp = tmp.substr(tmp.find_first_not_of(" "), std::string::npos);
        map[str.substr(0, str.find(':'))] = tmp;
    }
    this->_RAM = map;
}

void RAM::update()
{
}

void RAM::displayGraphical()
{
    std::string rawData = Utils::exec("free -m | grep -i mem");
    std::stringstream ss(rawData);
    std::string temp;
    int used;
    int total;
    ss >> temp >> total >> used;
    float ratioSize = 100 * (float) used / (float) total;

    sf::RectangleShape r;
    sf::RectangleShape border;
    sf::Text t;
    sf::Text title;
    window->setVisible(true);
    window->clear(sf::Color::Black);

    r.setFillColor(sf::Color::Yellow);
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
    title.setString("RAM");
    title.setFillColor(sf::Color::White);

    window->draw(border);
    window->draw(r);
    window->draw(t);
    window->draw(title);
    window->display();
}

void RAM::displayText()
{
    int n = 5;
    move(5, 70);
    printw("RAM:");
    for (auto it = this->_RAM.begin(); it != this->_RAM.end(); ++it) {
        std::string line = it->first + ": " + it->second;
        mvprintw(n, 75, "%s", line.data());
        n++;
    }
}
