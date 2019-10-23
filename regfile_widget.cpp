#include "regfile_widget.h"

regFile_Widget::regFile_Widget(QWidget *parent) : Tree_Widget(parent)
{
    this->setColumnCount(3);
    this->setHeaderLabels({"  Name","Num","Value"});
    this->init_registers();
}

void regFile_Widget::init_registers()
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

void regFile_Widget::updateRegisters()
{
    map<string,Register*> all_registers = emit get_registers();

    for (uint i = 0; i < Items.size(); ++i) {
       string name = this->Items[i]->text(RegisterName).toStdString() ;
       int value = all_registers[name]->getValue();
       this->Items[i]->setText(RegisterValue,  QString::fromStdString( to_string(value) )  );
    }
}
