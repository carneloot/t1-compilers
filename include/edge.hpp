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
     * @brief Retorna o vertice 1
     * 
     * @return int id do vertice 1
     */
    int getV1();

    /**
     * @brief Retorna o vertice 2
     * 
     * @return int id do vertice 2
     */
    int getV2();

private:
    /**
     * @brief Vertices que estão ligados com essa aresta
     */
    int v1, v2;

};

}

#endif
