#include "Hypercube.hpp"
#include "EdmondsKarp.hpp"

#include <iostream>

int main(int argc, char* argv[]) {
    Hypercube cube (atoi(argv[1]));
    // cube.printGraph();
    EdmondsKarp alg (cube);
    auto res = alg.run(0, cube.getVertices() - 1);
    std::cout << res.flow << "\n";
    return 0;
}