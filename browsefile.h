#ifndef BROWSEFILE_H
#define BROWSEFILE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QFileDialog>
#include <QLabel>
#include <bits/stdc++.h>
using namespace std;
#define MIN_WIDTH_LABEL 95
#define DIRECTORY "C:\\MIPS_Simulator\\TestCases"
class BrowseFile : public QWidget
{
    Q_OBJECT
private:
    QHBoxLayout* layout;
    QLabel* label;
    QLineEdit* entry;
    QPushButton* BrowseBtn;
    QFileDialog* file_dialog;
    string path;
    bool SelectedPath;
public:
    BrowseFile(string name , QWidget* parent = nullptr);
    void ObserverPattern();
    bool isSelectedPath();
    void clear();
    string getText();

public slots:
    void show_dialog();
    void SetFilePath(QStringList);
signals:
};
#endif // BROWSEFILE_H
