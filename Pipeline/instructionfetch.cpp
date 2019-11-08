#include "instructionfetch.h"

InstructionFetch::InstructionFetch(QObject *parent) : Stage(parent)
{
    // PC
    this->PC= new QGraphicsRectItem(-940,45,40,75);
    this->PC->setPen(QPen(QBrush(Qt::red,Qt::SolidPattern),5));
    emit addnewItem(this->PC);
    // Instruction Memory
    this->Ins_Memory = new QGraphicsRectItem(-862,-28,155,222);
    this->Ins_Memory->setPen(QPen(QBrush(Qt::red,Qt::SolidPattern),5));
    emit addnewItem(this->Ins_Memory);

    // ====================== Paths ===========================
    this->paths["Hazard_PC"] = newPath( { "-541,-407" ,"-918,-407" ,"-918,40" } );
    this->paths["Hazard_IFID"] = newPath( {"-543,-393" ,"-651,-393" ,"-651,-132" });

    this->paths["PC_InstructionMemory"] = newPath( { "-898,84" ,"-863,84" });
    this->paths["InstructionMemory_IFID"] = newPath( { "-704,84" ,"-675,84" });

    // ====================== Text =============================
    this->PC_txt = new QGraphicsTextItem("PC");
    this->InstructionMemory_txt = new QGraphicsTextItem("Instruction\nMemory");
    this->PC_txt->setDefaultTextColor(TEXT_COLOR);
    this->InstructionMemory_txt->setDefaultTextColor(TEXT_COLOR);
    this->PC_txt->setPos(-938,67);
    this->InstructionMemory_txt->setPos(-840,56);
    this->PC_txt->setFont(QFont("Arial",15,QFont::Bold));
    this->InstructionMemory_txt->setFont(QFont("Arial",15,QFont::Bold));
    emit addnewItem(this->PC_txt);
    emit addnewItem(this->InstructionMemory_txt);

    this->text_instruction->setPlainText("InstructionFetch");
    this->text_instruction->setFont(QFont("Arial",15,QFont::Bold));
    this->text_instruction->setDefaultTextColor(TEXT_COLOR);
    this->text_instruction->setPos(-900,-350);
    emit addnewItem(this->text_instruction);
}

void InstructionFetch::setStageColor(QColor clr)
{
    // set Pen Color and Width
    this->color = clr;
    this->pen.setColor(this->color);
    this->pen.setWidth(PATH_WIDTH);
    // set Pen to all Components
    this->PC->setPen(this->pen);
    this->Ins_Memory->setPen(this->pen);
    // Paths
    for (auto i = this->paths.begin(); i != this->paths.end(); i++)
        i->second->setPen(this->pen);
    this->text_instruction->setDefaultTextColor(this->color);


}
