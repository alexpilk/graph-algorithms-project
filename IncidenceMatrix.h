//
// Created by Drasik on 5/7/2018.
//

#ifndef SDIZO_PROJECT_2_INCIDENCEMATRIX_H
#define SDIZO_PROJECT_2_INCIDENCEMATRIX_H

#include <vector>
#include "Graph.h"

using namespace std;

class IncidenceMatrix : public Graph {
    using Graph::Graph;
private:
    vector<vector<int>> matrix;
    vector<int> weights;

    vector<int> createEdge(int v1, int v2);

public:
    explicit IncidenceMatrix(int size, bool directed);

    void addEdge(int v1, int v2, int weight) override;

    void deleteRandomEdge() override;

    void deleteEdge(int edge_index);

    vector<Edge> getAdjacentEdges(int vertex) override;

    vector<Edge> getAllEdges() override;

    void print() override;
};


#endif //SDIZO_PROJECT_2_INCIDENCEMATRIX_H
