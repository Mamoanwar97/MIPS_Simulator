#include "testcase.h"

TestCase::TestCase(string Name,QWidget *parent) : QWidget (parent)
{
    // Memory Allocation
    this->layout = new QHBoxLayout();
    this->setLayout(this->layout);
    this->label  = new QLabel();
    this->BtnDetails = new QPushButton("Details");
    this->BtnTest    = new QPushButton("Test");
    this->id = 0;
    // label init
    this->name = Name;
    this->label->setText(QString::fromStdString (this->name) ) ;
    this->label->setStyleSheet(grey);
    this->label->setAlignment(Qt::AlignCenter);
    // Design Layout
    this->layout->addWidget(this->label);
    this->layout->setStretch(0,50); // index 0 is label ,,, any big value is good for dominant stretching for label
    this->layout->addWidget(this->BtnDetails,Qt::AlignRight);
    this->layout->addWidget(this->BtnTest,Qt::AlignRight);
    this->setMinimumWidth(MIN_SIZE);

    this->init_details_widget();
    this->ObserverPattern();
    this->show();
}

void TestCase::ObserverPattern()
{
    connect(this->BtnDetails,SIGNAL(clicked()) ,this,SLOT(show_details()));
    connect(this->BtnTest   ,SIGNAL(clicked()) ,this,SLOT(Test_Files()));
}

void TestCase::init_details_widget()
{
    // Memory Allocation
    this->DetailsWidget = new QTabWidget() ; // don't put ("this" as parent) we want it hidden
    this->RegFile_Details = new Tree_Widget();
    this->DataMem_Details = new Tree_Widget();
    // Design of RegFile
    this->RegFile_Details->setColumnCount(2);
    this->RegFile_Details->setHeaderLabels ( {"    ID","Warnings"} );
    this->RegFile_Details->setStyleSheet("QTreeView::item {padding: 15px; color: black;}");
    this->RegFile_Details->setTreeColor(QColor(255,255,220));
    this->RegFile_Details->setWarning(true);
    this->RegFile_Details->headerItem()->setTextAlignment(0,Qt::AlignCenter);
    this->RegFile_Details->headerItem()->setTextAlignment(1,Qt::AlignCenter);
    // Design of DataMem
    this->DataMem_Details->setColumnCount(2);
    this->DataMem_Details->setHeaderLabels ( {"    ID","Warnings"} );
    this->DataMem_Details->setStyleSheet("QTreeView::item {padding: 15px; color: black;}");
    this->DataMem_Details->setTreeColor(QColor(255,255,220));
    this->DataMem_Details->setWarning(true);
    this->DataMem_Details->headerItem()->setTextAlignment(0,Qt::AlignCenter);
    this->DataMem_Details->headerItem()->setTextAlignment(1,Qt::AlignCenter);
    // Design
    this->DetailsWidget->addTab(this->RegFile_Details,"RegFile");
    this->DetailsWidget->addTab(this->DataMem_Details,"DataMemory");
    this->DetailsWidget->setMovable(true);

}

void TestCase::show_details()
{
    this->DetailsWidget->show();
}

void TestCase::Set_Warnings_DataMem(vector<string> warnings)
{
    for (uint i =0 ; i< warnings.size() ; i++)
    {
        this->id ++ ;
        QStringList Warning ;
        // id , Warning ICon , Warning
        Warning.append( QString::fromStdString(to_string(this->id)) );
        Warning.append( QString::fromStdString("Warning: " + warnings[i]) );
        // add the colomns item to RegFile
        this->DataMem_Details->addItem(Warning);
    }
}

void TestCase::Test_Result(bool result)
{
    this->testCaseState = result;
    if (this->testCaseState) // if sucess
        this->label->setStyleSheet(green);
    else
        this->label->setStyleSheet(red);
}

void TestCase::Test_Files()
{

}

void TestCase::Set_Warnings_RegFile(vector<string> warnings)
{
    for (uint i =0 ; i< warnings.size() ; i++)
    {
        this->id ++ ;
        QStringList Warning ;
        // id , Warning ICon , Warning
        Warning.append( QString::fromStdString(to_string(this->id)) );
        Warning.append( QString::fromStdString("Warning: " + warnings[i]) );
        // add the colomns item to RegFile
        this->RegFile_Details->addItem(Warning);
    }
}

