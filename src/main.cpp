

#include "../includes/helpers.hpp"
#include "../includes/Airport.hpp"
#include "../includes/Departure.hpp"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <iomanip>


void remove_substring(std::string& line, const std::string substring) {
	size_t pos;
	while ((pos = line.find(substring)) != std::string::npos) {
		line.erase(pos, substring.length());
	}
}


const std::string line_sep = "------------------------------------------------------------------------------------------------\n";

std::ostream& operator<<(std::ostream& os, const Departure& d) {
	os << std::left
		<< line_sep 
		<< d.description << "\n"
		<< line_sep 
		<< std::setw(20) << "Scheduled Departure" << " | " << d.scheduled_departure << "\n"
		<< std::setw(20) << "Scheduled Arrival"	  << " | " << d.scheduled_arrival << "\n"
		<< std::setw(20) << "Departure Airport"   << " | " << d.departure_airport << "\n"
		<< std::setw(20) << "Arrival Airport"     << " | " << d.arrival_airport << "\n"
		<< line_sep;
	return os;
}

int main(int argc, char *argv[])
{
	// Step 1: Create a file stream for the .ics file
	std::cout << "Current path: " << std::filesystem::current_path() << std::endl;
	std::ifstream departure_file_stream("../../../data-sets/departures.ics");

	// Step 2: Check if the file opened, if not display a warning and exit gracefully.
	if (!departure_file_stream.is_open()) {
		std::cerr << "failed to open the file\n";
		return -1;
	}

	std::string line;

	std::vector<Departure> departures;
	Departure temp_departure;
	
	// process each line of the file, and ignore attributes that are unneeded
	while (std::getline(departure_file_stream, line)) {
		if (line.find("BEGIN:VCALENDAR") != std::string::npos) {
			continue;
		}
		if (line.find("VERSION") != std::string::npos) {
			continue;
		}
		if (line.find("PRODID") != std::string::npos) {
			continue;
		}
		if (line.find("CALSCALE") != std::string::npos) {
			continue;
		}
		if (line.find("BEGIN:VEVENT") != std::string::npos) {
			continue;
		}

		if (line.find("END:VCALENDAR") != std::string::npos) {
			continue;
		}
		
		// When the attribute indicates the end of the event, push back the event string into the events vector
		if (line.find("END:VEVENT") != std::string::npos) {
			departures.push_back(temp_departure);
			temp_departure = Departure();
			continue;
		}

		// This line is the departure time
		if (line.find("DTSTART") != std::string::npos) {
			remove_substring(line, "DTSTART:");
			temp_departure.scheduled_departure = line;
		}

		// This line is the arrival time
		if (line.find("DTEND") != std::string::npos) {
			remove_substring(line, "DTEND:");
			temp_departure.scheduled_arrival = line;
		}

		if (line.find("SUMMARY") != std::string::npos) {
			remove_substring(line, "SUMMARY:");
			temp_departure.description = line;
		}
	
		if (line.find("DESCRIPTION") != std::string::npos) {
			remove_substring(line, "DESCRIPTION:");
			// @todo validate that the description has the following format
			// ABC to DEF
			temp_departure.departure_airport = line.substr(0, 3);
			temp_departure.arrival_airport = line.substr(7, 3);
		}
	
	}

	for (const auto& departure : departures) {
		std::cout << departure << "\n";
	}

}