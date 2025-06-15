#pragma once
#include "./helpers.hpp"
#include <chrono>

/*
 * \name Departure
 * \brief Data structure to store departure data.
 *
 * \members
 * - scheduled_departure An ISO timestamp for the scheduled departure.
 * - scheduled_arrival An ISO timestamp for the scheduled arrival.
 * - description A description of the departure (e.g. YYZ to MNL (long-haul
 * route)
 * - departure_airport The airport code for the origin airport.
 * - arrival_airport The airport code for the destination airport.
 */
struct Departure {
    std::string scheduled_departure_ISO;
    std::string scheduled_arrival_ISO;
    std::string description;
    std::string departure_airport;
    std::string arrival_airport;
};

std::ostream &operator<<(std::ostream &os, const Departure &d);
