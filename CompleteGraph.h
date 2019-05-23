//
// Created by Bleo on 5/23/2019.
//

#ifndef TEMA_3_POO_HARTA_COMPLETEGRAPH_H
#define TEMA_3_POO_HARTA_COMPLETEGRAPH_H

#include "Graph.h";
#include <vector>

using namespace std;

class CompleteGraph : public Graph {
    int n = 0;
    vector < pair < double,double> > nodes;
public:
    void GetDistance (const int x, const int y) override;
    void AddEdge (const int x, const int y) override;
    void CreateGraph () override;
    int size () override;
    ~CompleteGraph () {};
};

void CompleteGraph :: AddEdge (const int x, const int y){

}

int CompleteGraph :: size() {
    return n;
}

void CompleteGraph :: CreateGraph () {
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
}

void CompleteGraph :: GetDistance(const int x, const int y) {
    double D = DistantaPlan (nodes[x - 1] , nodes[y - 1]);
    cout << "\nLungimea drumului minim dintre orasul " << x << " si orasul " << y << " este de " << D << "!\n";
}

#endif //TEMA_3_POO_HARTA_COMPLETEGRAPH_H
