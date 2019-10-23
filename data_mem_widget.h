#ifndef DATA_MEM_WIDGET_H
#define DATA_MEM_WIDGET_H
#include "tree_widget.h"
#include "data_memory.h"

#define COLOMN_SIZE 17
#define ROW_SIZE (MEM_SIZE/ (COLOMN_SIZE-1) )
class Data_Mem_Widget : public Tree_Widget
{
    Q_OBJECT
private :
    int * memory;
    string convert_int_to_hex_string(int);
public:
    explicit Data_Mem_Widget(QWidget *parent = nullptr);

public slots:
    void update_memory();
    void update_memory(uint);
signals:
    int * get_access_memory();
};

#endif // DATA_MEM_WIDGET_H
