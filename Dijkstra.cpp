//
// Created by Drasik on 5/9/2018.
//

#include "Dijkstra.h"

Dijkstra::Dijkstra(Graph *graph) {
    this->graph = graph;
    completed.resize(graph->getSize());
    paths.resize(graph->getSize());
    fill(completed.begin(), completed.end(), false);
    fill(paths.begin(), paths.end(), Dijkstra::Path(-1, INF));
}

int Dijkstra::getMinVertex() {
    bool found = false;
    int min_index = 0;

    for (int i = 0; i < paths.size(); i++) {
        if (completed[i])
            continue;
        if (!found || paths[i].distance < paths[min_index].distance) {
            found = true;
            min_index = i;
        }
    }
    return min_index;
}

vector<Dijkstra::Path> Dijkstra::findShortestPaths(int start_vertex) {
    paths[start_vertex].distance = 0;
    for (int i = 0; i < graph->getSize(); i++) {
        int current_vertex = getMinVertex();
        if (paths[current_vertex].distance == INF)
            break;
        completed[current_vertex] = true;
        for (Graph::Edge edge : graph->getAdjacentEdges(current_vertex)) {
            int current_cost = paths[current_vertex].distance + edge.weight;
            if (current_cost < paths[edge.neighbor].distance || paths[edge.neighbor].distance == INF) {
                paths[edge.neighbor].distance = current_cost;
                paths[edge.neighbor].last_vertex = edge.vertex;
            }
        }
    }
    return paths;
}
