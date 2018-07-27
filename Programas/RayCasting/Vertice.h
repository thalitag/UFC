#ifndef VERTICE_H
#define VERTICE_H

class Vertice{
	public:
		float x, y, z;

		Vertice();
		Vertice(float, float, float);

		void escala(float, float, float);
        void translacao(float, float, float);
		void rotacaoX(float);
		void rotacaoY(float);
		void rotacaoZ(float);
		void normalizacao();
		float norma();
		void novaDirecao();
		float produtoEscalar(Vertice*);
		Vertice* somarVetores(Vertice*);
		Vertice* subtrairVetores(Vertice*);
		Vertice* ProdutoCorrespondente(Vertice*);
		Vertice* produtoVetorial(Vertice*);
		Vertice* vetorEscalar(float);

};

#endif
