#include "Observador.h"
#include "Matriz.h"

Observador::Observador(Vertice* observerPos, Vertice* lookAt, Vertice* viewUp, int d, int Nx, int Ny, float W, float H){
    observerPosition = observerPos;
    this->lookAt = lookAt;
    this->viewUp = viewUp;

    Kc = observerPosition->subtrairVetores(lookAt);
    Kc->normalizacao();

    this->viewUp = viewUp->subtrairVetores(observerPosition);

    Ic = this->viewUp->produtoVetorial(Kc);
    Ic->normalizacao();

    Jc = Kc->produtoVetorial(Ic);

    kwindow = new Janela(d, Nx, Ny, W, H);

    Tc_m[0][0] = Ic->x; Tc_m[0][1] = Jc->x; Tc_m[0][2] = Kc->x; Tc_m[0][3] = observerPosition->x;
    Tc_m[1][0] = Ic->y; Tc_m[1][1] = Jc->y; Tc_m[1][2] = Kc->y; Tc_m[1][3] = observerPosition->y;
    Tc_m[2][0] = Ic->z; Tc_m[2][1] = Jc->z; Tc_m[2][2] = Kc->z; Tc_m[2][3] = observerPosition->z;
    Tc_m[3][0] = 0;     Tc_m[3][1] = 0;     Tc_m[3][2] = 0;     Tc_m[3][3] = 1;

    Tm_c[0][0] = Ic->x; Tm_c[0][1] = Ic->y; Tm_c[0][2] = Ic->z; Tm_c[0][3] = -observerPosition->produtoEscalar(Ic);
    Tm_c[1][0] = Jc->x; Tm_c[1][1] = Jc->y; Tm_c[1][2] = Jc->z; Tm_c[1][3] = -observerPosition->produtoEscalar(Jc);
    Tm_c[2][0] = Kc->x; Tm_c[2][1] = Kc->y; Tm_c[2][2] = Kc->z; Tm_c[2][3] = -observerPosition->produtoEscalar(Kc);
    Tm_c[3][0] = 0;     Tm_c[3][1] = 0;     Tm_c[3][2] = 0;     Tm_c[3][3] = 1;
}

void Observador::T_w_c(Cena *c){
    float v[4];
    float* u;
    v[3] = 1;

    for( int i=0; i<75; i++ ){//saber tamanho da lista de objetos
        for( int j=0; j<8; j++ ){//saber quantidade de vertices por objeto
            v[0] = c->ListaObjetos[i]->ListaVertices[j]->x;
            v[1] = c->ListaObjetos[i]->ListaVertices[j]->y;
            v[2] = c->ListaObjetos[i]->ListaVertices[j]->z;
            u = vetorMultMatriz(Tm_c, v);

            c->ListaObjetos[i]->ListaVertices[j]->x = u[0];
            c->ListaObjetos[i]->ListaVertices[j]->y = u[1];
            c->ListaObjetos[i]->ListaVertices[j]->z = u[2];
            delete u;
        }
    }

    v[0] = c->LS->posicao->x; v[1] = c->LS->posicao->y; v[2] = c->LS->posicao->z; v[3] = 1;
    u = vetorMultMatriz(Tm_c, v);

    c->LS->posicao->x = u[0]; c->LS->posicao->y = u[1]; c->LS->posicao->z = u[2];

    delete u;

    observerPosition->x = 0; observerPosition->y = 0; observerPosition->z = 0;
}
