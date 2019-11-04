#include "graph.hpp"
#include <iostream>
#include <climits>

Reg::Graph::Graph(int id) {
    this->id = id;
}

Reg::Graph::~Graph() {
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
    auto vertex = it->second;

    if (!vertex->isPhysical()) {
        this->size--;
    }

    vertices.erase(it);

    for (auto adjacent : vertex->getAdjacents()) {
        adjacent->subDegree();
    }
}

void Reg::Graph::addEdge(int id1, int id2) {
    Reg::Vertex *v1 = this->getVertexById(id1);
    Reg::Vertex *v2 = this->getVertexById(id2);
    v1->addAdjacent(v2);
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

        for (auto v2 : vertex->getAdjacents()) {
            file << "\t" << vertex->getId() << " -- " << v2->getId() << ";" << std::endl;
        }
    }


    file << "}" << std::endl;
}

Reg::Vertex *Reg::Graph::getVertexToBeRemoved(int k) {
    int minDegree = INT_MAX;
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

    for (auto adjacent : vertex->getAdjacents()) {
        adjacent->addDegree();
    }
}

std::vector<Reg::Vertex *> Reg::Graph::getAdjacents(int id) {
    Reg::Vertex *v = this->getVertexById(id);
    std::vector<Reg::Vertex *> adj = v->getAdjacents();
    std::vector<Reg::Vertex *> result;

    for (auto v2 : adj) {
        auto test = this->getVertexById(v2->getId());
        if (test != nullptr) {
            result.push_back(v2);
        }
    }

    return result;
}