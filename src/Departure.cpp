#include "../includes/Departure.hpp"
#include "../includes/helpers.hpp"

#include <iomanip>
std::ostream &operator<<(std::ostream &os, const Departure &d) {
    os << std::left << line_sep << "\n"
       << std::setw(80) << d.description << "\n"
       << line_sep << "\n"
       << std::setw(20) << "Scheduled Departure" << " | " << d.scheduled_departure_ISO
       << "\n"
       << std::setw(20) << "Scheduled Arrival" << " | " << d.scheduled_arrival_ISO << "\n"
       << std::setw(20) << "Departure Airport" << " | " << d.departure_airport << "\n"
       << std::setw(20) << "Arrival Airport" << " | " << d.arrival_airport << "\n"
       << line_sep << "\n";
    return os;
}