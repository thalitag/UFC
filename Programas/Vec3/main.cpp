#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "Vec3.h"

using namespace std;

void transformarEmGrau(float anguloRad);

int main(int argc, char *argv[])
{

    Vec3 v(5,2,9);
    Vec3 u(7,1,-3);
    cout << "Vetor v: ";
    v.imprimir();
    cout << "Vetor u: ";
    u.imprimir();

    double a = v.anguloEntreVetores(u);
    cout << "\n Angulo entre v e u: "<< endl;
    transformarEmGrau(a);

    cout<< "Produto escalar v.u = "<<v.produtoEscalar(u);
    cout<< "\nProduto vetorial v e u: ";
    v.produtoVetorial(u).imprimir();

    cout<<"\nProjecao de v sobre u: ";
    v.projecao(u).imprimir();

    v.
}

void transformarEmGrau(float anguloRad){//imprime valor do angulo em graus
        cout<<(180*anguloRad/M_PI)<<" graus"<<endl;

}
