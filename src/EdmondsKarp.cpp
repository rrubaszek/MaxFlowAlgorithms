#include "EdmondsKarp.hpp"

#include <queue>
#include <limits>
#include <iostream>

EdmondsKarp::EdmondsKarp(Hypercube& graph) {
    residual = graph.getGraph();
    size = residual.size();
    for (const auto& [u, list] : graph.getGraph()) {
        for (const auto& [v, weight] : list) {
            residual[v].emplace_back(u, weight);
        }
    }
}

bool EdmondsKarp::bfs(int s, int t, std::vector<int>& parent) {
    std::queue<int> q;
    std::vector<bool> visited (size, false);

    q.push(s);
    visited.at(s) = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (const auto& [u, weight] : residual[v]) {
            if (!visited.at(u) && weight > 0) {
                q.push(u);
                visited.at(u) = true;
                parent.at(u) = v;

                if (u == t) return true;
            }
        }
    }

    return false;
}

EdmondsKarp::Path EdmondsKarp::run(int source, int target) {
    int flow = 0;
    std::vector<int> path (size, -1);
    
    while (bfs(source, target, path)) {
        int path_flow = std::numeric_limits<int>::max();

        for (int t = target; t != source; t = path.at(t)) {
            int u = path.at(t);
            // Find the edge capacity in the residual graph
            for (const auto& [v, weight] : residual[u]) {
                if (v == t) {
                    path_flow = std::min(path_flow, weight);
                    break;
                }
            }
        }

        for (int t = target; t != source; t = path.at(t)) {
            int u = path.at(t);
            // Update the forward edge in the residual graph
            for (auto& [v, weight] : residual[u]) {
                if (v == t) {
                    weight -= path_flow; // Reduce the capacity on the forward edge
                    break;
                }
            }

            bool reverseEdgeFound = false;
            for (auto& [v, weight] : residual[t]) {
                if (v == u) {
                    weight += path_flow; // Increase the capacity on the reverse edge
                    reverseEdgeFound = true;
                    break;
                }
            }

            // If reverse edge does not exist, add a new one with the flow
            if (!reverseEdgeFound) {
                residual[t].emplace_back(u, path_flow); // Add reverse edge with pathFlow
            }
        }
        flow += path_flow;
        std::cout << flow << "\n";
    }

    return { flow, path };
}