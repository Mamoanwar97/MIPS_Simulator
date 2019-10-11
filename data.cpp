#include "data.h"

Data::Data(string Name, int Size)
{
    this->name = Name;
    this->size = Size ;
    this->address = new long(this->size);
    cout << "address " << this->name << " " << this->address<<endl;
}

long* Data::get_address()
{
    return this->address;
}

int Data::get_size()
{
    return this->size;
}

string Data::get_name()
{
    return this->name;
}
