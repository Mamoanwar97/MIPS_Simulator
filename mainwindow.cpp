#include "mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->gui = new GUI();
    this->setCentralWidget(this->gui);
//    this->setStyleSheet("background-color:grey");




// ========================================================
//    QGridLayout * grid = new QGridLayout();
//    QWidget *red , *black ,*grey , *w4, *w5, *w6 ,*c;
//    red = new QWidget();
//    black = new QWidget();
//    grey = new QWidget();
//    c  = new QWidget();

//    red->setStyleSheet("background-color:red");
//    black->setStyleSheet("background-color:black");
//    grey->setStyleSheet("background-color:grey");
//    c->setStyleSheet("background-color:white");

//    grid->addWidget(red  ,0,0,3,3);
//    grid->addWidget(black,0,3,-1,1);
//    grid->addWidget(grey ,3,0,1,3);
//    c->setLayout(grid);
//    this->setCentralWidget(c);
// ==========================================================

}

MainWindow::~MainWindow()
{
    delete gui;
    delete this;
}
