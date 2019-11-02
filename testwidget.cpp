#include "testwidget.h"

TestWidget::TestWidget(QWidget *parent) : QWidget(parent)
{
    this->centralLayout = new QVBoxLayout();
    this->grid = new QGridLayout();

    this->testcasesWidget = new QWidget();
    this->testCasesLayout = new QVBoxLayout();
    this->scroll = new QScrollArea();

    this->RegFileBrowse = new BrowseFile ("RegFile:");
    this->DataMemBrowse = new BrowseFile ("DataMemory:");
    this->AssemblyBrowse= new BrowseFile ("Asembly:");
    this->AddTestBtn = new QPushButton("Add TestCase");
    this->TestAllBtn = new QPushButton("Test All");

//    for (uint i =0 ; i<10 ; i++)
//        this->addTestCase();

    this->Design();
    this->ObserverPattern();
    this->show();
}

void TestWidget::Design()
{
    this->grid->addWidget(this->AssemblyBrowse,0,0,1,-1);
    this->grid->addWidget(this->RegFileBrowse ,1,0,1,-1);
    this->grid->addWidget(this->DataMemBrowse ,2,0,1,-1);
    this->grid->addWidget(this->AddTestBtn,3,0);
    this->grid->addWidget(this->TestAllBtn,3,1);

    this->testcasesWidget->setLayout(this->testCasesLayout);
    scroll->setWidget(this->testcasesWidget);
    scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll->setWidgetResizable(true);

    this->centralLayout->addLayout(this->grid);
    this->centralLayout->addWidget(this->scroll);

    this->setLayout(this->centralLayout);
    this->testcasesWidget->setStyleSheet("background-color:white");
    //    this->testcasesWidget->setStyleSheet("border:2px solid");
}

void TestWidget::ObserverPattern()
{
    connect(this->AddTestBtn,SIGNAL(clicked()),this,SLOT(addTestCase()));
}

void TestWidget::addTestCase()
{
    if (this->RegFileBrowse->isSelectedPath() && this->DataMemBrowse->isSelectedPath() && this->AssemblyBrowse->isSelectedPath())
    {
        // add new TestCase
        ulong id = this->TestCases.size();
        TestCase* testcase = new TestCase("TestCase"+to_string(id+1));
        this->testCasesLayout->addWidget(testcase);
        this->TestCases.push_back(testcase);
        // clear the browsers
        this->RegFileBrowse->clear();
        this->DataMemBrowse->clear();
        this->AssemblyBrowse->clear();
    }
    else {
        cout << "you are not ray2 "<< endl;
    }
}
