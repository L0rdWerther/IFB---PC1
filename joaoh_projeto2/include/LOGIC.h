#ifndef TOY_ASSEMBLY_LOGIC_H
#define TOY_ASSEMBLY_LOGIC_H

#include "../include/LOGIC.h"      

void BEQ(int RX[], int* i, int registrador[], int RY[], int inteiro[]);
void BLT(int RX[], int* i, int registrador[], int RY[], int inteiro[]);
void JMP(int inteiro[], int* i);

#endif //TOY_ASSEMBLY_LOGIC_H