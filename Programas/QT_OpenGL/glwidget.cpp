#include "glwidget.h"
#include <cmath>
#include <GL/glut.h>
#include <iostream>
using namespace std;

GLWidget::GLWidget(QWidget *parent):
    QGLWidget(parent)
{
    //Posição do observador
    this->Obx = 700;
    this->Oby = 400;
    this->Obz = 700;

    //LookAt
    this->Lookx = 300;
    this->Looky = 0;
    this->Lookz = 300;

    //Posição da fonte de luz
    this->FLx = 900;
    this->FLy = 900;
    this->FLz = 900;

    //Iluminação
    this->Ia1 = 0.6;    this->Ia2 = 0.6;    this->Ia3 = 0.6;//Ambiente
    this->Id1 = 0.5;    this->Id2 = 0.5;    this->Id3 = 0.5;//Difusa
    this->Ie1 = 0.4;    this->Ie2 = 0.4;    this->Ie3 = 0.4;//Especular

    //Cubo
    this->ListaVertices[0][0] = -1; this->ListaVertices[0][1] = 1;  this->ListaVertices[0][2] = 1;
    this->ListaVertices[1][0] = 1;  this->ListaVertices[1][1] = 1;  this->ListaVertices[1][2] = 1;
    this->ListaVertices[2][0] = 1;  this->ListaVertices[2][1] = 1;  this->ListaVertices[2][2] = -1;
    this->ListaVertices[3][0] = -1; this->ListaVertices[3][1] = 1;  this->ListaVertices[3][2] = -1;
    this->ListaVertices[4][0] = -1; this->ListaVertices[4][1] = -1; this->ListaVertices[4][2] = 1;
    this->ListaVertices[5][0] = 1;  this->ListaVertices[5][1] = -1; this->ListaVertices[5][2] = 1;
    this->ListaVertices[6][0] = 1;  this->ListaVertices[6][1] = -1; this->ListaVertices[6][2] = -1;
    this->ListaVertices[7][0] = -1; this->ListaVertices[7][1] = -1; this->ListaVertices[7][2] = -1;

    this->normals[0][0] = -1; this->normals[0][1] = 1;  this->normals[0][2] = 1;
    this->normals[1][0] = 1;  this->normals[1][1] = 1;  this->normals[1][2] = 1;
    this->normals[2][0] = 1;  this->normals[2][1] = 1;  this->normals[2][2] = -1;
    this->normals[3][0] = -1; this->normals[3][1] = 1;  this->normals[3][2] = -1;
    this->normals[4][0] = -1; this->normals[4][1] = -1; this->normals[4][2] = 1;
    this->normals[5][0] = 1;  this->normals[5][1] = -1; this->normals[5][2] = 1;
    this->normals[6][0] = 1;  this->normals[6][1] = -1; this->normals[6][2] = -1;
    this->normals[7][0] = -1; this->normals[7][1] = -1; this->normals[7][2] = -1;

    //Materiais e Cores
    this->teste[0] = 0.1;   this->teste[1] = 0.1;   this->teste[2] = 0.1; this->teste[3] = 0.1;
    this->Kesp[0] = 0.2;    this->Kesp[1] = 0.2;    this->Kesp[2] = 0.2; this->Kesp[3] = 0.2;

    this->cor[0] = 0.66; this->cor[1] = 0.46; this->cor[2] = 0.4;
    this->m[0] = 0.66; this->m[1] = 0.46; this->m[2] = 0.4; this->m[3] = 0.1;
    this->mA[0] = 0.30; this->mA[1] = 0.10; this->mA[2] = 0; this->mA[3] = 0.1;
    this->mE[0] = 0.15; this->mE[1] = 0.12; this->mE[2] = 0.1; this->mE[3] = 0.1;


    this->corPiso[0] = 0.66; this->corPiso[1] = 0.66; this->corPiso[2] = 0.66;
    this->m1[0] = 0.76; this->m1[1] = 0.76; this->m1[2] = 0.76; this->m1[3] = 0.1;

    this->corParede[0] = 0.69;  this->corParede[1] = 0.76; this->corParede[2] = 0.87;
    this->m2[0] = 0.69; this->m2[1] = 0.76; this->m2[2] = 0.87; this->m2[3] = 0.1;

    this->branco[0] = 1;    this->branco[1] = 1;    this->branco[2] = 1;
    this->corBranco[0] = 1; this->corBranco[1] = 1; this->corBranco[2] = 1; this->corBranco[3] = 0.1;

    this->preto[0] = 0;    this->preto[1] = 0;    this->preto[2] = 0;
    this->corPreto[0] = 0; this->corPreto[1] = 0; this->corPreto[2] = 0; this->corPreto[3] = 0.1;

    this->cinza[0] = 0.5;    this->cinza[1] = 0.5;    this->cinza[2] = 0.5;
    this->corCinza[0] = 0.5; this->corCinza[1] = 0.5; this->corCinza[2] = 0.5; this->corCinza[3] = 0.1;

    this->prata[0] = 0.7529;    this->prata[1] = 0.7529;    this->prata[2] = 0.7529;
    this->corPrata[0] = 0.7529; this->corPrata[1] = 0.7529; this->corPrata[2] = 0.7529; this->corPrata[3] = 0.1;

    this->corTv2[0] = 0.3;    this->corTv2[1] = 0.3;    this->corTv2[2] = 0.3;
    this->m4[0] = 0.3; this->m4[1] = 0.3; this->m4[2] = 0.3; this->m4[3] = 0.1;

    this->corBalcao[0] = 0.56;    this->corBalcao[1] = 0.46;    this->corBalcao[2] = 0.3;
    this->m5[0] = 0.56; this->m5[1] = 0.46; this->m5[2] = 0.3; this->m5[3] = 0.1;

    this->corMic2[0] = 0.35;    this->corMic2[1] = 0.35;    this->corMic2[2] = 0.35;
    this->m7[0] = 0.35; this->m7[1] = 0.35; this->m7[2] = 0.35; this->m7[3] = 0.1;

    this->corSofa[0] = 0.6;    this->corSofa[1] = 0.6;    this->corSofa[2] = 0.6;
    this->m8[0] = 0.6; this->m8[1] = 0.6; this->m8[2] = 0.6; this->m8[3] = 0.1;
   
    this->corColc[0] = 0.8;    this->corColc[1] = 0.8;    this->corColc[2] = 0.8;
    this->m9[0] = 0.8; this->m9[1] = 0.8; this->m9[2] = 0.8; this->m9[3] = 0.1;

    connect( &timer, SIGNAL(timeout()), this, SLOT(updateGL()) );
    timer.start(16);
}

void GLWidget::initializeGL()
{
    glClearColor(0,0,0,1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
}

void GLWidget::paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );


    //Luz
    float LightAmbient[3] = {Ia1,Ia2,Ia3};
    float LightDiffuse[3] = {Id1,Id2,Id3};
    float LightSpecular[3] = {Ie1,Ie2,Ie3};
    float LightPosition[3] = {FLx,FLy,FLz};

    glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, LightSpecular);
    glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);

    float LightAttenuation[3] = {0.8, 0.8, 0.8};
    glLightfv(GL_LIGHT0, GL_ATTENUATION_EXT, LightAttenuation);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt( Obx,Oby,Obz, Lookx,Looky,Lookz, 0,1,0 );

    //Cenario
    Banheiro();
    Sala();
    Cozinha();
    QuartoSolteiro();
    QuartoCasal();
    Estrutura();

}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,(float)w/h,1, 3000);
    glClearColor(0.6f, 0.6f, 0.6f, 0.1f);
    glClear( GL_COLOR_BUFFER_BIT );
    glClear( GL_DEPTH_BUFFER_BIT );
    glEnable( GL_DEPTH_TEST );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();


    updateGL();
}

void GLWidget::Cubo(){
    quad(6, 2, 1, 5); // Face x+
    quad(3, 0, 1, 2); // Face y+
    quad(5, 1, 0, 4); // Face z+
    quad(4, 0, 3, 7); // Face x-
    quad(6, 5, 4, 7); // Face y-
    quad(7, 3, 2, 6); // Face z-
}

void GLWidget::quad(int a, int b, int c, int d){
    glBegin(GL_QUADS);
        glNormal3fv(this->normals[a]);
        glVertex3fv(this->ListaVertices[a]);
        glNormal3fv(this->normals[b]);
        glVertex3fv(this->ListaVertices[b]);
        glNormal3fv(this->normals[c]);
        glVertex3fv(this->ListaVertices[c]);
        glNormal3fv(this->normals[d]);
        glVertex3fv(this->ListaVertices[d]);
    glEnd();
}

void GLWidget::Material(GLfloat *ka_i, GLfloat *kd_i, GLfloat *ks_i){
    glMaterialfv(GL_FRONT, GL_AMBIENT, ka_i);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,kd_i);
    glMaterialfv(GL_FRONT, GL_SPECULAR, ks_i);
    glMaterialf(GL_FRONT, GL_SHININESS, 0.4);
}

void GLWidget::Estrutura(){

    //Piso
    glPushMatrix();
        Material(teste, m1, m1);
        glColor3fv(corPiso);

        glTranslatef(300,-5,300);
        glScalef(300,5,300);
        Cubo();
    glPopMatrix();
    //Parede1
    glPushMatrix();
        Material(teste, m2, m2);
        glColor3fv(corParede);

        glTranslatef(292.5, 100, 95);
        glScalef(7.5,100,95);
        Cubo();
    glPopMatrix();
    //Parede2
    glPushMatrix();
        Material(teste, m2, m2);
        glColor3fv(corParede);

        glTranslatef(142.5,100,262.5);
        glScalef(142.5,100,7.5);
        Cubo();
    glPopMatrix();
    //Parede3
    glPushMatrix();
        Material(teste, m2, m2);
        glColor3fv(corParede);

        glTranslatef(292.5,100,475);
        glScalef(7.5,100,125);
        Cubo();
    glPopMatrix();
    //Parede4
    glPushMatrix();
        Material(teste, m2, m2);
        glColor3fv(corParede);

        glTranslatef(505,100,122.5);
        glScalef(95,100,7.5);
        Cubo();
    glPopMatrix();
    //Parede5
    glPushMatrix();
        Material(teste, m2, m2);
        glColor3fv(corParede);

        glTranslatef(402.5,100,113);
        glScalef(7.5,100,17.5);
        Cubo();
    glPopMatrix();

}

void GLWidget::QuartoCasal(){
    //Cama Casal
    //cama1c
    glPushMatrix();
        Material(mA, m, mE);
        glColor3fv(cor);

        glTranslatef(130, 0, 470);
        glRotatef(90,0,1,0);
        glTranslatef(-300, 0, -200);
        glTranslatef(300,25,305);
        glScalef(70,25,2.5);
        Cubo();
    glPopMatrix();
    //cama2c
    glPushMatrix();
        Material(mA, m, mE);
        glColor3fv(cor);

        glTranslatef(130, 0, 470);
        glRotatef(90,0,1,0);
        glTranslatef(-300, 0, -200);
        glTranslatef(232.5,37.5,202.5);
        glScalef(2.5,12.5,100);
        Cubo();
    glPopMatrix();
    //cama3c
    glPushMatrix();
        Material(mA, m, mE);
        glColor3fv(cor);

        glTranslatef(130, 0, 470);
        glRotatef(90,0,1,0);
        glTranslatef(-300, 0, -200);
        glTranslatef(367.5,37.5,202.5);
        glScalef(2.5,12.5,100);
        Cubo();
    glPopMatrix();
    //cama4c
    glPushMatrix();
        Material(mA, m, mE);
        glColor3fv(cor);
        glTranslatef(130, 0, 470);
        glRotatef(90,0,1,0);
        glTranslatef(-300, 0, -200);
        glTranslatef(300,50,100);
        glScalef(70,40,2.5);
        Cubo();
    glPopMatrix();
    //colchaoc
    glPushMatrix();
        Material(m9, m9, m9);
        glColor3fv(corColc);

        glTranslatef(130, 0, 470);
        glRotatef(90,0,1,0);
        glTranslatef(-300, 0, -200);
        glTranslatef(300,50,200);
        glScalef(62.5,12.5,102);
        Cubo();
    glPopMatrix();

    //Guarda Roupas
    //guardaRc
    glPushMatrix();
        Material(mA, m, mE);
        glColor3fv(cor);

        glTranslatef(65,100,295);
        glScalef(50,100,25);
        Cubo();
    glPopMatrix();
    //gavetac
    glPushMatrix();
        Material(teste, m, mE);
        glColor3fv(cor);

        glTranslatef(65,20,321);
        glScalef(40,10,1);
        Cubo();
    glPopMatrix();
    //puxador3Rc
    glPushMatrix();
        Material(corPrata, corPrata, corPrata);
        glColor3fv(prata);

        glTranslatef(65,19,323);
        glScalef(10,1,1);
        Cubo();
    glPopMatrix();
    //divisorRc
    glPushMatrix();
        Material(teste, corPreto, corPreto);
        glColor3fv(preto);

        glTranslatef(65,115,321);
        glScalef(1,85,1);
        Cubo();
    glPopMatrix();
    //puxador1Rc
    glPushMatrix();
        Material(corPrata, corPrata, corPrata);
        glColor3fv(prata);

        glTranslatef(55,115,321);
        glScalef(1,25,1);
        Cubo();
    glPopMatrix();
    //puxador2Rc
    glPushMatrix();
        Material(corPrata, corPrata, corPrata);
        glColor3fv(prata);

        glTranslatef(75,115,321);
        glScalef(1,25,1);
        Cubo();
    glPopMatrix();

}

void GLWidget::QuartoSolteiro(){
    //Cama Solteiro
    //cama1s
    glPushMatrix();
        Material(m, m, m);
        glColor3fv(cor);

        glTranslatef(112.5, 0, 97.5);
        glRotatef(90,0,1,0);
        glTranslatef(-300, 0, -202.5);
        glTranslatef(300,25,295);
        glScalef(40,25,2.5);
        Cubo();
    glPopMatrix();
    //cama2s
    glPushMatrix();
        Material(m, m, m);
        glColor3fv(cor);

        glTranslatef(112.5, 0, 97.5);
        glRotatef(90,0,1,0);
        glTranslatef(-300, 0, -202.5);
        glTranslatef(262.5,37.5,202.5);
        glScalef(2.5,12.5,90);
        Cubo();
    glPopMatrix();
    //cama3s
    glPushMatrix();
        Material(m, m, m);
        glColor3fv(cor);

        glTranslatef(112.5, 0, 97.5);
        glRotatef(90,0,1,0);
        glTranslatef(-300, 0, -202.5);
        glTranslatef(337.5,37.5,202.5);
        glScalef(2.5,12.5,90);
        Cubo();
    glPopMatrix();
    //cama4s
    glPushMatrix();
        Material(m, m, m);
        glColor3fv(cor);
        glTranslatef(112.5, 0, 97.5);
        glRotatef(90,0,1,0);
        glTranslatef(-300, 0, -202.5);
        glTranslatef(300,40,110);
        glScalef(40,40,2.5);
        Cubo();
    glPopMatrix();
    //colchaos
    glPushMatrix();
        Material(m9, m9, m9);
        glColor3fv(corColc);

        glTranslatef(112.5, 0, 97.5);
        glRotatef(90,0,1,0);
        glTranslatef(-300, 0, -202.5);
        glTranslatef(300,47.5,202.5);
        glScalef(35,12.5,90);
        Cubo();
    glPopMatrix();

    //Guarda Roupas
    //guardaRs
    glPushMatrix();
        Material(m, m, m);
        glColor3fv(cor);

        glTranslatef(65,100,230);
        glScalef(50,100,25);
        Cubo();
    glPopMatrix();
    //gavetas
    glPushMatrix();
        Material(m, m, m);
        glColor3fv(cor);

        glTranslatef(65,20,204);
        glScalef(40,10,1);
        Cubo();
    glPopMatrix();
    //puxador3Rs
    glPushMatrix();
        Material(corPrata, corPrata, corPrata);
        glColor3fv(prata);

        glTranslatef(65,19,202);
        glScalef(10,1,1);
        Cubo();
    glPopMatrix();
    //divisorRs
    glPushMatrix();
        Material(corPreto, corPreto, corPreto);
        glColor3fv(preto);

        glTranslatef(65,115,204);
        glScalef(1,85,1);
        Cubo();
    glPopMatrix();
    //puxador1Rs
    glPushMatrix();
        Material(corPrata, corPrata, corPrata);
        glColor3fv(prata);

        glTranslatef(55,115,204);
        glScalef(1,25,1);
        Cubo();
    glPopMatrix();
    //puxador2Rs
    glPushMatrix();
        Material(corPrata, corPrata, corPrata);
        glColor3fv(prata);

        glTranslatef(75,115,204);
        glScalef(1,25,1);
        Cubo();
    glPopMatrix();
}

void GLWidget::Cozinha(){
    //Microondas
    //microondas
    glPushMatrix();
        Material(corBranco, corBranco, corBranco);
        glColor3fv(branco);

        glTranslatef(505, 0, 167.5);
        glTranslatef(-300, 0, -300);
        glTranslatef(285,60,300);
        glScalef(18,10,15);
        Cubo();
    glPopMatrix();
    //microondas2
    glPushMatrix();
        Material(m7, m7, m7);
        glColor3fv(corMic2);

        glTranslatef(505, 0, 167.5);
        glTranslatef(-300, 0, -300);
        glTranslatef(283,60,300.5);
        glScalef(14,8,15.05);
        Cubo();
    glPopMatrix();
    //microondas3
    glPushMatrix();
        Material(corBranco, corBranco, corBranco);
        glColor3fv(branco);

        glTranslatef(505, 0, 167.5);
        glTranslatef(-300, 0, -300);
        glTranslatef(293,60,315.1);
        glScalef(1, 7, 1);
        Cubo();
    glPopMatrix();

    //Balcão
    //balcao1    
    glPushMatrix();
        Material(m5, m5, m5);
        glColor3fv(corBalcao);

        glTranslatef(505, 0, 167.5);
        glTranslatef(-300, 0, -300);
        glTranslatef(285,25,300);
        glScalef(40,25,20);
        Cubo();
    glPopMatrix();
    //balcao2    
    glPushMatrix();
        Material(m, m, m);
        glColor3fv(cor);
        
        glTranslatef(505, 0, 167.5);
        glTranslatef(-300, 0, -300);
        glTranslatef(267,25,320.5);
        glScalef(15,21,2);
        Cubo();
    glPopMatrix();
    //balcao3    
    glPushMatrix();
        Material(m, m, m);
        glColor3fv(cor);
        
        glTranslatef(505, 0, 167.5);
        glTranslatef(-300, 0, -300);
        glTranslatef(305,25,320.5);
        glScalef(15,21,2);
        Cubo();
    glPopMatrix();

    //Geladeira
    //geladeira
    glPushMatrix();
        Material(teste, corBranco, corBranco);
        glColor3fv(branco);
        
        glTranslatef(420,70,155);
        glScalef(25,70,25);
        Cubo();
    glPopMatrix();    
    //divisoriaGel
    glPushMatrix();
        Material(teste, corPrata, corPrata);
        glColor3fv(prata);
        
        glTranslatef(420,89,182);
        glScalef(25,1,1);
        Cubo();
    glPopMatrix();
    //puxador1
    glPushMatrix();
        Material(teste, corPrata, corPrata);
        glColor3fv(prata);
        
        glTranslatef(404,96,182);
        glScalef(4,1,1);
        Cubo();
    glPopMatrix();

    //Mesa
    //tampo
    glPushMatrix();
        Material(m, m, m);
        glColor3fv(cor);
     
        glTranslatef(480, 0, 280);   
        glTranslatef(0, 57.5, 0);
        glScalef(50, 1.5, 25);
        Cubo();
    glPopMatrix();
    //perna1
    glPushMatrix();
        Material(m, m, m);
        glColor3fv(cor);
     
        glTranslatef(480, 0, 280);   
        glTranslatef(-47.5, 28, 23.5);
        glScalef(2.5, 28, 1.5);
        Cubo();
    glPopMatrix();
    //perna2
    glPushMatrix();
        Material(m, m, m);
        glColor3fv(cor);
     
        glTranslatef(480, 0, 280);   
        glTranslatef(-47.5, 28, -23.5);
        glScalef(2.5, 28, 1.5);
        Cubo();
    glPopMatrix();
    //perna3
    glPushMatrix();
        Material(m, m, m);
        glColor3fv(cor);
     
        glTranslatef(480, 0, 280);   
        glTranslatef(47.5, 28, 23.5);
        glScalef(2.5, 28, 1.5);
        Cubo();
    glPopMatrix();
    //perna4
    glPushMatrix();
        Material(m, m, m);
        glColor3fv(cor);
     
        glTranslatef(480, 0, 280);   
        glTranslatef(47.5, 28, -23.5);
        glScalef(2.5, 28, 1.5);
        Cubo();
    glPopMatrix();

    //Cadeiras
    //cadeira1
    glPushMatrix();
        Material(m, m, m);
        glColor3fv(cor);
     
        glTranslatef(480, 0, 300);
        glTranslatef(-300, 0, -300);   
        glTranslatef(300,41.5,300);
        glScalef(20,1.5,20);
        Cubo();
    glPopMatrix();
    //cadeira2
    glPushMatrix();
        Material(m, m, m);
        glColor3fv(cor);
     
        glTranslatef(480, 0, 300);
        glTranslatef(-300, 0, -300);   
        glTranslatef(300,38,320);
        glScalef(20,38,1.5);
        Cubo();
    glPopMatrix();
    //cadeira3
    glPushMatrix();
        Material(m, m, m);
        glColor3fv(cor);
     
        glTranslatef(480, 0, 300);
        glTranslatef(-300, 0, -300);   
        glTranslatef(300,20,281.5);
        glScalef(20,20,1.5);
        Cubo();
    glPopMatrix();


    //cadeira2_1
    glPushMatrix();
        Material(m, m, m);
        glColor3fv(cor);
     
        glTranslatef(480, 0, 260);
        glRotatef(180,0,1,0);
        glTranslatef(-300, 0, -300);   
        glTranslatef(300,41.5,300);
        glScalef(20,1.5,20);
        Cubo();
    glPopMatrix();
    //cadeira2_2
    glPushMatrix();
        Material(m, m, m);
        glColor3fv(cor);
     
        glTranslatef(480, 0, 260);
        glRotatef(180,0,1,0);
        glTranslatef(-300, 0, -300);   
        glTranslatef(300,38,320);
        glScalef(20,38,1.5);
        Cubo();
    glPopMatrix();
    //cadeira2_3
    glPushMatrix();
        Material(m, m, m);
        glColor3fv(cor);
     
        glTranslatef(480, 0, 260);
        glRotatef(180,0,1,0);
        glTranslatef(-300, 0, -300);   
        glTranslatef(300,20,281.5);
        glScalef(20,20,1.5);
        Cubo();
    glPopMatrix();


    //cadeira3_1
    glPushMatrix();
        Material(m, m, m);
        glColor3fv(cor);
     
        glTranslatef(430, 0, 280);
        glRotatef(270,0,1,0);
        glTranslatef(-300, 0, -300);   
        glTranslatef(300,41.5,300);
        glScalef(20,1.5,20);
        Cubo();
    glPopMatrix();
    //cadeira3_2
    glPushMatrix();
        Material(m, m, m);
        glColor3fv(cor);
     
        glTranslatef(430, 0, 280);
        glRotatef(270,0,1,0);
        glTranslatef(-300, 0, -300);   
        glTranslatef(300,38,320);
        glScalef(20,38,1.5);
        Cubo();
    glPopMatrix();
    //cadeira3_3
    glPushMatrix();
        Material(m, m, m);
        glColor3fv(cor);
     
        glTranslatef(430, 0, 280);
        glRotatef(270,0,1,0);
        glTranslatef(-300, 0, -300);   
        glTranslatef(300,20,281.5);
        glScalef(20,20,1.5);
        Cubo();
    glPopMatrix();


    //cadeira4_1
    glPushMatrix();
        Material(m, m, m);
        glColor3fv(cor);
     
        glTranslatef(530, 0, 280);
        glRotatef(90,0,1,0);
        glTranslatef(-300, 0, -300);   
        glTranslatef(300,41.5,300);
        glScalef(20,1.5,20);
        Cubo();
    glPopMatrix();
    //cadeira4_2
    glPushMatrix();
        Material(m, m, m);
        glColor3fv(cor);
     
        glTranslatef(530, 0, 280);
        glRotatef(90,0,1,0);
        glTranslatef(-300, 0, -300);   
        glTranslatef(300,38,320);
        glScalef(20,38,1.5);
        Cubo();
    glPopMatrix();
    //cadeira4_3
    glPushMatrix();
        Material(m, m, m);
        glColor3fv(cor);
     
        glTranslatef(530, 0, 280);
        glRotatef(90,0,1,0);
        glTranslatef(-300, 0, -300);   
        glTranslatef(300,20,281.5);
        glScalef(20,20,1.5);
        Cubo();
    glPopMatrix();
}

void GLWidget::Sala(){
    //Sofá
    //sofa1
    glPushMatrix();
        Material(m8, m8, m8);
        glColor3fv(corSofa);
     
        glTranslatef(425, 0, 470);
        glRotatef(270,0,1,0);
        glTranslatef(-200, 0, -200);   
        glTranslatef(200,18,200);
        glScalef(80,18,25);
        Cubo();
    glPopMatrix();
    //sofa2
    glPushMatrix();
        Material(m8, m8, m8);
        glColor3fv(corSofa);
     
        glTranslatef(425, 0, 470);
        glRotatef(270,0,1,0);
        glTranslatef(-200, 0, -200);   
        glTranslatef(200,32,180);
        glScalef(80,32,7.5);
        Cubo();
    glPopMatrix();
    //sofa3
    glPushMatrix();
        Material(m8, m8, m8);
        glColor3fv(corSofa);
     
        glTranslatef(425, 0, 470);
        glRotatef(270,0,1,0);
        glTranslatef(-200, 0, -200);   
        glTranslatef(287.5,25,200);
        glScalef(7.5,25,33);
        Cubo();
    glPopMatrix();
    //sofa4
    glPushMatrix();
        Material(m8, m8, m8);
        glColor3fv(corSofa);
     
        glTranslatef(425, 0, 470);
        glRotatef(270,0,1,0);
        glTranslatef(-200, 0, -200);   
        glTranslatef(112.5,25,200);
        glScalef(7.5,25,33);
        Cubo();
    glPopMatrix();

    //Televisão
    //tv1
    glPushMatrix();
        Material(preto, preto, preto);
        glColor3fv(corPreto);
     
        glTranslatef(309.6, 70, 470);
        glRotatef(90,0,1,0);
        glTranslatef(-300, 0, -300);   
        glTranslatef(292.5,25,300);
        glScalef(40,20,1);
        Cubo();
    glPopMatrix();
    //tv2
    glPushMatrix();
        Material(m4, m4, m4);
        glColor3fv(corTv2);
     
        glTranslatef(309.6, 70, 470);
        glRotatef(90,0,1,0);
        glTranslatef(-300, 0, -300);   
        glTranslatef(292,25,300.5);
        glScalef(39,19,1.05);
        Cubo();
    glPopMatrix();

}

void GLWidget::Banheiro(){
    //Sanitario
    //sanitario1
    glPushMatrix();
        Material(branco, branco, branco);
        glColor3fv(corBranco);
     
        glTranslatef(520,25,85);
        glRotatef(340,1,0,0);
        glScalef(10,20,20);
        Cubo();
    glPopMatrix();
    //sanitario2
    glPushMatrix();
        Material(branco, branco, branco);
        glColor3fv(corBranco);
     
        glTranslatef(520,25,90);
        glScalef(10,23,20);
        Cubo();
    glPopMatrix();
    //sanitario3
    glPushMatrix();
        Material(branco, branco, branco);
        glColor3fv(corBranco);
     
        glTranslatef(520,45,78);
        glScalef(18,8,20);
        Cubo();
    glPopMatrix();
    //sanitario4
    glPushMatrix();
        Material(branco, branco, branco);
        glColor3fv(corBranco);
     
        glTranslatef(520,54,78);
        glScalef(14,1.5,16);
        Cubo();
    glPopMatrix();
    //sanitario5
    glPushMatrix();
        Material(branco, branco, branco);
        glColor3fv(corBranco);
     
        glTranslatef(520,68,100);
        glScalef(15,15,5);
        Cubo();
    glPopMatrix();


    //Pia
    //pia1
    glPushMatrix();
        Material(prata, prata, prata);
        glColor3fv(corPrata);
     
        glTranslatef(460,70,98);
        glScalef(20,3.5,10);
        Cubo();
    glPopMatrix();
    //pia2
    glPushMatrix();
        Material(prata, prata, prata);
        glColor3fv(corPrata);
     
        glTranslatef(441.5,77,98);
        glScalef(1.5,3.5,10);
        Cubo();
    glPopMatrix();
    //pia3
    glPushMatrix();
        Material(prata, prata, prata);
        glColor3fv(corPrata);
     
        glTranslatef(478.5,77,98);
        glScalef(1.5,3.5,10);
        Cubo();
    glPopMatrix();
    //pia4
    glPushMatrix();
        Material(prata, prata, prata);
        glColor3fv(corPrata);
     
        glTranslatef(460,77,89.5);
        glScalef(17,3.5,1.5);
        Cubo();
    glPopMatrix();


    //Torneira
    //torneira1
    glPushMatrix();
        Material(prata, prata, prata);
        glColor3fv(corPrata);
     
        glTranslatef(460,83,112.5);
        glScalef(1,0.5,5);
        Cubo();
    glPopMatrix();
    //torneira2
    glPushMatrix();
        Material(prata, prata, prata);
        glColor3fv(corPrata);
     
        glTranslatef(460,82,107.5);
        glScalef(1,0.5,0.5);
        Cubo();
    glPopMatrix();
    //troneira3
    glPushMatrix();
        Material(prata, prata, prata);
        glColor3fv(corPrata);
     
        glTranslatef(460,84,111);
        glScalef(1.5,0.5,0.5);
        Cubo();
    glPopMatrix();


    //Chuveiro
    //chuveiro1
    glPushMatrix();
        Material(prata, prata, prata);
        glColor3fv(corPrata);
     
        glTranslatef(570,182,105);
        glScalef(0.5,0.5,10);
        Cubo();
    glPopMatrix();
    //chuveiro2
    glPushMatrix();
        Material(prata, prata, prata);
        glColor3fv(corPrata);
     
        glTranslatef(570,181,95.5);
        glScalef(0.5,1,0.5);
        Cubo();
    glPopMatrix();
    //chuveiro3
    glPushMatrix();
        Material(prata, prata, prata);
        glColor3fv(corPrata);
     
        glTranslatef(570,180,95.5);
        glScalef(2.5,0.25,2.5);
        Cubo();
    glPopMatrix();
}


