#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Observador.h"
#include "Cena.h"
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int Nx = 350;
    int Ny = 350;
    float H = 150;
    float W = 150;
    float dist = 100;

    Observador* ob = new Observador(new Vertice(700,300,700), new Vertice(200,50,300), new Vertice(200, 200, 300), dist, Nx, Ny, W, H);
    Cena* cena = new Cena();

    cena->modelagem();

    ob->T_w_c(cena);
    ob->kwindow->rayCasting(cena);

    //srand(time(NULL));

    QImage image = QImage( Nx, Ny, QImage::Format_RGB32 );

    for( int i=0; i<Nx; i++ ){
        for( int j=0; j<Ny; j++ ){
            //NORMALIZANDO
            /*if(ob->kwindow->pixelCores[i][j]->x >1)
               ob->kwindow->pixelCores[i][j]->x=1;


            if(ob->kwindow->pixelCores[i][j]->y >1)
               ob->kwindow->pixelCores[i][j]->y=1;


            if(ob->kwindow->pixelCores[i][j]->z >1)
               ob->kwindow->pixelCores[i][j]->z=1;
            *///NORMALIZANDO
            image.setPixel(j, i, qRgb( ob->kwindow->pixelCores[i][j]->x*255, ob->kwindow->pixelCores[i][j]->y*255, ob->kwindow->pixelCores[i][j]->z*255 ));
            delete ob->kwindow->pixelCores[i][j];
        }
    }

    QGraphicsScene * graphic = new QGraphicsScene( this );

    graphic->addPixmap( QPixmap::fromImage( image ) );

    ui->graphicsView->setScene(graphic);
}

MainWindow::~MainWindow()
{
    delete ui;
}
