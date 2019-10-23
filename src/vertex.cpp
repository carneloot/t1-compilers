#include "vertex.hpp"

Reg::Vertex::Vertex(int id) : id(id) {}

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
