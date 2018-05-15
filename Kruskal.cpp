//
// Created by Drasik on 5/9/2018.
//

#include "Kruskal.h"


vector<Graph::Edge> Kruskal::getMST() {
    vector<Graph::Edge> mst;
    vector<Graph::Edge> edges = graph->getAllEdges();
//    cout << " - - - " << endl;
    for (Graph::Edge edge : edges) {
        bool visited[mst.size()];
        for (int i = 0; i < mst.size(); i++) {
            visited[i] = false;
        }
//        cout << "starting " << edge.vertex << " " << edge.neighbor << endl;
        if (!findCycle(edge.vertex, edge.neighbor, mst, visited)) {
            mst.emplace_back(edge);
//            cout << "added" << endl;
        }
//        else
//            cout << "not added" << endl;
    }
//    cout << " - - - " << endl;
    return mst;
}

bool Kruskal::findCycle(int vertex, int neighbor, vector<Graph::Edge> mst, bool visited[]) {
//    cout << "V: " << vertex << " N: " << neighbor << endl;
//    for (int i = 0; i < mst.size(); i++) {
//        cout << visited[i] << " ";
//        mst[i].print();
//    }
//    cout << endl;
    bool found = false;
    for (int i = 0; i < mst.size(); i++) {
        Graph::Edge mst_edge = mst[i];
        if (found)
            return true;
        if (visited[i])
            continue;
        if (neighbor == mst_edge.vertex) {
            if (vertex == mst_edge.neighbor)
                return true;
            else {
                visited[i] = true;
                if (findCycle(vertex, mst_edge.neighbor, mst, visited))
                    found = true;
            }
        }

        if (neighbor == mst_edge.neighbor) {
            if (vertex == mst_edge.vertex)
                return true;
            else {
                visited[i] = true;
                if(findCycle(vertex, mst_edge.vertex, mst, visited))
                    found = true;
            }
        }
    }
    return found;
}
