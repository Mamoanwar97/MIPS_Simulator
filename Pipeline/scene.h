#ifndef SCENE_H
#define SCENE_H

#define MAX_TOP_LEFT_CORNER -984,-446
#define WIDTH_MUX 1
#define MUXs_SIZE 5
#define REGISTERS_COLOR QColor(50,50,50)
#define INITAIL_COLOR QColor(50,50,50)
#define OFF_COLOR QColor(50,50,50)
#define FLUSH_COLOR QColor(50,50,50)

#define fetch 0
#define decode 1
#define ex 2
#define memory 3
#define wb 4

#define PC_POS 0
#define STALL 1
#define FLUSH 2

#include <QObject>
#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QFont>
#include <QPainter>
#include <QPaintEvent>
#include <QRect>
#include <QRectF>
#include <QLabel>
#include <QPointF>
#include <QPainterPath>
#include <bits/stdc++.h>
#include <iostream>
#include <QImage>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSceneEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
#include "path.h"
#include "stage.h"
#include "instructionfetch.h"
#include "instructiondecode.h"
#include "execution.h"
#include "memorystage.h"
#include "writebackstage.h"
#include <stack>
#include <QStack>
#include <fstream>

using namespace std;
class state {
public:
    QColor color;
    QString text_instruction;
    state(QColor clr = Qt::white ){ this->color = clr;}
};

class myScene : public QGraphicsScene
{
    Q_OBJECT
private:
    QGraphicsTextItem* cursor; // printing coordinates

    vector<QColor> colors;
    int index_color;  // fetch color
    uint index; // state index


    vector<string> code;
    vector<string> clocks_verilog;
    uint max_clocks;
    ifstream code_file ,verilog_file;
    string codePath , verilogPath;


    vector< vector<state> > states;


    InstructionFetch* IF;
    InstructionDecode* ID;
    Execution* EX;
    MemoryStage* MEM;
    WriteBackStage* WB;




    QGraphicsRectItem* IF_ID;
    QGraphicsRectItem* ID_EX;
    QGraphicsRectItem* EX_MEM;
    QGraphicsRectItem* MEM_WB;
    // Text Drawing *** Not Imortant ***
    QGraphicsTextItem* IFID_txt;
    QGraphicsTextItem* IDEX_txt;
    QGraphicsTextItem* EXMEM_txt;
    QGraphicsTextItem* MEMWB_txt;
    QGraphicsTextItem** MUX_txt;

    int PC;
    int flush;
    int stall;

public:
    explicit myScene(QWidget *parent = nullptr);
    void updateStagesColors(int);

private:
    void RegistersUnit();
    void initColors();
    void initText();
    void ReadModelSim();
    void initStates();
    vector<string> split_string(string s,string splitter);
    QString parasePC_Text(string pc);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

signals:

public slots:
    void addNewItem(QGraphicsItem*);
    void UpdatePipeline(int direction);
    void INIT_Scene(vector<string>);

};

#endif // SCENE_H
