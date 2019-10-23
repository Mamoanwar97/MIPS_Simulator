#ifndef ASSEMBLER_H
#define ASSEMBLER_H
#include <QObject>
#include <bits/stdc++.h>
using namespace std;

#define opcode 6
#define fun 5
#define main_operand 0
#define I_Format_Fun 100
#define J_Format_Fun 200
class Simulator;
class Assembler : public QObject
{
    Q_OBJECT
    friend class Simulator;
private:

    vector<deque<long>> assembled_Instructions;
    vector<string> assembled_Instr_Strings;
    map<string,pair<uint,uint>> operands;
    string operand;

public:
    Assembler();
    long get_16bit_value(string s );
public slots:

    vector<string> get_assembled_strings();
    uint get_opcode(string Operand);
    uint get_fun(string Operand);
    void print(deque<long> x);
    void Assemble(vector<string> Instruction);
    void convert_Assemble_to_String(deque<long>,uint);
    void print_all();

signals:
    uint get_register_num(string);
    uint get_PC();
    uint get_label_address(string);
    int* get_data_address(string);

    bool check_for_word(string s);
    long get_data_word(string s);

};

#endif // ASSEMBLER_H
