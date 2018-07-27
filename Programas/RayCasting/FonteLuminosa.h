#ifndef FONTELUMINOSA_H
#define FONTELUMINOSA_H

#include "Vertice.h"

class FonteLuminosa{
	public:
	    Vertice *Iamb, *Idif, *Iesp;
	    Vertice* posicao;
	    FonteLuminosa(float* ia, float* id, float* ie, Vertice* v);
};

#endif
