#ifndef PRINT_SONG_LIST_H
#define PRINT_SONG_LIST_H

#include <iostream>
#include <chrono>

class PrintSongList{
public:
    static std::string printSongList(std::chrono::system_clock::time_point dateTime = std::chrono::system_clock::now());
};

#endif // PRINT_SONG_LIST_H