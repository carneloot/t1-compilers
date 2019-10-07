#include "edge.hpp"

Reg::Edge::Edge(int v1, int v2) : v1(v1), v2(v2) {
    
}

Reg::Edge::~Edge() {}

bool Reg::Edge::operator ==(Reg::Edge *other) {
    return this->v1 == other->v1 && this->v2 == other->v2;
}
