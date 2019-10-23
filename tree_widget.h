#ifndef TREE_WIDGET_H
#define TREE_WIDGET_H

#define REGISTER "registers"
#define EXECUTE "Execute"
#define DATA_MEMORY "data_memory"
#define ADDRESS 0
#define CODE 1
#define INSTRUCTION 2
#define RegisterValue 2
#define RegisterName 0
#define COLOR 220,220,220

#include "register.h"
#include <bits/stdc++.h>
#include <QObject>
#include <QWidget>
#include <QTabWidget>
#include <QTextEdit>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QStringList>

using namespace std;

class Tree_Widget : public QTreeWidget
{
    Q_OBJECT
protected:
    QColor color;
    bool flag_color;
    vector<QTreeWidgetItem*> Items ;

public:
    explicit Tree_Widget(QWidget *parent = nullptr);
    void init_registers();
    void addItem();
    void addItem(QStringList);
    void setColor(QTreeWidgetItem*item);
    void clean_from_specials();


};

#endif // TREE_WIDGET_H
