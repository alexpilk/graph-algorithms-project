//
// Created by Drasik on 5/13/2018.
//
#include "Graph.h"

void Graph::fillWithRandomEdges() {
    int min_weight = 1;
    int max_weight = 100;
    for (int v1 = 0; v1 < size; v1++) {
        for (int v2 = v1 + 1; v2 < size; v2++) {
            addEdge(v1, v2, randint(min_weight, max_weight));
            if (directed)
                addEdge(v2, v1, randint(min_weight, max_weight));
        }
    }
}

void Graph::fillWithRandomEdges(float density) {
    fillWithRandomEdges();

    int max_edges = size * (size - 1);
    max_edges = directed ? max_edges : max_edges / 2;
    auto number_of_edges = (int) (density * max_edges);
    int edges_to_delete = max_edges - number_of_edges;

    for (int i = 0; i < edges_to_delete; i++) {
        deleteRandomEdge();
    }
}
