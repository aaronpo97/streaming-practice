#include "../includes/Airport.hpp"
#include <helpers.hpp>
#include <iomanip>
#include <iostream>

std::ostream &operator<<(std::ostream &os, const Coordinates &c) {
    os << std::fixed << std::setprecision(6) << c.latitude << ", " << std::fixed
       << std::setprecision(6) << c.longitude;
    return os;
}

std::ostream &operator<<(std::ostream &os, const Timezone &t) {
    os << std::left << std::setw(20) << "Winter" << " | " << t.winter << "\n"
       << std::setw(20) << "Summer" << " | " << t.summer;
    return os;
}

std::ostream &operator<<(std::ostream &os, const Airport &a) {
    os << std::left << line_sep << "\n"
       << "Airport: " << a.name << "\n"
       << line_sep << "\n"
       << std::setw(20) << "IATA Code" << " | " << a.iata_code << "\n"
       << std::setw(20) << "Annual Passengers" << " | " << a.annual_passengers << "\n"
       << std::setw(20) << "Elevation (ft)" << " | " << a.elevation_ft << "\n"
       << std::setw(20) << "Elevation (m)" << " | " << std::fixed << std::setprecision(2)
       << feetToMetres(a.elevation_ft) << "\n"
       << std::setw(20) << "Timezone" << " | " << a.timezone << "\n"
       << std::setw(20) << "Address" << " | " << a.address << "\n"
       << std::setw(20) << "Coordinates" << " | " << a.coordinates << "\n"
       << line_sep << "\n";

    return os;
}
