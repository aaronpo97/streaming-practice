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

struct Timezone {
    std::string winter; // e.g., "UTC-5"
    std::string summer; // e.g., "UTC-4"
};

struct Airport {
    std::string  name;
    std::string  iata_code;
    unsigned int annual_passengers;
    int          elevation_ft;
    Timezone     timezone;

    std::optional<std::string> city;     // Optional, can be empty
    std::optional<std::string> country;  // Optional, can be empty
    std::optional<std::string> state;    // Optional, can be empty
    std::optional<std::string> province; // Optional, can be empty
    std::optional<std::string> address;
    Coordinates                coordinates;
};

std::ostream &operator<<(std::ostream &os, const Coordinates &c);
std::ostream &operator<<(std::ostream &os, const Timezone &t);
std::ostream &operator<<(std::ostream &os, const Airport &a);
