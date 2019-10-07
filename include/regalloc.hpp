#include "graph.hpp"

class Regalloc {
public:

    /**
     * @brief Construtor padrão do Regalloc
     */
    Regalloc();

    /**
     * @brief Le a entrada específica do professor
     */
    void readInput();

    /**
     * @brief Exporta o grafo para um arquivo .dot.
     * 
     * @param filepath caminho para o arquivo a ser guardado
     */
    void exportToDot(const std::string filepath);

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
