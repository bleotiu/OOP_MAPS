//
// Created by Bleo on 5/22/2019.
//

#ifndef TEMA_3_POO_HARTA_GRAPH_H
#define TEMA_3_POO_HARTA_GRAPH_H

#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

#define INF 1e9

class Graph {
protected:
    double DistantaPlan(pair <double,double> A, pair <double,double> B);
public:

    virtual void CreateGraph () = 0;
    virtual void AddEdge (const int x, const int y) = 0;
    virtual void GetDistance (const int x, const int y) = 0;
    virtual int size () = 0;
    virtual ~Graph () {};
};

double Graph ::DistantaPlan(pair<double, double> A, pair<double, double> B) {
    return sqrt ( (A.first - B.first) * (A.first - B.first) + (A.second - B.second) * (A.second - B.second) );
}

#endif //TEMA_3_POO_HARTA_GRAPH_H
