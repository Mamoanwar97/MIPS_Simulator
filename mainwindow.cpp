#include "mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
        this->gui = new GUI();
        this->setCentralWidget(this->gui);
        this->setStyleSheet("background-color:rgb(0,0,128);""color: rgb(0,0,102);""font-weight: 400;");
}
