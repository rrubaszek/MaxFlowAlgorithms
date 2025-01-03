#pragma once

#include <vector>
#include <unordered_map>

class Hypercube {
private:
    std::unordered_map<int, std::vector<std::pair<int, int>>> graph;
public:
    Hypercube(int dimension);
};