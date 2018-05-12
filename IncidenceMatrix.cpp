//
// Created by Drasik on 5/7/2018.
//

#include "IncidenceMatrix.h"
#include "utils.h"
#include <algorithm>

using namespace std;


IncidenceMatrix::IncidenceMatrix(unsigned int size, bool directed) {
    this->directed = directed;
    this->size = size;
}

void IncidenceMatrix::addEdge(int v1, int v2, int weight) {
    auto edge = createEdge(v1, v2);
    matrix.emplace_back(edge);
    weights.emplace_back(weight);
}

vector<int> IncidenceMatrix::createEdge(int v1, int v2) {
    vector<int> edge;
    edge.resize(size);
    fill(edge.begin(), edge.end(), 0);
    if (v1 == v2)
        edge[v1] = 2;
    else {
        edge[v1] = 1;
        edge[v2] = directed ? -1 : 1;
    }
    return edge;
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
    cout << endl;
}

vector<Graph::Edge> IncidenceMatrix::getAdjacentEdges(int vertex) {
    vector<Edge> edges;
    int neighbor;
    for (int edge_index = 0; edge_index < matrix.size(); edge_index++) {
        vector<int> row = matrix[edge_index];
        if (row[vertex] == 1) {
            int neighbor_mark;
            if (directed)
                neighbor_mark = -1;
            else
                neighbor_mark = 1;
            row[vertex] = 0;
            neighbor = distance(row.begin(), find(row.begin(), row.end(), neighbor_mark));
        } else if (row[vertex] == 2) {
            neighbor = vertex;
        } else {
            continue;
        }
        Edge edge = Edge(vertex, neighbor, weights[edge_index]);
        edges.emplace_back(edge);
    }
    return edges;
}

vector<Graph::Edge> IncidenceMatrix::getAllEdges() {
    vector<Edge> all_edges;
    for (int edge_index = 0; edge_index < matrix.size(); edge_index++) {
        vector<int> row = matrix[edge_index];
        int neighbor;
        for (int vertex = 0; vertex < row.size(); vertex++) {
            if (row[vertex] == 0) {
                continue;
            } else if (abs(row[vertex]) == 1) {
                int neighbor_mark;
                if (directed)
                    neighbor_mark = row[vertex] * -1;
                else
                    neighbor_mark = 1;
                neighbor = distance(row.begin(), find(row.begin() + vertex + 1, row.end(), neighbor_mark));
            } else if (row[vertex] == 2) {
                neighbor = vertex;
            }
            Edge edge = Edge(vertex, neighbor, weights[edge_index]);
            all_edges.emplace_back(edge);
            break;
        }
    }
    sort(all_edges.begin(), all_edges.end());
    return all_edges;
}

void IncidenceMatrix::deleteRandomEdge() {
    int edge_index = randint(0, matrix.size() - 1);
    deleteEdge(edge_index);
}

void IncidenceMatrix::deleteEdge(int edge_index) {
    matrix.erase(matrix.begin() + edge_index);
    weights.erase(weights.begin() + edge_index);
}
