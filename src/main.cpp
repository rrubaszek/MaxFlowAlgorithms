#include "Hypercube.hpp"

#include <iostream>

int main(int argc, char* argv[]) {
    Hypercube cube (atoi(argv[1]));
    cube.printGraph();
    return 0;
}