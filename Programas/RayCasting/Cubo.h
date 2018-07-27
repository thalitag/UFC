#ifndef CUBO_H
#define CUBO_H

#include "Vertice.h"
#include "Face.h"
#include "Material.h"

class Cubo{
	public:
	    Cubo(Material *mat);
        Vertice *ListaVertices[8];
	    Face* ListaFaces[12];

	    void translacao(float, float, float);
	    void escala(float, float, float);
	    void rotacaoX(float);
	    void rotacaoY(float);
	    void rotacaoZ(float);
};

#endif
