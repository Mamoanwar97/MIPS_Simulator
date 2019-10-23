#include "tree_widget.h"

Tree_Widget::Tree_Widget(QWidget *parent) : QTreeWidget(parent)
{
    this->color.setRgb(COLOR);
    this->flag_color = 1;
}


void Tree_Widget::addItem()
{
    QTreeWidgetItem * item = new QTreeWidgetItem(QStringList());
    this->setColor(item);

    this->addTopLevelItem(item);
    this->Items.push_back(item);}
void Tree_Widget::addItem(QStringList s)
{
    QTreeWidgetItem * item = new QTreeWidgetItem(s);
    this->setColor(item);

    this->addTopLevelItem(item);
    this->Items.push_back(item);}

void Tree_Widget::setColor(QTreeWidgetItem *item)
{
    if (this->flag_color)
    {
        for (uint i =0;i <item->columnCount();i++) {
            item->setBackground(i,this->color);
        }
        this->flag_color = 0;
    }
    else {
        this->flag_color = 1;
    }
}
