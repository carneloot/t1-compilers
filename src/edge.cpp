#include "edge.hpp"

Reg::Edge::Edge(int v1, int v2) : v1(v1), v2(v2) {}

Reg::Edge::~Edge() {}

int Reg::Edge::getV1() {
    return v1;
}

int Reg::Edge::getV2() {
    return v2;
}