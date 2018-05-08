#include <iostream>
#include "AdjacencyList.h"
#include "IncidenceMatrix.h"


void test_graph(Graph *graph) {
    graph->addEdge(0, 2, 2);
    graph->addEdge(0, 0, 40);
    graph->addEdge(1, 2, 9);
    graph->addEdge(1, 0, 90);
    graph->print();
}

int main() {
    Graph matrix_graph = IncidenceMatrix(3, true);
    Graph list_graph = AdjacencyList(3, true);
    test_graph(&matrix_graph);
    test_graph(&list_graph);
    return 0;
}