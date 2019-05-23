//
// Created by Bleo on 5/23/2019.
//

#ifndef TEMA_3_POO_HARTA_FACTORY_H
#define TEMA_3_POO_HARTA_FACTORY_H

//#include "Graph.h"

class Factory{
public:
    static Graph * NewGraph (const int code){
        switch (code){
            case 0 :
                return new GeneralGraph;
            case 1 :
                return new DirectedAcyclicGraph;
            case 2 :
                return new LineGraph;
            case 3 :
                return new Tree;
            case 4 :
                return new CompleteGraph;
        }
    }
};

#endif //TEMA_3_POO_HARTA_FACTORY_H
