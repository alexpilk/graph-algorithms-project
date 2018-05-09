#include <iostream>
#include "AdjacencyList.h"
#include "IncidenceMatrix.h"
#include "Kruskal.h"

void test_graph(Graph *graph) {
    graph->addEdge(0, 2, 2);
    graph->addEdge(0, 0, 40);
    graph->addEdge(1, 2, 9);
    graph->addEdge(1, 0, 90);
    graph->print();
}
// 0 11 2
int main() {
    auto matrix_graph = IncidenceMatrix(3, true);
    auto list_graph = AdjacencyList(3, false);
    test_graph(&matrix_graph);
    test_graph(&list_graph);
//    vector<int> distances = matrix_graph.dijkstraShortestPath(0);
//    for(int distance : distances){
//        cout << distance << endl;
//    }


    vector<Graph::Edge> distances = matrix_graph.getAllEdges();
    for(Graph::Edge distance : distances) {
        cout << distance.vertex << " " << distance.neighbor << " " << distance.weight << endl;
    }
    vector<Graph::Edge> mst = Kruskal().getMST(&matrix_graph);
    for(Graph::Edge edge : mst) {
        edge.print();
    }
    return 0;
}