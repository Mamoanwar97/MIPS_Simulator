#ifndef LABEL_H
#define LABEL_H
#include <bits/stdc++.h>
#include <QObject>
using namespace std;

class Data
{
private:
    long* address;
    int size;
    string name;
public:
    Data(string Name,int Size);
    long* get_address();
    int get_size();
    string get_name();

    uint* operator [] (string Name);
};

#endif // LABEL_H
