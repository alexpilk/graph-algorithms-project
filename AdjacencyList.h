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
    struct Edge {
        int neighbor;
        int weight;

        Edge(int neighbor, int weight) {
            this->neighbor = neighbor;
            this->weight = weight;
        }
    };

    bool directed;
    vector<vector<Edge>> list;
public:
    explicit AdjacencyList(unsigned int size, bool directed);

    void addEdge(int v1, int v2, int weight) override;

    void print() override;
};


#endif //SDIZO_PROJECT_2_ADJACENCYLIST_H
