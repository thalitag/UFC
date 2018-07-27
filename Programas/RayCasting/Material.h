#ifndef MATERIAL_H
#define MATERIAL_H

#include "Vertice.h"

class Material{
	public:
	    Material();
	    Material(float* kAmbiente, float* kDifusa, float* kEspecular, float mm);
	    Vertice *Kamb, *Kdif, *Kesp;
	    float m;//Coeficiente de Polimento
};

#endif
