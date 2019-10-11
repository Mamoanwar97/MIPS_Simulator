#include "label.h"


Label::Label(uint index, string Name)
{
    this->address = index;
    this->name = Name;
}

uint Label::get_address()
{
    return this->address;
}

string Label::get_name()
{
    return this->name;
}
