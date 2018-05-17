#include <iostream>
#include "AdjacencyList.h"
#include "IncidenceMatrix.h"
#include "Kruskal.h"
#include "Dijkstra.h"
#include <fstream>
#include <sstream>


using namespace std;

pair<int, vector<Graph::Edge>> parse_file(const string path) {
    vector<Graph::Edge> edges;
    ifstream infile(path);
    string line;
    getline(infile, line, ' ');
    int number_of_edges = stoi(line);
    getline(infile, line);
    int size = stoi(line);
    int v1, v2, weight;
    while (getline(infile, line)) {
        istringstream iss(line);
        string tmp;
        getline(iss, tmp, ' ');
        v1 = stoi(tmp);
        getline(iss, tmp, ' ');
        v2 = stoi(tmp);
        getline(iss, tmp);
        weight = stoi(tmp);
        edges.emplace_back(Graph::Edge(v1, v2, weight));
    }
    return make_pair(size, edges);
}

void menu() {
    int start_option;
    AdjacencyList *list_graph = nullptr;
    IncidenceMatrix *matrix_graph = nullptr;
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
                    auto parsed = parse_file("example_graph.txt");
                    int size = parsed.first;
                    vector<Graph::Edge> edges = parsed.second;
                    list_graph = new AdjacencyList(size, false);
                    matrix_graph = new IncidenceMatrix(size, false);
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
                    auto parsed = parse_file("example_graph.txt");
                    int size = parsed.first;
                    vector<Graph::Edge> edges = parsed.second;
                    list_graph = new AdjacencyList(size, true);
                    matrix_graph = new IncidenceMatrix(size, true);
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
                    if (matrix_graph == nullptr) {
                        cout << "No graph\n";
                        continue;
                    }
                    int start;
                    cout << "Enter start vertex:\n";
                    cin >> start;
                    auto dijkstra = Dijkstra(matrix_graph);
                    auto paths = dijkstra.findShortestPaths(start);
                    for (int i = 0; i < paths.size(); i++) {
                        cout << "Path from " << start << " to " << i << " has ";
                        paths[i].print();
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
                    auto paths = dijkstra.findShortestPaths(start);
                    for (int i = 0; i < paths.size(); i++) {
                        cout << "Path from " << start << " to " << i << " has ";
                        paths[i].print();
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