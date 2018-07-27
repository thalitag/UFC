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

    for(int i=0;i<n;i++){
        cout<<"V["<<i<<"]: ";
        cin>>v[i];
    }
    cout<<endl;
    return v;
}

//imprime vetor(teste)
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


double **calcular_gauss(double **m,int n){
    double pivo,f,det=1;
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
            }
        }
    }
    return m;
}
//usar depois de gauss
double determinante(double **m,int n){
    m=calcular_gauss(m,n);
    double det=1;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(i==j){
                det=det*m[i][j];
            }
        }
    }

    return det;
}

double *cramer(double **m, int n,double *v,double a){
    double **m_aux = (double**)malloc(sizeof(double)*n);
        for(int i = 0; i < n+1; i++)
            m_aux[i] = (double*) malloc(sizeof(double)*n);

    double *det = (double*)malloc(sizeof(double)*n);

    //matriz auxiliar recebe matriz principal
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            m_aux[i][j]=m[i][j];
        }
    }
    //calcula determinante trocando as colunas
    for(int i=0;i<n;i++){
        int k;
        for(int j=0;j<n;j++){
            for(int k=i;k==i;k++){
                m_aux[j][k]=v[j];
            }
        }

        det[i]=determinante(m_aux,n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                m_aux[i][j]=m[i][j];
            }
        }
    }

    //determinate da matriz principal
    double D=determinante(m,n);

    for(int i=0;i<n;i++){
        det[i]=(det[i]/D)*a;
    }
    return det;
}




int main(){
    double *v,*d;
    int n;
    cout << "Quantidade de pêndulos: ";
    cin >> n;
    cout<<endl;
    double **c,**t;
    double a=0;
    double **m = preencher_matriz(n);
    imprimir_matriz(m,n);
    //c=calcular_gauss_determinate(m,n);
   // cout<<c;
    v=vetor(n);
    impritmir_vetor(v,n);
    d=cramer(m,n,v,a);
    impritmir_vetor(d,n);
    return 0;
}

