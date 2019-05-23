//
// Created by Bleo on 5/22/2019.
//

#ifndef TEMA_3_POO_HARTA_GENERALGRAPH_H
#define TEMA_3_POO_HARTA_GENERALGRAPH_H

#include "Graph.h"
#include <vector>
#include <queue>

using namespace std;

class GeneralGraph : public Graph{
    int n = 0,m;
    vector <pair <double, double> > nodes;
    vector < vector <pair <int, double> > > edges;

    double Dijkstra (int start, int finish);
public:

    void CreateGraph () override;
    void AddEdge (const int x, const int y) override;
    void GetDistance (const int x, const int y) override;
    int size () override;
    ~GeneralGraph () {};
};

int GeneralGraph :: size() {
    return n;
}

double GeneralGraph :: Dijkstra(int start, int finish) {
    --start; --finish;
    vector <double> d(n,INF);
    d[start] = 0;
    priority_queue < pair<double,int>, vector< pair<double,int> >, greater<pair<double,int> > >pq;
    pq.push(make_pair(d[start],start));
    int X,Y,cnt = 0;
    unsigned i;
    double C;
    while (cnt < n && !pq.empty()){
        X = pq.top().second;
        pq.pop();
        ++cnt;
        for (i = 0; i < edges[X].size(); ++i){
            Y = edges[X][i].first;
            C = edges[X][i].second;
            if (d[X] + C < d[Y]){
                d[Y] = d[X] + C;
                pq.push(make_pair(d[Y],Y));
            }
        }
    }
    return d[finish];
}

void GeneralGraph :: CreateGraph() {
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
    cout << "\nIntroduceti numarul de muchii si apoi apasati Enter: ";
    cin >> m;
    cout << "\nIntroduceti muchiile in forma X Y cu spatiu intre ele si apoi apasati Enter: ";
    edges.resize (n);
    for (i = 0; i < m; ++i){
        cin >> x >> y;
        --x;--y;
        while (x < 0 || y < 0 || x >= n || y >= n) {
            cout << "\nMuchia " << i << " introdusa incorect. X si Y trebuie sa fie intre 1 si numarul de noduri."
                                        "\nIntroduceti dinnou muchia";
            cin >> x >> y;
            --x;--y;
        }
        D = DistantaPlan (nodes[x],nodes[y]);
        edges[x].push_back (make_pair(y,D));
        edges[y].push_back (make_pair(x,D));
    }
}

void GeneralGraph :: AddEdge (const int x, const int y) {
    double D = DistantaPlan (nodes[x - 1],nodes[y - 1]);
    edges[x - 1].push_back (make_pair(y - 1,D));
    edges[y - 1].push_back (make_pair(x - 1,D));
}

void GeneralGraph :: GetDistance (const int x, const int y) {
    double D = Dijkstra(x, y);
    if (D < INF)
        cout << "Distanta de la orasul " << x << " la orasul " << y << " este de " << D << "!\n";
    else
        cout << "Nu se poate ajunge din orasul " << x << " in orasul " << y << "!\n";
}

#endif //TEMA_3_POO_HARTA_GENERALGRAPH_H
