#ifndef ALU_H
#define ALU_H
#include <bits/stdc++.h>
#include <QObject>
using namespace std;
#include "assembler.h"

#define SEGMENT_SIZE sizeof(int)
#define PRINT_CODE 4
#define EXIT_CODE 10

class ALU : public QObject
{
    Q_OBJECT
private:
    string operand;
    int input1;
    int input2;
    int result;
    uint Zero_Flag;
    map<uint,vector<string>> Instructions;
public:
    explicit ALU(QObject *parent = nullptr);
    void R_Format_ALU(vector<string>);
    void I_Format_ALU(vector<string>);
    void J_Format_ALU(vector<string>);
    bool Special_MIPS(vector<string>);
    void clear();
    int get_16_bit_value(string s);
    void info_alu(vector<string>);

signals:
    uint get_fun_format(string name);
    int read_register(string name);
    void set_register(string name,int value);
    void change_PC_Label(string);
    void change_PC_address(int);
    int  PC_current_instr();

    void Push(string);
    void Pop(string);
    void syscall(string);

    bool check_for_word(string s);
    int get_data_word(string s);

    int get_value_data_memory(uint);
    void set_value_data_memory(uint,int);
    void update_memory_gui(uint);
    void Info_Output(string);
public slots:
    void ALU_Operation(vector<string>);
};

#endif // ALU_H
