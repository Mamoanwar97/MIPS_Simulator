#ifndef TESTWIDGET_H
#define TESTWIDGET_H
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "tree_widget.h"
#include "editor.h"
#include <iostream>
#include <bits/stdc++.h>
#include <QHBoxLayout>
#include <QStyle>
#include <QTreeWidget>
#include <QIcon>

#define green "background-color:rgb(0, 200, 0)"
#define red "background-color:rgb(255, 0, 0)"
#define grey "background-color:rgb(170, 170, 170)"
#define MIN_SIZE 600

class TestWidget : QWidget
{
    Q_OBJECT
private:
    QHBoxLayout* layout;
    QLabel* label;
    string name;
    QPushButton* BtnDetails;

    QTabWidget* DetailsWidget;
    Tree_Widget* RegFile_Details;
    Tree_Widget* DataMem_Details;

    Editor* output = new Editor();

public:
    TestWidget(string ,QWidget* parent=nullptr);
    void ObserverPattern();
    void init_details_widget();
signals:
    void Write_Warnings(vector<string>);

public slots:
    void show_details();
};

#endif // TESTWIDGET_H
