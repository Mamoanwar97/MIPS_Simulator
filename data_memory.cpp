#include "data_memory.h"

Data_Memory::Data_Memory(QWidget *parent) : QTableWidget(parent)
{
    this->memory = new int(MEM_SIZE);
}

void Data_Memory::write_memory(uint address, int value)
{
    this->memory[address] = value;
}

int Data_Memory::read_memory(uint address)
{
    return this->memory[address];
}

int *Data_Memory::get_Memory_Access()
{
    return this->memory;
}
