#ifndef ALU_H
#define ALU_H
#include <bits/stdc++.h>
#include <QObject>
using namespace std;
#include "assembler.h"

#define SEGMENT_SIZE sizeof(long)
#define PRINT_CODE 4
#define EXIT_CODE 10

class ALU : public QObject
{
    Q_OBJECT
private:
    string operand;
    long input1;
    long input2;
    long result;
    uint Zero_Flag;
    map<uint,vector<string>> Instructions;
public:
    explicit ALU(QObject *parent = nullptr);
    void R_Format_ALU(vector<string>);
    void I_Format_ALU(vector<string>);
    void J_Format_ALU(vector<string>);
    bool Special_MIPS(vector<string>);
    void clear();
    long get_16_bit_value(string s);

signals:
    uint get_fun_format(string name);
    long read_register(string name);
    void set_register(string name,long value);
    void change_PC_Label(string);
    void change_PC_address(int);
    int  PC_current_instr();

    void Push(string);
    void Pop(string);
    void syscall(string);

    bool check_for_word(string s);
    long get_data_word(string s);

    long get_value_data_memory(uint);
    void set_value_data_memory(uint,long);
public slots:
    void ALU_Operation(vector<string>);
};

#endif // ALU_H
