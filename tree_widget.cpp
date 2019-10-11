#include "tree_widget.h"

Tree_Widget::Tree_Widget(string type ,QWidget *parent) : QTreeWidget(parent)
{
    this->Type = type;
    this->color.setRgb(COLOR);
    this->flag_color = 1;

    if(type == REGISTER)
    {
        this->setColumnCount(3);
        this->setHeaderLabels({"  Name","Num","Value"});
        this->init_registers();
    }
    else if (type == EXECUTE)
    {
        this->setColumnCount(3);
        this->setHeaderLabels({"  Address","Code","Instruction"});
    }
}

void Tree_Widget::init_registers()
{
    this->addItem({"$zero", "0"  , "0" });
    this->addItem({ "$at" , "1"  , "0" });
    this->addItem({ "$v0" , "2"  , "0" });
    this->addItem({ "$v1" , "3"  , "0" });
    this->addItem({ "$a0" , "4"  , "0" });
    this->addItem({ "$a1" , "5"  , "0" });
    this->addItem({ "$a2" , "6"  , "0" });
    this->addItem({ "$a3" , "7"  , "0" });
    this->addItem({ "$t0" , "8"  , "0" });
    this->addItem({ "$t1" , "9"  , "0" });
    this->addItem({ "$t2" , "10" , "0" });
    this->addItem({ "$t3" , "11" , "0" });
    this->addItem({ "$t4" , "12" , "0" });
    this->addItem({ "$t5" , "13" , "0" });
    this->addItem({ "$t6" , "14" , "0" });
    this->addItem({ "$t7" , "15" , "0" });
    this->addItem({ "$s0" , "16" , "0" });
    this->addItem({ "$s1" , "17" , "0" });
    this->addItem({ "$s2" , "18" , "0" });
    this->addItem({ "$s3" , "19" , "0" });
    this->addItem({ "$s4" , "20" , "0" });
    this->addItem({ "$s5" , "21" , "0" });
    this->addItem({ "$s6" , "22" , "0" });
    this->addItem({ "$s7" , "23" , "0" });
    this->addItem({ "$t8" , "24" , "0" });
    this->addItem({ "$t9" , "25" , "0" });
    this->addItem({ "$k0" , "26" , "0" });
    this->addItem({ "$k1" , "27" , "0" });
    this->addItem({ "$gp" , "28" , "0" });
    this->addItem({ "$sp" , "29" , "0" });
    this->addItem({ "$fp" , "30" , "0" });
    this->addItem({ "$ra" , "31" , "0" });
}
void Tree_Widget::updateRegisters()
{
    if (this->Type != REGISTER)
        return;

    map<string,Register*> all_registers = emit get_registers();

    for (uint i = 0; i < Items.size(); ++i) {
       string name = this->Items[i]->text(RegisterName).toStdString() ;
       long value = all_registers[name]->getValue();
       this->Items[i]->setText(RegisterValue,  QString::fromStdString( to_string(value) )  );
    }}
void Tree_Widget::updateInstructions()
{
    if (this->Type != EXECUTE)
        return;

    // delete the memory that the pointers points to to erase it from the GUI
    for (uint i = 0; i < this->Items.size(); ++i)
       delete this->Items[i];

    // clear the vector
    this->Items.clear();

    vector<string> instructions = emit require_Instructions();
    vector<string> Assembly_code = emit require_AssembledInstructions();

    uint_fast64_t n = instructions.size();
    cout << "n = " << n << endl;

    for (uint i = 0; i < n; ++i)
    {
        QString Instruction = QString::fromStdString( instructions[i] );
        QString Address     = QString::fromStdString( to_string (i*4) );
        QString Code        = QString::fromStdString( Assembly_code[i]);
        QStringList S       = {Address , Code , Instruction};
        this->addItem(S);
    }
}

void Tree_Widget::addItem()
{
    QTreeWidgetItem * item = new QTreeWidgetItem(QStringList());
    this->setColor(item);

    this->addTopLevelItem(item);
    this->Items.push_back(item);}
void Tree_Widget::addItem(QStringList s)
{
    QTreeWidgetItem * item = new QTreeWidgetItem(s);
    this->setColor(item);

    this->addTopLevelItem(item);
    this->Items.push_back(item);}

void Tree_Widget::setColor(QTreeWidgetItem *item)
{
    if (this->flag_color)
    {
        for (uint i =0;i <item->columnCount();i++) {
            item->setBackground(i,this->color);
        }
        this->flag_color = 0;
    }
    else {
        this->flag_color = 1;
    }
}
