#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

#include "Graph.h"
#include "GeneralGraph.h"
#include "dag.h"
#include "LineGraph.h"
#include "CompleteGraph.h"
#include "Tree.h"
#include "Factory.h"

using namespace std;

void Interface (){
    int task,region_code,X,Y,R;
    vector < pair< Graph *,int> > regions;
    Graph * curr;
    cout << "Bun venit la MisterMaps! \n"
            "Pentru a crea o regiune introduceti 1 si apasati Enter.\n"
            "Pentru a adauga un drum intre 2 orase introduceti 2 si apasati Enter.\n"
            "Pentru a primi drumul minim dintre 2 orase introduceti 3 si apasati Enter.\n"
            "Pentru a inchide aplicatia introduceti 0 si apasati Enter.\n";
    cin >> task;
    while (true){
        if (task < 0 || task > 3)
            cout << "Ati introdus un cod de operatie invalid!\nVa rugam sa incercati dinnou!\n";
        if (task == 0) {
            cout << "Va multumim ca ati utilizat MisterMaps!\n";
            return ;
        }
        if (task == 1) {
            cout << "Ati ales sa creati o noua regiune! \nAcum va trebui sa precizati formatul regiunii\n"
                    "Pentru formatul unui graf general introduceti 0 si apasati Enter\n"
                    "Pentru un graf aciclic orientat introduceti 1 si apasati Enter\n"
                    "Pentru un graf in linie introduceti 2 si apasati Enter\n"
                    "Pentru un arbore introduceti 3 si apasati Enter\n"
                    "Pentru un graf complet introduceti 4 si apasati Enter\n";
            cin >> region_code;
            curr = Factory :: NewGraph (region_code);
            curr->CreateGraph ();
            regions.push_back (make_pair(curr,region_code));
            cout << "Regiunea " << regions.size() << " a fost adaugata!\n";
        }
        if (task == 2) {
            cout << "Ati ales sa adaugati un drum intre 2 orase!\n"
                    "Acum introduceti in ordine numarul regiunii si cele 2 orase : \n";
            cin >> R >> X >> Y;
            while (R < 1 || R > regions.size()){
                cout << "Regiunea introdusa nu exista!\nIntroduceti inca odata datele : \n";
                cin >> R >> X >> Y;
            }
            while (X > regions[R - 1].first->size() || X < 1 || Y < 1 || Y > regions[R - 1].first->size()){
                cout << "Orasele introduse nu se afla in regiune!\nIntroduceti inca odata datele : \n";
                cin >> R >> X >> Y;
                while (R < 1 || R > regions.size()){
                    cout << "Regiunea introdusa nu exista!\nIntroduceti inca odata datele : \n";
                    cin >> R >> X >> Y;
                }
            }
            if (regions[R - 1].second > 1)
                cout << "Regiunea " << R << " nu suporta adaugare de drum!\n";
            else{
                regions[R - 1].first->AddEdge (X,Y);
                cout << "Drumul a fost adaugat cu succes!\n";
            }
        }
        if (task == 3){
            cout << "Ati ales sa primiti lungimea drumului minim intre 2 orase!\n"
                    "Acum introduceti in ordine numarul regiunii si cele 2 orase : \n";
            cin >> R >> X >> Y;
            while (R < 1 || R > regions.size()){
                cout << "Regiunea introdusa nu exista!\nIntroduceti inca odata datele : \n";
                cin >> R >> X >> Y;
            }
            while (X > regions[R - 1].first->size() || X < 1 || Y < 1 || Y > regions[R - 1].first->size()){
                cout << "Orasele introduse nu se afla in regiune!\nIntroduceti inca odata datele : \n";
                cin >> R >> X >> Y;
                while (R < 1 || R > regions.size()){
                    cout << "Regiunea introdusa nu exista!\nIntroduceti inca odata datele : \n";
                    cin >> R >> X >> Y;
                }
            }
            regions[R - 1].first->GetDistance (X,Y);
        }
        cout << "\n\nPentru a crea o regiune introduceti 1 si apasati Enter.\n"
                "Pentru a adauga un drum intre 2 orase introduceti 2 si apasati Enter.\n"
                "Pentru a primi drumul minim dintre 2 orase introduceti 3 si apasati Enter.\n"
                "Pentru a inchide aplicatia introduceti 0 si apasati Enter.\n";
        cin >> task;
    }
}

int main() {
    Interface();
    Graph * A, * B, *C, *D, *E;
    A = new GeneralGraph();
    //A->CreateGraph();
    //A->AddEdge(2,5);
    //A->GetDistance(2,5);
    B = new DirectedAcyclicGraph();
    //B->CreateGraph();
    //B->AddEdge(2,5);
    //B->GetDistance(2,5);
    C = new LineGraph();
    //C->CreateGraph();
    //C->GetDistance(2,5);
    D = new CompleteGraph();
    //D -> CreateGraph();
    //D -> GetDistance(2,5);
    E = new Tree();
    //E->CreateGraph();
    //E->GetDistance(5,3);
    return 0;
}