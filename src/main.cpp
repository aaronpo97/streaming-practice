#include <chrono>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <regex>
#include <sstream>
#include <unordered_set>

#include "../includes/Departure.hpp"
#include "../includes/Parsers.hpp"
#include "../includes/helpers.hpp"

int main(int argc, char *argv[]) {
    // Step 1: Create a file stream for the .ics file
    std::ifstream departure_file_stream("./data-sets/departures.ics");

    // Step 2: Check if the file opened, if not display a warning and exit
    // gracefully.
    if (!departure_file_stream.is_open()) {
        std::cerr << "failed to open the file\n";
        return -1;
    }

    // Step 3: Call the parsing function
    std::vector<Departure> departures =
        Parsers::parse_departure_data(departure_file_stream);

    for (const auto &departure : departures) {
        std::cout << departure << "\n";
    }

    // Step 4: Close the file stream
    departure_file_stream.close();

    // Step 1: Get the airports.ini file
    std::ifstream airports_file_stream("./data-sets/airports.ini");
    // Step 2: Check if the file opened, if not display a warning and exit
    if (!airports_file_stream.is_open()) {
        std::cerr << "failed to open the airports file\n";
        return -1;
    }

    // Step 3: Call the parsing function
    // std::vector<Airport> airports = Parsers::parse_airport_data(airports_file_stream);
    std::vector<Airport> airports = {
        {.name              = "Toronto Pearson International Airport",
         .iata_code         = "YYZ",
         .annual_passengers = 50000000,
         .elevation_ft      = 569,
         .timezone          = "UTC-5",
         .address           = "6301 Silver Dart Dr, Mississauga, ON L5P 1B2, Canada",
         .coordinates       = {43.6777, -79.6248}},
    };

    for (const auto &airport : airports) {
        std::cout << airport << "\n";
    }
    // Step 4: Close the file stream
    airports_file_stream.close();

    // Step 5: Print the airports
}