#include "../includes/Airport.hpp"
#include <iomanip>
#include <iostream>

// struct Airport {
//     std::string  name;
//     std::string  province;
//     std::string  city;
//     std::string  iata_code;
//     unsigned int annual_passangers;
//     unsigned int elevation_ft;
//     std::string  timezone;
//     std::string  address;
//     Coordinates  coordinates;
// };

std::ostream &operator<<(std::ostream &os, const Airport &d) {
    os << std::left << std::setw(20) << d.name << std::setw(15) << d.province
       << std::setw(15) << d.city << std::setw(10) << d.iata_code << std::setw(10)
       << d.annual_passangers << std::setw(10) << d.elevation_ft << std::setw(15)
       << d.timezone << std::setw(30) << d.address << std::fixed << std::setprecision(6)
       << "(" << d.coordinates.first << ", " << d.coordinates.second << ")";
    return os;
}
