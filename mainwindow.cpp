#include "mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
        this->gui = new GUI();
        this->setCentralWidget(this->gui);
        this->setStyleSheet("background-color:rgb(128,0,23);"
                            "color: rgb(0,0,128);");

    //  ======= ToolBox Container ============
    //    QToolBox* toolBox = new QToolBox();
    //    toolBox->addItem(red,"red");
    //    toolBox->addItem(black,"black");
    //    toolBox->addItem(grey,"grey");
    //    QVBoxLayout *layout = new QVBoxLayout;
    //    layout->addWidget(toolBox);
    //    c->setLayout(layout);
    //    this->setCentralWidget(c);

    // ================ Grid =========================
//        QGridLayout * grid = new QGridLayout();
//        QWidget *red , *black ,*grey , *w4, *w5, *w6 ,*c;
//        red = new QWidget();
//        black = new QWidget();
//        grey = new QWidget();
//        c  = new QWidget();

//        red->setStyleSheet("background-color:red");
//        black->setStyleSheet("background-color:black");
//        grey->setStyleSheet("background-color:grey");
//        c->setStyleSheet("background-color:white");

//        grid->addWidget(red  ,0,0,3,3);
//        grid->addWidget(black,0,3,-1,1);
//        grid->addWidget(grey ,3,0,1,3);
//        c->setLayout(grid);
//        this->setCentralWidget(c);

//        QDockWidget* dock = new QDockWidget();
//        dock->setWidget(black);
//        this->addDockWidget(Qt::RightDockWidgetArea,dock);

    // ==========================================================

}
