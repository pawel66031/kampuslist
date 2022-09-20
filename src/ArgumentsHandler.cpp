#include "ArgumentsHandler.hpp"
#include <iostream>
#include <vector>

bool ArgumentHandler::ReadArguments(int size, char* arguments[]){
    unsigned int _numArgument = 1;
    
    for(int i = 0; i < size; ++i){
        std::cout << arguments[i] << '\n';
    }
    std::cout << '\n';

    // std::vector<int> vec;
    // vec.s

    return true;
}