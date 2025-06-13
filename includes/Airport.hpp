#pragma once

#include <utility>

using Coordinates = std::pair<double, double>;

struct Airport {
	std::string name;
	std::string province;
	std::string city; 
	std::string iata_code;
	unsigned int annual_passangers;
	unsigned int elevation_ft;
	std::string timezone;
	std::string address;
	Coordinates coordinates;
};

