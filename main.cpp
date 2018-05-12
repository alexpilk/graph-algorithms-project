#include <iostream>
#include "AdjacencyList.h"
#include "IncidenceMatrix.h"
#include "Kruskal.h"

void test_graph(Graph *graph) {
    graph->fillWithRandomEdges(0.5);
    cout << "Graph:" << endl;
    graph->print();
    vector<int> distances = graph->dijkstraShortestPath(0);
    cout << "Dijkstra:" << endl;
    for(int distance : distances){
        cout << distance << endl;
    }
    cout << "Kruskal:" << endl;
    vector<Graph::Edge> mst = Kruskal().getMST(graph);
    for(Graph::Edge edge : mst) {
        edge.print();
    }
}

int main() {
    auto matrix_graph = IncidenceMatrix(4, true);
    auto list_graph = AdjacencyList(4, true);
    test_graph(&matrix_graph);
    test_graph(&list_graph);
    return 0;
}
