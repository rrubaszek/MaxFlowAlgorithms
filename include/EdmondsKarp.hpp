#pragma once

#include "Hypercube.hpp"
#include "ResidualNetwork.hpp"

class EdmondsKarp {
private:
    size_t size;
    struct Path {
        int flow;
        std::unordered_map<int, std::unordered_map<int, int>> edge_flow;
    };

    ResidualNetwork residual;
    int bfs(int s, int t, std::vector<int>& parent);
    
public:
    EdmondsKarp(Hypercube& graph);
    Path run(int source, int target);
};