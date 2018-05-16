#include <iostream>
#include "AdjacencyList.h"
#include "IncidenceMatrix.h"
#include "Kruskal.h"
#include "Dijkstra.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

//void test_graph(Graph *graph) {
//    graph->fillWithRandomEdges(0.5);
//    cout << "Graph:" << endl;
//    graph->print();
//    vector<int> distances = Dijkstra(graph).findShortestPaths(0);
//    cout << "Dijkstra:" << endl;
//    for(int distance : distances){
//        cout << distance << endl;
//    }
//    cout << "Kruskal:" << endl;
//    vector<Graph::Edge> mst = Kruskal(graph).getMST();
//    for(Graph::Edge edge : mst) {
//        edge.print();
//    }
//}

//void measure_graph(ofstream* output, unsigned int vertices, double density) {
//    *output << ",";
//    auto matrix_graph = IncidenceMatrix(vertices, true);
//    matrix_graph.fillWithRandomEdges(density);
//    auto dijkstra = Dijkstra(&matrix_graph);
//    *output << measure(dijkstra, dijkstra.findShortestPaths, 1);
//
//    *output << ",";
//    matrix_graph = IncidenceMatrix(vertices, false);
//    matrix_graph.fillWithRandomEdges(density);
//    auto kruskal = Kruskal(&matrix_graph);
//    *output << measure(kruskal, kruskal.getMST);
//
//    *output << ",";
//    auto list_graph = AdjacencyList(vertices, true);
//    list_graph.fillWithRandomEdges(density);
//    dijkstra = Dijkstra(&list_graph);
//    *output << measure(dijkstra, dijkstra.findShortestPaths, 1);
//
//    *output << ",";
//    list_graph = AdjacencyList(vertices, false);
//    list_graph.fillWithRandomEdges(density);
//    kruskal = Kruskal(&list_graph);
//    *output << measure(kruskal, kruskal.getMST);
//}
vector<Graph::Edge> parse_file(const string path) {
    vector<Graph::Edge> edges;
    ifstream infile(path);
    string first_line;
    infile >> first_line;
    getline(infile, first_line);
    string line;
    int v1, v2, weight;
    while (getline(infile, line)) {

        istringstream iss(line); // Turn the string into a stream.
        string tmp;

        getline(iss, tmp, ' ');
        v1 = stoi(tmp);
        getline(iss, tmp, ' ');
        v2 = stoi(tmp);
        getline(iss, tmp);
        weight = stoi(tmp);
        edges.emplace_back(Graph::Edge(v1, v2, weight));
    }
    return edges;
}

void menu() {
    int start_option;
    AdjacencyList *list_graph = NULL;
    IncidenceMatrix *matrix_graph = NULL;
    do {
        cout << "=========================\n"
                "1 - MST\n"
                "2 - Shortest path\n"
                "0 - Exit\n"
                "=========================" << endl;
        cin >> start_option;
        if (start_option == 0)
            break;
        else if (start_option == 1) {
            do {
                cout << "=========================\n"
                        "1 - Load graph from file\n"
                        "2 - Generate random graph\n"
                        "3 - Display graph\n"
                        "4 - Run Kruskal on Incidence Matrix\n"
                        "5 - Run Kruskal on Adjacency List\n"
                        "0 - Exit\n"
                        "=========================" << endl;
                cin >> start_option;
                if (start_option == 0)
                    break;
                else if (start_option == 1) {
                    vector<Graph::Edge> edges = parse_file("example_graph.txt");
                    list_graph = new AdjacencyList(edges.size(), false);
                    matrix_graph = new IncidenceMatrix(edges.size(), false);
                    for (Graph::Edge edge : edges) {
                        list_graph->addEdge(edge.vertex, edge.neighbor, edge.weight);
                        matrix_graph->addEdge(edge.vertex, edge.neighbor, edge.weight);
                    }
                } else if (start_option == 2) {
                    int size, density;
                    cout << "Enter vertices:\n";
                    cin >> size;
                    cout << "Enter density (1-100)%:\n";
                    cin >> density;
                    list_graph = new AdjacencyList(size, false);
                    matrix_graph = new IncidenceMatrix(size, false);
                    matrix_graph->fillWithRandomEdges(density / 100.0);
                    for (Graph::Edge edge : matrix_graph->getAllEdges())
                        list_graph->addEdge(edge.vertex, edge.neighbor, edge.weight);

                } else if (start_option == 3) {
                    if (!list_graph) {
                        cout << "No graph\n";
                        continue;
                    }
                    list_graph->print();
                    matrix_graph->print();
                    continue;
                } else if (start_option == 4) {
                    if (!list_graph) {
                        cout << "No graph\n";
                        continue;
                    }
                    auto kruskal = Kruskal(matrix_graph);
                    vector<Graph::Edge> mst = kruskal.getMST();
                    for (Graph::Edge edge : mst) {
                        edge.print();
                    }
                } else if (start_option == 5) {
                    if (!list_graph) {
                        cout << "No graph\n";
                        continue;
                    }
                    auto kruskal = Kruskal(list_graph);
                    vector<Graph::Edge> mst = kruskal.getMST();
                    for (Graph::Edge edge : mst) {
                        edge.print();
                    }
                }
            } while (true);
        } else if (start_option == 2) {  // TODO: remove duplicated code
            do {
                cout << "=========================\n"
                        "1 - Load graph from file\n"
                        "2 - Generate random graph\n"
                        "3 - Display graph\n"
                        "4 - Run Dijkstra on Incidence Matrix\n"
                        "5 - Run Dijkstra on Adjacency List\n"
                        "0 - Exit\n"
                        "=========================" << endl;
                cin >> start_option;
                if (start_option == 0)
                    break;
                else if (start_option == 1) {
                    vector<Graph::Edge> edges = parse_file("example_graph.txt");
                    list_graph = new AdjacencyList(edges.size(), true);
                    matrix_graph = new IncidenceMatrix(edges.size(), true);
                    for (Graph::Edge edge : edges) {
                        list_graph->addEdge(edge.vertex, edge.neighbor, edge.weight);
                        matrix_graph->addEdge(edge.vertex, edge.neighbor, edge.weight);
                    }
                } else if (start_option == 2) {
                    int size, density;
                    cout << "Enter vertices:\n";
                    cin >> size;
                    cout << "Enter density (1-100)%:\n";
                    cin >> density;
                    list_graph = new AdjacencyList(size, false);
                    matrix_graph = new IncidenceMatrix(size, false);
                    matrix_graph->fillWithRandomEdges(density / 100.0);
                    for (Graph::Edge edge : matrix_graph->getAllEdges())
                        list_graph->addEdge(edge.vertex, edge.neighbor, edge.weight);

                } else if (start_option == 3) {
                    if (list_graph == nullptr) {
                        cout << "No graph\n";
                        continue;
                    }
                    list_graph->print();
                    matrix_graph->print();
                    continue;
                } else if (start_option == 4) {
                    if (list_graph == nullptr) {
                        cout << "No graph\n";
                        continue;
                    }
                    int start;
                    cout << "Enter start vertex:\n";
                    cin >> start;
                    auto dijkstra = Dijkstra(matrix_graph);
                    vector<int> weights = dijkstra.findShortestPaths(start);
                    for (int i = 0; i < matrix_graph->getSize(); i++) {
                        if (weights[i] != 2147483647)
                            cout << "Path from " << start << " to " << i << " takes " << weights[i] << endl;
                        else
                            cout << "Path from " << start << " to " << i << " doesn't exist" << endl;
                    }
                } else if (start_option == 5) {
                    if (list_graph == nullptr) {
                        cout << "No graph\n";
                        continue;
                    }
                    int start;
                    cout << "Enter start vertex:\n";
                    cin >> start;
                    auto dijkstra = Dijkstra(list_graph);
                    vector<int> weights = dijkstra.findShortestPaths(start);
                    for (int i = 0; i < list_graph->getSize(); i++) {
                        if (weights[i] != 2147483647)
                            cout << "Path from " << start << " to " << i << " takes " << weights[i] << endl;
                        else
                            cout << "Path from " << start << " to " << i << " doesn't exist" << endl;
                    }
                }
            } while (true);
        }
    } while (true);
}


int main() {
    menu();
    return 0;
}