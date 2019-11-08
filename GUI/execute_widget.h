#ifndef EXECUTE_WIDGET_H
#define EXECUTE_WIDGET_H
#include "tree_widget.h"

class Execute_Widget : public Tree_Widget
{
    Q_OBJECT
public:
    explicit Execute_Widget(QWidget *parent = nullptr);

public slots:
    void updateInstructions();
signals:
    vector<string> require_Instructions();
    vector<string> require_AssembledInstructions();
};

#endif // EXECUTE_WIDGET_H
