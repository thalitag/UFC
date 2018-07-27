#include "FonteLuminosa.h"

FonteLuminosa::FonteLuminosa(float *ia, float *id, float *ie, Vertice *v){
    this->Iamb = new Vertice( ia[0], ia[1], ia[2] );
    this->Idif = new Vertice( id[0], id[1], id[2] );
    this->Iesp = new Vertice( ie[0], ie[1], ie[2] );
    this->posicao = v;
}
