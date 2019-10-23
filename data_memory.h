#ifndef DATA_MEMORY_H
#define DATA_MEMORY_H

#include <QObject>
#include <QTableWidget>
#include <iostream>
#include <bits/stdc++.h>

#define MEM_SIZE 8192

using namespace std;
class Data_Memory : public QObject
{
    Q_OBJECT
private:
    int* memory ;
public:
    explicit Data_Memory(QObject *parent = 0);
    void clear();
signals:

public slots:
    void write_memory(uint address , int value);
    int read_memory (uint address);


    int *get_Memory_Access();
};

#endif // DATA_MEMORY_H
