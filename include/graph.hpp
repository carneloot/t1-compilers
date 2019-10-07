#ifndef __GRAPH__
#define __GRAPH__

#include <list>
#include <utility>
#include "vertex.hpp"
#include "edge.hpp"

namespace Reg {

class Graph {

public:
    /**
     * @brief Construtor padrao do grafo
     * 
     * @param id id do grafo
     */
    Graph(int id);

    /**
     * @brief Destrutor padrão
     */
    ~Graph();
    
    /**
     * @brief Adiciona um vertice ao grafo
     * 
     * @param id vertice a ser adicionado
     */
    void addVertex(int id);

    /**
     * @brief Adiciona uma aresta no grafo
     * 
     * @param v1 vertice um
     * @param v2 vertice dois
     */
    void addEdge(int v1, int v2);

    /**
     * @brief Remove elementos repetidos das listas
     */
    void clearLists();

private:
    /**
     * @brief Vertices
     */
    std::list<Reg::Vertex *> vertices;

    /**
     * @brief Arestas
     */
    std::list<Reg::Edge *> edges;

    /**
     * @brief Identificação do grafo
     */
    int id;
};

}

#endif
