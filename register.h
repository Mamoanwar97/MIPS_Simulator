#ifndef REGISTER_H
#define REGISTER_H
#include <bits/stdc++.h>
using namespace std;
#include <QObject>
class Register : public QObject
{
    Q_OBJECT
private:
    string name;
    long value ;
    uint num ;
public:
    Register(string Name,uint Num,long Value=0);
    void clear();
public slots:
    void setValue(long);
    long getValue();
    uint getNum();
    string getName();

};

#endif // REGISTER_H
