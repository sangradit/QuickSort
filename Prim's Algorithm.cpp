#include <iostream>
#include <vector>
#include <queue>
#include <utility>

int spanningTree(int V, const std::vector<std::vector<int>>& edges) {
    std::vector<std::vector<std::pair<int, int>>> adj(V);

    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        adj[u].push_back({wt, v});
        adj[v].push_back({wt, u});
    }

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    std::vector<bool> visited(V, false);

    int res = 0;

    pq.push({0, 0});

    while (!pq.empty()) {
        int wt = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) {
            continue;
        }

        visited[u] = true;
        res += wt;

        for (const auto& neighbor_pair : adj[u]) {
            int edge_wt = neighbor_pair.first;
            int v = neighbor_pair.second;

            pq.push({edge_wt, v});
        }
    }
    
    return res;
}

int main() {
    std::vector<std::vector<int>> edges1 = {
        {0, 1, 5},
        {1, 2, 3},
        {0, 2, 1}
    };
    int V1 = 3;
    int mst_weight1 = spanningTree(V1, edges1);
    std::cout << "Bobot MST untuk Graf 1: " << mst_weight1 << std::endl;

    std::vector<std::vector<int>> edges2 = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    int V2 = 4;
    int mst_weight2 = spanningTree(V2, edges2);
    std::cout << "Bobot MST untuk Graf 2: " << mst_weight2 << std::endl;

    return 0;
}
