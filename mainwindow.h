#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <bits/stdc++.h>
#include <QMainWindow>
#include "gui.h"
#include <QEvent>
#include <QKeyEvent>
#include <QStackedLayout>
#include <QStackedWidget>
#include <QComboBox>
#include <QToolBox>
#include <QGroupBox>
#include <QDockWidget>

using namespace  std;

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    GUI* gui ;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:

signals:

};
#endif // MAINWINDOW_H
