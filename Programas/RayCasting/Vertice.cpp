#include "Vertice.h"
#include "Matriz.h"
#include <cmath>
using namespace std;

Vertice::Vertice(){
    this->x = 1;
    this->y = 1;
    this->z = 1;
}

Vertice::Vertice(float nx, float ny, float nz){
    this->x = nx;
    this->y = ny;
    this->z = nz;
}

void Vertice::escala(float sx, float sy, float sz){
    this->x = this->x*sx;
    this->y = this->y*sy;
    this->z = this->z*sz;
}

void Vertice::translacao(float tx, float ty, float tz){
    this->x = this->x + tx;
    this->y = this->y + ty;
    this->z = this->z + tz;
}

void Vertice::rotacaoX(float ang){
	//Matriz de rotação em X
    float R[4][4] = {{1,0,0,0}, {0,cos(ang),-sin(ang),0}, {0,sin(ang),cos(ang),0}, {0,0,0,1}};
    //Vetor de multiplicação
    float v[4] = {this->x,this->y,this->z,1};

    //Multiplica vetor por Matriz
    float* u;
    u = vetorMultMatriz(R, v);

    this->x = u[0];
    this->y = u[1];
    this->z = u[2];
}

void Vertice::rotacaoY(float ang){
	//Matriz de rotação em Y
    float R[4][4] = {{cos(ang),0,sin(ang),0}, {0,1,0,0}, {-sin(ang),0,cos(ang),0}, {0,0,0,1}};
    //Vetor de multiplicação
    float v[4] = {this->x,this->y,this->z,1};

    //Multiplica vetor por Matriz
    float* u;
    u = vetorMultMatriz(R, v);

    this->x = u[0];
    this->y = u[1];
    this->z = u[2];
}

void Vertice::rotacaoZ(float ang){
	//Matriz de rotação em Z
    float R[4][4] = {{cos(ang),-sin(ang),0,0}, {sin(ang),cos(ang),0,0}, {0,0,1,0}, {0,0,0,1}};
    //Vetor de multiplicação
    float v[4] = {this->x,this->y,this->z,1};

    //Multiplica vetor por Matriz
    float* u;
    u = vetorMultMatriz(R, v);

    this->x = u[0];
    this->y = u[1];
    this->z = u[2];
}

void Vertice::normalizacao(){
    float n = norma();

    this->x = this->x/n;
   	this->y = this->y/n;
    this->z = this->z/n;
}

float Vertice::norma(){
    return sqrt(x*x + y*y + z*z);
}

void Vertice::novaDirecao(){
    this->x=-x;
    this->y=-y;
    this->z=-z;
}

float Vertice::produtoEscalar(Vertice* u){
	return this->x*u->x + this->y*u->y + this->z*u->z;
}

Vertice* Vertice::somarVetores(Vertice* u){
	Vertice* v = new Vertice(this->x + u->x, this->y + u->y, this->z + u->z);

    return v;
}

Vertice* Vertice::subtrairVetores(Vertice* u){
	Vertice* v = new Vertice(this->x - u->x, this->y - u->y, this->z - u->z);

    return v;
}

Vertice* Vertice::ProdutoCorrespondente(Vertice* u){
    Vertice* v = new Vertice(this->x*u->x, this->y*u->y, this->z*u->z);

    return v;
}

Vertice* Vertice::produtoVetorial(Vertice* u){
    Vertice* v = new Vertice(this->y*u->z - this->z*u->y, (this->z*u->x - this->x*u->z), this->x*u->y - this->y*u->x);

    return v;
}

Vertice* Vertice::vetorEscalar(float k){
	Vertice* v = new Vertice(this->x*k, this->y*k, this->z*k);

    return v;
}


