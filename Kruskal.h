//
// Created by Drasik on 5/9/2018.
//

#ifndef SDIZO_PROJECT_2_KRUSKAL_H
#define SDIZO_PROJECT_2_KRUSKAL_H

#include <vector>
#include "IncidenceMatrix.h"
#include "AdjacencyList.h"

using namespace std;

class Kruskal {
private:
    Graph *graph;
public:
    explicit Kruskal(Graph *graph) {
        this->graph = graph;
    }

    vector<Graph::Edge> getMST();
};


#endif //SDIZO_PROJECT_2_KRUSKAL_H
