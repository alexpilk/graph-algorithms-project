//
// Created by Drasik on 5/7/2018.
//

#ifndef SDIZO_PROJECT_2_ADJACENCYLIST_H
#define SDIZO_PROJECT_2_ADJACENCYLIST_H

#include <vector>
#include "Graph.h"

using namespace std;

class AdjacencyList : public Graph {
private:

    bool directed;
    vector<vector<Edge>> list;
public:
    explicit AdjacencyList(unsigned int size, bool directed);

    void addEdge(int v1, int v2, int weight) override;

    vector<Edge> getEdges(int vertex) override;

    vector<int> dijkstraShortestPath(int start_vertex) override;

    void print() override;
};

#endif //SDIZO_PROJECT_2_ADJACENCYLIST_H
