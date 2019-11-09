#include "writebackstage.h"

WriteBackStage::WriteBackStage(QObject* parent) : Stage (parent)
{
    // MUX
    painter.addRoundRect(822,-3,38,122,105);
    this->Mux_MEMWD_RegFile = new QGraphicsPathItem(painter);
    this->Mux_MEMWD_RegFile->setPen(QPen(QBrush(Qt::red,Qt::SolidPattern),5));
    emit addnewItem(Mux_MEMWD_RegFile);

    // ================= Paths =========================
    this->paths["MEMWB_Forward_Up"  ] = newPath( {"763,-155" ,"793,-155" ,"793,453" ,"401,453"  });
    // *********** Same Path *****************
    this->paths["MEMWB_Forward_Down"] = newPath( {"762,354" ,"776,354" ,"776,434" ,"412,434"    });
    this->paths["MEMWB_RegFile_Back"] = newPath( {"603,434" ,"603,530" ,"-502,530" ,"-502,48" ,"-323,48"  });
    // ***************************************

    this->paths["MEMWB_MUX_input1"] = newPath( { "762,26" ,"818,26" });
    this->paths["MEMWB_MUX_input2"] = newPath( { "760,101" ,"818,101"});
    // ************** Same Path ***************
    this->paths["MUX_Write_RegFile"] = newPath( {"863,56" ,"879,56" ,"879,516" ,"-471,516" ,"-471,112" ,"-326,112"  });
    this->paths["MUX_ExecutionMUX_1"] = newPath( {"82,515" ,"82,-40" ,"176,-40" });
    this->paths["MUX_ExecutionMUX_2"] = newPath( {"83,154" ,"178,154"  });
    //    this->paths[""] = newPath( {  });

    // Text
    this->text_instruction->setPlainText("WriteBack");
    this->text_instruction->setFont(QFont("Arial",FONT_SIZE,QFont::Bold));
    this->text_instruction->setDefaultTextColor(TEXT_COLOR);
    this->text_instruction->setPos(700,-350);
    emit addnewItem(this->text_instruction);

}


void WriteBackStage::setStageColor(QColor clr,vector<string> muxs)
{
    // set Pen Color and Width
    this->color = clr;
    this->pen.setColor(this->color);
    this->pen.setWidth(PATH_WIDTH);
    // set Pen to all Components
    this->Mux_MEMWD_RegFile->setPen(this->pen);

    // Paths
    for (auto i = this->paths.begin(); i != this->paths.end(); i++)
        i->second->setPen(this->pen);
    this->text_instruction->setDefaultTextColor(this->color);


}
