#include "execute_widget.h"

Execute_Widget::Execute_Widget(QWidget *parent) : Tree_Widget(parent)
{
    this->setColumnCount(3);
    this->setHeaderLabels({"  Address","Code","Instruction"});

}

void Execute_Widget::updateInstructions()
{
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

