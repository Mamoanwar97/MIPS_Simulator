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
#include "filestester.h"

#define green "background-color:rgb(0, 255, 0); color:white"
#define red "background-color:rgb(255,0,0); color:white"
#define grey "background-color:rgb(220, 220, 220) ; color:white"
#define MIN_WIDTH 600
#define TEST_HIGHT 50
#define DETAILS_WIDTH 600
#define DETAILS_HIGHT 400

class TestCase : public QWidget
{
    Q_OBJECT
    friend class TestWidget;
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

    filesTester* file_tester;
    string assembly_path;

public:
    TestCase(string ,QWidget* parent=nullptr);
    void ObserverPattern();
    void init_details_widget();
    void setPaths(string assembly , string  regfile , string datamem);

signals:
    void startSimulationTestCase(string);
public slots:
    void show_details();
    void Set_Warnings_RegFile(vector<string>);
    void Set_Warnings_DataMem(vector<string>);
    void Test_Result(bool result);
    void start_simulating();

};

#endif // TestCase_H
