#ifndef SISTEMALINEAR_H
#define SISTEMALINEAR_H

float* metodoGauss(float A[][3], float b[], int n);
void eliminacaoGauss(float A[][3], float b[], int n);
float pivotacaoParcial(float A[][3], float b[], int k, int n);
void trocaLinhas(float A[][3], float b[], int j, int k, int n);
float* voltarSubstituicao(float A[][3], float b[], int n);

#endif
