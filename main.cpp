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
vector<Graph::Edge> parse_file(const string path){
    vector<Graph::Edge> edges;
    ifstream infile(path);
    string first_line;
    infile >> first_line;
    getline(infile, first_line);
    string line;
    int v1, v2, weight;
    while (getline(infile, line)){

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
    AdjacencyList *list_graph;
    IncidenceMatrix *matrix_graph;
    do {
        cout << "1 - Load graph from file\n"
                "2 - Generate random graph\n"
                "0 - Exit:" << endl;
        cin >> start_option;
        if (start_option == 0)
            break;
        else {
            vector<Graph::Edge> edges = parse_file("example_graph.txt");
            list_graph = new AdjacencyList(edges.size(), false);
            matrix_graph = new IncidenceMatrix(edges.size(), false);
            for (Graph::Edge edge : edges){
                list_graph->addEdge(edge.vertex, edge.neighbor, edge.weight);
                matrix_graph->addEdge(edge.vertex, edge.neighbor, edge.weight);
            }
            list_graph->print();
            matrix_graph->print();
        }
//        if (start_option == 1 or start_option == 2) {
//            switch (start_option) {
//                case 1: {
//                    file_name = "array.txt";
//                    pair<int *, int> input_data = parse_file(file_name, base_array);
//                    structure = new DynamicArray(input_data.first, input_data.second);
//                    break;
//                }
//                case 2: {
//                    file_name = "list.txt";
//                    pair<int *, int> input_data = parse_file(file_name, base_array);
//                    structure = new List(input_data.first, input_data.second);
//                    break;
//                }
//                default:
//                    continue;
//            }
//            cout << "Read data structure from file: ";
//            structure->print();
//            int action;
//            do {
//                cout << "Available actions: insert (1), remove (2), search (3). Enter 0 to exit:" << endl;
//                cin >> action;
//                if (action == 0)
//                    break;
//                int index;
//                try {
//                    switch (action) {
//                        case 1:
//                            cout << "Choose index (enter -1 to access the last element):" << endl;
//                            cin >> index;
//                            int value;
//                            cout << "Enter value:" << endl;
//                            cin >> value;
//                            if (index == -1)
//                                structure->addLast(value);
//                            else
//                                structure->insert(value, index);
//                            break;
//                        case 2:
//                            cout << "Choose index (enter -1 to access the last element):" << endl;
//                            cin >> index;
//                            if (structure->getSize() == 0){
//                                cout << "Cannot remove value from an empty list/array." << endl;
//                                break;
//                            }
//                            if (index == -1)
//                                structure->removeLast();
//                            else
//                                structure->removeOnIndex(index);
//                            break;
//                        case 3: {
//                            int value;
//                            cout << "Enter value:" << endl;
//                            cin >> value;
//                            int search_index = structure->search(value);
//                            if (search_index == -1)
//                                cout << "Value not found" << endl;
//                            else
//                                cout << "Found value on index " << search_index << endl;
//                            break;
//                        }
//                        default:
//                            continue;
//                    }
//                } catch (IndexError &e) {
//                    cout << "Index " << index << " out of range" << endl;
//                }
//                structure->print();
//            } while (true);
//        } else if (start_option == 3) {
//            int action;
//            file_name = "heap.txt";
//            pair<int *, int> input_data = parse_file(file_name, base_array);
//            auto *array = new DynamicArray(input_data.first, input_data.second);
//            auto *heap = new Heap(array);
//            cout << "Read heap structure from file:" << endl;
//            heap->print();
//            do {
//                try {
//                    cout << "Available actions: insert (1), extract (2), search (3). Enter 0 to exit:" << endl;
//                    cin >> action;
//                    if (action == 0)
//                        break;
//                    else if (action == 1) {
//                        int value;
//                        cout << "Enter value:" << endl;
//                        cin >> value;
//                        heap->insert(value);
//                    } else if (action == 2) {
//                        int value = heap->extract();
//                        cout << "Extracted " << value << endl;
//                    } else if (action == 3) {
//                        int value;
//                        cout << "Enter value:" << endl;
//                        cin >> value;
//                        int found = heap->search(value);
//                        if(found)
//                            cout << "Value " << value << " found" << endl;
//                        else
//                            cout << "Value " << value << " NOT found" << endl;
//                    }
//                    heap->print();
//                } catch (IndexError &e) {
//                    cout << "Cannot extract value from an empty heap" << endl;
//                }
//            } while (true);
//        }
    } while (true);
}


int main() {
    menu();
    return 0;
}