#include "gui.h"

GUI::GUI(QWidget *parent) :
    QWidget (parent)
{
    this->path = "/home/amrelsersy/MIPS/dummy.txt";
    // memory allocation
    this->simulator = new Simulator();
//    this->simulator->Simulate(this->path);
    this->grid    = new QGridLayout();

    this->tabWidget       = new QTabWidget();
    this->Registers_Table = new regFile_Widget();
    this->Execution       = new Execute_Widget();
    this->Data_Memory     = new Data_Mem_Widget();

    this->Code_Editor     = new Editor();
    this->IO_Screen       = new Editor();
    this->IO_Screen_Container = new QTabWidget();
    this->IO_Screen->setReadOnly(true);

    this->init_horizontal_layout();
    this->Design();
    this->Signals_Slots();
}

GUI::~GUI()
{
    delete this->grid;
    delete this->simulator;
    delete this->tabWidget;
    delete this->Code_Editor;
    delete this->IO_Screen;
    delete this->Registers_Table;
    delete this->Execution;
}

void GUI::Design()
{
    this->setStyleSheet("background-color:white");
    this->tabWidget->addTab(this->Code_Editor,EDIT);
    this->tabWidget->addTab(this->Execution,EXECUTE);
    this->tabWidget->addTab(this->Data_Memory,DATA_MEM);
    this->tabWidget->setMovable(true);

    this->IO_Screen_Container->addTab(this->IO_Screen,"Output");

    // Grid Design
    this->grid->addLayout(this->horizontalLayout,0,0,1,-1);
    this->grid->addWidget(this->tabWidget,1,0,3,3);
    this->grid->addWidget(this->Registers_Table,1,3,-1,1);
    this->grid->addWidget(this->IO_Screen_Container,4,0,1,3);

    // for resizing
    this->grid->setColumnStretch(0,1); // TabWidget
    this->grid->setRowStretch(1,3); // TabWidget also
    this->grid->setRowStretch(2,3); // TabWidget also
    this->grid->setRowStretch(4,2); // IO_Screen

    // Set Min Size
    this->grid->setColumnMinimumWidth(0,Width_Editor); // TabWidget and IO_Screen
    this->grid->setRowMinimumHeight(1,Hight_Editor);   // TabWidget
    this->grid->setColumnMinimumWidth(3,Registers_Width); // Registers Table
    this->grid->setRowMinimumHeight(4,O_Screen_Hight);   // IO_Screen

    this->setLayout(this->grid);
}

void GUI::init_horizontal_layout()
{
    this->horizontalLayout = new QHBoxLayout();
    this->lineEdit         = new QLineEdit();
//    this->lineEdit->       setReadOnly(true);
    this->includeBtn       = new QPushButton(INCLUDE);
    this->RunBtn           = new QPushButton(RUN);
    this->DebugBtn         = new QPushButton(DEBUG);

    this->horizontalLayout->addWidget(this->lineEdit);
    this->horizontalLayout->addWidget(this->includeBtn);
    this->horizontalLayout->addWidget(this->RunBtn);
    this->horizontalLayout->addWidget(this->DebugBtn);
}

void GUI::Signals_Slots()
{
    connect( this->Execution,SIGNAL(require_Instructions() ), this->simulator , SLOT ( get_instructions() ) );
    connect( this->Execution,SIGNAL(require_AssembledInstructions() ), this->simulator->assembler , SLOT ( get_assembled_strings() ) );

    connect( this->Data_Memory,SIGNAL(get_access_memory() ), this->simulator->data_memory, SLOT ( get_Memory_Access() ) );
    connect( this->Registers_Table,SIGNAL(get_registers() ), this->simulator->register_file , SLOT ( registers_reading() ) );
    connect( this->simulator->Alu ,SIGNAL( syscall(string) ) , this,SLOT( Output_Screen(string) ) );

    connect( this->RunBtn     , SIGNAL(clicked() )     , this , SLOT( Start_Simulation() ) );
    connect( this->includeBtn , SIGNAL(clicked() )     , this , SLOT( Start_Simulation_File() ) );

    connect( this->simulator, SIGNAL(getInstruction_Editor()), this->Code_Editor,SLOT(Read_Code_Text_Editor() ));
    connect( this->simulator, SIGNAL(update_assembled_instruction() ) , this->Execution , SLOT( updateInstructions() ) );
    connect( this->simulator, SIGNAL(update_registers() )    , this->Registers_Table , SLOT( updateRegisters() ) );
    connect( this->simulator, SIGNAL(update_data_memory() ), this->Data_Memory , SLOT( update_memory() ) );
    connect( this->simulator->Alu , SIGNAL (update_memory_gui(uint)) , this->Data_Memory , SLOT(update_memory(uint)) );
}

void GUI::keyPressEvent(QKeyEvent *event)
{
    if(event->key()== Qt::Key_L){
        this->Execution->updateInstructions();
        cout << "L pressed" << endl;
    }
    else if (event->key() == Qt::Key_R) {
        this->Registers_Table->updateRegisters();
        cout << "R Pressed" << endl;
    }
}

void GUI::Start_Simulation()
{
    this->IO_Screen->clear();
    this->simulator->Simulate();
}

void GUI::Start_Simulation_File()
{
    this->IO_Screen->clear();
    string path = this->lineEdit->text().toStdString();
    this->simulator->Simulate(path);
}

void GUI::Output_Screen(string syscall_msg)
{
    vector<string> x ;
    x.push_back(syscall_msg);
    this->IO_Screen->Write_Code_Text_Editor(x);
    x.clear();
}

