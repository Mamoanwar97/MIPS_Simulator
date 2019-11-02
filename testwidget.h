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


class TestWidget : public QWidget
{
    Q_OBJECT
private:
    QGridLayout* grid;
    QVBoxLayout* testCasesLayout ;


public:
    TestWidget(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // TESTWIDGET_H
