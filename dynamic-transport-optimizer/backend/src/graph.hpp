#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <unordered_map>
#include <string>

struct Edge {
    int to;
    int time;
    std::string mode;
};

struct Node {
    int id;
    std::string name;
    std::string type;
    double lat, lon;
};

class Graph {
public:
    void addNode(Node node);
    void addEdge(int from, int to, int time, std::string mode);
    Node getNodeById(int id);
    std::vector<Node> getNodes();
    const std::unordered_map<int, std::vector<Edge>>& getAdjList();
private:
    std::unordered_map<int, Node> nodes;
    std::unordered_map<int, std::vector<Edge>> adjList;
};

#endif
