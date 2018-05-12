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
    vector<vector<Edge>> list;
public:
    explicit AdjacencyList(unsigned int size, bool directed);

    void deleteRandomEdge() override;

    void deleteEdge(int vertex, int edge_index);

    void addEdge(int v1, int v2, int weight) override;

    vector<Edge> getAdjacentEdges(int vertex) override;

    vector<Edge> getAllEdges() override;

    vector<int> dijkstraShortestPath(int start_vertex) override;

    void print() override;
};

#endif //SDIZO_PROJECT_2_ADJACENCYLIST_H
