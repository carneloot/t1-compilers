#include "vertex.hpp"

Reg::Vertex::Vertex(int id, bool physical) : id(id), physical(physical) {
    if (physical) {
        color = id;
    }
}

Reg::Vertex::~Vertex() {}

void Reg::Vertex::paint(int color) {
    if (color >= 0) {
        this->color = color;
    }
}

int Reg::Vertex::getId() {
    return this->id;
}

int Reg::Vertex::getColor() {
    return this->color;
}

int Reg::Vertex::getDegree() {
    return this->degree;
}

void Reg::Vertex::addDegree() {
    this->degree++;
}

void Reg::Vertex::subDegree() {
    this->degree--;
}

bool Reg::Vertex::isPhysical() {
    return this->physical;
}

void Reg::Vertex::addAdjacent(Reg::Vertex *adjacent) {
    this->adjacents.push_back(adjacent);
}

std::vector<Reg::Vertex *> Reg::Vertex::getAdjacents() {
    return this->adjacents;
}