#ifndef INSTRUCTIONFETCH_H
#define INSTRUCTIONFETCH_H

#include <QObject>
#include "stage.h"

class InstructionFetch : public Stage
{
    Q_OBJECT
private:
    QGraphicsRectItem* PC;
    QGraphicsRectItem* Ins_Memory;
    QGraphicsTextItem* PC_txt;
    QGraphicsTextItem* InstructionMemory_txt;


    QGraphicsPolygonItem* PC_Adder;
    QGraphicsTextItem* pcAdder_txt;
    QGraphicsPathItem* MUX_PC;

public:
    InstructionFetch(QObject *parent);
    void setStageColor(QColor clr,vector<string> muxs = vector<string>());

signals:

public slots:
};

#endif // INSTRUCTIONFETCH_H
