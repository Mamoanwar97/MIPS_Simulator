#ifndef BROWSEFILE_H
#define BROWSEFILE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QFileDialog>
#include <bits/stdc++.h>
using namespace std;

class BrowseFile : QWidget
{
    Q_OBJECT
private:
    QHBoxLayout* layout;
    QLineEdit* entry;
    QPushButton* BrowseBtn;
    QFileDialog* file_dialog;
    string path;
    bool SelectedPath;
public:
    BrowseFile(QWidget* parent = nullptr);
    void ObserverPattern();
    bool isSelectedPath();
    void clear();

public slots:
    void show_dialog();
    void SetFilePath(QStringList);
signals:
};
#endif // BROWSEFILE_H
