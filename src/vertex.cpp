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

bool Reg::Vertex::operator ==(Reg::Vertex *other) {
    return this->id == other->id;
}
