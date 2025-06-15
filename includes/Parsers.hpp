#pragma once

#include "./Airport.hpp"
#include "./Departure.hpp"

#include <fstream>
namespace Parsers {
    std::vector<Departure> parse_departure_data(std::ifstream &departure_file_stream);

    std::vector<Airport> parse_airport_data(std::ifstream &airport_file_stream);
} // namespace Parsers