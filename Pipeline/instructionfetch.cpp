#include "instructionfetch.h"

InstructionFetch::InstructionFetch(QObject *parent) : Stage(parent)
{
    // PC_Adder
    this->PC_Adder= new QGraphicsPolygonItem(QPolygonF(QVector<QPointF>( {QPointF(-813,-122),QPointF(-813,-99),QPointF(-803,-90),QPointF(-815,-80),QPointF(-815,-60),QPointF(-781,-76),QPointF(-781,-106)   }   ) ));
    this->PC_Adder->setPen(QPen(QBrush(Qt::red,Qt::SolidPattern),5));
    emit addnewItem(this->PC_Adder);
    // PC
    this->PC= new QGraphicsRectItem(-940,45,40,75);
    this->PC->setPen(QPen(QBrush(Qt::red,Qt::SolidPattern),5));
    emit addnewItem(this->PC);
    // Instruction Memory
    this->Ins_Memory = new QGraphicsRectItem(-862,-28,155,222);
    this->Ins_Memory->setPen(QPen(QBrush(Qt::red,Qt::SolidPattern),5));
    emit addnewItem(this->Ins_Memory);
    // ======= MUX ==========
    painter.addRoundRect(-820,-305,38,122,105);
    this->MUX_PC= new QGraphicsPathItem(painter);
    this->MUX_PC->setPen(QPen(QBrush(Qt::red,Qt::SolidPattern),5));
    emit addnewItem(MUX_PC);
    // ====================== Paths ===========================
    this->paths["Hazard_PC"] = newPath( { "-541,-407" ,"-918,-407" ,"-918,40" } );
    this->paths["Hazard_IFID"] = newPath( {"-543,-393" ,"-651,-393" ,"-651,-132" });

    this->paths["PC_InstructionMemory"] = newPath( { "-898,84" ,"-863,84" });
    this->paths["InstructionMemory_IFID"] = newPath( { "-704,84" ,"-675,84" });

    this->paths["PC_pcAdder"] = newPath( { "-883,82" ,"-883,-74" ,"-815,-74"  });
    this->paths["puls_4"] = newPath( { "-854,-112" ,"-813,-112" });
    this->paths["pcAdder_MUX"] = newPath( {"-781,-92" ,"-732,-92" ,"-732,-211" ,"-781,-211"} );
    this->paths["MUX_PC"] = newPath( {"-820,-254" ,"-973,-254" ,"-973,79" ,"-942,79"} );

    // ====================== Text =============================
    this->PC_txt = new QGraphicsTextItem("PC");
    this->InstructionMemory_txt = new QGraphicsTextItem("Instruction\nMemory");
    this->PC_txt->setDefaultTextColor(TEXT_COLOR);
    this->InstructionMemory_txt->setDefaultTextColor(TEXT_COLOR);
    this->PC_txt->setPos(-938,67);
    this->InstructionMemory_txt->setPos(-840,56);
    this->PC_txt->setFont(QFont("Arial",FONT_SIZE,QFont::Bold));
    this->InstructionMemory_txt->setFont(QFont("Arial",FONT_SIZE,QFont::Bold));
    emit addnewItem(this->PC_txt);
    emit addnewItem(this->InstructionMemory_txt);

    this->text_instruction->setPlainText("InstructionFetch");
    this->text_instruction->setFont(QFont("Arial",FONT_SIZE,QFont::Bold));
    this->text_instruction->setDefaultTextColor(TEXT_COLOR);
    this->text_instruction->setPos(-900,-350);
    emit addnewItem(this->text_instruction);

    this->pcAdder_txt = new QGraphicsTextItem("4        +");
    this->pcAdder_txt->setFont(QFont("Arial",FONT_SIZE,QFont::Bold));
    this->pcAdder_txt->setDefaultTextColor(TEXT_COLOR);
    this->pcAdder_txt->setPos(-860,-109);
    emit addnewItem(this->pcAdder_txt);
}

void InstructionFetch::setStageColor(QColor clr)
{
    // set Pen Color and Width
    this->color = clr;
    this->pen.setColor(this->color);
    this->pen.setWidth(PATH_WIDTH);
    // set Pen to all Components
    this->PC->setPen(this->pen);
    this->PC_Adder->setPen(this->pen);
    this->Ins_Memory->setPen(this->pen);
    this->MUX_PC->setPen(this->pen);
    // Paths
    for (auto i = this->paths.begin(); i != this->paths.end(); i++)
        i->second->setPen(this->pen);
    this->text_instruction->setDefaultTextColor(this->color);
    this->pcAdder_txt->setDefaultTextColor(this->color);

}
