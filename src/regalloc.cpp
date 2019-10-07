#include "regalloc.hpp"
#include <iostream>
#include <fstream>
#include <list>
#include <string>

Regalloc::Regalloc() {}

void Regalloc::readInput() {

    // Getting graph name
    std::string line;

    std::getline(std::cin, line);

    std::size_t startPos = 6;
    std::size_t endPos = line.find(':');

    int graphId = std::stoi(std::string(line, startPos, endPos - startPos));
    graph = new Reg::Graph(graphId);

    // Getting K
    std::getline(std::cin, line);
    startPos = 2;
    k = std::stoi(std::string(line, startPos, line.size() - startPos));

    // Getting all the edges
    while (std::getline(std::cin, line)) {
        endPos = line.find_first_of(" ");
        startPos = 0;
        int vId = std::stoi(std::string(line, startPos, endPos - startPos));

        graph->addVertex(vId);

        startPos = endPos + 5;

        endPos = line.find_first_of(" ", startPos);
        while ((endPos = line.find_first_of(" ", startPos)) != std::string::npos) {
            int v2Id = std::stoi(std::string(line, startPos, endPos - startPos));

            graph->addVertex(v2Id);
            graph->addEdge(vId, v2Id);

            startPos = endPos + 1;
        }
        int v2Id = std::stoi(std::string(line, startPos, line.length() - startPos));

        graph->addVertex(v2Id);
        graph->addEdge(vId, v2Id);
    }
}

// For testing purposes
void Regalloc::exportToDot(const std::string filepath) {
    std::ofstream file;

    file.open(filepath);

    if (file.is_open()) {
        graph->exportToDot(file);
    }

    file.close();
}