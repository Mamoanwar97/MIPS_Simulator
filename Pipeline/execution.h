#ifndef EXECUTION_H
#define EXECUTION_H
#define WIDTH_MUX 1
#include "stage.h"
class Execution : public Stage
{
    Q_OBJECT
private:
    QGraphicsPolygonItem* ALU;
    QGraphicsPathItem* Forwarding_Unit;
    QGraphicsPathItem* Mux_IDEX_ALU_1;
    QGraphicsPathItem* Mux_IDEX_ALU_2;
    QGraphicsPathItem* Mux_IDEX_EXMEM;

    // Text
    QGraphicsTextItem* ALU_txt;
    QGraphicsTextItem* ForwardUnit_txt;
public:
    Execution(QObject *parent);
    void setStageColor(QColor clr);
};

#endif // EXECUTION_H
