#ifndef INSTRUCTIONDECODE_H
#define INSTRUCTIONDECODE_H
#include "stage.h"

class InstructionDecode : public Stage
{
    Q_OBJECT
private:
    QGraphicsRectItem* RegFile ;
    QGraphicsEllipseItem* Control;
    QGraphicsEllipseItem* Comparator;
    QGraphicsPathItem* Hazard_Unit;
    QGraphicsPathItem* Mux_Control_IDEX;
    // Text (Not Important)
    QGraphicsTextItem* RegFile_txt;
    QGraphicsTextItem* Control_txt;
    QGraphicsTextItem* HazardUnit_txt;
    QGraphicsTextItem* zero;
public:
    InstructionDecode(QObject* parent);
    void setStageColor(QColor clr,vector<string> muxs = vector<string>());

};

#endif // INSTRUCTIONDECODE_H
