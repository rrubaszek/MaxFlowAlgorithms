#pragma once

#include "Hypercube.hpp"

class EdmondsKarp {
private:
    size_t size;
    struct Path
    {
        int flow;
        std::vector<int> path;
    };

    std::unordered_map<int, std::vector<std::pair<int, int>>> residual;
    bool bfs(int s, int t, std::vector<int>& parent);
    
public:
    EdmondsKarp(Hypercube& graph);
    Path run(int source, int target);
};