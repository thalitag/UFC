#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Obx_valueChanged(double arg1)
{
    this->ui->GLwidget->Obx = arg1;
}

void MainWindow::on_Oby_valueChanged(double arg1)
{
    this->ui->GLwidget->Oby = arg1;
}

void MainWindow::on_Obz_valueChanged(double arg1)
{
    this->ui->GLwidget->Obz = arg1;
}

void MainWindow::on_Lookx_valueChanged(double arg1)
{
    this->ui->GLwidget->Lookx = arg1;
}

void MainWindow::on_Looky_valueChanged(double arg1)
{
    this->ui->GLwidget->Looky = arg1;
}

void MainWindow::on_Lookz_valueChanged(double arg1)
{
    this->ui->GLwidget->Lookz = arg1;
}

void MainWindow::on_FLx_valueChanged(double arg1)
{
    this->ui->GLwidget->FLx = arg1;
}

void MainWindow::on_FLy_valueChanged(double arg1)
{
    this->ui->GLwidget->FLy = arg1;
}

void MainWindow::on_FLz_valueChanged(double arg1)
{
    this->ui->GLwidget->FLz = arg1;
}

bool h = true;

void MainWindow::wired()
{

    h = !h;

    if(h)
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void MainWindow::on_ia1_valueChanged(double arg1)
{
    this->ui->GLwidget->Ia1 = arg1;
}

void MainWindow::on_ia2_valueChanged(double arg1)
{
    this->ui->GLwidget->Ia2 = arg1;
}

void MainWindow::on_ia3_valueChanged(double arg1)
{
    this->ui->GLwidget->Ia3 = arg1;
}

void MainWindow::on_id1_valueChanged(double arg1)
{
    this->ui->GLwidget->Id1 = arg1;
}

void MainWindow::on_id2_valueChanged(double arg1)
{
    this->ui->GLwidget->Id2 = arg1;
}

void MainWindow::on_id3_valueChanged(double arg1)
{
    this->ui->GLwidget->Id3 = arg1;
}

void MainWindow::on_ie1_valueChanged(double arg1)
{
    this->ui->GLwidget->Ie1 = arg1;
}

void MainWindow::on_ie2_valueChanged(double arg1)
{
    this->ui->GLwidget->Ie2 = arg1;
}

void MainWindow::on_ie3_valueChanged(double arg1)
{
    this->ui->GLwidget->Ie3 = arg1;
}
