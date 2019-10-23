#ifndef REGFILE_WIDGET_H
#define REGFILE_WIDGET_H
#include "tree_widget.h"

class regFile_Widget : public Tree_Widget
{
    Q_OBJECT
public:
    explicit regFile_Widget (QWidget *parent = nullptr);
    void init_registers();

public slots:
    void updateRegisters();
signals:
    map<string,Register*> get_registers();
};

#endif // REGFILE_WIDGET_H
