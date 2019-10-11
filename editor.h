#ifndef Editor_H
#define Editor_H

#include <bits/stdc++.h>
#include <QObject>
#include <QWidget>
#include <QTabWidget>
#include <QTextEdit>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QStringList>


using namespace std;
class GUI;
class Editor : public QTextEdit
{
    Q_OBJECT
    friend class GUI;
private:

public:
    explicit Editor(QWidget *parent = nullptr);

signals:

public slots:
    void Write_Code_Text_Editor(vector<string>);
    vector<string> Read_Code_Text_Editor();
};

vector<string> split_string(string s,string splitter);


#endif // Editor_H
