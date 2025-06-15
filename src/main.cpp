

#include "../includes/Airport.hpp"
#include "../includes/Departure.hpp"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <regex>
#include <chrono>
#include <iomanip>


void remove_substring(std::string& line, const std::string substring);
void trim(std::string& s);
std::vector<Departure> parse_departure_data(std::ifstream &departure_file_stream);


void remove_substring(std::string& line, const std::string substring) {
	size_t pos;
	while ((pos = line.find(substring)) != std::string::npos) {
		line.erase(pos, substring.length());
	}
}

void trim(std::string& s) {
	s.erase(s.find_last_not_of(" \t\r\n") + 1); // right trim
	s.erase(0, s.find_first_not_of(" \t\r\n")); // left trim
}



std::vector<Departure> parse_departure_data(std::ifstream &departure_file_stream) {
	const std::regex DESCRIPTION_PATTERN("^[A-Za-z]{3} to [A-Za-z]{3}$");
	
	std::vector<Departure> departures;
	Departure departure;

	std::string line;

	
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
			departures.push_back(departure);
			departure = Departure();
			continue;
		}

		// This line is the departure time
		if (line.find("DTSTART") != std::string::npos) {
			remove_substring(line, "DTSTART:");
			trim(line);
			departure.scheduled_departure = line;
		}

		// This line is the arrival time
		if (line.find("DTEND") != std::string::npos) {
			remove_substring(line, "DTEND:");
			trim(line);
			departure.scheduled_arrival = line;
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

			// get the flight description in the format `^[A-Za-z]{3} to [A-Za-z]{3}$` 
			// e.g. YYZ to YHZ
			std::string flight_description = line.substr(0, 10);

			if (!std::regex_match(flight_description, DESCRIPTION_PATTERN)) {
				std::cerr << "WARNING: Invalid description format\n";
			};
			departure.departure_airport = flight_description.substr(0, 3);
			departure.arrival_airport = flight_description.substr(7, 3);
		}

	}

	for (const auto& departure : departures) {
		std::cout << departure << "\n";
	}
	
	return departures;
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

	// Step 3: Call the parsing function
	std::vector<Departure> departures = parse_departure_data(departure_file_stream);

	

}