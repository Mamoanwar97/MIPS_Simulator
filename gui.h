#ifndef GUI_H
#define GUI_H

#include "execute_widget.h"
#include "regfile_widget.h"
#include "data_mem_widget.h"
#include "tree_widget.h"
#include "editor.h"
#include "simulator.h"
#include <bits/stdc++.h>
#include <QObject>
#include <QLineEdit>
#include <QDebug>
#include <QWidget>
#include <QPushButton>
#include <QKeyEvent>
#include <QBrush>
#include <QColor>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QSpacerItem>
#include <QVBoxLayout>
#include <QLabel>
#include <QTabWidget>
#include <QTextEdit>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QStringList>

#define RUN "Run"
#define DEBUG "Debug"
#define INCLUDE "include"
#define EDIT "Edit"
#define EXECUTE "Execute"
#define REGISTERS_TYPE "registers"
#define DATA_MEM "Memory"

#define Width_Editor 600
#define Hight_Editor 500
#define Registers_Width 300
#define O_Screen_Hight 150

using namespace  std;


class GUI : public QWidget
{
    Q_OBJECT
    friend class MainWindow;
private:
    Simulator* simulator ;
    string path;

    QGridLayout* grid ;

    QTabWidget* tabWidget;
    Editor* Code_Editor;
    Execute_Widget* Execution;
    Data_Mem_Widget* Data_Memory;

    QHBoxLayout* horizontalLayout;
    QLineEdit *  lineEdit;
    QPushButton* includeBtn;
    QPushButton* RunBtn;
    QPushButton* DebugBtn;


    Editor* IO_Screen;
    QTabWidget* IO_Screen_Container;
    regFile_Widget* Registers_Table;
public:
    explicit GUI(QWidget *parent = nullptr);
    ~GUI();

    void Design();
    void init_horizontal_layout();
    void Signals_Slots();


    void keyPressEvent(QKeyEvent * event);

signals:
    void update(vector<int>);

public slots:
    void Start_Simulation();
    void Start_Simulation_File();
    void Output_Screen(string);
};

vector<string> split_string(string s,string splitter);

#endif // GUI_H
