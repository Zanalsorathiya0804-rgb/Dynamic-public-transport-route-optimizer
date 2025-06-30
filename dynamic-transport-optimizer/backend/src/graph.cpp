#include "graph.hpp"

void Graph::addNode(Node node) {
    nodes[node.id] = node;
}

void Graph::addEdge(int from, int to, int time, std::string mode) {
    adjList[from].push_back({to, time, mode});
}

Node Graph::getNodeById(int id) {
    return nodes[id];
}

std::vector<Node> Graph::getNodes() {
    std::vector<Node> all;
    for (auto& [id, node] : nodes) all.push_back(node);
    return all;
}

const std::unordered_map<int, std::vector<Edge>>& Graph::getAdjList() {
    return adjList;
}
