#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QFileDialog>
#include "testcase.h"
#include "browsefile.h"
#include <QScrollArea>


class TestWidget : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout* centralLayout;
    QGridLayout* grid;
    QWidget* testcasesWidget;
    QScrollArea* scroll;
    QVBoxLayout* testCasesLayout ;
    BrowseFile* RegFileBrowse;
    BrowseFile* DataMemBrowse;
    BrowseFile* AssemblyBrowse;
    QPushButton* AddTestBtn;
    QPushButton* TestAllBtn;
    vector<TestCase*> TestCases;

public:
    TestWidget(QWidget *parent = nullptr);
    void Design();
    void ObserverPattern();
signals:

public slots:
    void addTestCase();
};

#endif // TESTWIDGET_H
