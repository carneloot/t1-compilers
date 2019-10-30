#include "graph.hpp"
#include <vector>
#include "vertex.hpp"

class Regalloc {
public:

    /**
     * @brief Construtor padrão do Regalloc
     */
    Regalloc();

    /**
     * @brief Destrutor padrão do Regalloc
     */
    ~Regalloc();

    /**
     * @brief Le a entrada específica do professor
     */
    void build();

    void rebuild();

    void simplify(int k);

    bool assign(int k);

    /**
     * @brief Exporta o grafo para um arquivo .dot.
     * 
     * @param filepath caminho para o arquivo a ser guardado
     */
    void exportToDot(const std::string filepath);

    /**
     * @brief Retorna o valor de K
     */
    int getK();

    int getGraphNumber();

private:
    /**
     * @brief Valor do K a ser testado
     */
    int K;

    /**
     * @brief Grafo de teste
     */
    Reg::Graph *graph;

    std::vector<Reg::Vertex *> currStack;
};
