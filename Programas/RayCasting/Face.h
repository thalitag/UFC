#ifndef FACE_H
#define FACE_H

#include "Vertice.h"
#include "Material.h"

class Face{
	public:
		Material* propriedadeMaterial;
		Vertice *v1, *v2, *v3;

		Face(Vertice* u, Vertice* v, Vertice* w, Material *mat);
		Vertice* calculaNormal();
		float getInterseccao(Vertice* u);
};

#endif
