#include "execution.h"

Execution::Execution(QObject * parent) : Stage (parent)
{
    // ALU
    this->ALU= new QGraphicsPolygonItem(QPolygonF(QVector<QPointF>( {QPointF(315,-60),QPointF(389,13),QPointF(388,88),QPointF(315,158),QPointF(314,70),QPointF(328,48),QPointF(314,29)   }   ) ));
    this->ALU->setPen(QPen(QBrush(Qt::red,Qt::SolidPattern),5));
    emit addnewItem(this->ALU);

    // Forwarding Unit
    QPainterPath painter;
    painter.addRoundRect(255,377,155,85,95);
    this->Forwarding_Unit = new QGraphicsPathItem(painter);
    this->Forwarding_Unit->setPen(QPen(QBrush(Qt::red,Qt::SolidPattern),5));
    emit addnewItem(this->Forwarding_Unit);

    // MUXs
    painter.addRoundRect(180,-105,38,122,105);
    this->Mux_IDEX_ALU_1= new QGraphicsPathItem(painter);
    this->Mux_IDEX_ALU_1->setPen(QPen(QBrush(Qt::red,Qt::SolidPattern),5));
    emit addnewItem(Mux_IDEX_ALU_1);
    painter.addRoundRect(180,54,38,122,105);
    this->Mux_IDEX_ALU_2 = new QGraphicsPathItem(painter);
    this->Mux_IDEX_ALU_2->setPen(QPen(QBrush(Qt::red,Qt::SolidPattern),5));
    emit addnewItem(Mux_IDEX_ALU_2);
    painter.addRoundRect(180,271,38,122,105);
    this->Mux_IDEX_EXMEM = new QGraphicsPathItem(painter);
    this->Mux_IDEX_EXMEM->setPen(QPen(QBrush(Qt::red,Qt::SolidPattern),5));
    emit addnewItem(Mux_IDEX_EXMEM);

    // =================================  Paths =================================================
    this->paths["ForwardMUX_ALU_input1"] = newPath( { "221,-43" ,"311,-43" } );  // input1 ALU
    // ********** Same Path ***********
    this->paths["ForwardMUX_ALU_input2"] = newPath( {"220,116" ,"286,116" ,"286,189" ,"407,189"} ); // input2 ALU
    this->paths["ForwardMUX_ALU_input2_part2"]  = newPath({"286,115" ,"313,115"}); // INPUT2 Directly ALU ... Trash Wire
    // ********************************
    this->paths["ALU_Output"] = newPath( {"390,50" ,"411,50" } );

    this->paths["Forward_Mux_1"] = newPath( { "268,386" ,"268,45" ,"197,45" ,"197,22" } );                   this->paths["Forward_Mux_1"]->setWidth(WIDTH_MUX);
    this->paths["Forward_Mux_2"] = newPath( {"260,399" ,"245,399" ,"245,200" ,"200,200" ,"200,180" } );      this->paths["Forward_Mux_2"]->setWidth(WIDTH_MUX);
    this->paths["IDEX_MUX_1"] = newPath( {"15,-73" ,"175,-73" } );
    this->paths["IDEX_MUX_2"] = newPath( { "14,73" ,"175,73"  } );

    this->paths["IDEX_Forward_rs"] = newPath( {"14,269" ,"129,269" ,"129,416" ,"251,416"   } );
    this->paths["IDEX_MUX3_rd"] = newPath( {  "14,357" ,"177,357" } );

    // *********** Same Path ************
    this->paths["IDEX_Forward_rt"] = newPath( { "32,390" ,"32,437" ,"256,437" } );
    this->paths["IDEX_MUX3_rt"] = newPath( { "13,325" ,"176,325" } );
    this->paths["IDEX_Hazard_rt"] = newPath( { "33,323" ,"33,389" ,"-452,389" ,"-452,-333" } );
    // **********************************

    this->paths["MUX_EXMEM"] = newPath( {"221,339" ,"409,339"  } );

    // ************* Same Path **********
    this->paths["IDEX_Hazard"] = newPath( {"70,-207" ,"70,-384" ,"-342,-384"  });
    this->paths["IDEX_EXMEM_M"] = newPath( { "12,-205" ,"336,-205" ,"336,-155" ,"408,-155" } );
    // **********************************

    this->paths["IDEX_EXMEM_WB"] = newPath( { "15,-265" ,"348,-265" ,"348,-210" ,"410,-210" } );

    // ==================================Text Not Important============================================
    this->ALU_txt = new QGraphicsTextItem("ALU");
    this->ForwardUnit_txt = new QGraphicsTextItem("Forwarding\n       Unit");
    this->ALU_txt->setDefaultTextColor(QColor(TEXT_COLOR));
    this->ForwardUnit_txt->setDefaultTextColor(QColor(TEXT_COLOR));

    this->ALU_txt->setPos(330,30);
    this->ForwardUnit_txt->setPos(270,392);
    this->ALU_txt->setFont(QFont("Arial",FONT_SIZE,QFont::Bold));
    this->ForwardUnit_txt->setFont(QFont("Arial",FONT_SIZE,QFont::Bold));
    emit addnewItem(this->ALU_txt);
    emit addnewItem(this->ForwardUnit_txt);


    // ============ Text Instruction =============
    this->text_instruction->setPlainText("Execution");
    this->text_instruction->setFont(QFont("Arial",FONT_SIZE,QFont::Bold));
    this->text_instruction->setDefaultTextColor(TEXT_COLOR);
    this->text_instruction->setPos(200,-350);
    emit addnewItem(this->text_instruction);

}

void Execution::setStageColor(QColor clr,vector<string> muxs)
{
    // set Pen Color and Width
    this->color = clr;
    this->pen.setColor(this->color);
    this->pen.setWidth(PATH_WIDTH);
    // set Pen to all Components
    this->ALU->setPen(this->pen);
    this->Forwarding_Unit->setPen(this->pen);
    this->Mux_IDEX_ALU_1->setPen(this->pen);
    this->Mux_IDEX_ALU_2->setPen(this->pen);
    this->Mux_IDEX_EXMEM->setPen(this->pen);
    // Paths
    for (auto i = this->paths.begin(); i != this->paths.end(); i++)
        i->second->setPen(this->pen);

    this->text_instruction->setDefaultTextColor(this->color);

    if (muxs.size() >0)
    {
        string mux1 = muxs[0]; // upper mux alu input 1
        string mux2 = muxs[1]; // lower mux alu input 2
        if (mux1 != "0")
        {
            this->paths["IDEX_MUX_1"]->setColor(OFF_COLOR);
        }
        if (mux2 != "0")
        {
            this->paths["IDEX_MUX_2"]->setColor(OFF_COLOR);
        }
    }
}
