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
public:
    vector<Graph::Edge> getMST(Graph* graph);
};


#endif //SDIZO_PROJECT_2_KRUSKAL_H
