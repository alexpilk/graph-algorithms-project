#include <iostream>
#include "AdjacencyList.h"
#include "IncidenceMatrix.h"
#include "Kruskal.h"
#include "Dijkstra.h"

void test_graph(Graph *graph) {
    graph->fillWithRandomEdges(0.5);
    cout << "Graph:" << endl;
    graph->print();
    vector<int> distances = Dijkstra(graph).findShortestPaths(0);
    cout << "Dijkstra:" << endl;
    for(int distance : distances){
        cout << distance << endl;
    }
    cout << "Kruskal:" << endl;
    vector<Graph::Edge> mst = Kruskal(graph).getMST();
    for(Graph::Edge edge : mst) {
        edge.print();
    }
}

int main() {
    auto matrix_graph = IncidenceMatrix(5, false);
    auto list_graph = AdjacencyList(5, false);
    test_graph(&matrix_graph);
    test_graph(&list_graph);
    return 0;
}
