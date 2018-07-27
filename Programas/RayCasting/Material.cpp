#include "Material.h"

Material::Material(){
    this->Kamb = new Vertice( 0.3, 0.3, 0.3 );
    this->Kdif = new Vertice( 0.7, 0.7, 0.6 );
    this->Kesp = new Vertice( 0.7, 0.7, 0.6 );
    this->m = 1;
}

Material::Material(float* kambiente, float* kdifusa, float* kespecular, float mm){
    this->Kamb = new Vertice( kambiente[0], kambiente[1], kambiente[2] );
    this->Kdif = new Vertice( kdifusa[0], kdifusa[1], kdifusa[2] );
    this->Kesp = new Vertice( kespecular[0], kespecular[1], kespecular[2] );
    this->m = mm;
}
