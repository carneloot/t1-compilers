#include "graph.hpp"
#include <iostream>

Reg::Graph::Graph(int id) {
    this->id = id;
}

Reg::Graph::~Graph() {}

void Reg::Graph::addVertex(int id) {
    auto vertexFound = getVertexById(id);
    if (!vertexFound) {
        vertices.push_back(new Reg::Vertex(id));
    }
}

void Reg::Graph::addEdge(int id1, int id2) {
    edges.push_back(new Reg::Edge(id1, id2));
}

Reg::Vertex *Reg::Graph::getVertexById(int id) {
    for (auto it = vertices.begin(); it != vertices.end(); it++) {
        if ((*it)->getId() == id) {
            return *it;
        }
    }
    return nullptr;
}

void Reg::Graph::exportToDot(std::ofstream &file) {
    file << "strict graph {" << std::endl;

    for (auto vertex : this->vertices) {
        file << vertex->getId() << "[label=\""
            << vertex->getId() << "\n" << vertex->getColor()
            << "\"];" << std::endl;
    }

    for (auto edge : this->edges) {
        file << edge->getV1() << " -- " << edge->getV2() << ";" << std::endl;
    }

    file << "}" << std::endl;
}
