#include "Face.h"
#include "SistemaLinear.h";
#include <iostream>
using namespace std;

Face::Face(Vertice* u, Vertice* v, Vertice* w, Material *mat){
	v1 = u;
    v2 = v;
    v3 = w;
    propriedadeMaterial = mat;
}

Vertice* Face::calculaNormal(){
	Vertice* w1 = v2->subtrairVetores(v1);
    Vertice* w2 = v3->subtrairVetores(v1);
    Vertice* N = w1->produtoVetorial(w2);
    N->normalizacao();

    delete w1;
    delete w2;
    return N;
}

float Face::getInterseccao(Vertice* u){
    Vertice* w1 = v2->subtrairVetores(v1);
    Vertice* w2 = v3->subtrairVetores(v1);
    w1->novaDirecao();
    w2->novaDirecao();
    float A[3][3] = {{u->x, w1->x, w2->x}, {u->y, w1->y, w2->y}, {u->z, w1->z, w2->z}};
    float b[3] = {v1->x, v1->y, v1->z};
    float* x = metodoGauss(A, b, 3);
    //Combinação Convexa
    float c = 1 - x[1] - x[2];

    delete w1;
    delete w2;

    if( ( x[1] > 0 ) && ( x[2] > 0 ) && ( c > 0 ) ){//Visivel
        return x[0];//Distancia real da face
    }

    return 99999;
}