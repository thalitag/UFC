#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Obx_valueChanged(double arg1);

    void on_Oby_valueChanged(double arg1);

    void on_Obz_valueChanged(double arg1);

    void on_Lookx_valueChanged(double arg1);

    void on_Looky_valueChanged(double arg1);

    void on_Lookz_valueChanged(double arg1);

    void on_FLx_valueChanged(double arg1);

    void on_FLy_valueChanged(double arg1);

    void on_FLz_valueChanged(double arg1);

    void wired();

    void on_ia1_valueChanged(double arg1);

    void on_ia2_valueChanged(double arg1);

    void on_ia3_valueChanged(double arg1);

    void on_id1_valueChanged(double arg1);

    void on_id2_valueChanged(double arg1);

    void on_id3_valueChanged(double arg1);

    void on_ie1_valueChanged(double arg1);

    void on_ie2_valueChanged(double arg1);

    void on_ie3_valueChanged(double arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
