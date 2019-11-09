#ifndef MEMORYSTAGE_H
#define MEMORYSTAGE_H

#include "stage.h"
class MemoryStage : public Stage
{
    Q_OBJECT
private:
    QGraphicsRectItem* Data_Memory;
    QGraphicsTextItem* DataMemory_txt;

public:
    MemoryStage(QObject* parent);
    void setStageColor(QColor clr,vector<string> muxs = vector<string>());

};

#endif // MEMORYSTAGE_H
