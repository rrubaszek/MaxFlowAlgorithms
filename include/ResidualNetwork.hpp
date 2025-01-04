#pragma once

#include <vector>
#include <unordered_map>

struct ResidualNetwork {
    std::unordered_map<int, std::vector<int>> vertices;
    std::unordered_map<int, std::unordered_map<int, int>> capacity;
    std::unordered_map<int, std::unordered_map<int, int>> edge_flow; 
};