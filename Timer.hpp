#ifndef TIMER_HPP
#define TIMER_HPP

#include <string>

class Timer{
private:
    // unsigned char day; 
    // unsigned char month; 
    // unsigned int year;
    std::string month; 
    std::string day; 
    std::string year; 
public:
    Timer();

    std::string GetDay()    {return std::string(2 - std::min((size_t)2, day.length()), '0') + day;}
    std::string GetMonth()  {return std::string(2 - std::min((size_t)2, month.length()), '0') + month;}
    std::string GetYear()   {return std::string(4 - std::min((size_t)4, year.length()), '0') + year;}

    std::string GetDate();
};

#endif //TIMER_HPP