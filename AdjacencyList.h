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

    struct DijkstraVertex {
        int vertex;
        int cost;

        DijkstraVertex(int vertex, int cost) {
            this->vertex = vertex;
            this->cost = cost;
        }
    };

    bool directed;
    vector<vector<Edge>> list;
public:
    explicit AdjacencyList(unsigned int size, bool directed);

    void addEdge(int v1, int v2, int weight) override;

    vector<Edge> getEdges(int vertex) override;

    vector<int> dijkstraShortestPath(int start_vertex);

    int getMinVertex(vector<int> distances, vector<bool> completed);

    void print() override;
};

#endif //SDIZO_PROJECT_2_ADJACENCYLIST_H
