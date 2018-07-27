#include "Janela.h"
#include "Face.h"
#include <cstddef>
#include <math.h>
#include <iostream>
using namespace std;

Janela::Janela(float d, int nx, int ny, float w, float h){
    this->distance = d;
    this->Nx = nx;
    this->Ny = ny;
    this->W = w;
    this->H = h;

    this->pixelCores = new Vertice**[Nx];

    for( int i=0; i<Nx; i++ )
        this->pixelCores[i] = new Vertice*[Ny];

    for( int i=0; i<Nx; i++ ){
        for( int j=0; j<Ny; j++ )
            this->pixelCores[i][j] = new Vertice(1, 1, 1);
    }
}

void Janela::rayCasting(Cena *c){
    for( int i=0; i<Nx; i++ ){
        for( int j=0; j<Ny; j++ ){
            Vertice* pixel = new Vertice((-W/2 + (W/Nx)/2 + j*(W/Nx)), (H/2 - (H/Ny)/2 - i*(H/Ny)), -distance );
            Face* f = NULL;
            float t = 99999;

            for( int k=0; k<75; k++ ){//tem q saber o tamanho da lista de objetos
                for( int l=0; l<12; l++ ){//tem q saber o tamanho da lista de faces
                    Vertice* n = c->ListaObjetos[k]->ListaFaces[l]->calculaNormal();

                    if( n->produtoEscalar(pixel) < 0 ){
                        float tt = c->ListaObjetos[k]->ListaFaces[l]->getInterseccao(pixel);
                        if( tt < t ){
                            f = c->ListaObjetos[k]->ListaFaces[l];
                            t = tt;
                        }
                    }
                }
            }

            if( f != NULL ){
                getPixColor(f, pixel->vetorEscalar(t), c->LS, i, j);
            }
            else{
                pixelCores[i][j]->x=1.0;
                pixelCores[i][j]->y=1.0;
                pixelCores[i][j]->z=1.0;
            }
            delete pixel;
        }
    }

    normalizacaoCores();
}

void Janela::getPixColor(Face *f, Vertice* IP, FonteLuminosa *ls, int i, int j){
    Vertice* n = f->calculaNormal();

    Vertice* l = ls->posicao->subtrairVetores(IP);
    l->normalizacao();
    IP->novaDirecao();
    Vertice* v = IP;
    v->normalizacao();

    float t = 2*l->produtoEscalar(n);
    Vertice* r = n->vetorEscalar(t);
    r = r->subtrairVetores(l);

    Vertice* compAmb = ls->Iamb->ProdutoCorrespondente(f->propriedadeMaterial->Kamb);

    Vertice* compDif = ls->Idif->ProdutoCorrespondente(f->propriedadeMaterial->Kdif);
    compDif = compDif->vetorEscalar(n->produtoEscalar(l));
    if( n->produtoEscalar(l) < 0 ){
        compDif->x = 0;
        compDif->y = 0;
        compDif->z = 0;
    }

    t = r->produtoEscalar(v);
    t = pow(t,f->propriedadeMaterial->m);
    Vertice* compEsp = new Vertice(0, 0, 0);
    if( t>0 ){
        compEsp = ls->Iesp->ProdutoCorrespondente(f->propriedadeMaterial->Kesp);
        compEsp = compEsp->vetorEscalar(t);
    }

    Vertice* intLuz = compAmb->somarVetores(compDif);
    intLuz = intLuz->somarVetores(compEsp);

    pixelCores[i][j]->x = intLuz->x;
    pixelCores[i][j]->y= intLuz->y;
    pixelCores[i][j]->z= intLuz->z;

    delete intLuz;
    delete compEsp;
    delete compAmb;
    delete compDif;
    delete n;
    delete l;
    delete r;
}

void Janela::normalizacaoCores(){
    float t = pixelCores[0][0]->x;

    for( int i=0; i<Nx; i++ ){
        for(int j=0; j<Ny; j++){
            float t1 = pixelCores[i][j]->x;
            float t2 = pixelCores[i][j]->y;
            float t3 = pixelCores[i][j]->z;

            if( t1 > t2 && t1 > t3 && t1 > t )
                t = t1;
            if( t2 > t1 && t2 > t3 && t2 > t )
                t = t2;
            if( t3 > t2 && t3 > t1 && t3 > t )
                t = t3;
        }
    }
    
    if( t > 1 ){

        for( int i=0; i<Nx; i++ ){
            for( int j=0; j<Ny; j++ ){
                pixelCores[i][j]->x /= t;
                pixelCores[i][j]->y /= t;
                pixelCores[i][j]->z /= t;
            }
        }
    }
}
