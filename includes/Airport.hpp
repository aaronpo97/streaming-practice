#pragma once

#include <string>
#include <utility>

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

struct Coordinates {
    double latitude;
    double longitude;
};

struct Airport {
    std::string  name;
    std::string  iata_code;
    unsigned int annual_passengers;
    int          elevation_ft;
    std::string  timezone;
    std::string  address;
    Coordinates  coordinates;
};

std::ostream &operator<<(std::ostream &os, const Coordinates &c);
std::ostream &operator<<(std::ostream &os, const Airport &a);
