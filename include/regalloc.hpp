#include "graph.hpp"

class Regalloc {
public:
    Regalloc();
    virtual void readInput();

private:
    int k;
    Graph *graph;
};
