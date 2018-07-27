#include "Vec3.h"
#include <cmath>
#include <math.h>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

Vec3::Vec3(){ }

Vec3::~Vec3(){ }

Vec3::Vec3(float x, float y, float z){
    this->x = x;
    this->y = y;
    this->z = z;
    this->comprimento = this->modulo();
}

void Vec3::imprimir(){
    cout<<"("<< this->x <<", "<< this->y <<", "<< this->z<<")"<< endl;

}

Vec3 Vec3::operator+(const Vec3& vetor) const{
    return Vec3(this->x+vetor.x, this->y+vetor.y, this->z+vetor.z);
}

Vec3 Vec3::operator-(const Vec3& vetor) const{
    return Vec3(this->x-vetor.x, this->y-vetor.y, this->z-vetor.z);
}

Vec3 &Vec3::operator+=(const Vec3& vetor) {
    this->x+=vetor.x;
    this->y+=vetor.y;
    this->z+=vetor.z;
    return *this;
}

Vec3 &Vec3::operator-=(const Vec3& vetor) {
    this->x-=vetor.x;
    this->y-=vetor.y;
    this->z-=vetor.z;
    return *this;
}

Vec3 Vec3 ::operator*(float escalar) const{
    return Vec3(this->x*escalar, this->y*escalar, this->z*escalar);

}

Vec3 &Vec3::operator*=(float escalar) {
    this->x*=escalar;
    this->y*=escalar;
    this->z*=escalar;
    return *this;
}
Vec3 Vec3 ::operator/(float escalar) const{
    return Vec3(this->x/escalar, this->y/escalar, this->z/escalar);

}

Vec3 &Vec3::operator/=(float escalar) {
    this->x/=escalar;
    this->y/=escalar;
    this->z/=escalar;
    return *this;
}


float Vec3::modulo()const{
    return sqrt(this->x*this->x + this->y*this->y + this->z*this->z);
}


Vec3 &Vec3::normalizar(){
    return *this/=this->modulo();
}

float Vec3::produtoEscalar(const Vec3& vetor) const{
    return (this->x*vetor.x+this->y*vetor.y+this->z*vetor.z);
}

Vec3 Vec3::produtoVetorial(const Vec3& vetor)const{
    return Vec3(this->y*vetor.z-vetor.y*this->z, -1*(this->x*vetor.z-vetor.x*this->z),this->x*vetor.y-vetor.x*this->y);

}

double Vec3::anguloEntreVetores(const Vec3& vetor) const{
    return acos(this->produtoEscalar(vetor)/(this->comprimento*vetor.comprimento));

}

Vec3 Vec3::projecao(const Vec3& vetor)const{
    return Vec3(vetor*(this->produtoEscalar(vetor)/pow(vetor.comprimento,2)));

}

void Vec3::setX(float x){
    this->x = x;
}

void Vec3::setY(float y){
    this->y = y;
}

void Vec3::setZ(float z){
    this->z = z;
}

