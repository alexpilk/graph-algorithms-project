#include <iostream>
#include "AdjacencyList.h"
#include "utils.h"
#include "Kruskal.h"
#include <chrono>
void test_graph(Graph *graph) {
//    graph->addEdge(0, 2, 2);
//    graph->addEdge(0, 0, 40);
//    graph->addEdge(1, 2, 9);
//    graph->addEdge(1, 0, 90);
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

//    for(int n=0; n<10; ++n)
//        cout << randint(1, 5) << ' ';
    auto matrix_graph = IncidenceMatrix(3, true);
    auto list_graph = AdjacencyList(3, true);
    test_graph(&matrix_graph);
    test_graph(&list_graph);
    return 0;
}
