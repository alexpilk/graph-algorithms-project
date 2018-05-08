//
// Created by Drasik on 5/9/2018.
//

#ifndef SDIZO_PROJECT_2_DIJKSTRA_H
#define SDIZO_PROJECT_2_DIJKSTRA_H

#include <vector>
#include <limits>
#include "Graph.h"

using namespace std;

class Dijkstra {
private:
    int INF = numeric_limits<int>::max();
    Graph* graph;
    vector<bool> completed;
    vector<int> distances;

    int getMinVertex();

public:
    explicit Dijkstra(Graph* graph);

    vector<int> findShortestPaths(int start_vertex);
};


#endif //SDIZO_PROJECT_2_DIJKSTRA_H
