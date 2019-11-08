#include "memorystage.h"

MemoryStage::MemoryStage(QObject* parent) : Stage (parent)
{
    // Data Memory
    this->Data_Memory = new QGraphicsRectItem(536,1,145,225);
    this->Data_Memory->setPen(QPen(QBrush(Qt::red,Qt::SolidPattern),5));
    emit addnewItem(this->Data_Memory);

    // ******** Same Path **********
    this->paths["EXMEM_MEMWB_UP"] = newPath( {"464,-208" ,"665,-208" ,"665,-156" ,"708,-156"  });
    this->paths["EXMEM_Forward_WB"] = newPath( { "484,-207" ,"484,418" ,"415,418" });
    // *****************************
    // ******** Same Path ***************
    this->paths["EXMEM_MEMWB_Down"] = newPath( { "465,339" ,"708,339" });
    this->paths["EXMEM_Forward_Down_MUX"] = newPath( { "475,341" ,"475,397" ,"410,397" });
    // **********************************

    // ******** Same Path **********
    this->paths["EXMEM_Memory_From_ALU_Result"] = newPath( { "466,27" ,"534,27" });
    this->paths["EXMEM_Back_EX_MUX_1"] = newPath( { "504,26" ,"504,489" ,"63,489" ,"63,-3" ,"178,-3" });
    this->paths["EXMEM_Back_EX_MUX_2"] = newPath( { "63,115" ,"178,116" });
    this->paths["EXMEM_MEMWB_Middle"] = newPath( { "504,262" ,"709,262" });
    // *****************************

    this->paths["EXMEM_Memory_from_MUX_ALU"] = newPath( { "465,189" ,"534,189" }); // comes from input2 ALU
    this->paths["DataMemory_Result"] = newPath( { "684,27" ,"708,27" });

    // =============== Text =================
    this->DataMemory_txt = new QGraphicsTextItem("Data Memory");
    this->DataMemory_txt->setDefaultTextColor(TEXT_COLOR);

    this->DataMemory_txt->setPos(545,90);
    this->DataMemory_txt->setFont(QFont("Arial",15,QFont::Bold));
    emit addnewItem(this->DataMemory_txt);

    // Text Instruction
    this->text_instruction->setPlainText("InstructionFetch");
    this->text_instruction->setFont(QFont("Arial",15,QFont::Bold));
    this->text_instruction->setDefaultTextColor(TEXT_COLOR);
    this->text_instruction->setPos(450,-350);
    emit addnewItem(this->text_instruction);

}

void MemoryStage::setStageColor(QColor clr)
{
    // set Pen Color and Width
    this->color = clr;
    this->pen.setColor(this->color);
    this->pen.setWidth(PATH_WIDTH);
    // set Pen to all Components
    this->Data_Memory->setPen(this->pen);

    // Paths
    for (auto i = this->paths.begin(); i != this->paths.end(); i++)
        i->second->setPen(this->pen);
    // for Text
    this->text_instruction->setDefaultTextColor(this->color);

}
