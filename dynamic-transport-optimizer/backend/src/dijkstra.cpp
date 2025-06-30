#include "dijkstra.hpp"
#include "graph.hpp"
#include "json.hpp"
#include <fstream>
#include <queue>
#include <climits>
#include <algorithm>

using json = nlohmann::json;

std::pair<std::vector<int>, int> dijkstra(Graph& graph, int source, int target) {
    std::unordered_map<int, int> dist, parent;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int,int>>, std::greater<>> pq;

    for (auto node : graph.getNodes()) dist[node.id] = INT_MAX;
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        for (auto edge : graph.getAdjList().at(u)) {
            if (dist[u] + edge.time < dist[edge.to]) {
                dist[edge.to] = dist[u] + edge.time;
                parent[edge.to] = u;
                pq.push({dist[edge.to], edge.to});
            }
        }
    }

    std::vector<int> path;
    for (int v = target; v != source; v = parent[v]) path.push_back(v);
    path.push_back(source);
    std::reverse(path.begin(), path.end());
    return {path, dist[target]};
}

void saveRouteAsJSON(Graph& graph, std::vector<int> path, int total_time) {
    json j;
    j["total_time"] = total_time;
    for (int id : path) {
        auto node = graph.getNodeById(id);
        j["route"].push_back({{"id", node.id}, {"name", node.name}, {"type", node.type},
                              {"lat", node.lat}, {"lon", node.lon}});
    }
    std::ofstream o("../../routes_output.json");
    o << j.dump(4);
}
