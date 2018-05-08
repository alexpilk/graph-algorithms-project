//
// Created by Drasik on 5/9/2018.
//

#include "Dijkstra.h"

Dijkstra::Dijkstra(Graph* graph) {
    this->graph = graph;
    completed.resize(graph->getSize());
    distances.resize(graph->getSize());
    fill(completed.begin(), completed.end(), false);
    fill(distances.begin(), distances.end(), INF);
}

int Dijkstra::getMinVertex() {
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

vector<int> Dijkstra::findShortestPaths(int start_vertex) {
    distances[start_vertex] = 0;
    for (int i = 0; i < graph->getSize(); i++) {
        int current_vertex = getMinVertex();
        if (distances[current_vertex] == INF)
            break;
        completed[current_vertex] = true;
        for (Graph::Edge edge : graph->getEdges(current_vertex)) {
            int current_cost = distances[current_vertex] + edge.weight;
            if (current_cost < distances[edge.neighbor] || distances[edge.neighbor] == INF)
                distances[edge.neighbor] = current_cost;
        }
    }
    return distances;
}
