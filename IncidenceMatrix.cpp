//
// Created by Drasik on 5/7/2018.
//

#include "IncidenceMatrix.h"
#include <iostream>
using namespace std;


IncidenceMatrix::IncidenceMatrix(unsigned int size, bool directed) {
    this->directed = directed;
    this->size = size;
}

void IncidenceMatrix::addEdge(int v1, int v2, int weight) {
    vector<int> edge;
    edge.resize(size);
    fill(edge.begin(), edge.end(), 0);
    if(v1 == v2)
        edge[v1] = 2;
    else {
        edge[v1] = 1;
        edge[v2] = directed ? -1 : 1;
    }
    matrix.emplace_back(edge);
    weights.emplace_back(weight);
}

void IncidenceMatrix::print() {
    cout << "Incidence matrix:" << endl;
    for (int vertex = 0; vertex < size; vertex++) {
        for (vector<int> edge : matrix) {
            cout << edge[vertex] << "\t";
        }
        cout << endl;
    }
    cout << "Weights:" << endl;
    for (int weight : weights)
        cout << weight << " ";
}

