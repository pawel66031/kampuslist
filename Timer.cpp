#include "Timer.hpp"

#include <chrono>

Timer::Timer() {	
	// Current time
	auto current_time = std::chrono::system_clock::now();
	std::time_t getTime = std::chrono::system_clock::to_time_t(current_time);
	struct tm *parts = std::localtime(&getTime);


	day = std::to_string(parts->tm_mday);
	month = std::to_string(1 + parts->tm_mon);
	year = std::to_string(1900 + parts->tm_year);
}



std::string Timer::GetDate(){
	return year + 
		std::string(2 - std::min((unsigned char)2, (unsigned char)month.length()), '0') + month +
		std::string(2 - std::min((unsigned char)2, (unsigned char)day.length()), '0') + day 
	;
}