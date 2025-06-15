#include "../includes/helpers.hpp"
#include <string>

void remove_substring(std::string &line, const std::string substring) {
    size_t pos;
    while ((pos = line.find(substring)) != std::string::npos) {
        line.erase(pos, substring.length());
    }
}

void trim(std::string &s) {
    s.erase(s.find_last_not_of(" \t\r\n") + 1); // right trim
    s.erase(0, s.find_first_not_of(" \t\r\n")); // left trim
}
