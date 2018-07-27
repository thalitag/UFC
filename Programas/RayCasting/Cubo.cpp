#include "Cubo.h"
Cubo::Cubo(Material *mat){
    ListaVertices[0] = new Vertice(1, -1, 1);
    ListaVertices[1] = new Vertice(1, -1, -1);
    ListaVertices[2] = new Vertice(-1, -1, -1);
    ListaVertices[3] = new Vertice(-1, -1, 1);
    ListaVertices[4] = new Vertice(1, 1, 1);
    ListaVertices[5] = new Vertice(1, 1, -1);
    ListaVertices[6] = new Vertice(-1, 1, -1);
    ListaVertices[7] = new Vertice(-1, 1, 1);

    ListaFaces[0] = new Face(ListaVertices[3], ListaVertices[0], ListaVertices[7], mat);
    ListaFaces[1] = new Face(ListaVertices[0], ListaVertices[4], ListaVertices[7], mat);
    ListaFaces[2] = new Face(ListaVertices[0], ListaVertices[5], ListaVertices[4], mat);
    ListaFaces[3] = new Face(ListaVertices[0], ListaVertices[1], ListaVertices[5], mat);
    ListaFaces[4] = new Face(ListaVertices[2], ListaVertices[3], ListaVertices[6], mat);
    ListaFaces[5] = new Face(ListaVertices[3], ListaVertices[7], ListaVertices[6], mat);
    ListaFaces[6] = new Face(ListaVertices[1], ListaVertices[2], ListaVertices[5], mat);
    ListaFaces[7] = new Face(ListaVertices[2], ListaVertices[6], ListaVertices[5], mat);
    ListaFaces[8] = new Face(ListaVertices[0], ListaVertices[3], ListaVertices[1], mat);
    ListaFaces[9] = new Face(ListaVertices[3], ListaVertices[2], ListaVertices[1], mat);
    ListaFaces[10] = new Face(ListaVertices[7], ListaVertices[4], ListaVertices[6], mat);
    ListaFaces[11] = new Face(ListaVertices[4], ListaVertices[5], ListaVertices[6], mat);
}

void Cubo::translacao(float tx, float ty, float tz){
    int i;

    for( i=0; i<8; i++ )
        ListaVertices[i]->translacao(tx, ty, tz);
}

void Cubo::escala(float sx, float sy, float sz){
    int i;

    for( i=0; i<8; i++ )
        ListaVertices[i]->escala(sx, sy, sz);
}

void Cubo::rotacaoX(float ang){
    int i;

    for( i=0; i<8; i++ )
        ListaVertices[i]->rotacaoX(ang);
}

void Cubo::rotacaoY(float ang){
    int i;

    for( i=0; i<8; i++ )
        ListaVertices[i]->rotacaoY(ang);
}

void Cubo::rotacaoZ(float ang){
    int i;

    for( i=0; i<8; i++ )
        ListaVertices[i]->rotacaoZ(ang);
}
