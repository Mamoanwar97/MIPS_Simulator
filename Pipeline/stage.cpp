#include "stage.h"

Stage::Stage(QObject *parent) : QObject(parent)
{
    this->color = QColor(Qt::black);
    this->text_instruction = new QGraphicsTextItem();
    // must be called at first to connect the signal befor we emit it
    connect(this,SIGNAL(addnewItem(QGraphicsItem*)),parent,SLOT(addNewItem(QGraphicsItem*)));
}

Path *Stage::newPath(vector<string> points)
{
    Path* temp = new Path(points);
    temp->setColor(QColor(Qt::blue));
    emit addnewItem(temp);
    return temp;
}

QColor Stage::getColor()
{
    return this->color;
}

void Stage::setTextInstruction(QString text)
{
    this->text_instruction->setPlainText(text);
}
