#include "graph.hpp"
#include <iostream>

Reg::Graph::Graph(int id) {
    this->id = id;
}

Reg::Graph::~Graph() {
    for (auto it = edges.begin(); it != edges.end(); it++) {
        delete (*it);
    }

    for (auto it = vertices.begin(); it != vertices.end(); it++) {
        delete (*it).second;
    }
}

void Reg::Graph::addVertex(int id, bool physical) {
    if (vertices.find(id) == vertices.end()) {
        Reg::Vertex *vertex = new Reg::Vertex(id, physical);
        vertices.insert({ id, vertex });

        if (!physical) {
            this->size++;
        }
    }
}

void Reg::Graph::removeVertex(int id) {
    auto it = vertices.find(id);

    if (!it->second->isPhysical()) {
        this->size--;
    }

    vertices.erase(it);

    for (auto edge : edges) {
        if (edge->getV2() == id) {
            auto v1 = this->getVertexById(edge->getV1());
            if (v1)
                v1->subDegree();
        }
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

Reg::Vertex *Reg::Graph::getVertexToBeRemoved(int k) {
    int minDegree = edges.size() + 1;
    Reg::Vertex *minVertex;

    for (auto it = vertices.begin(); it != vertices.end(); it++) {
        Reg::Vertex *vertex = it->second;
        if (vertex->isPhysical()) continue;

        int currDegree = vertex->getDegree();

        // If the degree is smaller
        if (currDegree < minDegree) {
            minDegree = currDegree;
            minVertex = vertex;
        } else
        
        // Else if the degree is the same
        if (currDegree == minDegree) {
            if (vertex->getId() < minVertex->getId()) {
                minVertex = vertex;
            }
        }
    }

    if (minVertex->getDegree() < k) {
        return minVertex;
    }

    // Potential spill

    Reg::Vertex *maxVertex = vertices.begin()->second;

    for (auto it = vertices.begin(); it != vertices.end(); it++) {
        Reg::Vertex *vertex = it->second;
        if (vertex->isPhysical()) continue;

        int currDegree = vertex->getDegree();

        if (currDegree > maxVertex->getDegree()) {
            maxVertex = vertex;
        } else if (currDegree == maxVertex->getDegree()) {
            if (vertex->getId() < maxVertex->getId()) {
                maxVertex = vertex;
            }
        }
    }

    return maxVertex;
}

int Reg::Graph::getId() {
    return id;
}

bool Reg::Graph::isEmpty() {
    return this->size == 0;
}

void Reg::Graph::readdVertex(Reg::Vertex *vertex) {
    int id = vertex->getId();
    if (vertices.find(id) == vertices.end()) {
        vertices.insert({ id, vertex });
        this->size++;
    }

    for (auto edge : edges) {
        if (edge->getV2() == id) {
            auto v1 = this->getVertexById(edge->getV1());
            if (v1)
                v1->addDegree();
        }
    }
}

std::vector<Reg::Edge *> Reg::Graph::getEdges(int id) {
    std::vector<Reg::Edge *> adjacentEdges;

    for (auto edge : edges) {
        if (edge->getV1() == id) {
            adjacentEdges.push_back(edge);
        }
    }

    return adjacentEdges;
}