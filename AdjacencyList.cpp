//
// Created by Drasik on 5/7/2018.
//

#include "AdjacencyList.h"
#include <algorithm>

using namespace std;


AdjacencyList::AdjacencyList(unsigned int size, bool directed) {
    this->size = size;
    this->directed = directed;
    list.resize(size);
}

void AdjacencyList::addEdge(int v1, int v2, int weight) {
    list[v1].emplace_back(Edge(v1, v2, weight));
    if (!directed && v1 != v2)
        list[v2].emplace_back(Edge(v2, v1, weight));
}

void AdjacencyList::print() {
    cout << "Adjacency list" << endl;
    for (int vertex = 0; vertex < list.size(); vertex++) {
        cout << vertex;
        for (auto edge : list[vertex])
            cout << " -> " << edge.neighbor << " (weight " << edge.weight << ")";
        cout << endl;
    }
}

vector<Graph::Edge> AdjacencyList::getAdjacentEdges(int vertex) {
    return list[vertex];
}

vector<Graph::Edge> AdjacencyList::getAllEdges() {
    vector<Edge> all_edges;
    for (vector<Edge> edges : list)
        all_edges.insert(all_edges.end(), edges.begin(), edges.end());
    sort(all_edges.begin(), all_edges.end());
    if (!directed)
        all_edges.erase(unique(all_edges.begin(), all_edges.end()), all_edges.end());
    return all_edges;
}

void AdjacencyList::deleteRandomEdge() {
    int vertex = randint(0, size-1);
    while(list[vertex].empty()){
        vertex = randint(0, size-1);
    }
    int edge_index = randint(0, list[vertex].size()-1);
    deleteEdge(vertex, edge_index);
}

void AdjacencyList::deleteEdge(int vertex, int edge_index) {
    int neighbor = list[vertex][edge_index].neighbor;
    list[vertex].erase(list[vertex].begin() + edge_index);
    if (!directed)
        list[neighbor].erase(
                remove_if(list[neighbor].begin(), list[neighbor].end(), [&](Edge const & edge) {
                    return edge.neighbor == vertex;
                }), list[neighbor].end());
}

//void AdjacencyList::fillWithRandomEdges(float density) {
//    Graph::fillWithRandomEdges();
//
//    int max_edges = size * (size - 1);
//    max_edges = directed ? max_edges : max_edges / 2;
//    auto number_of_edges = (int) (density * max_edges);
//    int edges_to_delete = max_edges - number_of_edges;
//
//    for (int i = 0; i < edges_to_delete; i++) {
//        int v1 = randint(0, size-1);
//        while(list[v1].empty()){
//            v1 = randint(0, size-1);
//        }
//        int edge_index = randint(0, list[v1].size()-1);
//        int v2 = list[v1][edge_index].neighbor;
//        list[v1].erase(list[v1].begin() + edge_index);
//        if (!directed)
//            list[v2].erase(
//                    remove_if(list[v2].begin(), list[v2].end(), [&](Edge const & edge) {
//                        return edge.neighbor == v1;
//                    }), list[v2].end());
//    }
//}
