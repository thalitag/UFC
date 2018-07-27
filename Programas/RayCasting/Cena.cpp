    #include "Cena.h"
    #include "Material.h"
    #include <cmath>
    using namespace std;

    Cena::Cena(){
        //Materiais e Cores
        float cor[3] = {0.66, 0.46, 0.4};
        Material* m = new Material(cor, cor, cor, 0.1);

        float corPiso[3] = {0.86, 0.86, 0.86};
        Material *m1 = new Material(corPiso, corPiso, corPiso, 0.1);

        float corParede[3] = {0.69, 0.76, 0.87};
        Material *m2 = new Material(corParede, corParede, corParede, 0.1);

        float branco[3] = {1, 1, 1};
        Material *corBranco = new Material(branco, branco, branco, 0.1);

        float preto[3] = {0, 0, 0};
        Material *corPreto = new Material(preto, preto, preto, 0.1);

        float cinza[3] = {0.5, 0.5, 0.5};
        Material *corCinza = new Material(cinza, cinza, cinza, 0.1);

        float prata[3] = {0.7529, 0.7529, 0.7529};
        Material *corPrata = new Material(prata, prata, prata, 0.1);

        float corTv2[3] = {0.3, 0.3, 0.3};
        Material *m4 = new Material(corTv2,corTv2,corTv2, 0.1);

        float corBalcao[3] = {0.56,0.46,0.3};
        Material *m5 = new Material(corBalcao, corBalcao, corBalcao, 0.1);

        float corMic2[3] = {0.35, 0.35, 0.35};
        Material *m7 = new Material(corMic2, corMic2, corMic2, 0.1);

        float corSofa[3] = {0.6, 0.6, 0.6};
        Material *m8 = new Material(corSofa, corSofa, corSofa, 0.1);

        float corColc[3] = {0.8, 0.8, 0.8};
        Material *m9 = new Material(corColc, corColc, corColc, 0.1);


        //Piso
        piso = new Cubo(m1);

        //Paredes
        parede1 = new Cubo(m2);
        parede2 = new Cubo(m2);
        parede3 = new Cubo(m2);
        parede4 = new Cubo(m2);
        parede5 = new Cubo(m2);


        /*Cozinha*/
        //Microondas
        microondas = new Cubo(corBranco);
        microondas2 = new Cubo(m7);
        microondas3 = new Cubo(corBranco);

        //Balcão
        balcao1 = new Cubo(m5);
        balcao2 = new Cubo(m);
        balcao3 = new Cubo(m);

        //Geladeira
        geladeira = new Cubo(corBranco);
        puxador1 = new Cubo(corPrata);
        divisoriaGel = new Cubo(corPrata);

        //Cadeiras
        cadeira2_1 = new Cubo(m);
        cadeira2_2 = new Cubo(m);
        cadeira2_3 = new Cubo(m);

        cadeira3_1 = new Cubo(m);
        cadeira3_2 = new Cubo(m);
        cadeira3_3 = new Cubo(m);

        cadeira4_1 = new Cubo(m);
        cadeira4_2 = new Cubo(m);
        cadeira4_3 = new Cubo(m);

        cadeira1 = new Cubo(m);
        cadeira2 = new Cubo(m);
        cadeira3 = new Cubo(m);

        //Mesa
        tampo = new Cubo(m);
        perna1 = new Cubo(m);
        perna2 = new Cubo(m);
        perna3 = new Cubo(m);
        perna4 = new Cubo(m);


        /*Sala*/
        //Sofá
        sofa1 = new Cubo(m8);
        sofa2 = new Cubo(m8);
        sofa3 = new Cubo(m8);
        sofa4 = new Cubo(m8);

        //Televisão
        tv1 = new Cubo(corPreto);
        tv2 = new Cubo(m4);

        /*Quarto casal*/
        //Cama casal
        cama1c = new Cubo(m);
        cama2c = new Cubo(m);
        cama3c = new Cubo(m);
        cama4c = new Cubo(m);
        colchaoc = new Cubo(m9);

        //Guarda Roupas
        guardaRc = new Cubo(m);
        gavetac = new Cubo(m);
        puxador3Rc = new Cubo(corPrata);
        divisorRc = new Cubo(corPreto);
        puxador1Rc = new Cubo(corPrata);
        puxador2Rc = new Cubo(corPrata);


        /*Quarto solteiro*/
        //Cama solteiro
        cama1s = new Cubo(m);
        cama2s = new Cubo(m);
        cama3s = new Cubo(m);
        cama4s = new Cubo(m);
        colchaos = new Cubo(m9);

        //Guarda Roupas
        guardaRs = new Cubo(m);
        gavetas = new Cubo(m);
        puxador3Rs = new Cubo(corPrata);
        divisorRs = new Cubo(corPreto);
        puxador1Rs = new Cubo(corPrata);
        puxador2Rs = new Cubo(corPrata);

        /*Banheiro*/
        //Sanitario
        sanitario1 = new Cubo(corBranco);
        sanitario2 = new Cubo(corBranco);
        sanitario3 = new Cubo(corBranco);
        sanitario4 = new Cubo(corBranco);
        sanitario5 = new Cubo(corBranco);

        //Pia
        pia1 =  new Cubo(corBranco);
        pia2 =  new Cubo(corBranco);
        pia3 =  new Cubo(corBranco);
        pia4 =  new Cubo(corBranco);

        //Torneira
        torneira1 = new Cubo(corPrata);
        torneira2 = new Cubo(corPrata);
        torneira3 = new Cubo(corPrata);

        //Chuveiro
        chuveiro1 = new Cubo(corPrata);
        chuveiro2 = new Cubo(corPrata);
        chuveiro3 = new Cubo(corPrata);


        //Fonte de Luz
        float ia[3] = {0.66, 0.46, 0.4};
        float id[3] = {0.8, 0.8, 0.8};
        float is[3] = {0.8, 0.8, 0.8};
        LS = new FonteLuminosa(ia, id, is, new Vertice(800, 350, 650));


        /*Lista de Objetos*/
        ListaObjetos[0] = piso;
        ListaObjetos[1] = parede1;
        ListaObjetos[2] = parede2;
        ListaObjetos[3] = parede3;
        ListaObjetos[4] = parede4;
        ListaObjetos[5] = parede5;
        //Cozinha
        ListaObjetos[6] = balcao1;
        ListaObjetos[7] = balcao2;
        ListaObjetos[8] = balcao3;
        ListaObjetos[9] = microondas;
        ListaObjetos[10] = microondas2;
        ListaObjetos[11] = microondas3;
        ListaObjetos[12] = geladeira;
        ListaObjetos[13] = puxador1;
        ListaObjetos[14] = divisoriaGel;
        ListaObjetos[15] = tampo;
        ListaObjetos[16] = perna1;
        ListaObjetos[17] = perna2;
        ListaObjetos[18] = perna3;
        ListaObjetos[19] = perna4;
        ListaObjetos[20] = cadeira1;
        ListaObjetos[21] = cadeira2;
        ListaObjetos[22] = cadeira3;
        ListaObjetos[23] = cadeira2_1;
        ListaObjetos[24] = cadeira2_2;
        ListaObjetos[25] = cadeira2_3;
        ListaObjetos[26] = cadeira3_1;
        ListaObjetos[27] = cadeira3_2;
        ListaObjetos[28] = cadeira3_3;
        ListaObjetos[29] = cadeira4_1;
        ListaObjetos[30] = cadeira4_2;
        ListaObjetos[31] = cadeira4_3;
        //Sala
        ListaObjetos[32] = sofa1;
        ListaObjetos[33] = sofa2;
        ListaObjetos[34] = sofa3;
        ListaObjetos[35] = sofa4;
        ListaObjetos[36] = tv1;
        ListaObjetos[37] = tv2;
        //Quarto Casal
        ListaObjetos[38] = cama1c;
        ListaObjetos[39] = cama2c;
        ListaObjetos[40] = cama3c;
        ListaObjetos[41] = cama4c;
        ListaObjetos[42] = colchaoc;
        ListaObjetos[43] = guardaRc;
        ListaObjetos[44] = gavetac;
        ListaObjetos[45] = puxador3Rc;
        ListaObjetos[46] = divisorRc;
        ListaObjetos[47] = puxador1Rc;
        ListaObjetos[48] = puxador2Rc;
        //Quarto Solteiro
        ListaObjetos[49] = cama1s;
        ListaObjetos[50] = cama2s;
        ListaObjetos[51] = cama3s;
        ListaObjetos[52] = cama4s;
        ListaObjetos[53] = colchaos;
        ListaObjetos[54] = guardaRs;
        ListaObjetos[55] = gavetas;
        ListaObjetos[56] = puxador3Rs;
        ListaObjetos[57] = divisorRs;
        ListaObjetos[58] = puxador1Rs;
        ListaObjetos[59] = puxador2Rs;
        //Banheiro
        ListaObjetos[60] = sanitario1;
        ListaObjetos[61] = sanitario2;
        ListaObjetos[62] = sanitario3;
        ListaObjetos[63] = sanitario4;
        ListaObjetos[64] = sanitario5;
        ListaObjetos[65] = pia1;
        ListaObjetos[66] = pia2;
        ListaObjetos[67] = pia3;
        ListaObjetos[68] = pia4;
        ListaObjetos[69] = torneira1;
        ListaObjetos[70] = torneira2;
        ListaObjetos[71] = torneira3;
        ListaObjetos[72] = chuveiro1;
        ListaObjetos[73] = chuveiro2;
        ListaObjetos[74] = chuveiro3;

    }

    void Cena::modelagem(){

        //Piso
        piso->escala(300,1,300);
        piso->translacao(300, -1, 300);

        //Paredes internas
        parede1->escala(7.5,100,95);
        parede2->escala(142.5,100,7.5);
        parede3->escala(7.5,100,125);
        parede4->escala(95,100,7.5);
        parede5->escala(7.5,100,17.5);

        parede1->translacao(292.5, 100, 95);
        parede2->translacao(142.5,100,262.5);
        parede3->translacao(292.5,100,475);
        parede4->translacao(505,100,122.5);
        parede5->translacao(402.5,100,113);



        //Paredes externas
/*      //NORTE
        parede6->escala(300,100,7.5);//6 metros
        parede6->translacao(300, 100, 7.5);
        //LESTE
        parede7->escala(7.5,100,300);//6 metros
        parede7->translacao(592.5, 100, 300);
        //SUL
        parede8->escala(252.5,100,7.5);//5.3 metros
        parede8->translacao(347.5, 100, 592.5);
        //OESTE
        parede9->escala(7.5,100,300);//6 metros
        parede9->translacao(7.5, 100, 300);
*/


        //--------Cozinha------------
        //Microondas
        microondas->escala(18,10,15);
        microondas2->escala(14,8,15.05);
        microondas3->escala(1, 7, 1);

        microondas->translacao(285,60,300);
        microondas2->translacao(283,60,300.5);
        microondas3->translacao(293,60,315.1);

        //Balcão
        balcao1->escala(40,25,20);
        balcao2->escala(15,21,0.5);
        balcao3->escala(15,21,0.5);

        balcao1->translacao(285,25,300);
        balcao2->translacao(267,25,320.5);
        balcao3->translacao(305,25,320.5);
        //balcao_mic
        for(int i = 6; i < 12 ; i++){
            ListaObjetos[i]->translacao(-300, 0, -300);
        }
        //balcao_mic
        for(int i = 6; i < 12 ; i++){
            ListaObjetos[i]->translacao(505, 0, 167.5);
        }


        //Geladeira
        geladeira->escala(25,70,25);
        geladeira->translacao(420,70,155);

        divisoriaGel->escala(25,1,1);
        divisoriaGel->translacao(420,89,182);

        puxador1->escala(4,1,1);
        puxador1->translacao(404,96,182);


        //Mesa
        tampo->escala(50, 1.5, 25);
        perna1->escala(2.5, 28, 1.5);
        perna2->escala(2.5, 28, 1.5);
        perna3->escala(2.5, 28, 1.5);
        perna4->escala(2.5, 28, 1.5);

        tampo->translacao(0, 57.5, 0);
        perna1->translacao(-47.5, 28, 23.5);
        perna2->translacao(-47.5, 28, -23.5);
        perna3->translacao(47.5, 28, 23.5);
        perna4->translacao(47.5, 28, -23.5);
        for(int i = 15; i < 20; i++){
            ListaObjetos[i]->translacao(480, 0, 280);
        }


        //Cadeiras
        //cadeira1
        cadeira1->escala(20,1.5,20);//assento
        cadeira2->escala(20,38,1.5);//costas
        cadeira3->escala(20,20,1.5);//perna frente

        cadeira1->translacao(300,41.5,300);
        cadeira2->translacao(300,38,320);
        cadeira3->translacao(300,20,281.5);
        for(int i = 20; i < 23 ; i++){
            ListaObjetos[i]->translacao(-300, 0, -300);
        }
        for(int i = 20; i < 23 ; i++){
            ListaObjetos[i]->translacao(480, 0, 300);
        }


        //cadeira2
        cadeira2_1->escala(20,1.5,20);//assento
        cadeira2_2->escala(20,38,1.5);//costas
        cadeira2_3->escala(20,20,1.5);//perna frente

        cadeira2_1->translacao(300,41.5,300);
        cadeira2_2->translacao(300,38,320);
        cadeira2_3->translacao(300,20,281.5);
        for(int i = 23; i < 26 ; i++){
            ListaObjetos[i]->translacao(-300, 0, -300);
        }
        for(int i = 23 ; i < 26 ; i++){
            ListaObjetos[i]->rotacaoY(3.14159);
        }
        for(int i = 23; i < 26 ; i++){
            ListaObjetos[i]->translacao(480, 0, 260);
        }


        //cadeira3
        cadeira3_1->escala(20,1.5,20);//assento
        cadeira3_2->escala(20,38,1.5);//costas
        cadeira3_3->escala(20,20,1.5);//perna frente

        cadeira3_1->translacao(300,41.5,300);
        cadeira3_2->translacao(300,38,320);
        cadeira3_3->translacao(300,20,281.5);
        for(int i = 26; i < 29 ; i++){
            ListaObjetos[i]->translacao(-300, 0, -300);
        }
        for(int i = 26 ; i < 29 ; i++){
            ListaObjetos[i]->rotacaoY(4.71239);
        }
        for(int i = 26; i < 29 ; i++){
            ListaObjetos[i]->translacao(430, 0, 280);
        }


        //cadeira4
        cadeira4_1->escala(20,1.5,20);//assento
        cadeira4_2->escala(20,38,1.5);//costas
        cadeira4_3->escala(20,20,1.5);//perna frente

        cadeira4_1->translacao(300,41.5,300);
        cadeira4_2->translacao(300,38,320);
        cadeira4_3->translacao(300,20,281.5);
        for(int i = 29; i < 32; i++){
            ListaObjetos[i]->translacao(-300, 0, -300);
        }
        for(int i = 29 ; i < 32; i++){
            ListaObjetos[i]->rotacaoY(1.5708);
        }
        for(int i = 29; i < 32; i++){
            ListaObjetos[i]->translacao(530, 0, 280);
        }


        //----------Sala-------------
        //Sofá
        sofa1->escala(80,18,25);
        sofa2->escala(80,32,7.5);//encosto
        sofa3->escala(7.5,25,33);
        sofa4->escala(7.5,25,33);

        sofa1->translacao(200,18,200);
        sofa2->translacao(200,32,180);
        sofa3->translacao(287.5,25,200);
        sofa4->translacao(112.5,25,200);

        //sofa
        for(int i = 32; i < 36 ; i++){
            ListaObjetos[i]->translacao(-200, 0, -200);
        }

        //sofa
        for(int i = 32 ; i < 36 ; i++){
            ListaObjetos[i]->rotacaoY(4.71239);
        }
        //sofa
        for(int i = 32; i < 36 ; i++){
            ListaObjetos[i]->translacao(425, 0, 470);
        }

        //Televisão
        tv1->escala(40,20,1);
        tv2->escala(39,19,1.05);

        tv1->translacao(292.5,25,300);
        tv2->translacao(292,25,300.5);

        //tv
        for(int i = 36; i < 38 ; i++){
            ListaObjetos[i]->translacao(-300, 0, -300);
        }

        //tv
        for(int i = 36 ; i < 38 ; i++){
            ListaObjetos[i]->rotacaoY(1.5708);
        }
        //tv
        for(int i = 36; i < 38 ; i++){
            ListaObjetos[i]->translacao(309.6, 70, 470);
        }


        //-------Quarto Casal---------
        //Cama Casal
        cama1c->escala(70,25,2.5);
        cama2c->escala(2.5,12.5,100);
        cama3c->escala(2.5,12.5,100);
        cama4c->escala(70,40,2.5);
        colchaoc->escala(62.5,12.5,102.5);

        cama1c->translacao(300,25,305);
        cama2c->translacao(232.5,37.5,202.5);
        cama3c->translacao(367.5,37.5,202.5);
        cama4c->translacao(300,50,100);
        colchaoc->translacao(300,50,200);

        //camac
        for(int i = 38; i < 43 ; i++){
            ListaObjetos[i]->translacao(-300, 0, -200);
        }

        //camac
        for(int i = 38 ; i < 43 ; i++){
            ListaObjetos[i]->rotacaoY(1.5708);
        }
        //camac
        for(int i = 38; i < 43 ; i++){
            ListaObjetos[i]->translacao(130, 0, 470);
        }

        //Guarda Roupas
        guardaRc->escala(50,100,25);
        guardaRc->translacao(65,100,295);

        divisorRc->escala(1,85,1);
        divisorRc->translacao(65,115,321);

        gavetac->escala(40,10,1);
        gavetac->translacao(65,20,321);

        puxador3Rc->escala(10,1,1);
        puxador3Rc->translacao(65,19,323);

        puxador1Rc->escala(1,25,1);
        puxador1Rc->translacao(55,115,321);

        puxador2Rc->escala(1,25,1);
        puxador2Rc->translacao(75,115,321);


        //-------Quarto Solteiro--------
        //Cama Solteiro
        cama1s->escala(40,25,2.5);
        cama2s->escala(2.5,12.5,90);
        cama3s->escala(2.5,12.5,90);
        cama4s->escala(40,40,2.5);
        colchaos->escala(35,12.5,90);

        cama1s->translacao(300,25,295);
        cama2s->translacao(262.5,37.5,202.5);
        cama3s->translacao(337.5,37.5,202.5);
        cama4s->translacao(300,40,110);
        colchaos->translacao(300,47.5,202.5);

        //cama_s
        for(int i = 49; i < 54 ; i++){
            ListaObjetos[i]->translacao(-300, 0, -202.5);
        }

        //cama_s
        for(int i = 49; i < 54 ; i++){
            ListaObjetos[i]->rotacaoY(1.5708);
        }
        //cama_s
        for(int i = 49; i < 54 ; i++){
            ListaObjetos[i]->translacao(112.5, 0, 97.5);
        }

        //Guarda Roupas
        guardaRs->escala(50,100,25);
        guardaRs->translacao(65,100,230);

        divisorRs->escala(1,85,1);
        divisorRs->translacao(65,115,204);

        gavetas->escala(40,10,1);
        gavetas->translacao(65,20,204);

        puxador3Rs->escala(10,1,1);
        puxador3Rs->translacao(65,19,202);

        puxador1Rs->escala(1,25,1);
        puxador1Rs->translacao(55,115,204);

        puxador2Rs->escala(1,25,1);
        puxador2Rs->translacao(75,115,204);


        //-------Banheiro-------
        //Sanitario
        sanitario1->escala(10,20,20);
        sanitario1->rotacaoX(5.93412);
        sanitario1->translacao(520,25,85);

        sanitario2->escala(10,23,20);
        sanitario2->translacao(520,25,90);

        sanitario3->escala(18,8,20);
        sanitario3->translacao(520,45,78);

        sanitario4->escala(14,1.5,16);
        sanitario4->translacao(520,54,78);

        sanitario5->escala(15,15,5);
        sanitario5->translacao(520,68,100);

        //Pia
        pia1->escala(20,3.5,10);
        pia1->translacao(460,70,98);

        pia2->escala(1.5,3.5,10);
        pia2->translacao(441.5,77,98);

        pia3->escala(1.5,3.5,10);
        pia3->translacao(478.5,77,98);

        pia4->escala(17,3.5,1.5);
        pia4->translacao(460,77,89.5);

        //Torneira
        torneira1->escala(1,0.5,5);
        torneira1->translacao(460,83,112.5);

        torneira2->escala(1,0.5,0.5);
        torneira2->translacao(460,82,107.5);

        torneira3->escala(1.5,0.5,0.5);
        torneira3->translacao(460,84,111);

        //Chuveiro
        chuveiro1->escala(0.5,0.5,10);
        chuveiro1->translacao(570,182,105);

        chuveiro2->escala(0.5,1,0.5);
        chuveiro2->translacao(570,181,95.5);

        chuveiro3->escala(2.5,0.25,2.5);
        chuveiro3->translacao(570,180,95.5);

}
