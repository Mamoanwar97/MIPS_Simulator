#include "data_memory.h"

Data_Memory::Data_Memory(QWidget *parent) : QTableWidget(parent)
{
    this->memory = new int(SIZE);
}

void Data_Memory::write_memory(uint address, long value)
{
    this->memory[address] = value;
}

long Data_Memory::read_memory(uint address)
{
    return this->memory[address];
}
