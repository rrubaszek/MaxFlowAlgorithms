#pragma once

#include <cstddef>
#include <vector>
#include <unordered_map>

class Hypercube {
private:
    int dimension;
    size_t vertices;
    std::unordered_map<int, std::vector<std::pair<int, int>>> graph;

    int hammingWeight(int n);
    int countZeroes(int n);
    int countWeight(int i, int j);
public:
    Hypercube(size_t dimension);
    void printGraph();
    std::unordered_map<int, std::vector<std::pair<int, int>>> getGraph();
    size_t getVertices();
};