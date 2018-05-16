//
// Created by Drasik on 5/9/2018.
//

#ifndef SDIZO_PROJECT_2_DIJKSTRA_H
#define SDIZO_PROJECT_2_DIJKSTRA_H

#include <vector>
#include "Graph.h"

using namespace std;

class Dijkstra {
public:
    struct Path {
        int last_vertex;
        int distance;

        Path() = default;

        Path(int last_vertex, int distance) {
            this->last_vertex = last_vertex;
            this->distance = distance;
        }

        void print() {
            cout << "distance: ";
            if (distance == INF)
                cout << "infinite";
            else
                cout << distance;
            if (last_vertex != -1)
                cout << ", last vertex: " << last_vertex;
            cout << endl;
        }
    };

    explicit Dijkstra(Graph *graph);

    vector<Path> findShortestPaths(int start_vertex);

private:
    Graph *graph;
    vector<bool> completed;
    vector<Path> paths;

    int getMinVertex();

};


#endif //SDIZO_PROJECT_2_DIJKSTRA_H
