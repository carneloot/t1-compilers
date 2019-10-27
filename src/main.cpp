#include <iostream>
#include <iomanip>
#include <regalloc.hpp>

int main(int argc, char *argv[]) {
    Regalloc regalloc;

    regalloc.build();

    int K = regalloc.getK();

    bool gotRight[K - 2];
    for (int k = K; k >= 2; k--) {
        // Print current K info
        std::cout
            << "----------------------------------------" << std::endl
            << "K = " << k << std::endl
            << std::endl;

        regalloc.simplify(k);

        gotRight[k - 2] = regalloc.assign(k);

        regalloc.rebuild();
    }

    std::cout
        << "----------------------------------------" << std::endl
        << "----------------------------------------";

    int graphNumber = regalloc.getGraphNumber();

    for (int k = K; k >= 2; k--) {
        std::cout << std::endl
            << "Graph " << graphNumber << " -> K = " << std::right << std::setw(2) << k
            << ": " << ((gotRight[k - 2]) ? "Successful Allocation" : "SPILL");
    }

    return 0;
}
