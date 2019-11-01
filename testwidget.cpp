#include "testwidget.h"

TestWidget::TestWidget(string Name,QWidget *parent) : QWidget (parent)
{
    // Memory Allocation
    this->layout = new QHBoxLayout();
    this->setLayout(this->layout);
    this->label  = new QLabel();
    this->BtnDetails = new QPushButton("Details");
    // label init
    this->name = Name;
    this->label->setText(QString::fromStdString (this->name) ) ;
    this->label->setStyleSheet(grey);
    this->label->setAlignment(Qt::AlignCenter);
    // Design Layout
    this->layout->addWidget(this->label);
    this->layout->setStretch(0,50); // index 0 is label ,,, any big value is good for dominant stretching for label
    this->layout->addWidget(this->BtnDetails,Qt::AlignRight);
    this->setMinimumWidth(MIN_SIZE);

    this->init_details_widget();
    this->ObserverPattern();
    this->show();
}

void TestWidget::ObserverPattern()
{
    connect(this->BtnDetails,SIGNAL(clicked()) ,this,SLOT(show_details()));
}

void TestWidget::init_details_widget()
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
    this->RegFile_Details->setAlignCenter(true);
    this->RegFile_Details->setWarning(true);
    this->RegFile_Details->headerItem()->setTextAlignment(0,Qt::AlignCenter);
    this->RegFile_Details->headerItem()->setTextAlignment(1,Qt::AlignCenter);
    // Design of DataMem
    this->DataMem_Details->setColumnCount(1);
    this->DataMem_Details->setHeaderLabels ( {"    ID","Warnings"} );
    this->DataMem_Details->setStyleSheet("QTreeView::item {padding: 15px; color: black;}");
    this->DataMem_Details->setTreeColor(QColor(255,255,220));
    this->DataMem_Details->setAlignCenter(true);
    this->DataMem_Details->headerItem()->setTextAlignment(0,Qt::AlignCenter);
    this->DataMem_Details->headerItem()->setTextAlignment(1,Qt::AlignCenter);
    // Design
    this->DetailsWidget->addTab(this->RegFile_Details,"RegFile");
    this->DetailsWidget->addTab(this->DataMem_Details,"DataMemory");
    this->DetailsWidget->setMovable(true);

    this->RegFile_Details->addItem({"1","Warning Register is not ray2"});
    this->RegFile_Details->addItem({"2","Warning Register is not ray2"});
    this->RegFile_Details->addItem({"3","Warning: register $s0 expected to be xx not YY"});
    this->RegFile_Details->addItem({"4","Warning Register is not ray2"});
    this->RegFile_Details->addItem({"5","Warning Register is not ray2"});

//    output = new Editor(QColor(255,255,170)); // yellow
//    this->output->setStyleSheet("QPlainTextEdit {height: 200%;}");
//    this->DetailsWidget->addTab(this->output,"Registers");
//    connect(this,SIGNAL(Write_Warnings(vector<string>)), output,SLOT(Write_Code_Text_Editor(vector<string>)));
//    vector<string> x = {"Warning: register $s0 expected to be xx not YY","Warning: register $s0 expected to be xx not YY","Warning not ray2" , "Warning: register $s0 expected to be xx not YY" ,"Warning: register $s0 expected to be xx not YY","Warning: register $s0 expected to be xx not YY"};
//    emit Write_Warnings(x);


}

void TestWidget::show_details()
{
   this->DetailsWidget->show();
}

