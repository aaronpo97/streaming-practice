#include "../includes/Departure.hpp"
#include "../includes/helpers.hpp"

std::ostream& operator<<(std::ostream& os, const Departure& d) {
	os << std::left
		<< line_sep
		<< d.description << "\n"
		<< line_sep
		<< std::setw(20) << "Scheduled Departure" << " | " << d.scheduled_departure << "\n"
		<< std::setw(20) << "Scheduled Arrival" << " | " << d.scheduled_arrival << "\n"
		<< std::setw(20) << "Departure Airport" << " | " << d.departure_airport << "\n"
		<< std::setw(20) << "Arrival Airport" << " | " << d.arrival_airport << "\n"
		<< line_sep;
	return os;
}