#include <iostream>
#include "AdjacencyList.h"
#include "IncidenceMatrix.h"


int main() {
    auto graph = IncidenceMatrix(3, true);
    graph.addEdge(0, 2, 2);
    graph.addEdge(0, 0, 40);
    graph.addEdge(1, 2, 9);
    graph.addEdge(1, 0, 90);
    graph.print();
    return 0;
}