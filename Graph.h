//
// Created by Drasik on 5/8/2018.
//

#ifndef SDIZO_PROJECT_2_GRAPH_H
#define SDIZO_PROJECT_2_GRAPH_H

#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

class Graph {
protected:
    int size;
    bool directed;
public:
    struct Edge {
        int vertex;
        int neighbor;
        int weight;

        Edge() = default;

        Edge(int vertex, int neighbor, int weight) {
            this->vertex = vertex;
            this->neighbor = neighbor;
            this->weight = weight;
        }

        bool operator<(const Edge &edge) const {
            return (weight < edge.weight);
        }

        bool operator==(const Edge &edge) const {
            return (vertex == edge.vertex && neighbor == edge.neighbor) ||
                   (vertex == edge.neighbor && neighbor == edge.vertex);
        }

        void print() {
            cout << vertex << " - " << neighbor << " (weight " << weight << ")" << endl;
        }
    };

    void fillWithRandomEdges();

    void fillWithRandomEdges(double density);

    virtual void addEdge(int v1, int v2, int weight) = 0;

    virtual void deleteRandomEdge() = 0;

    virtual vector<Edge> getAdjacentEdges(int vertex) = 0;

    virtual vector<Edge> getAllEdges() = 0;

    virtual void print() = 0;

    unsigned int getSize() {
        return size;
    }
};


#endif //SDIZO_PROJECT_2_GRAPH_H
