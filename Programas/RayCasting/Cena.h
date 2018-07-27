#ifndef CENA_H
#define CENA_H

#include "FonteLuminosa.h"
#include "Cubo.h"

class Cena{
public:
    Cena();
    void modelagem();

    Cubo *piso;//Piso
    Cubo *parede1, *parede2, *parede3, *parede4, *parede5;//Paredes internas
    //Cubo *parede6, *parede7, *parede8, *parede9;//Paredes externas

    //Cozinha
    Cubo *microondas, *microondas2, *microondas3;//Microondas
    Cubo *balcao1, *balcao2, *balcao3;//Balcão
    Cubo *geladeira, *divisoriaGel, *puxador1;//Geladeira
    Cubo *cadeira1, *cadeira2, *cadeira3, *cadeira2_1, *cadeira2_2, *cadeira2_3, *cadeira3_1, *cadeira3_2, *cadeira3_3, *cadeira4_1, *cadeira4_2, *cadeira4_3;//Cadeiras
    Cubo *tampo, *perna1, *perna2, *perna3, *perna4;//Mesa

    //Sala
    Cubo *sofa1, *sofa2, *sofa3, *sofa4;//Sofá
    Cubo *tv1, *tv2;//Televisão

    //Quarto Casal
    Cubo *cama1c, *cama2c, *cama3c, *cama4c, *colchaoc;//Cama casal
    Cubo *guardaRc, *divisorRc, *puxador1Rc, *puxador2Rc, *gavetac, *puxador3Rc;//Guarda Roupas

    //Quarto Solteiro
    Cubo *cama1s, *cama2s, *cama3s, *cama4s, *colchaos;//Cama solteiro
    Cubo *guardaRs, *divisorRs, *puxador1Rs, *puxador2Rs, *gavetas, *puxador3Rs;//Guarda Roupas

    //Banheiro
    Cubo *sanitario1, *sanitario2, *sanitario3, *sanitario4, *sanitario5;//Sanitario
    Cubo *pia1, *pia2, *pia3, *pia4;//Pia
    Cubo *torneira1, *torneira2, *torneira3;//Torneira
    Cubo *chuveiro1, *chuveiro2, *chuveiro3;//Chuveiro


    Cubo* ListaObjetos[75];//75
    FonteLuminosa* LS;
};

#endif
