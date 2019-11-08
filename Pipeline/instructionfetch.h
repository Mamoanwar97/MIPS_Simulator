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

public:
    InstructionFetch(QObject *parent);
    void setStageColor(QColor clr);

signals:

public slots:
};

#endif // INSTRUCTIONFETCH_H
