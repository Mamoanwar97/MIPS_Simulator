#ifndef WRITEBACKSTAGE_H
#define WRITEBACKSTAGE_H
#include "stage.h"
class WriteBackStage : public Stage
{
    Q_OBJECT
private:
    QGraphicsPathItem* Mux_MEMWD_RegFile;
public:
    WriteBackStage(QObject* parent);
    void setStageColor(QColor clr,vector<string> muxs = vector<string>());

};

#endif // WRITEBACKSTAGE_H
