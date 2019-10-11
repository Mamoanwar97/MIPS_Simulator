#ifndef LABEL_H
#define LABEL_H
#include <bits/stdc++.h>
#include <QObject>
using namespace std;

class Memory
{
private:
    uint address;
    string name;
public:
    Label(uint index , string Name);
    uint get_address();
    string get_name();

};

#endif // LABEL_H
