#include <iostream>
#include "AdjacencyList.h"
#include "IncidenceMatrix.h"
#include "Kruskal.h"
#include "Dijkstra.h"
#include <vector>
#include <iostream>
#include <fstream>


using namespace std;

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

void measure_graph(ofstream* output, unsigned int vertices, double density) {
    *output << ",";
    auto matrix_graph = IncidenceMatrix(vertices, true);
    matrix_graph.fillWithRandomEdges(density);
    auto dijkstra = Dijkstra(&matrix_graph);
    *output << measure(dijkstra, dijkstra.findShortestPaths, 1);

    *output << ",";
    matrix_graph = IncidenceMatrix(vertices, false);
    matrix_graph.fillWithRandomEdges(density);
    auto kruskal = Kruskal(&matrix_graph);
    *output << measure(kruskal, kruskal.getMST);

    *output << ",";
    auto list_graph = AdjacencyList(vertices, true);
    list_graph.fillWithRandomEdges(density);
    dijkstra = Dijkstra(&list_graph);
    *output << measure(dijkstra, dijkstra.findShortestPaths, 1);

    *output << ",";
    list_graph = AdjacencyList(vertices, false);
    list_graph.fillWithRandomEdges(density);
    kruskal = Kruskal(&list_graph);
    *output << measure(kruskal, kruskal.getMST);
}

int main() {

    ofstream report("report.txt");
//    report->open ("report.txt");
    report << "Count,Vertices,Density,Inc_Dijkstra,Inc_Kruskal,Adj_Dijkstra,Adj_Kruskal" << endl;

    for (unsigned int vertices = 1; vertices <= 5; vertices += 1) {
        for (int density = 1; density <= 4; density++) {
            for(int i = 1; i <= 100; i++) {
                report << i << "," << vertices << "," << density;
                measure_graph(&report, vertices * 30, density * 0.25);
                report << endl;
            }
        }
    }
//    auto matrix_graph = IncidenceMatrix(9, true);
//    auto list_graph = AdjacencyList(9, true);
//    matrix_graph.fillWithRandomEdges(0.5);
//    test_graph(&matrix_graph);
//    test_graph(&list_graph);
    return 0;
}
