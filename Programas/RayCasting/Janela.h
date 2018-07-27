#ifndef JANELA_H
#define JANELA_H

#include "Vertice.h"
#include "Cena.h"

class Janela{
public:
    Janela(float d, int nx, int ny, float w, float h);
    
    Vertice*** pixelCores;
    float distance;
    int Nx, Ny;
    float W, H;

    void rayCasting(Cena *c);
    void getPixColor(Face*f, Vertice *IP, FonteLuminosa *ls, int i, int j);
    void normalizacaoCores();
};

#endif
