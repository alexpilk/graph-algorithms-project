//
// Created by Drasik on 5/7/2018.
//

#ifndef SDIZO_PROJECT_2_INCIDENCEMATRIX_H
#define SDIZO_PROJECT_2_INCIDENCEMATRIX_H

#include <vector>
using namespace std;

class IncidenceMatrix {
private:
    vector<vector<int>> matrix;
    vector<int> weights;
    bool directed;
    unsigned int size;
public:
    explicit IncidenceMatrix(unsigned int size, bool directed);
    void addEdge(int v1, int v2, int weight);
    void print();
};


#endif //SDIZO_PROJECT_2_INCIDENCEMATRIX_H
