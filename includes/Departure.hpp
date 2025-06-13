#pragma once
#include <chrono>
using Timestamp = std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds>;


struct Departure {
	Timestamp scheduled_departure;
	Timestamp scheduled_arrival;
	
};