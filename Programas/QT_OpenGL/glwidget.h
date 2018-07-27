#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QTimer>

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);

    float Obx, Oby, Obz, Lookx, Looky, Lookz, FLx, FLy, FLz, Ia1, Ia2, Ia3, Id1, Id2, Id3, Ie1, Ie2, Ie3;

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

    void Cubo();
    void quad(int a, int b, int c, int d);
    void Material(GLfloat *ka_i, GLfloat *kd_i, GLfloat *ks_i);
    //Cenario
    void Estrutura();
    void QuartoCasal();
    void QuartoSolteiro();
    void Cozinha();
    void Sala();
    void Banheiro();

    GLfloat ListaVertices[8][3];
    GLfloat normals[8][3];

    //Materiais e Cores
    GLfloat teste[4];
    GLfloat Kesp[4];

    GLfloat cor[3];
    GLfloat m[4], mA[4], mE[4];

    GLfloat corPiso[3];
    GLfloat m1[4];

    GLfloat corParede[3];
    GLfloat m2[4];

    GLfloat branco[3];
    GLfloat corBranco[4];

    GLfloat preto[3];
    GLfloat corPreto[4];

    GLfloat cinza[3];
    GLfloat corCinza[4];

    GLfloat prata[3];
    GLfloat corPrata[4];

    GLfloat corTv2[3];
    GLfloat m4[4];

    GLfloat corBalcao[3];
    GLfloat m5[4];

    GLfloat corMic2[3];
    GLfloat m7[4];

    GLfloat corSofa[3];
    GLfloat m8[4];

    GLfloat corColc[3];
    GLfloat m9[4];

private:
    QTimer timer;
};

#endif // GLWIDGET_H
