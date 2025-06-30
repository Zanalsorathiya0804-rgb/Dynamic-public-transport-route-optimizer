#include "graph.hpp"
#include "dijkstra.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

int main() {
    Graph graph;
    std::ifstream nodesFile("../data/nodes.csv"), edgesFile("../data/edges.csv");
    std::string line;

    getline(nodesFile, line);
    while (getline(nodesFile, line)) {
        std::stringstream ss(line);
        Node node;
        std::string temp;
        getline(ss, temp, ','); node.id = stoi(temp);
        getline(ss, node.name, ',');
        getline(ss, node.type, ',');
        getline(ss, temp, ','); node.lat = stod(temp);
        getline(ss, temp, ','); node.lon = stod(temp);
        graph.addNode(node);
    }

    getline(edgesFile, line);
    while (getline(edgesFile, line)) {
        std::stringstream ss(line);
        int from, to, time;
        std::string mode, temp;
        getline(ss, temp, ','); from = stoi(temp);
        getline(ss, temp, ','); to = stoi(temp);
        getline(ss, mode, ',');
        getline(ss, temp, ','); time = stoi(temp);
        graph.addEdge(from, to, time, mode);
    }

    auto [path, total_time] = dijkstra(graph, 1, 3);
    saveRouteAsJSON(graph, path, total_time);
    std::cout << "Saved route to routes_output.json\n";
}
