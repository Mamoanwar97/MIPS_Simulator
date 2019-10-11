#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <fstream>
#include <bits/stdc++.h>
#include <QObject>
using namespace std;
#include "assembler.h"
#include "register_file.h"
#include "alu.h"
#include "data.h"

#define PC         this->Program_Counter->getValue() /4
#define Set_PC(x)  this->Program_Counter->setValue((x)*4)
#define SYSCALL "syscall"


class GUI;
class Simulator : public QObject
{
    Q_OBJECT

    friend class GUI;
private:
    ALU* Alu ;
    Assembler* assembler;
    Register_File* register_file;
    Register* Program_Counter;

    ifstream file;
    string code_path;
    uint address;

    vector<string> code;
    vector<vector<string>> instructions;
    map<string,uint> Lables;
    map<string,Data*> Memory_Data;

public:
    Simulator();
    ~Simulator();
    void Simulate();
    void Simulate(string path);
    void Split_Instruction(string s,uint index);
    void Read_Data();
    uint Read_Data_Editor(vector<string>);
    void Read_Instruction();
    void Read_Instruction_Editor();
    void Observer_Pattern();
    void Assemble_Instructions();
    void ALU_Logic();
    void clear();
private:
    bool check_for_specials(string);
    bool check_for_Lable(string,uint);
    vector<string> split_string(string s,string splitter);
    void print(vector<string>);
    void print(map<string,uint>);
    void print(deque<string> x);
    void print_all();


signals:
    vector<string> getInstruction_Editor();
    void Assemble_Instruction(vector<string>);
    void ALU_Instruction(vector<string>);
    void print_assembled_instruction();
    void print_registers();
    void update_assembled_instruction();
    void update_registers();


public slots:
    void set_Program_Counter(string label);
    void set_Program_Counter(int adress);
    uint get_Label(string);
    long *get_Data_address(string);
    vector<string> get_instructions();
};

#endif // SIMULATOR_H
