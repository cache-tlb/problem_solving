#include <cstdio>
#include <iostream>

using namespace std;

#define WORDMASK 0x0F
#define ADDRMASK 0xFF
const int MEMSIZE = 256;
const char *table = "0123456789ABCDEF\0";
const int instr_len[] = {3,3,1,1,1,1,3,3,1};
typedef unsigned char uint8_t;

void swap(uint8_t &a, uint8_t &b) {
    uint8_t tmp = a; a = b; b = tmp;
}

int pc;         // not > 255 (0xFF)
uint8_t A, B;   // accumulator, 1 word(4 bit)
uint8_t mem[MEMSIZE]; // 1 word each
string line;
char output[MEMSIZE+1] = {};

void process() {
    pc = 0;
    A = 0; B = 0;
    while((mem[pc] & WORDMASK) != 0x08){
        bool branch = false;
        unsigned int addr = (mem[pc+1] << 4) + mem[pc+2];
        addr &= ADDRMASK;
        int code = mem[pc] & WORDMASK;
        switch(code){
        case 0:
            A = mem[addr] & WORDMASK;
            break;
        case 1:
            mem[addr] = A & WORDMASK;
            break;
        case 2:
            swap(A, B);
            break;
        case 3:
            A = (A&WORDMASK) + (B&WORDMASK);
            B = (A >> 4) & WORDMASK;
            A = A & WORDMASK;
            //cout << (int)A << ' ' << (int)B << endl;
            break;
        case 4:
            A = (A+1) & WORDMASK;
            break;
        case 5:
            A = (A-1) & WORDMASK;
            break;
        case 6:
            if((A&WORDMASK)==0){
                pc = addr;
                branch = true;
            }
            else{/*nothing*/}
            break;
        case 7:
            pc = addr;
            branch = true;
            break;
        case 8: return;
        default: break;
        }
        if(!branch){
            int len = instr_len[code];
            pc += len;
        }
        if(pc >= 0xF0){
            pc -= 0xF0;
        }
    }
}

int main(int argc, char const *argv[])
{
    while(cin >> line){
        if(line[0]=='8') break;
        for(int i = 0; i < MEMSIZE; i++){
            if('0' <= line[i] && line[i] <= '9'){
                mem[i] = line[i] - '0';
            }else {
                mem[i] = line[i] - 'A' + 10;
            }
        }
        process();
        for(int i = 0; i < MEMSIZE; i++){
            output[i] = table[mem[i]];
        }
        output[MEMSIZE] = '\0';
        printf("%s\n", output);
    }
    return 0;
}
