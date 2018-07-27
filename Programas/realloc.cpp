#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){
	int n = 3;
	
	//Aloca memoria
	double **B = (double**)malloc(sizeof(double)*n);
	for(int i = 0; i < n; i++)
		B[i] = (double*) malloc(sizeof(double)*n);

	//Seta valores
	B[0][0] = 1;	B[0][1] = 2;	B[0][2] = 3;
	B[1][0] = 4;	B[1][1] = 5;	B[1][2] = 6;
	B[2][0] = 7;	B[2][1] = 8;	B[2][2] = 9;

	//Mostra matriz
	cout<<"Matriz inicial"<<endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout<<B[i][j]<<" ";
		}
		cout<<endl;
	}


	int addColunas = 1;

	//Realoca memoria para transformar em uma matriz mxn
	B = (double**)realloc(B ,sizeof(double)*(n+addColunas));
	for(int i = n; i < n+addColunas; i++)
		B[i] = (double*) malloc(sizeof(double)*n);

	//Seta novos valores para a coluna inserida
	B[0][3] = 1;	B[1][3] = 1;	B[2][3] = 1;
	
	//Mostra nova matriz
	cout<<"Nova matriz"<<endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n+addColunas; j++){
			cout<<B[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}