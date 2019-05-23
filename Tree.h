//
// Created by Iulian on 5/23/2019.
//

#ifndef TEMA_3_POO_HARTA_TREE_H
#define TEMA_3_POO_HARTA_TREE_H

#include "Graph.h"
#include <vector>
#include <queue>

class Tree : public Graph{
    int n = 0;
    vector < pair< double, double> > nodes;
    vector <vector<pair<int,double> > >edges;
    vector <double> distance;
    vector <int> level;
    vector <int> euler;
    vector <int> app;
    vector <vector <int> >rmq;
    vector <bool> sel;

    int LCA (int x, int y);
    int log2 (int X);
    void Compute ();
    void Euler (int x);
public:
    void CreateGraph () override;
    int size () override;
    void GetDistance (const int x, const int y) override;
    void AddEdge (const int x, const int y) override;
    ~Tree () {};
};

int Tree :: log2 (int x){
    if (x == 0)return 0;
    int i = 0;
    while ((1 << i) < x)
        ++i;
    if (x < (1 << i))
        --i;
    return i;
}

void Tree :: Euler(int x) {
    euler.push_back(x);
    sel[x] = true;
    if (!app[x])
        app[x] = euler.size() - 1;
    for (int i = 0; i < edges[x].size(); ++i)
        if(!sel[edges[x][i].first]){
            Euler(edges[x][i].first);
            euler.push_back(x);
        }
}

void Tree :: Compute () {
    int x,y,i,j,L;
    double c;
    distance.resize (n,INF);
    level.resize (n);
    app.resize (n,0);
    level[0] = 1;
    distance[0] = 0;
    queue <int> q;
    q.push(0);
    while (!q.empty()){
        x = q.front();
        q.pop();
        for (i = 0; i < edges[x].size(); ++i){
            y = edges[x][i].first;
            c = edges[x][i].second;
            if (distance[x] + c < distance[y]){
                level[y] = level[x] + 1;
                distance[y] = distance[x] + c;
                q.push(y);
            }
        }
    }
    sel.resize(n,false);
    Euler(0);
    L = log2(euler.size()) + 1;
    rmq.resize(L);
    for (i = 0; i < euler.size(); ++i)rmq[0].push_back(i);
    for (i = 1; i < L; ++i) {
        for (j = 0; j < euler.size() - (1 << i) + 1; ++j) {
            if (level[euler[rmq[i - 1][j]]] < level[euler[rmq[i - 1][j + (1 << (i - 1))]]])
                rmq[i].push_back(rmq[i - 1][j]);
            else
                rmq[i].push_back(rmq[i - 1][j + (1 << (i - 1))]);
        }
    }
}

int Tree :: LCA (int x, int y){
    int i,A = app[x],B = app[y];
    if (A > B)
        swap(A,B);
    i = log2 (B - A);
    if (level[ euler[rmq[i][A]] ] < level[ euler[rmq[i][B - (1 << i) + 1]] ])
        return euler[rmq[i][A]];
    return euler[rmq[i][B - (1 << i) + 1]];
}

int Tree :: size() {
    return n;
}

void Tree :: AddEdge(const int x, const int y) {

}

void Tree :: CreateGraph () {
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
    cout << "\nIntroduceti muchiile in forma X Y cu spatiu intre ele si apoi apasati Enter: ";
    edges.resize (n);
    for (i = 1; i < n; ++i){
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
    Compute();
}

void Tree :: GetDistance(const int x, const int y) {
    double D = distance[x - 1] + distance[y - 1] - 2 * distance[LCA(x - 1,y - 1)];
    cout << "\nLungimea drumului minim dintre orasul " << x << " si orasul " << y << " este de " << D << "!\n";
}

#endif //TEMA_3_POO_HARTA_TREE_H
