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

        currStack.push_back(v);

        bool potentialSpill = v->getDegree() >= k;

        std::cout << "Push: " << v->getId() << ((potentialSpill) ? " *" : "") << std::endl;
    }
}

bool Regalloc::assign(int k) {
    bool colors[K];
    while (!currStack.empty()) {
        for (int i = 0; i < k; i++) colors[i] = true;

        Reg::Vertex *vertex = currStack.back();
        currStack.pop_back();

        graph->readdVertex(vertex);
        std::vector<Reg::Vertex *> adjacentVertex = graph->getAdjacents(vertex->getId());

        // Check the available colors
        for (auto v2 : adjacentVertex) {
            int color = v2->getColor();
            if (color >= 0) {
                colors[color] = false;
            }
        }

        // Tries to use the first available color
        int i;
        for (i = 0; i < k; i++) {
            if (colors[i]) {
                vertex->paint(i);
                std::cout << "Pop: " << vertex->getId() << " -> " << i << std::endl;
                break;
            }
        }

        // If no colors are available, SPILL
        if (i == k) {
            std::cout << "Pop: " << vertex->getId() << " -> NO COLOR AVAILABLE" << std::endl;
            return false;
        }
    }

    return true;
}

void Regalloc::rebuild() {
    while (!currStack.empty()) {
        Reg::Vertex *vertex = currStack.back();
        currStack.pop_back();

        graph->readdVertex(vertex);
    }
}
