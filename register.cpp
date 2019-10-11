#include "register.h"

Register::Register(string Name,uint Num, long Value)
{
    this->name = Name;
    this->value = Value;
    this->num = Num;
}

void Register::clear()
{
    this->value = 0;
}

void Register::setValue(long Value)
{
    this->value = Value;
}

long Register::getValue()
{
    return this->value;
}

uint Register::getNum()
{
    return this->num;
}

string Register::getName()
{
    return this->name;
}
