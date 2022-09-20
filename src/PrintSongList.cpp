#include "PrintSongList.hpp"

std::string PrintSongList::printSongList(std::chrono::system_clock::time_point dateTime){
    std::time_t getTime = std::chrono::system_clock::to_time_t(dateTime);
    struct tm *parts = std::localtime(&getTime);

	std::string day = std::to_string(parts->tm_mday);
	std::string month = std::to_string(1 + parts->tm_mon);
	std::string year = std::to_string(1900 + parts->tm_year);

    return year +
        std::string(2 - std::min((unsigned char)2, (unsigned char)month.length()), '0') + month +
		std::string(2 - std::min((unsigned char)2, (unsigned char)day.length()), '0') + day 
        ;
}