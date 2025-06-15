#pragma once

#include <utility>
#include <string>

/*
 *  \name Airport
 *  \brief Basic data structure to represent an Airport
 * 
 *  \members
 * - name: Name of the airport.
 * - province: Province or state where the airport is located.
 * - city: City where the airport is located.
 * - iata_code: 3-letter IATA airport code.
 * - annual_passangers: Number of passengers served annually.
 * - elevation_ft: Elevation of the airport in feet.
 * - timezone: Timezone of the airport (e.g., "UTC-5").
 * - address: Full address of the airport.
 * - coordinates: Latitude and longitude pair (in degrees).
*/


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

