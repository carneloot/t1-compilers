#include "regalloc.hpp"
#include <iostream>
#include <string>

Regalloc::Regalloc() {}

void Regalloc::readInput() {

    // Getting graph name
    std::string line;

    std::getline(std::cin, line);

    int startPos = 6;
    int endPos = line.find(':');

    graph = new Graph(std::stoi(std::string(line, startPos, endPos - startPos)));

    // Getting K
    std::getline(std::cin, line);
    startPos = 2;
    k = std::stoi(std::string(line, startPos, line.size() - startPos));

    std::cout << k << std::endl;

    // Getting all the edges
    
}