//
// Created by Bleo on 5/22/2019.
//

#ifndef TEMA_3_POO_HARTA_LINEGRAPH_H
#define TEMA_3_POO_HARTA_LINEGRAPH_H

#include "Graph.h"
#include <vector>
#include <queue>

using namespace std;

class LineGraph : public Graph{
    int n = 0;
    vector <pair <double, double> > nodes;
    vector <double> distance;
public:
    void CreateGraph () override;
    void GetDistance (const int x, const int y) override;
    void AddEdge (const int x, const int y) override;
    int size () override;
    ~LineGraph () {};
};

int LineGraph :: size () {
    return n;
}

void LineGraph :: AddEdge(const int x, const int y) {

}

void LineGraph :: CreateGraph() {
    int i,x,y;
    double D;
    pair <double, double> P;
    cout << "\nIntroduceti numarul de noduri si apoi apasati Enter: ";
    cin >> n;
    cout << "\nIntroduceti coordonatele nodurilor cu spatiu intre ele si apoi apasati Enter: ";
    for (i = 0; i < n; ++i){
        cin >> P.first >> P.second;
        nodes.push_back(P);
    }
    distance.resize (n);
    cout << "\nIn continuare introduceti ordinea oraselor pe linie : ";
    cin >> x;
    distance[x - 1] = 0;
    for (i = 1; i < n; ++i){
        cin >> y;
        D = DistantaPlan (nodes[x - 1], nodes[y - 1]);
        distance[y - 1] = distance [x - 1] + D;
        x = y;
    }
}

void LineGraph :: GetDistance(const int x, const int y) {
    double D = abs (distance[x - 1] - distance[y - 1]);
    cout << "\nLungimea drumului minim dintre orasul " << x << " si orasul " << y << " este de " << D << "!\n";
}

#endif //TEMA_3_POO_HARTA_LINEGRAPH_H
