#ifndef INSTRUCTIONDECODE_H
#define INSTRUCTIONDECODE_H
#include "stage.h"

class InstructionDecode : public Stage
{
    Q_OBJECT
private:
    QGraphicsRectItem* RegFile ;
    QGraphicsEllipseItem* Control;
    QGraphicsPathItem* Hazard_Unit;
    QGraphicsPathItem* Mux_Control_IDEX;
    // Text (Not Important)
    QGraphicsTextItem* RegFile_txt;
    QGraphicsTextItem* Control_txt;
    QGraphicsTextItem* HazardUnit_txt;
public:
    InstructionDecode(QObject* parent);
    void setStageColor(QColor clr);

};

#endif // INSTRUCTIONDECODE_H
