#include "assembler.h"
Assembler::Assembler()
{
    // ============ R-Format =============
    this->operands["add"] = {0,32};
    this->operands["sub"] = {0,34};
    this->operands["and"] = {0,36};
    this->operands["or" ] = {0,37};
    this->operands["xor"] = {0,38};
    this->operands["nor"] = {0,39};
    this->operands["slt"] = {0,42};
    this->operands["sgt"] = {0,1};
    this->operands["sll"] = {0, 0};
    this->operands["srl"] = {0, 2};
    this->operands["jr" ] = {0, 8};
    // ============ I-Format =============
    this->operands["addi"] = {8, I_Format_Fun};
    this->operands["andi"] = {12,I_Format_Fun};
    this->operands["ori" ] = {13,I_Format_Fun};
    this->operands["xori"] = {14,I_Format_Fun};
    this->operands["slti"] = {10,I_Format_Fun};
    this->operands["sgti"] = {11,I_Format_Fun};
    this->operands["lui" ] = {15,I_Format_Fun};
    this->operands[ "lw" ] = {35,I_Format_Fun};
    this->operands[ "sw" ] = {43,I_Format_Fun};
    this->operands["beq" ] = {4, I_Format_Fun};
    this->operands["bne"]  = {5, I_Format_Fun};
    this->operands["li"]   = {101,I_Format_Fun};
    // ============ J-Format =============
    this->operands[ "j" ]     = {2, J_Format_Fun};
    this->operands["jal"]     = {3, J_Format_Fun};
    this->operands["push"]    = {200,J_Format_Fun};
    this->operands["pop"]     =  {201,J_Format_Fun};
    // ===================================
}

int Assembler::get_16bit_value(string s)
{
    if ( emit check_for_word(s))
    {
        return emit get_data_word(s);
    }
    return stol(s);
}

vector<string> Assembler::get_assembled_strings()
{
    return this->assembled_Instr_Strings;
}

uint Assembler::get_opcode(string Operand)
{
    return this->operands[Operand].first;
}

uint Assembler::get_fun(string Operand)
{
    return this->operands[Operand].second;
}

void Assembler::Assemble(vector<string> Instruction)
{
    deque<int> assembled_Instruction ;
    this->operand = Instruction[main_operand];

    if (this->operand == "syscall")
        return;

    assembled_Instruction.push_front(this->get_opcode(this->operand));
    uint Fun = this->get_fun(this->operand);

    if (Fun == I_Format_Fun )
    {
        if (this->operand == "sw" || this->operand == "lw")
        {
            assembled_Instruction.push_back( emit get_register_num(Instruction[3]) ) ;
            assembled_Instruction.push_back( emit get_register_num(Instruction[1]) ) ;
            assembled_Instruction.push_back( get_16bit_value(Instruction[2]) /4) ;  // 16-bit address value / 4 because in verilog the addressing is words not byte addressing
        }
        else if (this->operand == "beq" || this->operand == "bne")
        {
            assembled_Instruction.push_back( emit get_register_num(Instruction[1]) ) ;
            assembled_Instruction.push_back( emit get_register_num(Instruction[2]) ) ;
            // label address in words mode - address = pc address(in bytes)/4 +1(because pc incremented automatically)
            int x = ( emit get_label_address(Instruction[3]) ) - ( stoi(Instruction[4])/4 +1) ;
            cout << "x= " <<  emit get_label_address(Instruction[3]) << " - " << stoi(Instruction[4])/4+1 << "=" << x << endl;
            assembled_Instruction.push_back( ( x ) )  ;  // PC-relative addressing
        }
        else if (this->operand == "lui")
        {
            assembled_Instruction.push_back(0);
            assembled_Instruction.push_back( emit get_register_num(Instruction[1]) ) ;
            assembled_Instruction.push_back( get_16bit_value(Instruction[2]) ) ;  // shift value
        }

        else if (this->operand == "li")
        {
            assembled_Instruction.push_back(0);
            assembled_Instruction.push_back( emit get_register_num(Instruction[1]) ) ;
            assembled_Instruction.push_back( get_16bit_value(Instruction[2])) ;
        }
        else
        {
            assembled_Instruction.push_back( emit get_register_num(Instruction[2]) ) ;
            assembled_Instruction.push_back( emit get_register_num(Instruction[1]) ) ;
            assembled_Instruction.push_back( get_16bit_value(Instruction[3]) ) ;  // 16-bit value
        }
    }
    else if(Fun == J_Format_Fun)
    {
        if(this->operand == "push" || this->operand == "pop")
        {
            assembled_Instruction.push_back(emit get_register_num(Instruction[1]));
        }
        else
            assembled_Instruction.push_back( emit get_label_address(Instruction[1]) ) ;
    }
    else
    {
        if (this->operand == "srl" || this->operand == "sll")
            // R-Format Instructions - Shift
        {
            assembled_Instruction.push_back(0); // for shift instructions there is no first register
            assembled_Instruction.push_back( emit get_register_num(Instruction[2]) ) ;
            assembled_Instruction.push_back( emit get_register_num(Instruction[1]) ) ;
            assembled_Instruction.push_back( stoul(Instruction[3]) ) ;  // shift value
        }
        else if (this->operand == "jr")
            // R-Format Instructions - Jump
        {
            assembled_Instruction.push_back( emit get_register_num(Instruction[1]) ) ;
            assembled_Instruction.push_back( 0 ) ;
            assembled_Instruction.push_back( 0 ) ;
            assembled_Instruction.push_back( 0 ) ;
        }
        else
            // R-Format Instructions - Arthamatic and Logic
        {
            assembled_Instruction.push_back( emit get_register_num(Instruction[2]) ) ;
            assembled_Instruction.push_back( emit get_register_num(Instruction[3]) ) ;
            assembled_Instruction.push_back( emit get_register_num(Instruction[1]) ) ;
            assembled_Instruction.push_back(0); // for non shift instructions
        }
    }

    if (Fun != I_Format_Fun && Fun != J_Format_Fun)
        assembled_Instruction.push_back(Fun);


    this->convert_Assemble_to_String(assembled_Instruction,Fun);
    this->assembled_Instructions.push_back(assembled_Instruction);
}
string assemble(int num , uint n)
{
    string s;
    bitset<32> Num(num);
    for (uint i = 0; i < n; ++i) {
        if (Num[n-i-1] == 0)
            s += '0';
        else
            s += '1';
    }
    return s;
}
void Assembler::convert_Assemble_to_String(deque<int> instruction,uint Fun)
{
    string s;

    if(Fun == I_Format_Fun)
    {
        s += assemble(instruction[0],6) ; // opcode
        s += assemble(instruction[1],5) ; // registers
        s += assemble(instruction[2],5) ; // registers
        s += assemble(instruction[3],16); // 16-bit address
    }
    else if (Fun == J_Format_Fun)
    {
        s += assemble(instruction[0],6) ; // opcode
        s += assemble(instruction[1],26) ; // 26-bit address
    }
    else  // Fun == R_Format
    {
        s += assemble(instruction[0],6); // opcode
        s += assemble(instruction[1],5); // registers
        s += assemble(instruction[2],5); // registers
        s += assemble(instruction[3],5); // registers
        s += assemble(instruction[4],5); // shift
        s += assemble(instruction[5],6); // fun

    }

    // bitset converts string s to 32 bit array of (0,1)
    bitset<32> x(s);
    uint xx =uint( x.to_ulong()  );
    // stringstream to convert that int to hex string
    stringstream stream;
    stream << hex << xx;
    string result = "0x" + stream.str() ;

    this->assembled_Instr_Strings.push_back(result);
}

void Assembler::print_all()
{
    for (uint i =0 ;i < assembled_Instructions.size();i++)
        print(assembled_Instructions[i]);
    cout << endl;
}

void Assembler::File_assembled_instructions(string path )
{
    this->file.open(path);
    if (!file.is_open())
    {
        cout << "assembled file can't open ya ray2" << endl;
        return;
    }

    string s;
    for(uint i =0 ;i < assembled_Instr_Strings.size(); i++)
    {   s = assembled_Instr_Strings[i];
        s.erase(0,2);
        file << s << endl;
    }
    file.close();
    cout << "************* Assembled file is Written **************" << endl;
}
void Assembler::print(deque<int> x)
{
    for (uint i = 0; i < x.size(); ++i) {
        cout << x[i] << " ";
    }
    cout << endl;
}
