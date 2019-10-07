#include "regalloc.hpp"
#include <iostream>
#include <string>

Regalloc::Regalloc() {}

void Regalloc::readInput() {

    // Getting graph name
    std::string line;

    std::getline(std::cin, line);

    std::size_t startPos = 6;
    std::size_t endPos = line.find(':');

    graph = new Reg::Graph(std::stoi(std::string(line, startPos, endPos - startPos)));

    // Getting K
    std::getline(std::cin, line);
    startPos = 2;
    k = std::stoi(std::string(line, startPos, line.size() - startPos));

    // Getting all the edges
    int numOfEdges = 0;
    while (std::getline(std::cin, line)) {
        endPos = line.find_first_of(" ");
        startPos = 0;
        int vId = std::stoi(std::string(line, startPos, endPos - startPos));

        this->graph->addVertex(vId);

        startPos = endPos + 5;

        endPos = line.find_first_of(" ", startPos);
        while ((endPos = line.find_first_of(" ", startPos)) != std::string::npos) {
            int v2Id = std::stoi(std::string(line, startPos, endPos - startPos));
            this->graph->addEdge(vId, v2Id);
            startPos = endPos + 1;
            numOfEdges++;
        }
        int v2Id = std::stoi(std::string(line, startPos, line.length() - startPos));
        this->graph->addEdge(vId, v2Id);
        numOfEdges++;
    }

    this->graph->clearLists();
}