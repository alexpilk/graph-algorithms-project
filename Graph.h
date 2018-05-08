//
// Created by Drasik on 5/8/2018.
//

#ifndef SDIZO_PROJECT_2_GRAPH_H
#define SDIZO_PROJECT_2_GRAPH_H

#include <vector>

using namespace std;

class Graph {
protected:
    unsigned int size;
public:
    struct Edge {
        int neighbor;
        int weight;

        Edge(int neighbor, int weight) {
            this->neighbor = neighbor;
            this->weight = weight;
        }
    };

    virtual void addEdge(int v1, int v2, int weight) = 0;
    virtual vector<Edge> getEdges(int vertex) = 0;
    virtual void print() = 0;
    unsigned int getSize() {
        return size;
    }
};


#endif //SDIZO_PROJECT_2_GRAPH_H
