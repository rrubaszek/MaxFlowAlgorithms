#include "Hypercube.hpp"

#include <algorithm>
#include <cstddef>
#include <bitset>
#include <iostream>
#include <random>

Hypercube::Hypercube(size_t dimension) {
    this->dimension = dimension;
    this->vertices = 1 << dimension;

    for (size_t i = 0; i < vertices; ++i) {
        std::bitset<32> x(i);
        for (size_t j = 0; j < dimension; ++j) {
            size_t neighbour = i ^ (1 << j);
            if (i < neighbour) { // Directed graph
                graph[i].emplace_back(neighbour, countWeight(i, neighbour));
            }
        }
    }

    graph[vertices - 1] = std::vector<std::pair<int, int>>();
}

int Hypercube::hammingWeight(int n) {
    return std::bitset<32>(n).count();
}

int Hypercube::countZeroes(int n) {
    int zeroes = std::bitset<32>(n).flip().count();
    return zeroes - 32 + dimension;
}

int Hypercube::countWeight(int i, int j) {
    int h_i = hammingWeight(i);
    int h_j = hammingWeight(j);
    int z_i = countZeroes(i);
    int z_j = countZeroes(j);

    int l = std::max( {h_i, h_j, z_i, z_j} );
    int weight = 1 << l;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, weight);

    return dist(gen);
}

void Hypercube::printGraph() {
    std::cout << "Hypercube graph (adjacency list representation):\n";

    for (const auto& [vertex, neighbors] : graph) {
        std::cout << vertex << " (";
        std::bitset<32> vertexBits(vertex);
        std::cout << vertexBits.to_string().substr(32 - dimension) << "): ";
        for (const auto& [neighbor, weight] : neighbors) {
            std::cout << neighbor << " ";
        }
        std::cout << "\n";
    }
}

std::unordered_map<int, std::vector<std::pair<int, int>>> Hypercube::getGraph() {
    return graph;
}

size_t Hypercube::getVertices() {
    return vertices;
}