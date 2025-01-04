#include "Hypercube.hpp"
#include "EdmondsKarp.hpp"

#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 1 || std::string(argv[1]) != "--size") {
        std::cerr << "Size not provided. Usage: --size {value}\n";
    }
    else {
        Hypercube cube (atoi(argv[2]));
        EdmondsKarp alg (cube);
        auto res = alg.run(0, cube.getVertices() - 1);

        std::cout << res.flow << "\n";

        if (argc > 3 && std::string(argv[3]) == "--printFlow") {
            for (const auto& [u, list] : res.edge_flow) {
                for (const auto& [v, flow] : list) {
                    if (flow > 0) {
                        std::cout << u << " -> " << v << " : " << flow << "\n";
                    }
                }
            }
        }
    }

    return 0;
}