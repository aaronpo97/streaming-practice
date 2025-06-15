#pragma once
#include <chrono>
#include "./helpers.hpp"	
using Timestamp = std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds>;


/*
* \name Departure
* \brief Data structure to store departure data.
* 
* \members
* - scheduled_departure An ISO timestamp for the scheduled departure.
* - scheduled_arrival An ISO timestamp for the scheduled arrival.
* - description A description of the departure (e.g. YYZ to MNL (long-haul route)
* - departure_airport The airport code for the origin airport.
* - arrival_airport The airport code for the destination airport.
*/
struct Departure {
	std::string scheduled_departure;
	std::string scheduled_arrival;
	std::string description;
	std::string departure_airport;
	std::string arrival_airport;
};

std::ostream& operator << (std::ostream& os, const Departure& d);

