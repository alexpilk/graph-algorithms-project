//
// Created by Drasik on 5/9/2018.
//

#include "Kruskal.h"
#include "Graph.h"


vector<Graph::Edge> Kruskal::getMST(Graph* graph) {
    vector<Graph::Edge> mst;
    vector<Graph::Edge> edges = graph->getAllEdges();
    for (Graph::Edge edge : edges) {
        bool vertex_included = false;
        bool neighbor_included = false;
        for (Graph::Edge mst_edge : mst){
            if (edge.vertex == mst_edge.vertex || edge.vertex == mst_edge.neighbor)
                vertex_included = true;
            if (edge.neighbor == mst_edge.vertex || edge.vertex == mst_edge.neighbor)
                neighbor_included = true;
        }
        if (!vertex_included || !neighbor_included)
            mst.emplace_back(edge);
    }
    return mst;
}
