#ifndef TREE_WIDGET_H
#define TREE_WIDGET_H

#define REGISTER "registers"
#define EXECUTE "Execute"
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
private:
    string Type ;
    QColor color;
    bool flag_color;
    vector<QTreeWidgetItem*> Items ;

public:
    explicit Tree_Widget(string type,QWidget *parent = nullptr);
    void init_registers();
    void addItem();
    void addItem(QStringList);
    void setColor(QTreeWidgetItem*item);
    void clean_from_specials();
public slots:
    void updateRegisters();
    void updateInstructions();
signals:
    vector<string> require_Instructions();
    vector<string> require_AssembledInstructions();
    map<string,Register*> get_registers();

};

#endif // TREE_WIDGET_H
