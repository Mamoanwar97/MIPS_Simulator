#ifndef DATA_MEMORY_H
#define DATA_MEMORY_H

#include <QObject>
#include <QTableWidget>

#define MEM_SIZE 8192

class Data_Memory : public QTableWidget
{
    Q_OBJECT
private:
    int* memory ;
public:
    explicit Data_Memory(QWidget *parent = 0);

signals:

public slots:
    void write_memory(uint address , int value);
    int read_memory (uint address);

    int *get_Memory_Access();
};

#endif // DATA_MEMORY_H
