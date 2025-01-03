#pragma once

#include <cstddef>
#include <vector>
#include <unordered_map>

class Hypercube {
private:
    std::unordered_map<int, std::vector<std::pair<int, int>>> graph;
    int dimension;

    int hammingWeight(int n);
    int countZeroes(int n);
    int countWeight(int i, int j);
public:
    Hypercube(size_t dimension);
    void printGraph();
};