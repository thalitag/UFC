#include "SistemaLinear.h"
#include <cmath>
using namespace std;

float* metodoGauss(float A[][3], float b[], int n){
    eliminacaoGauss(A, b, n);
    return voltarSubstituicao(A, b, n);
}

void eliminacaoGauss(float A[][3], float b[], int n){
    float m;
    int i, j, k;

    for(k=0; k<n-1; k++){
        for(i=k+1; i<n; i++){
            pivotacaoParcial(A, b, k, n);
            m = - A[i][k]/A[k][k];
            A[i][k] = 0;
            for(j=k+1; j<n; j++)
                A[i][j] = A[i][j] + m*A[k][j];
            b[i] = b[i] + m*b[k];
        }
    }
}

float pivotacaoParcial(float A[][3], float b[], int k, int n){
    int i, j;
    float m;

    j = k;
    m = abs( A[k][k] );

    for( i=k+1; i<n; i++){
        if( m < abs( A[i][k] ) ){
            m = abs( A[i][k] );
            j = i;
        }
    }

    if( j != k )
        trocaLinhas(A, b, j, k, n);

    return A[j][k];
}

void trocaLinhas(float A[][3], float b[], int j, int k, int n){
    int i;
    float t;

    for( i=0; i<n; i++){
        t = A[j][i];
        A[j][i] = A[k][i];
        A[k][i] = t;
    }

    t = b[j];
    b[j] = b[k];
    b[k] = t;
}

float* voltarSubstituicao(float A[][3], float b[], int n){
    float* x = new float[n];
    float s;
    int k, j;

    x[n-1] = b[n-1]/A[n-1][n-1];
    for(k=n-2; k>-1; k--){
        s = 0;
        for(j=k+1; j<n; j++)
            s = s + A[k][j]*x[j];
        x[k] = (b[k] - s)/A[k][k];
    }

    return x;
}
