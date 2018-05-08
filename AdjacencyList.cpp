//
// Created by Drasik on 5/7/2018.
//

#include "AdjacencyList.h"
#include <iostream>
#include "Dijkstra.h"
#include <limits>

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
    Dijkstra* pathFinder = new Dijkstra(this);
    return pathFinder->findShortestPaths(start_vertex);
//    int INF = numeric_limits<int>::max();
//    vector<bool> completed;
//    vector<int> distances;
//    completed.resize(list.size());
//    distances.resize(list.size());
//    fill(completed.begin(), completed.end(), false);
//    fill(distances.begin(), distances.end(), INF);
//    distances[start_vertex] = 0;
//    for (int i = 0; i < list.size(); i++) {
//        int current_vertex = getMinVertex(distances, completed);
//        if (distances[current_vertex] == INF)
//            break;
//        completed[current_vertex] = true;
//        for (Edge edge : list[current_vertex]) {
//            int current_cost = distances[current_vertex] + edge.weight;
//            if (current_cost < distances[edge.neighbor] || distances[edge.neighbor] == INF)
//                distances[edge.neighbor] = current_cost;
//        }
//    }
//    return distances;
}

int AdjacencyList::getMinVertex(vector<int> distances, vector<bool> completed) {
    bool found = false;
    int min_index = 0;

    for (int i = 0; i < distances.size(); i++) {
        if (completed[i])
            continue;
        if (!found || distances[i] < distances[min_index]) {
            found = true;
            min_index = i;
        }
    }
    return min_index;
}

vector<Graph::Edge> AdjacencyList::getEdges(int vertex) {
    return list[vertex];
}
