#ifndef TestCase_H
#define TestCase_H
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
#define grey "background-color:rgb(220, 220, 220)"
#define MIN_SIZE 600

class TestCase : public QWidget
{
    Q_OBJECT
private:
    QHBoxLayout* layout;
    QLabel* label;
    string name;
    bool testCaseState;
    QPushButton* BtnDetails;
    QPushButton* BtnTest;

    QTabWidget* DetailsWidget;
    Tree_Widget* RegFile_Details;
    Tree_Widget* DataMem_Details;
    int id;

    string assemblyPath;
    string regfilePath;
    string datamemPath;

public:
    TestCase(string ,QWidget* parent=nullptr);
    void ObserverPattern();
    void init_details_widget();
signals:
public slots:
    void show_details();
    void Set_Warnings_RegFile(vector<string>);
    void Set_Warnings_DataMem(vector<string>);
    void Test_Result(bool result);
    void Test_Files();
};

#endif // TestCase_H
