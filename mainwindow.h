#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <bits/stdc++.h>
#include <QMainWindow>
#include "gui.h"
#include <QEvent>
#include <QKeyEvent>
#include "Pipeline/scene.h"

using namespace  std;
class View :public QGraphicsView
{
    Q_OBJECT
public:
    myScene *      my_scene;
    View(QWidget *parent = nullptr);
protected:
    void keyPressEvent(QKeyEvent *event);
signals:
    void updatePipeline(int);

};

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    GUI* gui ;
    View* pipeline_gui;

public:
    explicit MainWindow(QWidget *parent = nullptr);
public slots:
    void show_pipeline_gui();
};
#endif // MAINWINDOW_H
