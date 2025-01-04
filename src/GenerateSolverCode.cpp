#include "GenerateSolverCode.hpp"

#include <fstream>

GenerateSolverCode::GenerateSolverCode(const std::unordered_map<int, std::vector<std::pair<int, int>>>& graph, 
                                const std::string& filename,
                                int source, int target) {

    std::ofstream myFile(filename);

    myFile << "using JuMP, GLPK\n";
    myFile << "model = Model(GLPK.Optimizer)\n\n";

    myFile << "edges = [\n";
    for (const auto& [u, neighbours] : graph) {
        for (const auto& [v, weight] : neighbours) {
            myFile << "    (" << u << ", " << v << "),\n";
        }
    }
    myFile << "]\n";

    myFile << "capacities = Dict(\n";
    for (const auto& [u, neighbours] : graph) {
        for (const auto& [v, weight] : neighbours) {
            myFile << "    (" << u << ", " << v << ") => " << weight << ",\n";
        }
    }
    myFile << ")\n\n";

    myFile << "source = " << source << "\n";
    myFile << "target = " << target << "\n\n";

    myFile << "@variable(model, flow[e in edges] >= 0)\n\n";

    myFile << "@constraint(model, [e in edges], flow[e] <= capacities[e])\n\n";

    myFile << "for v in 0:" << target << "\n";
    myFile << "    if v != source && v != target\n";
    myFile << "        @constraint(model, sum(flow[(u, v)] for u in 0:" << target << " if (u, v) in edges) == sum(flow[(v, u)] for u in 0:" << target << " if (v, u) in edges))\n";
    myFile << "    end\n";
    myFile << "end\n\n";

    myFile << "@objective(model, Max, sum(flow[(source, v)] for v in 0:" << target << " if (source, v) in edges))\n\n";

    myFile << "optimize!(model)\n\n";

    myFile << "println(\"Maximum flow: \", objective_value(model))\n";
    myFile << "for e in edges\n";
    myFile << "    println(\"Flow on edge \", e, \": \", value(flow[e]))\n";
    myFile << "end\n";

    myFile.close();
}