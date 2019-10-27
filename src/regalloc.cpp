#include "regalloc.hpp"
#include <iostream>
#include <fstream>
#include <list>
#include <string>

Regalloc::Regalloc() {}

Regalloc::~Regalloc() {
    delete graph;
}

void Regalloc::build() {

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
    K = std::stoi(std::string(line, startPos, line.size() - startPos));

    // Getting all the edges
    while (std::getline(std::cin, line)) {
        endPos = line.find_first_of(" ");
        startPos = 0;
        int vId = std::stoi(std::string(line, startPos, endPos - startPos));
        bool v1Phys = vId < K;

        graph->addVertex(vId, v1Phys);

        startPos = endPos + 5;

        endPos = line.find_first_of(" ", startPos);
        while ((endPos = line.find_first_of(" ", startPos)) != std::string::npos) {
            int v2Id = std::stoi(std::string(line, startPos, endPos - startPos));
            bool v2Phys = v2Id < K;

            graph->addVertex(v2Id, v2Phys);
            graph->addEdge(vId, v2Id);

            startPos = endPos + 1;
        }
        int v2Id = std::stoi(std::string(line, startPos, line.length() - startPos));
        bool v2Phys = v2Id < K;

        graph->addVertex(v2Id, v2Phys);
        graph->addEdge(vId, v2Id);
    }

    // Printing Graph info
    std::cout
        << "Graph " << graph->getId() << " -> Physical Registers: " << K << std::endl
        << "----------------------------------------" << std::endl;
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

int Regalloc::getK() {
    return K;
}

int Regalloc::getGraphNumber() {
    return graph->getId();
}

void Regalloc::simplify(int k) {
    while (!graph->isEmpty()) {
        Reg::Vertex *v = graph->getVertexToBeRemoved(k);
        graph->removeVertex(v->getId());

        currStash.push_back(v);

        bool potentialSpill = v->getDegree() >= k;

        std::cout << "Push: " << v->getId() << ((potentialSpill) ? " *" : "") << std::endl;
    }
}

bool Regalloc::assign(int k) {
    std::cout << "Assigning" << std::endl;

    return (k > 5);
}

void Regalloc::rebuild() {}
