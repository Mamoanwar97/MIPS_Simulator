#include "alu.h"

ALU::ALU(QObject *parent) : QObject(parent)
{

}

void ALU::R_Format_ALU(vector<string> instruction)
{
    // ================= Specials ==================
    if (this->operand == "sll")
    {
        this->result = emit read_register(instruction[2]) << stoi(instruction[3]);
        emit set_register(instruction[1],this->result);
        return;
    }
    else if (this->operand == "srl")
    {
        this->result = emit read_register(instruction[2]) >> stoi(instruction[3]);
        emit set_register(instruction[1],this->result);
        return;
    }

    else if (this->operand == "jr")
    {
        emit change_PC_address( emit read_register(instruction[1]) );
        return;
    }
    else if (this->operand == "slt")
    {
        input1 = emit read_register(instruction[2]);
        input2 = emit read_register(instruction[3]);
        this->result = input1 - input2;
        if(input1 == input2)
            this->Zero_Flag = 1;
        if(input1 < input2)
            emit set_register(instruction[1],1);
        return;
    }
    // ==============================================
    input1 = emit read_register(instruction[2]);
    input2 = emit read_register(instruction[3]);

    if(this->operand == "add")
        this->result = input1 + input2;
    else if (this->operand == "sub")
        this->result = input1 - input2;
    else if (this->operand == "and")
        this->result = input1 & input2;
    else if (this->operand == "or")
        this->result = input1 | input2;
    else if (this->operand == "xor")
        this->result = input1 ^ input2;
    else if (this->operand == "nor")
        this->result = ~(input1 | input2);

    emit set_register(instruction[1],this->result);

}
void ALU::J_Format_ALU(vector<string> instruction)
{
    if (this->operand == "j")
    {
        emit change_PC_Label( instruction[1] );
    }
    else if (this->operand == "jal")
    {
        int current_instruction_address = emit PC_current_instr();
        cout << current_instruction_address << endl;
        emit change_PC_Label( instruction[1] );
        emit set_register("$ra",current_instruction_address);
    }}

void ALU::I_Format_ALU(vector<string> instruction)
{
    //  ==================Specials ==================
    if (this->operand == "lw")
    {
        input1 = emit read_register(instruction[3]) ; // base address
        input2 = get_16_bit_value(instruction[2]) ; // the shift
        this->result = input1+input2; // index

        uint address =this->result/4; // devide by 4 because it is num of bytes not words
        int value = emit get_value_data_memory(address);
        emit set_register(instruction[1],value);
        return;
    }
    else if (this->operand == "sw")
    {
        input1 = emit read_register(instruction[3]) ; // base address
        input2 = get_16_bit_value(instruction[2]) ; // the shift
        this->result = input1+input2; // index

        int value  = emit read_register(instruction[1] );  // get data from register to store it
        uint address =this->result/4; // devide by 4 because it is num of bytes not words

        emit set_value_data_memory(address,value);
        emit update_memory_gui(address);

        return;
    }
    else if (this ->operand == "li")
    {
        input1 = get_16_bit_value(instruction[2]);
        input2 = 0;
        this->result = input1;
        emit set_register(instruction[1],this->result);
        return;
    }
    else if (this->operand == "beq")
    {
        input1 = emit read_register(instruction[1]);
        input2 = emit read_register(instruction[2]);
        cout << "input1 = " << input1 << " , " << "input2= "<< input2 << endl;
        if (input1 == input2)
        {
            this->Zero_Flag = 1;
            emit change_PC_Label( instruction[3] );
        }
        return;
    }
    else if (this->operand == "bne")
    {
        input1 = emit read_register(instruction[1]);
        input2 = emit read_register(instruction[2]);
        cout << "input1 = " << input1 << " , " << "input2= "<< input2 << endl;

        if (input1 != input2)
            emit change_PC_Label( instruction[3] );
        return;
    }
    else if (this->operand== "lui")
    {
        input1 = get_16_bit_value (instruction[2]);
        this->result = input1 << 16;
        emit set_register(instruction[1],this->result);
        return;
    }
    else if(this->operand == "slti")
    {
        input1 = emit read_register(instruction[2]);
        input2 = get_16_bit_value( instruction[3] );
        if(input1 < input2)
        {
            this->result=1;
            emit set_register(instruction[1],1);
        }
        else
        {
            emit set_register(instruction[1],0);
            if(input1 == input2)
                this->Zero_Flag = 1;
        }
        return;}
    input1 = emit read_register(instruction[2]);
    input2 = get_16_bit_value(instruction[3]);
    if(this->operand == "addi")
        this->result = input1 +input2;
    else if(this->operand == "andi")
        this->result = input1 & input2;
    else if(this->operand == "ori")
        this->result = input1 | input2;
    else if(this->operand == "xori")
        this->result = input1 ^ input2;

    emit set_register(instruction[1],this->result);

}
bool ALU::Special_MIPS(vector<string> instruction)
{
    if(this->operand == "push")
    {
        emit Push(instruction[1]);
        return true;
    }
    else if (this->operand == "pop")
    {
        emit Pop(instruction[1]);
        return true;
    }
    else if (this->operand == "syscall")
    {
        input1 = emit read_register("$a0");
        input2 = emit read_register("$v0");
        if (input2 == PRINT_CODE)
        {
            if(instruction.size() ==2) // Syscall + address
            {
                emit syscall( to_string(input1) );
                cout << input1 << endl;
            }
            else if (instruction.size() == 3) // Syscall + String + address
            {
                emit syscall(instruction[1]);
                cout << instruction[1] << endl;
            }
        }
        else if (input2 == EXIT_CODE)
        {
            cout << "SYSCALL 10 End of Excution "<< endl;
            exit(1);
        }
        else {
            cout << "Syscall not Ray2" <<endl;
        }
        return true;
    }

    return  false;

}

void ALU::clear()
{
    this->Instructions.clear();
    this->input1=0;
    this->input2=0;
    this->operand="";
    this->result =0;
}

int ALU::get_16_bit_value(string s)
{
    if ( emit check_for_word(s))
    {
        return emit get_data_word(s);
    }
    return stol(s);
}


void ALU::ALU_Operation(vector<string> Instruction)
{
    this->operand = Instruction[0];
    //    cout << this->operand << endl ;

    if (this->Special_MIPS(Instruction))
    {
        //        cout << "SP"  << emit read_register("$sp") << endl;
        return;
    }

    uint Fun = emit get_fun_format(this->operand);

    if (Fun == I_Format_Fun)
        this->I_Format_ALU(Instruction);

    else if(Fun == J_Format_Fun)
        this->J_Format_ALU(Instruction);

    else
        this->R_Format_ALU(Instruction);

}
