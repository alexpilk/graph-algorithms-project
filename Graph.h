//
// Created by Drasik on 5/8/2018.
//

#ifndef SDIZO_PROJECT_2_GRAPH_H
#define SDIZO_PROJECT_2_GRAPH_H


class Graph {
public:
    virtual void addEdge(int v1, int v2, int weight) = 0;
    virtual void print() = 0;
};


#endif //SDIZO_PROJECT_2_GRAPH_H
