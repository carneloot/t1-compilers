#ifndef __EDGE__
#define __EDGE__

#include "vertex.hpp"

namespace Reg {

class Edge {

public:
    /**
     * @brief Construtor da aresta
     * 
     * @param a vertice 1
     * @param b vertice 2
     */
    Edge(int a, int b);

    /**
     * @brief Destrutor padrão da aresta
     */
    ~Edge();

    /**
     * @brief Compara duas arestas
     * 
     * @param other outra aresta a ser comparada
     * @return true se forem iguais
     * @return false de forem diferentes
     */
    bool operator ==(Reg::Edge *other);

private:
    /**
     * @brief Vertices que estão ligados com essa aresta
     */
    int v1, v2;

};

}

#endif
