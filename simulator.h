#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <fstream>
#include <bits/stdc++.h>
#include <QObject>

#include "assembler.h"
#include "register_file.h"
#include "alu.h"
#include "data_memory.h"
#include <QProcess>
#include <QThread>

#define PC_         this->Program_Counter->getValue() /4
#define Set_PC(x)  this->Program_Counter->setValue((x)*4)
#define SYSCALL "syscall"
#define DELAY 5


using namespace std;
class GUI;

class Simulator : public QObject
{
    Q_OBJECT

    friend class GUI;
    friend class MainWindow;
private:
    ALU* Alu ;
    Assembler* assembler;
    Register_File* register_file;
    Register* Program_Counter;
    Data_Memory* data_memory;

    ifstream file;
    string code_path;
    uint address;

    string file_assembly_path , file_assembly_path_pipeline;
    string file_regFile_path  , file_regFile_path_pipeline;
    string file_dataMemory_path, file_dataMemory_path_pipeline;
    QString modelsim_path;
    QString modelsim_pipeline_path;
    QString modelsim_command;
    QString modelsim_pipeline_command;
    QProcess* modelsim_process ;
    QProcess* modelsim_pipeline_process ;

    QString python_path;
    QString mode;

    vector<string> code;
    vector<vector<string>> instructions;
    map<string,uint> Lables;
    map<string,string> data_asciiz;
    map<string,int> data_word;


public:
    Simulator();
    ~Simulator();
    void Simulate();
    void Simulate(string path);
    void Split_Instruction(string s);
    uint Read_Data_Editor(vector<string>);
    void Read_Instruction_Editor();
    void Observer_Pattern();
    void Assemble_Instructions();
    void ALU_Logic();
    void clear();
    void Modelsim();

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
    void update_data_memory();
    void clear_data_memory();
    void ERROR_Output(string);
    void file_assembled_instructions(string path);
    void file_regFile_data(string path);
    void file_dataMemory_data(string path);
    void update_Text_Editor(vector<string>);
    void clearTextEditor();
    void show(vector<string>);
    void updatePipelineAssemblyCode(vector<string>);
public slots:
    void set_Program_Counter(string label);
    void set_Program_Counter(int adress);
    uint get_Label(string);
    vector<string> get_instructions();
    bool check_data_words(string s);
    int get_dataWord(string s);
    void update_GUI();

};

#endif // SIMULATOR_H
