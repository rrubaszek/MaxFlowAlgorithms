#include "EdmondsKarp.hpp"

#include <queue>
#include <limits>
#include <iostream>

EdmondsKarp::EdmondsKarp(Hypercube& graph) {
    this->size = graph.getVertices();
    auto m_graph = graph.getGraph();
    
    for (const auto& [u, edges] : m_graph) {
        for (const auto& [v, weight] : edges) {
            residual.vertices[u].push_back(v);
            residual.capacity[u][v] = weight;
        }
    }

    std::cout << "SIZE " << size << "\n";
}

int EdmondsKarp::bfs(int s, int t, std::vector<int>& parent) {
    std::queue<std::pair<int, int>> q;
    std::vector<bool> visited (size, false);

    q.push({ s, std::numeric_limits<int>::max() });
    visited.at(s) = true;

    while (!q.empty()) {
        int v = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int u : residual.vertices[v]) {
            if (!visited.at(u) && residual.capacity[v][u] > 0) {
                visited.at(u) = true;
                parent.at(u) = v;
                int new_flow = std::min(flow, residual.capacity[v][u]);

                if (u == t) {
                    return new_flow;
                }
                q.push({ u, new_flow });
            }
        }
    }

    return 0;
}

EdmondsKarp::Path EdmondsKarp::run(int source, int target) {
    int flow = 0;
    int new_flow;
    std::vector<int> parent (size, -1);
    
    do {
        new_flow = bfs(source, target, parent);
        flow += new_flow;
        int v = target;
        while (v != source) {
            int u = parent[v];
            residual.capacity[u][v] -= new_flow;
            residual.capacity[v][u] += new_flow;

            residual.edge_flow[u][v] += new_flow;
            residual.edge_flow[v][u] -= new_flow;

            v = u;
        }
    } while (new_flow > 0);

    return { flow, residual.edge_flow };
}