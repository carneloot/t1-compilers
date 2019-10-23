#include "graph.hpp"
#include <iostream>

Reg::Graph::Graph(int id) {
    this->id = id;
}

Reg::Graph::~Graph() {}

void Reg::Graph::addVertex(int id) {
    if (vertices.find(id) == vertices.end()) {
        Reg::Vertex *vertex = new Reg::Vertex(id);
        vertices.insert({ id, vertex });
    }
}

void Reg::Graph::addEdge(int id1, int id2) {
    Reg::Edge *edge = new Reg::Edge(id1, id2);
    edges.push_back(edge);

    Reg::Vertex *v1 = this->getVertexById(id1);
    v1->addDegree();
}

Reg::Vertex *Reg::Graph::getVertexById(int id) {
    if (vertices.find(id) != vertices.end()) {
        return vertices.find(id)->second;
    }
    return nullptr;
}

void Reg::Graph::exportToDot(std::ofstream &file) {
    file << "strict graph {" << std::endl;

    for (auto it = vertices.begin(); it != vertices.end(); it++) {
        Reg::Vertex *vertex = (*it).second;
        file << "\t" << vertex->getId() << "[label=\"" << vertex->getId()
            << "\\n" << vertex->getColor()
            << "\\n" << vertex->getDegree()
            << "\"];" << std::endl;
    }

    for (auto edge : this->edges) {
        file << "\t" << edge->getV1() << " -- " << edge->getV2() << ";" << std::endl;
    }

    file << "}" << std::endl;
}
