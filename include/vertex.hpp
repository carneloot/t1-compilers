#ifndef __VERTEX__
#define __VERTEX__

namespace Reg {

class Vertex {

public:
    /**
     * @brief Construtor padrão do vertice
     * 
     * @param id identificacao do vertice
     */
    Vertex(int id, bool physical);

    /**
     * @brief Destrutor padrão do vertice
     * 
     */
    ~Vertex();

    /**
     * @brief Pinta o vertice de uma certa cor
     * 
     * @param color cor a ser pintada
     */
    void paint(int color);

    /**
     * @brief Adiciona um grau para o vertice
     */
    void addDegree();

    /**
     * @brief Subtrai um grau do vertice
     */
    void subDegree();

    /**
     * @brief Retorna o id do vertice
     * 
     * @return int id do vertice
     */
    int getId();

    /**
     * @brief Retorna a cor do vertice
     * 
     * @return int cor do vertice. -1 caso não tenha cor ainda
     */
    int getColor();

    /**
     * @brief Retorna o grau do vertice
     * 
     * @return int grau do vertice
     */
    int getDegree();

    bool isPhysical();

private:
    /**
     * @brief Identificação do vertice
     */
    int id;

    /**
     * @brief Cor atual do vertice
     */
    int color = -1;

    /**
     * @brief Grau do vertice
     * 
     * Indica o numero de arestas ligadas a ele
     * 
     */
    int degree = 0;

    bool physical;
};

}

#endif
