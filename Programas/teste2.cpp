#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;



//coloca valor na função principal
float Funcao(float var,float a,float b){

    float funcao = a*pow(var,3)-9*b*var+3;

    return funcao;
}

//coloca valor na derivada
float Derivada(float var, float a, float b){

    float derivada = 3*a*pow(var,2)-9*b;

    return derivada;
}


//descobre o eixo onde foi encontrada a primeira raiz da funçao
bool Eixo(float fun1,float fun2,float fun3,float fun4){

    if(fun1*fun2 < 0){

        bool positivo = true;

        return positivo;

    }

    if(fun3*fun4 < 0){

        bool negativo = false;

        return negativo;
    }

}

//retorna o x inicial
float Xinicial(float a, float b){

    float x[10];
	int d = 0,k = 0;
	int e = d+1;
    int f = d;
	int g = f-1;


    float funcao = Funcao(d,a,b);
    float funcao2 = Funcao(e,a,b);
    float funcao3 = Funcao(f,a,b);
	float funcao4 = Funcao(g,a,b);

	while (funcao*funcao2 > 0 && funcao3*funcao4 > 0 ){

		d++;
		e++;
        f--;
        g--;

        funcao = Funcao(d,a,b);
        funcao2 = Funcao(e,a,b);
        funcao3 = Funcao(f,a,b);
        funcao4 = Funcao(g,a,b);

    }

    if(Eixo(funcao,funcao2,funcao3,funcao4) == 1){

        float v1 = (a*pow(d,3)-9*b*d+3)*(6*a*d);
        float v2 = (a*pow(e,3)-9*b*e+3)*(6*a*e);

        if(v1 >= 0){

            x[0] = d;

        }

        else{

            x[0] = e;

        }

    }

    else{

        float v3 = (a*pow(f,3)-9*b*f+3)*(6*a*f);
        float v4 = (a*pow(g,3)-9*b*g+3)*(6*a*g);

        if(v3 >= 0){

            x[0] = f;

        }

        else {

            x[0] = g;

        }

    }

    return x[0];

}


//checa se há raiz no intervalo
bool ChecaInter(float ini, float fim, float a, float b){

    float fun1 = Funcao(ini,a,b);
    float fun2 = Funcao(fim,a,b);

    if(fun1*fun2 < 0){

        return true;

    }

    else {

        return false;

    }

}

//retorna o deslocamento
float Deslocamento(float a, float b, float precisao){

    float deslocamento, x[10];

    x[0] = Xinicial(a,b);


    if(fabs(Funcao(x[0],a,b)) < precisao){

        deslocamento = x[0];

    }

    else{

        int i = 1;
        //criterio de parada |xn+1-xn|<precisao;
        x[i] = x[i-1] - (Funcao(x[i-1],a,b))/(Derivada(x[i-1],a,b));

            while(fabs(x[i]-x[i-1]) >= precisao){

                i = i + 1;

                x[i] = x[i-1] - (Funcao(x[i-1],a,b))/(Derivada(x[i-1],a,b));
            }

        deslocamento = x[i];

    }

    return deslocamento;

}



int main(){

    char resposta;
    bool positivo, negativo;
	float ini,fim,a,b,precisao;
	float x[10];

    cout << "Insira o valor para a3, a2 e a precisão" << endl;
	cin >> a;
	cin >> b;
    cin >> precisao;

    cout << "Checar se há raiz em um intervalo?"<<" "<<"s/n"<<endl;
	cin >> resposta;

	if(resposta == 's' || resposta == 'S'){

        cout<< "Insira o valor inicial e final do intervalo:"<<" "<<endl;
        cin >> ini;
        cin >> fim;

        if(ChecaInter(ini,fim,a,b) == 1){

            cout << "Há raiz no intervalo"<<" "<<"("<<ini<<","<<fim<<")"<<endl;

        }

        else{

            cout << "Não há raiz no intervalo"<<" "<<"("<<ini<<","<<fim<<")"<<endl;

        }

    }

    else{

        cout <<"Deslocamento" <<" "<< Deslocamento(a,b,precisao) <<endl;

    }

    return 0;
}










