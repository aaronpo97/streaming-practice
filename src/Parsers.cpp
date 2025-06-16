#include "../includes/Parsers.hpp"
#include "../includes/Departure.hpp"
#include "../includes/helpers.hpp"

#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

namespace Parsers {
    std::vector<Departure> parse_departure_data(std::ifstream &departure_file_stream) {
        const std::regex DESCRIPTION_PATTERN(R"(^[A-Z]{3} to [A-Z]{3}$)");
        const std::regex ISO8601_PATTERN(
            R"((\d{4})(\d{2})(\d{2})T(\d{2})(\d{2})(\d{2})Z)");

        const std::unordered_set<std::string> IGNORED_PREFIXES = {
            "BEGIN:VCALENDAR", "VERSION",      "PRODID",
            "CALSCALE",        "BEGIN:VEVENT", "END:VCALENDAR"};

        std::vector<Departure> departures;
        Departure              departure;

        std::string line;

        // process each line of the file, and ignore attributes that are
        // unneeded
        while (std::getline(departure_file_stream, line)) {

            if (std::any_of(IGNORED_PREFIXES.begin(), IGNORED_PREFIXES.end(),
                            [&line](const std::string &prefix) {
                                return line.find(prefix) != std::string::npos;
                            })) {
                continue;
            }

            // When the attribute indicates the end of the event, push back the
            // event string into the events vector
            if (line.find("END:VEVENT") != std::string::npos) {
                departures.push_back(departure);
                departure = Departure();
                continue;
            }

            // This line is the departure time
            if (line.find("DTSTART") != std::string::npos) {
                remove_substring(line, "DTSTART:");
                trim(line);
                // Check if the line matches the ISO8601 pattern
                if (!std::regex_match(line, ISO8601_PATTERN)) {
                    std::cerr << "WARNING: Invalid ISO8601 format for "
                                 "departure time\n";
                }

                departure.scheduled_departure_ISO = line; // e.g. 20260101T120000Z
            }

            // This line is the arrival time
            if (line.find("DTEND") != std::string::npos) {
                remove_substring(line, "DTEND:");
                trim(line);
                departure.scheduled_arrival_ISO = line; // e.g. 20260101T140000Z
            }

            if (line.find("SUMMARY") != std::string::npos) {
                remove_substring(line, "SUMMARY:");
                trim(line);
                departure.description = line;
            }

            if (line.find("DESCRIPTION") != std::string::npos) {
                // Remove the `DESCRIPTION` header
                remove_substring(line, "DESCRIPTION:");
                // trim trailing whitespace
                trim(line);

                // get the flight description in the format `^[A-Za-z]{3} to
                // [A-Za-z]{3}$` e.g. YYZ to YHZ
                std::string flight_description = line.substr(0, 10);

                if (!std::regex_match(flight_description, DESCRIPTION_PATTERN)) {
                    std::cerr << "WARNING: Invalid description format\n";
                };
                departure.departure_airport = flight_description.substr(0, 3);
                departure.arrival_airport   = flight_description.substr(7, 3);
            }
        }

        return departures;
    }

    /*
     * Example airport data format:
     *
     *     [YVR]
     *     Name=Vancouver International Airport
     *     Province=British Columbia
     *     City=Richmond
     *     IATA_Code=YVR
     *     Annual_Passengers=26205801
     *     Elevation_ft=14
     *     Timezone_Summer=UTC-7
     *     Timezone_Winter=UTC-8
     *     Address=3211 Grant McConachie Way, Richmond, BC V7B 0A4
     *     Coordinates=49.19472, -123.18389
     *
     */
    std::vector<Airport> parse_airport_data(std::ifstream &airport_file_stream) {
        std::vector<Airport> airports;
        std::string          line;
        Airport              airport;

        while (std::getline(airport_file_stream, line)) {
            // Check for heading lines e.g. [YYC]
            if (line.find('[') != std::string::npos &&
                line.find(']') != std::string::npos) {
                // If we have an airport, push it to the vector
                if (!airport.name.empty()) {
                    airports.push_back(airport);
                    airport = Airport();
                }

                continue;
            }

            std::stringstream str_stream(line);
            std::string       key, value;
            // Split the line into key-value pairs
            std::getline(str_stream, key, '=');
            std::getline(str_stream, value);

            trim(key);
            trim(value);

            // Process the key-value pairs
            if (key == "Name") {
                airport.name = value;
            } else if (key == "IATA_Code") {
                airport.iata_code = value;
            } else if (key == "Annual_Passengers") {
                airport.annual_passengers = std::stoul(value);
            } else if (key == "Elevation_ft") {
                airport.elevation_ft = std::stoi(value);
            } else if (key == "Timezone_Winter") {
                airport.timezone.winter = "UTC" + value;
            } else if (key == "Timezone_Summer") {
                airport.timezone.summer = "UTC" + value;
            } else if (key == "Province") {
                // Not used in the Airport struct, but can be stored if needed
                // airport.province = value;
            } else if (key == "State") {
                // Not used in the Airport struct, but can be stored if needed
                // airport.state = value;
            } else if (key == "Country") {
                // Not used in the Airport struct, but can be stored if needed
                // airport.country = value;
            } else if (key == "City") {
                // Not used in the Airport struct, but can be stored if needed
                // airport.city = value;
            } else if (key == "Address") {
                airport.address = value;
            } else if (key == "Coordinates") {
                std::stringstream coord_stream(value);
                std::string       lat_str, lon_str;
                std::getline(coord_stream, lat_str, ',');
                std::getline(coord_stream, lon_str);
                airport.coordinates.latitude  = std::stod(lat_str);
                airport.coordinates.longitude = std::stod(lon_str);
            }
        }

        return airports;
    }
} // namespace Parsers