#pragma once

#include <string>
#include <vector>
#include <unordered_map>

class GenerateSolverCode {
public:
    GenerateSolverCode(const std::unordered_map<int, std::vector<std::pair<int, int>>>& graph,
    const std::string& filename, int source, int target);
};