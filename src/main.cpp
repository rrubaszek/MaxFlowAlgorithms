#include "Hypercube.hpp"
#include "EdmondsKarp.hpp"
#include "GenerateSolverCode.hpp"

#include <iostream>
#include <string>
#include <unordered_map>

int main(int argc, char* argv[]) {
    std::unordered_map<std::string, std::string> args;

    for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]) == "--printFlow") {
            args[argv[i]] = "";
        }
        else {  
            args[argv[i]] = argv[i + 1];
            i++;
        }
    }
    if (args.count("--size")) {
        Hypercube cube (stoi(args.at("--size")));
        EdmondsKarp alg (cube);
        auto res = alg.run(0, cube.getVertices() - 1);
        std::cout << res.flow << "\n";

        if (args.count("--printFlow")) {
            for (const auto& [u, list] : res.edge_flow) {
                for (const auto& [v, flow] : list) {
                    if (flow > 0) {
                        std::cout << u << " -> " << v << " : " << flow << "\n";
                    }
                }
            }
        }

        if (args.count("--glpk")) {
            std::string filename = args.at("--glpk");
            GenerateSolverCode(cube.getGraph(), filename, 0, cube.getVertices() - 1);
        }
    }
    else {
        std::cerr << "Size not provided. Usage: --size {val}\n";
    }


    return 0;
}