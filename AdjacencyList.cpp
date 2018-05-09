//
// Created by Drasik on 5/7/2018.
//

#include "AdjacencyList.h"
#include <iostream>
#include "Dijkstra.h"

using namespace std;


AdjacencyList::AdjacencyList(unsigned int size, bool directed) {
    this->size = size;
    this->directed = directed;
    list.resize(size);
}

void AdjacencyList::addEdge(int v1, int v2, int weight) {
    list[v1].emplace_back(Edge(v2, weight));
    if (!directed && v1 != v2)
        list[v2].emplace_back(Edge(v1, weight));
}

void AdjacencyList::print() {
    for (int vertex = 0; vertex < list.size(); vertex++) {
        cout << vertex;
        for (auto edge : list[vertex])
            cout << " -> " << edge.neighbor << " (weight " << edge.weight << ")";
        cout << endl;
    }
}

vector<int> AdjacencyList::dijkstraShortestPath(int start_vertex) {
    auto* pathFinder = new Dijkstra(this);
    return pathFinder->findShortestPaths(start_vertex);
}

vector<Graph::Edge> AdjacencyList::getEdges(int vertex) {
    return list[vertex];
}
