#pragma once
#include <string>

constexpr char line_sep[] = "--------------------------------------------------"
                            "-----------------------------";

constexpr double feetToMetres(const double feet) { return feet * 0.3048; }

void remove_substring(std::string &line, const std::string substring);
void trim(std::string &s);