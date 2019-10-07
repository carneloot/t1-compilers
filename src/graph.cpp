#include "graph.hpp"

Reg::Graph::Graph(int id) : id(id) {
}

Reg::Graph::~Graph() {}

void Reg::Graph::addVertex(int id) {
    this->vertices.push_back(new Reg::Vertex(id));
}

void Reg::Graph::addEdge(int id1, int id2) {
    this->edges.push_back(new Reg::Edge(id1, id2));
}

void Reg::Graph::clearLists() {
    this->edges.unique();
    this->vertices.unique();
}
