#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <string>
#include <iostream>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

class Utils
{
public:
    Utils() = delete;
    ~Utils() = delete;
    Utils(const Utils &p2) = delete;

    static std::string exec(const char* cmd) {
        std::array<char, 128> buffer;
        std::string result;
        std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
        if (!pipe) {
            std::cerr << "Pipe opening failed!" << std::endl;
            return "";
        }
        while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
            result += buffer.data();
        }
        return result;
    }
};

#endif