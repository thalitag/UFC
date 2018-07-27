#ifndef OBSERVADOR_H
#define OBSERVADOR_H

#include "Vertice.h"
#include "Janela.h"
#include "Cena.h"

class Observador{
public:
    Observador(Vertice* observerPos, Vertice* lookAt, Vertice* viewUp, int d, int Nx, int Ny, float W, float H);

    void T_w_c(Cena* c);
    float Tc_m[4][4];
    float Tm_c[4][4];

    Janela* kwindow;

    Vertice* observerPosition;
    Vertice* lookAt;
    Vertice* viewUp;
    Vertice *Ic, *Jc, *Kc;

};

#endif
