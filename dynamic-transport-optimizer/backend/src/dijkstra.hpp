#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP
#include "graph.hpp"
#include <vector>
#include <utility>
std::pair<std::vector<int>, int> dijkstra(Graph& graph, int source, int target);
void saveRouteAsJSON(Graph& graph, std::vector<int> path, int total_time);

#endif
