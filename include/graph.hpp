#ifndef __GRAPH__
#define __GRAPH__

#include <vector>
#include <map>
#include <fstream>
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
     * @brief Exporta o grafo no formato graphviz
     * 
     * @param file arquivo para qual será gravada as informações
     */
    void exportToDot(std::ofstream &file);

    /**
     * @brief Pega o vertice por um id
     * 
     * @param id id a ser pesquisado
     * @return Reg::Vertex* o vertice encontrado. Caso não encontre, retorna nullptr
     */
    Reg::Vertex *getVertexById(int id);

private:
    /**
     * @brief Vertices
     */
    std::map<int, Reg::Vertex *> vertices;

    /**
     * @brief Arestas
     */
    std::vector<Reg::Edge *> edges;

    /**
     * @brief Identificação do grafo
     */
    int id;
};

}

#endif
