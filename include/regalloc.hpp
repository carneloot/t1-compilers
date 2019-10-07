#include "graph.hpp"

class Regalloc {
public:
    Regalloc();
    virtual void readInput();

private:
    /**
     * @brief Valor do K a ser testado
     */
    int k;

    /**
     * @brief Grafo de teste
     */
    Reg::Graph *graph;
};
