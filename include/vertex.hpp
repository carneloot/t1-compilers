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
    Vertex(int id);

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
     * @brief Compara dois vertices
     * 
     * @param other outro vertice a ser comparado
     * @return true se forem iguais
     * @return false se forem diferentes
     */
    bool operator ==(Reg::Vertex *other);

private:
    /**
     * @brief Identificação do vertice
     */
    int id;

    /**
     * @brief Cor atual do vertice
     */
    int color = -1;
};

}

#endif
