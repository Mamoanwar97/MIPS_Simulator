#include "data_memory.h"

Data_Memory::Data_Memory(QObject *parent) : QObject(parent)
{
    this->memory = new int [MEM_SIZE];
    cout << "address from data_mem = " << this->memory << endl;

    for (uint i = 0 ; i < MEM_SIZE ; i++)
    {
        this->memory[i] =15;
    }
}

void Data_Memory::clear()
{
    delete this->memory;
}

void Data_Memory::write_memory(uint address, int value)
{
    this->memory[address] = value;
    cout << "address " << address << " " << this->memory[address] << endl;
}

int Data_Memory::read_memory(uint address)
{
    return this->memory[address];
}

int* Data_Memory::get_Memory_Access()
{
    return this->memory;
}
