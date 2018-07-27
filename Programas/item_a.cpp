#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

//cria matriz dada pelo usuário
double **preencher_matriz(int n){
    double **m = (double**)malloc(sizeof(double)*n);
	for(int i = 0; i < n+1; i++)
		m[i] = (double*) malloc(sizeof(double)*n);

    for(int i = 0; i<n; i++){
        for(int j=0;j<n; j++){
            cout << "M["<<i<<"]["<<j<<"]: ";
            cin >> m[i][j];
        }
    }
    cout<<endl;
    return m;
}

//cria vetor v dado pelo usuário
double *vetor(int n){
    double *v = (double*)malloc(sizeof(double)*n);
	/*for(int i = 0; i < n; i++)
		v[i] = (double*) malloc(sizeof(double));
*/
    for(int i=0;i<n;i++){
        cout<<"V["<<i<<"]: ";
        cin>>v[i];
    }
    cout<<endl;
    return v;
}

//imprime vetro(teste)
void *impritmir_vetor(double *v,int n){
    for(int i=0;i<n; i++){
        if(i==n-1){
            cout<<v[i]<<"\n";
        }
        else{
        cout<<v[i]<<" ; ";
        }
    }
    cout<<endl;
}

//concatena vetor v na matriz para criar a matriz aumentada
//double **matriz_aumentada(double **m, int n,double **v){
    /*m = (double**)realloc(m ,sizeof(double)*(n+1));
	for(int i = n; i < n+1; i++){
		m[i] = (double*) malloc(sizeof(double)*n);
	}*/
  /*  for(int i=0;i<n+1;i++){
        m[i][n]=v[0][i];
    }
    return m;
}*/

//imprime matriz
void imprimir_matriz(double **m, int n){
    for(int i = 0; i<n; i++){
        for(int j=0;j<n; j++){
            if(j==n-1){
				cout <<m[i][j]<<"\n";
			}
 			else{
 				cout << m[i][j]<<" ; ";
 			}
        }
    }
    cout<<endl;
}

//encontra posição do pivô da coluna(maior valor)
/*double achar_pivo(double **m,int n,int col){
    int posicao_pivo = m[0][col];
    for(int i = 1; i<=n; i++){
        if(m[i][col]>posicao_pivo){
            posicao_pivo = i;
        }
    }
    return posicao_pivo;
}*/

//troca duas linhas da atriz
/*double **trocar_linhas(double **m,int n, int col){
    int pivo;
    double **aux = (double**)malloc(sizeof(double)*n);
	for(int i = 0; i < n; i++)
		aux[i] = (double*) malloc(sizeof(double)*n);

    pivo = achar_pivo(m,n,col);
    cout<<pivo<<endl;
    if(pivo!=col){
        for(int i=0;i<=n;i++){
            aux[0][i] = m[pivo][i];
            m[pivo][i] = m[col][i];
            m[col][i] = aux[0][i];
        }
    }
    else{
        return m;
    }
    return m;
    free(aux);
}*/
//
//sem pivoteamento e com pivo diferente de zero
double **calcular_gauss(double **m,int n,double*v,double a){
    double pivo,f,d[n];
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(i!=j){
                pivo=m[i][i];
                f = m[j][i]/pivo;
                for(int k=0;k<n;k++){//percorre cada linha
                    double s = f*m[i][k];
                    double z = m[j][k];
                    m[j][k] = z - s;
                }

                v[j] = v[j] - f*v[i];

                }
            }
        }
    for (int i = 0; i < n; i++)
        d[i] = 1;
    for (int i = n-1; i >= 0; i--){
        double valor = 0;
        for (int j = 0; j < n; j++){
            if (i!=j){
                valor = valor + m[i][j]*d[j];
            }
        }
        d[i] = (v[i] - valor)/m[i][i];
    }
    for(int i=0;i<n;i++){
        d[i]=d[i]*a;
    }
    imprimir_matriz(m,n);
    impritmir_vetor(v,n);
    cout<<"Vetor d*a: "<<endl;
    impritmir_vetor(d,n);
}

int main(){
    double *v;
    int n;
    cout << "Quantidade de pêndulos: ";
    cin >> n;
    cout<<endl;
    double **c,**t;
    double a=0;
   double **m = preencher_matriz(n);
    imprimir_matriz(m,n);
    v = vetor(n);
    impritmir_vetor(v,n);
    //t =trocar_linhas(m,n,0);
    c=calcular_gauss(m,n,v,a);
    //imprimir_matriz(c,n);
    return 0;
}

