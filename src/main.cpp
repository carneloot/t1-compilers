#include <iostream>
#include <regalloc.hpp>

int main(int argc, char *argv[]) {
    Regalloc regalloc;

    regalloc.readInput();

    regalloc.exportToDot("./grafo.dot");

    return 0;
}
